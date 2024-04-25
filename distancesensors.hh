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

private:
    Ui::DistanceSensors *ui;
};

#endif // DISTANCESENSORS_HH
