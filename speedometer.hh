#ifndef SPEEDOMETER_HH
#define SPEEDOMETER_HH
/**
 * @file speedometer.hh
 * @brief Definicja klasy Speedometer
 *
 * Pilik zawiera definicję klasy Speedometer która jest klasą bazową
 */
#include <QWidget>
#include <QTimer>
#include <QSlider>
#include <QLabel>

/**
 * @brief Modeluje pojęcie prędkościomierza
 */
class Speedometer : public QWidget {
    Q_OBJECT
public:
    /**
     * @brief Speedometer
     * @param parent
     */
    explicit Speedometer(QWidget *parent = nullptr);
    /**
     * @brief setSpeed ustawia prędkość
     * @param speed parametr prędkości
     */
    void setSpeed(int speed);

private slots:
    /**
     * @brief updateNeedle odświeża pozycję wskazówki zegara
     */
    void updateNeedle();
    /**
     * @brief sliderValueChanged obsługuje zmienę slider'a
     * @param value wartość slider'a
     */
    void sliderValueChanged(int value);

protected:
    /**
     * @brief paintEvent pozwala na tworzenie  obiektu jakim jest zegar prędkościomierza
     */
    void paintEvent(QPaintEvent *) override;

private:
    /**
     * @brief m_timer -- odświeża dane
     */
    QTimer *m_timer;
    /**
     * @brief m_speedSlider -- ustawia slider
     */
    QSlider *m_speedSlider;
    /**
     * @brief m_speed -- przypisuje prędkość do zegara
     */
    int m_speed;
    /**
     * @brief m_angle -- ustawia wskazówkę
     */
    double m_angle;
};

#endif // SPEEDOMETER_HH
