//
//  BSLib.c
//  Option
//
//  Created by junyan on 10/21/16.
//  Copyright © 2016 junyan. All rights reserved.
//

#include "BSLib.hpp"



double BSCall (double S, double K, double T, double Sigma, double d, double r){
    if(T == 0){
      return ((S-K)>0? (S-K) : 0);
    }
    if(Sigma <= 0){
      return ((S*exp((r-d)*T)-K)>0?S*exp(-d)*T-K*exp(-r*T): 0);
    }
    double d1 = (log(S/K) + T*(r - d) + 0.5*Sigma*Sigma*T)/(sqrt(T)*Sigma);
    double d2 = (log(S/K) + T*(r - d) - 0.5*Sigma*Sigma*T)/(sqrt(T)*Sigma);
    return S*exp(-d*T)*gsl_cdf_ugaussian_P(d1) - K*exp(-r*T)*gsl_cdf_ugaussian_P(d2);
}

double BSPut (double S, double K, double T, double Sigma, double d, double r){
    if(T == 0){
      return ((K-S)>0? (K-S) : 0);
    }
    if(Sigma <= 0){
      return ((S*exp((r-d)*T)-K)<0?-S*exp(-d)*T+K*exp(-r*T): 0);
    }
    double d1 = (log(S/K) + T*(r - d) + 0.5*Sigma*Sigma*T)/(sqrt(T)*Sigma);
    double d2 = (log(S/K) + T*(r - d) - 0.5*Sigma*Sigma*T)/(sqrt(T)*Sigma);
    return -S*exp(-d*T)*gsl_cdf_ugaussian_P(-d1) + K*exp(-r*T)*gsl_cdf_ugaussian_P(-d2);
}

double BSCallDelta(double S, double K, double T, double Sigma, double d, double r){
    double d1 = (log(S/K) + T*(r - d) + 0.5*Sigma*Sigma*T)/(sqrt(T)*Sigma);
    return exp(-d*T)*gsl_cdf_ugaussian_P(d1);
}

double BSPutDelta(double S, double K, double T, double Sigma, double d, double r){
    double d1 = (log(S/K) + T*(r - d) + 0.5*Sigma*Sigma*T)/(sqrt(T)*Sigma);
    return exp(-d*T)*(gsl_cdf_ugaussian_P(d1)-1);
}

double BSVega(double S, double K, double T, double Sigma, double d, double r){
    double d1 = (log(S/K) + T*(r - d) + 0.5*Sigma*Sigma*T)/(sqrt(T)*Sigma);
    double d2 = (log(S/K) + T*(r - d) - 0.5*Sigma*Sigma*T)/(sqrt(T)*Sigma);
    double d1d = -(log(S/K) + T*(r - d) + 0.5*Sigma*Sigma*T)/(sqrt(T)*Sigma*Sigma) + 0.5/sqrt(T);
    double d2d = -(log(S/K) + T*(r - d) + 0.5*Sigma*Sigma*T)/(sqrt(T)*Sigma*Sigma) - 0.5/sqrt(T);
    return S*exp(-d*T)*gsl_ran_gaussian_pdf(d1, 1)*d1d - K*exp(-r*T)*gsl_ran_gaussian_pdf(d2, 1)*d2d;
}

double BSCallIV(double C, double S, double K, double T, double d, double r){
    double vol_left = 0;
    double vol_right = 20;
    int count = 0;
    double est = BSCall(S,K, T, (vol_left+vol_right)/2, d, r);
    while (fabs(est - C) > 0.000000000001) {
        if(est > C){
            vol_right = (vol_left + vol_right)/2;
        }
        else{
            vol_left = (vol_left + vol_right)/2;
        }
        est = BSCall(S, K, T, (vol_left + vol_right)/2, d, r);
        count++;
        if(count > 2000){
            return -1;
        }
    }
    return (vol_left + vol_right)/2;
}

double BSPutIV(double P , double S, double K, double T, double d, double r){
    double vol_left = 0;
    double vol_right = 20;
    int count = 0;
    double est = BSPut(S,K, T, (vol_left+vol_right)/2, d, r);
    while (fabs(est - P) > 0.000000000001) {
        if(est > P){
            vol_right = (vol_left + vol_right)/2;
        }
        else{
            vol_left = (vol_left + vol_right)/2;
        }
        est = BSPut(S, K, T, (vol_left + vol_right)/2, d, r);
        count++;
        if(count > 2000){
            return -1;
        }
    }
    return (vol_left + vol_right)/2;
}

void print_complex(gsl_complex s){
    printf("%f + %fi\n", s.dat[0], s.dat[1]);
}


gsl_complex operator+(const gsl_complex &a, const gsl_complex &b){
    return gsl_complex_add(a, b);
}

gsl_complex operator+(gsl_complex a, double b){
    return gsl_complex_add_real(a, b);
}

