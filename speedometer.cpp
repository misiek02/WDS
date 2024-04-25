#include "speedometer.hh"
#include <QPainter>
#include <QPolygon>
#include <QVBoxLayout>
#include <QLabel>

Speedometer::Speedometer(QWidget *parent) : QWidget(parent), m_angle(0), m_speed(0) {
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Speedometer::updateNeedle);
    m_timer->start(50); // Update every 100 milliseconds

    // Slider setup
    m_speedSlider = new QSlider(Qt::Horizontal, this);
    m_speedSlider->setRange(0, 100);
    m_speedSlider->setFixedWidth(300);
    m_speedSlider->setFixedHeight(30);
    connect(m_speedSlider, &QSlider::valueChanged, this, &Speedometer::sliderValue);

    // Layout setup
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_speedSlider);
    layout->addStretch();
    setLayout(layout);

    // QLabel *Display = new QLabel(this);
    // layout->addWidget(Display);
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
    painter.setWindow(-50, -50, 100, 100);

    // Draw the speedometer gauge
    QLinearGradient gradient(80, -40, 0, 40);
    gradient.setColorAt(0, QColor(170, 170, 170)); // Początkowy kolor gradientu
    gradient.setColorAt(1, QColor(100, 100, 100)); // Końcowy kolor gradientu
    painter.setPen(Qt::gray);
    painter.setBrush(gradient);
    painter.drawEllipse(-40, -40, 80, 80);
    painter.setPen(QPen(QColor(70, 70, 80), 2));
    painter.setBrush(Qt::transparent);
    painter.drawEllipse(-40, -40, 80, 80);

    // Draw the numbers background
    QFont font2 = painter.font();
    font2.setPointSize(4);
    font2.setBold(true);
    painter.setFont(font2);
    painter.setPen(Qt::black);
    for (int i = 0; i <= 100; i += 10) {
        painter.save();
        painter.rotate(-125 + i * 2.57);
        painter.translate(0, -34);
        painter.drawText(-4, 1, QString::number(i));
        painter.restore();
    }
    // Draw the numbers foreground
    QFont font = painter.font();
    font.setPointSize(4);
    font.setBold(true);
    painter.setFont(font);
    painter.setPen(QColor(220, 0, 0));
    for (int i = 0; i <= 100; i += 10) {
        painter.save();
        painter.rotate(-125 + i * 2.57);
        painter.translate(0, -34);
        painter.drawText(-5, 0, QString::number(i));
        painter.restore();
    }


    // Draw the needle
    painter.save();
    painter.rotate(m_angle);
    QPolygon needle;
    needle << QPoint(0, -32) << QPoint(2, 0) << QPoint(-2, 0);
    painter.setPen(QColor(220, 0, 0));
    painter.setBrush(QColor(190, 0, 0));
    painter.drawConvexPolygon(needle);
    painter.restore();
}

void Speedometer::updateNeedle() {
    m_angle = static_cast<double>(m_speed) / 100 * 260 - 130;
    update();
}

void Speedometer::sliderValue(int value) {
    setSpeed(value);
}
