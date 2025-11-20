//tutta la classe lettura è nell'header perchè è molto piccola e i metodi sono tutti standard (banali)
#ifndef LETTURA_H
#define LETTURA_H

class Lettura {
private:
    double yaw_v;
    double yaw_a;
    double pitch_v;
    double pitch_a;
    double roll_v;
    double roll_a;

public:
    //costruttore con parametri
    Lettura(double yv = 0, double ya = 0, double pv = 0, double pa = 0, double rv = 0, double ra = 0)
        : yaw_v(yv), yaw_a(ya), pitch_v(pv), pitch_a(pa), roll_v(rv), roll_a(ra) {}

    double getYawV()   const { return yaw_v; }
    double getYawA()   const { return yaw_a; }
    double getPitchV() const { return pitch_v; }
    double getPitchA() const { return pitch_a; }
    double getRollV()  const { return roll_v; }
    double getRollA()  const { return roll_a; }

    void setYawV(double v)   { yaw_v = v; }
    void setYawA(double v)   { yaw_a = v; }
    void setPitchV(double v) { pitch_v = v; }
    void setPitchA(double v) { pitch_a = v; }
    void setRollV(double v)  { roll_v = v; }
    void setRollA(double v)  { roll_a = v; }
};
#endif
