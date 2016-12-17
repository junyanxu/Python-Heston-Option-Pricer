//
//  BSDoc.hpp
//  Option
//
//  Created by junyan on 12/17/16.
//  Copyright © 2016 junyan. All rights reserved.
//

/*
 
 This file is used for providing helper documentation to functions in the module
 
 */

#ifndef BSDoc_hpp
#define BSDoc_hpp

#include <stdio.h>
#include <string>


namespace doc {
    
    const char HestonCall[] = "Calculate heston model call option price. The parameters follow the following sequence:\n\n S: Current underlying price\n V0: Current instantaneous volatility square\n K: Strike price\n T: Time to expiry\n r: Interest rate\n Kappa: Mean reversion maganitude\n Theta: Long term mean in Heston model\n Eta: Vol of vol\n Rho: Correlation of underlying stochastic term with vol\n Stepsize: Numerical solution stepsize. Recommend 0.4";
    
    const char HestonPut[] = "Calculate heston model put option price. The parameters follow the following sequence:\n\n S: Current underlying price\n V0: Current instantaneous volatility square\n K: Strike price\n T: Time to expiry\n r: Interest rate\n Kappa: Mean reversion maganitude\n Theta: Long term mean in Heston model\n Eta: Vol of vol\n Rho: Correlation of underlying stochastic term with vol\n Stepsize: Numerical solution stepsize. Recommend 0.4";
    
    const char HestonMixedGaussianCall[] = "Calculate heston model mixed gaussian call option price. The parameters follow the following sequence:\n\n S: Current underlying price\n V0: Current instantaneous volatility square\n K: Strike price\n T: Time to expiry\n r: Interest rate\n Kappa: Mean reversion maganitude\n Theta: Long term mean in Heston model\n Eta: Vol of vol\n Rho: Correlation of underlying stochastic term with vol\n\n The Mixed Gaussian part has four parameters:\n Up: average maganitude of up log jump\n UpSigma: dispersion maganitude of up log jump\n Down: average maganitude of down log jump\n DownSigma: dispersion maganitude of down log jump\nStepsize: Numerical solution stepsize. Recommend 0.4";
    
    const char HestonMixedGaussianPut[] = "Calculate heston model mixed gaussian put option price. The parameters follow the following sequence:\n\n S: Current underlying price\n V0: Current instantaneous volatility square\n K: Strike price\n T: Time to expiry\n r: Interest rate\n Kappa: Mean reversion maganitude\n Theta: Long term mean in Heston model\n Eta: Vol of vol\n Rho: Correlation of underlying stochastic term with vol\n\n The Mixed Gaussian part has four parameters:\n Up: average maganitude of up log jump\n UpSigma: dispersion maganitude of up log jump\n Down: average maganitude of down log jump\n DownSigma: dispersion maganitude of down log jump\nStepsize: Numerical solution stepsize. Recommend 0.4";
    
    const char TwoRegimeHestonCall[] = "Calculate two regime heston model call option price. The two regime stand for the different situation before and after the discrete event. The parameter of the heston model are assumed to be different. The parameters follow the following sequence:\n\n S: Current underlying price\n V0: Current instantaneous volatility square\n K: Strike price\n T1: Time to discrete event\n T2: Time from discrete event to expiry\n r: Interest rate\n Kappa1: Mean reversion maganitude before event\n Theta1: Long term mean in Heston model before event\n Eta1: Vol of vol before event\n Rho1: Correlation of underlying stochastic term with vol before event\n\n Kappa2: Mean reversion maganitude after event\n Theta2: Long term mean in Heston model after event\n Eta2: Vol of vol after event\n Rho2: Correlation of underlying stochastic term with vol after event\nStepsize: Numerical solution stepsize. Recommend 0.4";
    
    const char TwoRegimeHestonPut[] = "Calculate two regime heston model call option price. The two regime stand for the different situation before and after the discrete event. The parameter of the heston model are assumed to be different. The parameters follow the following sequence:\n\n S: Current underlying price\n V0: Current instantaneous volatility square\n K: Strike price\n T1: Time to discrete event\n T2: Time from discrete event to expiry\n r: Interest rate\n Kappa1: Mean reversion maganitude before event\n Theta1: Long term mean in Heston model before event\n Eta1: Vol of vol before event\n Rho1: Correlation of underlying stochastic term with vol before event\n\n Kappa2: Mean reversion maganitude after event\n Theta2: Long term mean in Heston model after event\n Eta2: Vol of vol after event\n Rho2: Correlation of underlying stochastic term with vol after event\nStepsize: Numerical solution stepsize. Recommend 0.4";
    
}


#endif /* BSDoc_hpp */




