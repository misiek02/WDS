#include "speedometer.hh"
#include <QPainter>
#include <QPolygon>
#include <QVBoxLayout>
#include <QLabel>

Speedometer::Speedometer(QWidget *parent) : QWidget(parent), m_angle(0), m_speed(0) {
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Speedometer::updateNeedle);
    m_timer->start(50);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addStretch(1);
    setLayout(layout);

    setMinimumSize(280, 280);
}

void Speedometer::setSpeed(int speed) {
    m_speed = speed;
    update();
}

void Speedometer::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int side = qMin(width(), height());

    painter.setViewport((width() - side) / 2, (height() - side) / 2, side, side);
    painter.setWindow(-35, -35, 70, 70);

    QLinearGradient gradient(56, -28, 0, 28);
    gradient.setColorAt(0, QColor(170, 170, 170));
    gradient.setColorAt(1, QColor(100, 100, 100));
    painter.setPen(Qt::gray);
    painter.setBrush(gradient);
    painter.drawEllipse(-28, -28, 56, 56);
    painter.setPen(QPen(QColor(70, 70, 80), 1.4));
    painter.setBrush(Qt::transparent);
    painter.drawEllipse(-28, -28, 56, 56);

    QFont font2 = painter.font();
    font2.setPointSize(2.8);
    font2.setBold(true);
    painter.setFont(font2);
    painter.setPen(Qt::black);
    for (int i = 0; i <= 100; i += 10) {
        painter.save();
        painter.rotate(-125 + i * 2.5);
        painter.translate(0, -23.8);
        painter.drawText(-2.8, 0.7, QString::number(i));
        painter.restore();
    }

    QFont font = painter.font();
    font.setPointSize(2.8);
    font.setBold(true);
    painter.setFont(font);
    painter.setPen(QColor(220, 0, 0));
    for (int i = 0; i <= 100; i += 10) {
        painter.save();
        painter.rotate(-125 + i * 2.5);
        painter.translate(0, -23.8);
        painter.drawText(-3.5, 0, QString::number(i));
        painter.restore();
    }

    painter.save();
    painter.rotate(m_angle);
    QPolygon needle;
    needle << QPoint(0, -22.4) << QPoint(1.4, 0) << QPoint(-1.4, 0);
    painter.setPen(QColor(220, 0, 0));
    painter.setBrush(QColor(190, 0, 0));
    painter.drawConvexPolygon(needle);
    painter.restore();
}

void Speedometer::updateNeedle() {
    m_angle = static_cast<double>(m_speed) / 100 * 260 - 130;
    update();
}

void Speedometer::sliderValueChanged(int value) {
    setSpeed(value);
}


void Speedometer::setSpeedValue(float value) {
    setSpeed(static_cast<int>(value));
}
