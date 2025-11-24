#ifndef LETTURA_H
#define LETTURA_H

/**
 * @class Lettura
 * @brief Rappresenta una singola lettura inerziale con 6 valori.
 *
 * La classe memorizza le letture di velocità angolare e accelerazione
 * lungo i tre assi principali: yaw, pitch e roll.
 * Ogni misura è composta da una coppia di valori: velocità e accelerazione.
 */
class Lettura
{

public:
    /**
     * @brief Costruttore della classe Lettura.
     *
     * Tutti i valori hanno default 0 se non specificati.
     *
     * @param yv Velocità angolare yaw
     * @param ya Accelerazione yaw
     * @param pv Velocità angolare pitch
     * @param pa Accelerazione pitch
     * @param rv Velocità angolare roll
     * @param ra Accelerazione roll
     */
    Lettura(double yv = 0, double ya = 0, double pv = 0, double pa = 0, double rv = 0, double ra = 0)
        : yaw_v(yv), yaw_a(ya), pitch_v(pv), pitch_a(pa), roll_v(rv), roll_a(ra) {}

    /**
     * Getter
     */
    double getYawV() const { return yaw_v; }
    double getYawA() const { return yaw_a; }
    double getPitchV() const { return pitch_v; }
    double getPitchA() const { return pitch_a; }
    double getRollV() const { return roll_v; }
    double getRollA() const { return roll_a; }

    /**
     * Setter
     */
    void setYawV(double v) { yaw_v = v; }
    void setYawA(double v) { yaw_a = v; }
    void setPitchV(double v) { pitch_v = v; }
    void setPitchA(double v) { pitch_a = v; }
    void setRollV(double v) { roll_v = v; }
    void setRollA(double v) { roll_a = v; }

private:
    double yaw_v;   // velocità angolare attorno all'asse yaw
    double yaw_a;   // accelerazione attorno all'asse yaw
    double pitch_v; // velocità angolare attorno all'asse pitch
    double pitch_a; // accelerazione attorno all'asse pitch
    double roll_v;  // velocità angolare attorno all'asse roll
    double roll_a;  // accelerazione attorno all'asse roll
};
#endif