gsl_complex operator+(double a, gsl_complex b){
    return gsl_complex_add_real(b, a);
}

gsl_complex operator*(const gsl_complex &a, const gsl_complex &b){
    return gsl_complex_mul(a, b);
}

gsl_complex operator*(gsl_complex a, double b){
    return gsl_complex_mul_real(a, b);
}

gsl_complex operator*(double a, gsl_complex b){
    return gsl_complex_mul_real(b, a);
}

gsl_complex operator/(const gsl_complex &a, const gsl_complex &b){
    return gsl_complex_div(a, b);
}

gsl_complex operator/(gsl_complex a, double b){
    return gsl_complex_div_real(a, b);
}

gsl_complex operator/(double a, gsl_complex b){
    return gsl_complex_pow_real(gsl_complex_div_real(b, a), -1);
}

gsl_complex operator-(const gsl_complex &a, const gsl_complex &b){
    return gsl_complex_sub(a, b);
}

gsl_complex operator-(gsl_complex a, double b){
    return gsl_complex_sub_real(a, b);
}

gsl_complex operator-(double a, gsl_complex b){
    return gsl_complex_mul_real(gsl_complex_sub_real(b, a), -1);
}

gsl_complex operator^(gsl_complex a, double b){
    return gsl_complex_pow_real(a, b);
}

gsl_complex operator^(const gsl_complex &a,const gsl_complex& b){
    return gsl_complex_pow(a, b);
}

gsl_complex log(const gsl_complex &a){
    return gsl_complex_log(a);
}

gsl_complex exp(const gsl_complex &a){
    return gsl_complex_exp(a);
}

gsl_complex I(const double& a){
    return gsl_complex_rect(0, a);
}

/*
 
 Heston Model Characteristic Function
 
*/

gsl_complex HestonCF(gsl_complex z, double x, double Volsquare, double T, double r,
                     double Chi, double Theta, double Ita, double Rho){
    gsl_complex zsqurez = (z^2) + z*I(1);
    gsl_complex ChiStar = Chi - z * I(Rho*Ita);
    gsl_complex Gamma = ((ChiStar^2) + zsqurez * Ita*Ita)^0.5;
    gsl_complex em = exp(Gamma * -T);
    gsl_complex A = I(r*T)*z + (T*(ChiStar-Gamma)-2*log((ChiStar-Gamma)/2/Gamma*(1 - em) + 1))*Chi*Theta/Ita/Ita;
    gsl_complex B = -1*zsqurez*(1-em)/(2*Gamma*em + (Gamma + ChiStar)*(1-em));
    return exp(A+z*I(x) + B*Volsquare);
}

gsl_complex TwoRegime2DHestonCF(gsl_complex y, gsl_complex z, double x, double Volsquare, double T, double r,
                              double Chi, double Theta, double Ita, double Rho){
    gsl_complex zsqurez = (z^2) + z*I(1);
    gsl_complex ChiStar = Chi - z * I(Rho*Ita);
    gsl_complex Gamma = ((ChiStar^2) + zsqurez * Ita*Ita)^0.5;
    gsl_complex em = exp(Gamma * -T);
    gsl_complex A = I(r*T)*z + (T*(ChiStar-Gamma)-2*log((ChiStar-Gamma - I(1)*y*Ita*Ita)/2/Gamma*(1 - em) + 1))*Chi*Theta/Ita/Ita;
    gsl_complex B = I(1)*y-(zsqurez+2*y*I(1)*ChiStar+y*y*Ita*Ita)*(1-em)/(2*Gamma*em + (Gamma + ChiStar-I(1)*y*Ita*Ita)*(1-em));
    return exp(A+z*I(x) + B*Volsquare);
}


gsl_complex TwoRegime1DHestonCF(gsl_complex z, double x, double Volsquare, double T1, double T2, double r,
                                double Chi1, double Theta1, double Ita1, double Rho1,
                                double Chi2, double Theta2, double Ita2, double Rho2){
    gsl_complex zsqurez2 = (z^2) + z*I(1);
    gsl_complex ChiStar2 = Chi2 - z * I(Rho2*Ita2);
    gsl_complex Gamma2 = ((ChiStar2^2) + zsqurez2 * Ita2*Ita2)^0.5;
    gsl_complex em2 = exp(Gamma2 * -T2);
    gsl_complex A = I(r*T2)*z + (T2*(ChiStar2-Gamma2)-2*log((ChiStar2-Gamma2)/2/Gamma2*(1 - em2) + 1))*Chi2*Theta2/Ita2/Ita2;
    gsl_complex B = -1*zsqurez2*(1-em2)/(2*Gamma2*em2 + (Gamma2 + ChiStar2)*(1-em2));
    return exp(A)*TwoRegime2DHestonCF(I(-1)*B, z, x, Volsquare,T1, r, Chi1, Theta1, Ita1, Rho1);
}


