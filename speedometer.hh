#ifndef SPEEDOMETER_HH
#define SPEEDOMETER_HH
/**
 * @file speedometer.hh
 * @brief Definicja klasy Speedometer
 *
 * Pilik zawiera definicje klasy Speedometer ktora jest klasa bazowa
 */
#include <QWidget>
#include <QTimer>
#include <QSlider>
#include <QLabel>

/**
 * @brief Modeluje pojecie predkosciomierza
 */
class Speedometer : public QWidget {
    Q_OBJECT
public:
    /**
     * @brief Konstruktor klasy Speedometer
     * @param parent wskaznik na obiekt nadrzedny
     */
    explicit Speedometer(QWidget *parent = nullptr);
    /**
     * @brief setSpeed ustawia predkosc
     * @param speed predkosc do ustawienia
     */
    void setSpeed(int speed);

private slots:
    /**
     * @brief updateNeedle odświeża pozycję wskazówki zegara
     */
    void updateNeedle();
    /**
     * @brief obsluguje zmiane wartosci suwaka
     * @param value wartosc suwaka
     */
    void sliderValueChanged(int value);

protected:
    /**
     * @brief paintEvent pozwala na tworzenie  obiektu jakim jest zegar prędkościomierza
     */
    void paintEvent(QPaintEvent *) override;

private:
    QTimer *m_timer; ///< Timer do odświezania danych.
    QSlider *m_speedSlider; ///< Suwak do ustawiania predkosci.
    int m_speed; ///< Aktualna predkosc.
    double m_angle; ///< Kat wskazowki.
};

#endif // SPEEDOMETER_HH
