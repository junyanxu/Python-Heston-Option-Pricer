//
//  BSDoc.hpp
//  Option
//
//  Created by junyan on 12/17/16.
//  Copyright © 2016 junyan. All rights reserved.
//

#ifndef BSDoc_hpp
#define BSDoc_hpp

#include <stdio.h>
#include <string>


namespace doc {
    
    const char HestonCall[] = "Calculate heston model call option price. The parameters follow the following sequence:\n S: Current underlying price\n V0: Current instantaneous volatility square\n K: Strike price\n T: Time to expiry\n r: Interest rate\n Kappa: Mean reversion maganitude\n Theta: Long term mean in Heston model\n Eta: Vol of vol\n Rho: Correlation of underlying stochastic term with vol\n Stepsize: Numerical solution stepsize. Recommend 0.4";
    
    const char HestonPut[] = "Calculate heston model put option price. The parameters follow the following sequence:\n S: Current underlying price\n V0: Current instantaneous volatility square\n K: Strike price\n T: Time to expiry\n r: Interest rate\n Kappa: Mean reversion maganitude\n Theta: Long term mean in Heston model\n Eta: Vol of vol\n Rho: Correlation of underlying stochastic term with vol\n Stepsize: Numerical solution stepsize. Recommend 0.4";
    
    const char HestonMixedGaussianCall[] = "Calculate heston model mixed gaussian call option price. The parameters follow the following sequence:\n S: Current underlying price\n V0: Current instantaneous volatility square\n K: Strike price\n T: Time to expiry\n r: Interest rate\n Kappa: Mean reversion maganitude\n Theta: Long term mean in Heston model\n Eta: Vol of vol\n Rho: Correlation of underlying stochastic term with vol\n\n The Mixed Gaussian part has four parameters:\n Up: average maganitude of up log jump\n UpSigma: dispersion maganitude of up log jump\n Down: average maganitude of down log jump\n DownSigma: dispersion maganitude of down log jump\nStepsize: Numerical solution stepsize. Recommend 0.4";
    
    const char HestonMixedGaussianPut[] = "Calculate heston model mixed gaussian put option price. The parameters follow the following sequence:\n S: Current underlying price\n V0: Current instantaneous volatility square\n K: Strike price\n T: Time to expiry\n r: Interest rate\n Kappa: Mean reversion maganitude\n Theta: Long term mean in Heston model\n Eta: Vol of vol\n Rho: Correlation of underlying stochastic term with vol\n\n The Mixed Gaussian part has four parameters:\n Up: average maganitude of up log jump\n UpSigma: dispersion maganitude of up log jump\n Down: average maganitude of down log jump\n DownSigma: dispersion maganitude of down log jump\nStepsize: Numerical solution stepsize. Recommend 0.4";
    
}


#endif /* BSDoc_hpp */