gsl_complex MixedGaussianCF(gsl_complex z, double Up, double UpSigma, double Down, double DownSigma){
    double P;
    if(exp(Up+0.5*UpSigma*UpSigma) - exp(Down+0.5*DownSigma*DownSigma) == 0)
        P=0.5;
    else
        P = (1 - exp(Down+0.5*DownSigma*DownSigma))/(exp(Up+0.5*UpSigma*UpSigma) - exp(Down+0.5*DownSigma*DownSigma));
    return exp(z*I(Up)-(z^2)*0.5*UpSigma*UpSigma)*P + exp(z*I(Down)-(z^2)*0.5*DownSigma*DownSigma)*(1-P);
}


double HestonCall(double S, double VolSquare, double K, double T, double r,
                  double Chi, double Theta, double Ita, double Rho, double StepSize)
{
    if(K==0){
        return S;
    }
    if(T==0){
        return S-K>0?S-K:0;
    }
    double x = log(S);
    double logK = log(K);
    const double step = StepSize;
    const double alpha = 1.5;
    const double range = 2000;
    double integral = 0;
    gsl_complex z;
    for (double i=-range; i< range; i=i+step) {
        z = i-I(alpha);
        integral = integral + GSL_REAL(HestonCF(z - I(1), x, VolSquare, T, r, Chi, Theta, Ita, Rho)*exp(z * I(-logK))/z/(I(1) - z))*step;
    }
    return integral/(2*M_PI)*exp(-r*T);
}

/*
double x, double Volsquare, double T1, double T2, double r,
double Chi1, double Theta1, double Ita1, double Rho1,
double Chi2, double Theta2, double Ita2, double Rho2*/

double TwoRegimeHestonCall(double S, double VolSquare, double K, double T1, double T2, double r,
                           double Chi1, double Theta1, double Ita1, double Rho1,
                           double Chi2, double Theta2, double Ita2, double Rho2, double StepSize)
{
    if(K==0){
        return S;
    }
    if(T1==0 && T2==0){
        return S-K>0?S-K:0;
    }
    double x = log(S);
    double logK = log(K);
    const double step = StepSize;
    const double alpha = 1.5;
    const double range = 2000;
    double integral = 0;
    gsl_complex z;
    for (double i=-range; i< range; i=i+step) {
        z = i-I(alpha);
        integral = integral + GSL_REAL(TwoRegime1DHestonCF(z - I(1), x, VolSquare, T1, T2, r, Chi1, Theta1, Ita1, Rho1,Chi2, Theta2, Ita2, Rho2)*exp(z * I(-logK))/z/(I(1) - z))*step;
    }
    return integral/(2*M_PI)*exp(-r*(T1+T2));
}


double HestonMixedGaussianCall(double S, double VolSquare, double K, double T, double r,
                               double Chi, double Theta, double Ita, double Rho, double Up,
                               double UpSigma, double Down, double DownSigma, double StepSize){
    if(K==0){
        return S;
    }
    if(T==0){
        return S-K>0?S-K:0;
    }
    double x = log(S);
    double logK = log(K);
    const double step = StepSize;
    const double alpha = 1.5;
    const double range = 2000;
    double integral = 0;
    gsl_complex z;
    for (double i=-range; i< range; i=i+step) {
        z = gsl_complex_rect(i, -alpha);
        integral = integral + GSL_REAL(HestonCF(z - I(1), x, VolSquare, T, r, Chi, Theta, Ita, Rho)*MixedGaussianCF(z-I(1), Up, UpSigma, Down, DownSigma) * exp(z*I(-logK))/z/(I(1)-z))*step;
    }
    return integral/(2*M_PI)*exp(-r*T);
}

double TwoRegimeHestonMixedGaussianCall(double S, double VolSquare, double K, double T1, double T2, double r,
                                        double Chi1, double Theta1, double Ita1, double Rho1,
                                        double Chi2, double Theta2, double Ita2, double Rho2,
                                        double Up, double UpSigma, double Down, double DownSigma,
                                        double StepSize)
{
    if(K==0){
        return S;
    }
    if(T1==0 && T2==0){
        return S-K>0?S-K:0;
    }
    double x = log(S);
    double logK = log(K);
    const double step = StepSize;
    const double alpha = 1.5;
    const double range = 2000;
    double integral = 0;
    gsl_complex z;
    for (double i=-range; i< range; i=i+step) {
        z = i-I(alpha);
        integral = integral + GSL_REAL(TwoRegime1DHestonCF(z - I(1), x, VolSquare, T1, T2, r, Chi1, Theta1, Ita1, Rho1,Chi2, Theta2, Ita2, Rho2)*MixedGaussianCF(z-I(1), Up, UpSigma, Down, DownSigma)*exp(z * I(-logK))/z/(I(1) - z))*step;
    }
    return integral/(2*M_PI)*exp(-r*(T1+T2));
}


