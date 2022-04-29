// Copyright 2022 Cheremushkin Kirill

#ifndef MODULES_POLYNOM_AND_MONOM_CHEREMUSHKINKI_INCLUDE_POLYNOM_H_
#define MODULES_POLYNOM_AND_MONOM_CHEREMUSHKINKI_INCLUDE_POLYNOM_H_

#include <iostream>

#include "Monom.h"

class Polynom : public Monom {
 private:
    Monom* StartMonom;
    int SIZE = 1;
 public :
    Polynom();
    explicit Polynom(int size);
    Polynom(const Polynom& polynom);

    void ClearList();
    void SetSize(int size);
    void Equalizer();
    Polynom& operator+(const Monom& monom);
    Polynom& operator-(const Monom& monom);
    Polynom& operator*(const Monom& monom);
    Polynom& operator/(const Monom& monom);

    Polynom& operator=(const Polynom& polynom);
    Polynom operator+(const Polynom& polynom);
    Polynom operator-(const Polynom& polynom);
    Polynom operator*(const Polynom& polynom);
    Polynom operator/(const Polynom& polynom);

    friend std::ostream& operator<<
        (std::ostream& stream, const Polynom& pol);
    friend std::string GetSign(double coef);
    friend Monom CurrentMonom(Monom* p, int id);

    ~Polynom();
    Monom* GetStartMonom();
};
#endif  // MODULES_POLYNOM_AND_MONOM_CHEREMUSHKINKI_INCLUDE_POLYNOM_H_
