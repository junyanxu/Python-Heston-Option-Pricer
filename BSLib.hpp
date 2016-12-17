//
//  BSLib.h
//  Option
//
//  Created by junyan on 10/21/16.
//  Copyright © 2016 junyan. All rights reserved.
//

#ifndef BSLib_h
#define BSLib_h

#include <stdio.h>
#include <math.h>
#include <gsl/gsl_cdf.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>


double BSCall(double S, double K, double T, double Sigma, double d, double r);
double BSPut(double S, double K, double T, double Sigma, double d, double r);
double BSVega(double S, double K, double T, double Sigma, double d, double r);
double BSCallDelta(double S, double K, double T, double Sigma, double d, double r);
double BSPutDelta(double S, double K, double T, double Sigma, double d, double r);
double BSGamma(double S, double K, double T, double Sigma, double d, double r);
double BSTheta(double S, double K, double T, double Sigma, double d, double r);


/*
 Main stochastics model pricer
 */

double HestonCall(double S, double VolSquare, double K, double T, double r,
                  double Chi, double Theta, double Ita, double Rho,
                  double StepSize);
double HestonMixedGaussianCall(double S, double VolSquare, double K, double T,
                               double r, double Chi, double Theta, double Ita,
                               double Rho, double Up, double UpSigma,
                               double Down, double DownSigma, double StepSize);
double TwoRegimeHestonCall(double S, double VolSquare, double K, double T1,
                           double T2, double r, double Chi1, double Theta1,
                           double Ita1, double Rho1, double Chi2, double Theta2,
                           double Ita2, double Rho2, double StepSize);

double TwoRegimeHestonMixedGaussianCall(double S, double VolSquare, double K, double T1, double T2, double r,
                                        double Chi1, double Theta1, double Ita1, double Rho1,
                                        double Chi2, double Theta2, double Ita2, double Rho2,
                                        double Up, double UpSigma, double Down, double DownSigma,
                                        double StepSize);
/*
 
 Compute implied volatility
 
 */

double BSCallIV(double C, double S, double K, double T, double d, double r);
double BSPutIV(double P , double S, double K, double T, double d, double r);

#endif /* BSLib_h */
