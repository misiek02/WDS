#ifndef GYROSCOPE_HH
#define GYROSCOPE_HH

#include <QWidget>

namespace Ui {
class Gyroscope;
}

class Gyroscope : public QWidget
{
    Q_OBJECT

public:
    explicit Gyroscope(QWidget *parent = nullptr);
    ~Gyroscope();

private:
    Ui::Gyroscope *ui;
};

#endif // GYROSCOPE_HH
