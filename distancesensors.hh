#ifndef DISTANCESENSORS_HH
#define DISTANCESENSORS_HH

#include <QWidget>

namespace Ui {
class DistanceSensors;
}

class DistanceSensors : public QWidget
{
    Q_OBJECT

public:
    explicit DistanceSensors(QWidget *parent = nullptr);
    ~DistanceSensors();

public slots:
    void setSharpValue(int value);
    void setTof1Value(int value);
    void setTof2Value(int value);
    void setMotor1Value(int value);

signals:
    void valueChanged(int newValue);


private:
    Ui::DistanceSensors *ui;
};

#endif // DISTANCESENSORS_HH
