#include "gas_radius_helpers.h"

#include <map>

#include "const.h"
#include "enviro.h"
#include "radius_tables.h"
#include "stargen.h"
#include "utils.h"

using namespace std;

// the following equations are derived from Tables 2, 3, and 4 from "Planetary
// Radii Across Five Orders of Magnitude in Mass And Stellar Insolation:
// Application to Transits" by J. J. Fortney, M. S. Marley, and J. W. Barnes
// (2007)

long double gas_radius_300Myr_1960K_0core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-0.0023409248, 0.1486173223, 0,
    // total_earth_masses);
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(3.5282715E-4, -0.0507203204, 3.469552483,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(4.1652964E-5, -0.0124458952, 2.367373509,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(2.1521998E-5, -0.0082989163, 2.167412625,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(2.888012E-6, -0.001888825, 1.650599014,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(9.910636E-7, -8.777515E-4, 1.52090465,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(9.0897815E-8, -1.738218E-4, 1.3880083387,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(8.1016701E-8, -1.61589E-4, 1.384534724,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-8.34155E-10, 7.514871E-6, 1.302683212,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.136757E-8, 4.3813022E-5, 1.273369053,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 1960k Gas Giants with 0 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_1960K_10core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[10] =
      radius_improved(10.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 10.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[10];
  } else if (total_earth_masses < 17.0) {
    /*double x[] = {10, 17, 28};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 1.102, 1.388}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-7.490421E-4, 0.0597068966, 0.3034559387,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-1.156097E-4, 0.0128328944, 1.119316948,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-2.017998E-7, -0.0013622754, 1.528091677,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(8.1505535E-6, -0.0030828602, 1.611055602,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(7.5739385E-7, -5.5396133E-4, 1.406006318,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(4.0833636E-7, -3.535656E-4, 1.382141258,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-2.713368E-9, -3.212472E-5, 1.321490048,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(6.3838633E-8, -1.145161E-4, 1.345391268,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-7.546348E-9, 3.2965273E-5, 1.274005715,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.20738E-8, 4.8566876E-5, 1.261405958,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.744773054, -0.0566473508, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 1960k Gas Giants with 10 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_1960K_25core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[25] =
      radius_improved(25.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 25.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[25];
  } else if (total_earth_masses < 28.0) {
    /*double x[] = {25, 28, 46};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.493, 0.945}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-3.88706E-4, 0.0538753566, -0.7107644649,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-5.29089E-5, 0.0125723116, 0.4786289127,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-9.343159E-6, 0.0035977678, 0.9113674749,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.311104E-6, 8.347406E-4, 1.134136539,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-3.258145E-7, 3.0958146E-4, 1.201500762,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.130893E-7, 1.4323034E-4, 1.232888792,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(3.8071532E-8, -4.390675E-5, 1.287176083,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-1.677399E-8, 6.9404099E-5, 1.232330123,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.318459E-8, 5.7035028E-5, 1.242319307,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.708788706, -0.052740637, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 1960k Gas Giants with 25 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_1960K_50core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[50] =
      radius_improved(50.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 50.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[50];
  } else if (total_earth_masses < 77.0) {
    /*double x[] = {50, 77, 129};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.801, 1.030}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-2.230627E-5, 0.008998937, 0.2403357023,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-4.496578E-6, 0.0028724042, 0.7342874095,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.002814E-6, 0.0010102282, 0.9731560336,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-3.612655E-7, 5.0853703E-4, 1.067817838,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.744883E-9, 6.3450487E-5, 1.19693464,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.9916E-8, 1.2165201E-4, 1.168763301,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.469994E-8, 6.9217479E-5, 1.211109098,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.621827834, -0.0429738523, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 1960k Gas Giants with 50 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_1960K_100core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[100] =
      radius_improved(100.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 100.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[100];
  } else if (total_earth_masses < 129.0) {
    /*double x[] = {100, 129, 215};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.669, 0.939}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.065249E-5, 0.0068039927, -0.0314469102,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-2.514914E-6, 0.0024666628, 0.5249194058,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-6.791171E-7, 0.0010310696, 0.7957949066,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.016244E-7, 3.1613354E-4, 1.003193355,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-5.340218E-8, 2.1650651E-4, 1.051415926,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.833398E-8, 9.5661492E-5, 1.149009604,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.47989044, -0.0273469969, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 1960k Gas Giants with 100 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_1960K(long double core_earth_masses,
                                    long double total_earth_masses,
                                    planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> core_mass_radii;
  core_mass_radii[0] = gas_radius_300Myr_1960K_0core_mass(
      total_earth_masses, the_planet, gas_300Myr_1960K_0core_mass);
  core_mass_radii[10] = gas_radius_300Myr_1960K_10core_mass(
      total_earth_masses, the_planet, gas_300Myr_1960K_10core_mass);
  core_mass_radii[25] = gas_radius_300Myr_1960K_25core_mass(
      total_earth_masses, the_planet, gas_300Myr_1960K_25core_mass);
  core_mass_radii[50] = gas_radius_300Myr_1960K_50core_mass(
      total_earth_masses, the_planet, gas_300Myr_1960K_50core_mass);
  core_mass_radii[100] = gas_radius_300Myr_1960K_100core_mass(
      total_earth_masses, the_planet, gas_300Myr_1960K_100core_mass);
  if (core_earth_masses <= 10.0) {
    /*jupiter_radii1 = gas_radius_300Myr_1960K_0core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_1960K_10core_mass(total_earth_masses, the_planet);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
    jupiter_radii2, 0.0, 10.0);*/
    jupiter_radii = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
  } else if (core_earth_masses <= 25.0) {
    /*jupiter_radii1 = gas_radius_300Myr_1960K_10core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_1960K_25core_mass(total_earth_masses, the_planet);*/
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 10.0, 25.0);
  } else if (core_earth_masses <= 50.0) {
    /*jupiter_radii1 = gas_radius_300Myr_1960K_25core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_1960K_50core_mass(total_earth_masses, the_planet);*/
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 25.0, 50.0);
  } else if (core_earth_masses <= 100.0) {
    /*jupiter_radii1 = gas_radius_300Myr_1960K_50core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_1960K_100core_mass(total_earth_masses, the_planet);*/
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii2 =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 50.0, 100.0);
  } else {
    /*upper_fraction = core_earth_masses / 100.0;
    jupiter_radii = gas_radius_300Myr_1960K_100core_mass(total_earth_masses,
    the_planet) * pow1_4(upper_fraction);*/
    /*jupiter_radii1 = gas_radius_300Myr_1960K_50core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_1960K_100core_mass(total_earth_masses, the_planet);
    jupiter_radii = planet_radius_helper2(core_earth_masses, 50.0,
    jupiter_radii1, 100.0, jupiter_radii2);*/
    jupiter_radii =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 1960k Gas Giants", the_planet,
                jupiter_radii, core_mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_1300K_0core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  if (total_earth_masses < 17.0) {
    // jupiter_radii = quad_trend(-0.0100049656, 0.3344961803, 0.0,
    // total_earth_masses);
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(0.0036515152, -0.2800454545, 6.500484848,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(1.4143077E-4, -0.02029921, 1.97949616,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(3.1503184E-5, -0.0067781174, 1.590132665,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(1.0791787E-6, -5.107723E-4, 1.28793102,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-8.362393E-8, -1.107693E-4, 1.25568069,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(4.5881091E-7, -3.99886E-4, 1.29276696,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(4.0603608E-8, -7.284791E-5, 1.231059637,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(5.2918075E-8, -8.809322E-5, 1.235482205,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.127259E-8, 6.5184687E-5, 1.161290949,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-6.427462E-9, 1.4028384E-5, 1.202604459,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594.0]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594.0]);
    jupiter_radii2 =
        planet_radius_helper2(total_earth_masses, 2154.0, mass_radii[2154],
                              3594.0, mass_radii[3594.0]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.697741752, -0.0644607785, total_earth_masses);
    jupiter_radii =
        planet_radius_helper2(total_earth_masses, 2154.0, mass_radii[2154],
                              3594.0, mass_radii[3594.0]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 1300k Gas Giants with 0 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_1300K_10core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[10] =
      radius_improved(10.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 10.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[10];
  } else if (total_earth_masses < 17.0) {
    /*double x[] = {10, 17, 28};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.801, 1.012}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-5.10101E-4, 0.0421363636, 0.2321010101,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-6.784434E-5, 0.0094093702, 0.8017275986,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-2.630871E-6, 0.0013881132, 1.032713713,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-4.699126E-6, 0.0018141739, 1.012169732,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.045896E-6, 5.5746278E-4, 1.113492063,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(8.2521868E-8, -4.398416E-5, 1.19064202,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-4.506128E-8, 5.5785869E-5, 1.171816871,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(3.7304385E-8, -4.618283E-5, 1.201397348,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.658587E-8, 8.581443E-5, 1.137506586,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-6.832022E-9, 1.7742682E-5, 1.192480902,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.663757403, -0.0605540647, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 1300k Gas Giants with 10 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_1300K_25core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[25] =
      radius_improved(25.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 25.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[25];
  } else if (total_earth_masses < 28.0) {
    /*double x[] = {25, 28, 46};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.447, 0.793}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-2.770829E-4, 0.0397263551, -0.4481049667,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-4.41493E-5, 0.0110755254, 0.3769457532,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-9.88761E-6, 0.0040176169, 0.7172671405,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-2.079249E-6, 0.0013315408, 0.9338320234,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-5.11689E-7, 4.9603121E-4, 1.041006115,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.253963E-7, 1.9395035E-4, 1.098004368,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(4.5427114E-9, 3.3085801E-5, 1.144670161,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.245741E-8, 1.0952805E-4, 1.107669742,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-7.740531E-9, 2.4353686E-5, 1.176456029,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.627773054, -0.0566473508, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 1300k Gas Giants with 25 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_1300K_50core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[50] =
      radius_improved(50.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 50.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[50];
  } else if (total_earth_masses < 77.0) {
    /*double x[] = {50, 77, 129};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.719, 0.921}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.871224E-5, 0.0077393378, 0.2340158863,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-4.270793E-6, 0.0027714785, 0.6345495454,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.025782E-6, 0.0010418872, 0.8564110054,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-3.20565E-7, 4.9040786E-4, 0.9604671163,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-4.07039E-8, 1.4393981E-4, 1.060975313,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-4.000376E-8, 1.4249333E-4, 1.061675457,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-9.859221E-9, 3.8615247E-5, 1.145566744,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.572796532, -0.05078728, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 1300k Gas Giants with 50 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_1300K_100core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[100] =
      radius_improved(100.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 100.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[100];
  } else if (total_earth_masses < 129.0) {
    /*double x[] = {100, 129, 215};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.627, 0.863}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-9.12576E-6, 0.0058834474, 0.0198970566,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-2.22355E-6, 0.0022045698, 0.4198011015,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-5.615702E-7, 9.0490131E-4, 0.7370296067,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.43652E-7, 3.8751855E-4, 0.8871190846,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-5.313927E-8, 2.0051933E-4, 0.9976325013,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.268764E-8, 6.1123E-5, 1.090208105,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.417866963, -0.0332070677, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 1300k Gas Giants with 100 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_1300K(long double core_earth_masses,
                                    long double total_earth_masses,
                                    planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> core_mass_radii;
  core_mass_radii[0] = gas_radius_300Myr_1300K_0core_mass(
      total_earth_masses, the_planet, gas_300Myr_1300K_0core_mass);
  core_mass_radii[10] = gas_radius_300Myr_1300K_10core_mass(
      total_earth_masses, the_planet, gas_300Myr_1300K_10core_mass);
  core_mass_radii[25] = gas_radius_300Myr_1300K_25core_mass(
      total_earth_masses, the_planet, gas_300Myr_1300K_25core_mass);
  core_mass_radii[50] = gas_radius_300Myr_1300K_50core_mass(
      total_earth_masses, the_planet, gas_300Myr_1300K_50core_mass);
  core_mass_radii[100] = gas_radius_300Myr_1300K_100core_mass(
      total_earth_masses, the_planet, gas_300Myr_1300K_100core_mass);
  if (core_earth_masses <= 10.0) {
    /*jupiter_radii1 = gas_radius_300Myr_1300K_0core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_1300K_10core_mass(total_earth_masses, the_planet);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
    jupiter_radii2, 0.0, 10.0);*/
    jupiter_radii = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
  } else if (core_earth_masses <= 25.0) {
    /*jupiter_radii1 = gas_radius_300Myr_1300K_10core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_1300K_25core_mass(total_earth_masses, the_planet);*/
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 10.0, 25.0);
  } else if (core_earth_masses <= 50.0) {
    /*jupiter_radii1 = gas_radius_300Myr_1300K_25core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_1300K_50core_mass(total_earth_masses, the_planet);*/
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 25.0, 50.0);
  } else if (core_earth_masses <= 100.0) {
    /*jupiter_radii1 = gas_radius_300Myr_1300K_50core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_1300K_100core_mass(total_earth_masses, the_planet);*/
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii2 =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 50.0, 100.0);
  } else {
    // jupiter_radii = planet_radius_helper2(core_earth_masses, 50.0,
    // jupiter_radii1, 100.0, jupiter_radii2);
    jupiter_radii =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 1300k Gas Giants", the_planet,
                jupiter_radii, core_mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_875K_0core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  if (total_earth_masses < 17.0) {
    // jupiter_radii = quad_trend(-0.004000191, 0.1618267762, 0.0,
    // total_earth_masses);
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(3.8749565E-4, -0.0356191223, 2.088538837,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(9.3665423E-5, -0.0138756858, 1.710085509,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(2.9530031E-5, -0.0059870325, 1.48291795,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.033808E-6, 3.0911825E-4, 1.179327341,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-3.189655E-7, 6.3212521E-5, 1.199153491,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(2.9136362E-7, -2.620929E-4, 1.240881696,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(4.6805591E-8, -7.084855E-5, 1.20479667,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(4.1230371E-8, -6.394642E-5, 1.202794407,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.463518E-8, 7.2131794E-5, 1.136928334,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-4.713332E-9, 3.4811211E-6, 1.192370187,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.687733926, -0.0664141354, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 875k Gas Giants with 0 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_875K_10core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[10] =
      radius_improved(10.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 10.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[10];
  } else if (total_earth_masses < 17.0) {
    /*double x[] = {10, 17, 28};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.755, 0.956}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-4.78753E-4, 0.0398166144, 0.2164771856,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-5.73111E-5, 0.00862991, 0.7592944188,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-7.459117E-6, 0.0024981165, 0.9358701306,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-5.029686E-6, 0.0019976537, 0.9600016722,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.260929E-6, 7.0120156E-4, 1.064528125,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-6.943588E-9, 3.2827146E-5, 1.150263131,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-3.178516E-8, 5.2253258E-5, 1.146597707,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(1.9389255E-8, -1.110067E-5, 1.164976283,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.854954E-8, 8.7940877E-5, 1.117037105,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-5.117892E-9, 7.1954199E-6, 1.18224663,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.653749577, -0.0625074216, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 875k Gas Giants with 10 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_875K_25core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[25] =
      radius_improved(25.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 25.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[25];
  } else if (total_earth_masses < 28.0) {
    /*double x[] = {25, 28, 46};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.438, 0.767}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-2.604418E-4, 0.0375504718, -0.4092268305,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-4.2363E-5, 0.0107267781, 0.3632083171,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-9.689922E-6, 0.003996124, 0.68775,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-2.273973E-6, 0.0014450376, 0.8934313454,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-5.231726E-7, 5.1186072E-4, 1.013133601,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.191944E-7, 1.9594972E-4, 1.072741401,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-9.476517E-9, 6.0119025E-5, 1.112145029,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.358044E-8, 1.0991773E-4, 1.088040915,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-6.832022E-9, 1.7742682E-5, 1.162480902,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.633757403, -0.0605540647, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 875k Gas Giants with 25 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_875K_50core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[50] =
      radius_improved(50.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 50.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[50];
  } else if (total_earth_masses < 77.0) {
    /*double x[] = {50, 77, 129};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.702, 0.899}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.801548E-5, 0.00749965, 0.2313407191,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-4.219424E-6, 0.0027538076, 0.6139742641,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.064772E-6, 0.0010723781, 0.8296578179,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-3.064167E-7, 4.7934391E-4, 0.9415547224,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-5.315875E-8, 1.6581053E-4, 1.03250878,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.972787E-8, 1.3806234E-4, 1.045939764,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-8.649041E-9, 3.0964689E-5, 1.132431155,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3494.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3494.0);
  } else {
    jupiter_radii = ln_trend(1.563788706, -0.052740637, total_earth_masses);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 875k Gas Giants with 50 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_875K_100core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[100] =
      radius_improved(100.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 100.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[100];
  } else if (total_earth_masses < 129.0) {
    /*double x[] = {100, 129, 215};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.618, 0.847}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-8.797834E-6, 0.0056892457, 0.0304920635,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-2.145569E-6, 0.0021435881, 0.4853074765,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-5.544961E-7, 8.9936934E-4, 0.7200734098,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.545424E-7, 4.0422677E-4, 0.8637111493,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-5.146447E-8, 1.9126768E-4, 0.9667899426,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.177913E-8, 5.451197E-5, 1.077232978,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    jupiter_radii = ln_trend(1.424851312, -0.0371137816, total_earth_masses);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 875k Gas Giants with 100 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_875K(long double core_earth_masses,
                                   long double total_earth_masses,
                                   planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> core_mass_radii;
  core_mass_radii[0] = gas_radius_300Myr_875K_0core_mass(
      total_earth_masses, the_planet, gas_300Myr_875K_0core_mass);
  core_mass_radii[10] = gas_radius_300Myr_875K_10core_mass(
      total_earth_masses, the_planet, gas_300Myr_875K_10core_mass);
  core_mass_radii[25] = gas_radius_300Myr_875K_25core_mass(
      total_earth_masses, the_planet, gas_300Myr_875K_25core_mass);
  core_mass_radii[50] = gas_radius_300Myr_875K_50core_mass(
      total_earth_masses, the_planet, gas_300Myr_875K_50core_mass);
  core_mass_radii[100] = gas_radius_300Myr_875K_100core_mass(
      total_earth_masses, the_planet, gas_300Myr_875K_100core_mass);
  if (core_earth_masses <= 10.0) {
    /*jupiter_radii1 = gas_radius_300Myr_875K_0core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_875K_10core_mass(total_earth_masses, the_planet);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
    jupiter_radii2, 0.0, 10.0);*/
    jupiter_radii = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
  } else if (core_earth_masses <= 25.0) {
    /*jupiter_radii1 = gas_radius_300Myr_875K_10core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_875K_25core_mass(total_earth_masses, the_planet);*/
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 10.0, 25.0);
  } else if (core_earth_masses <= 50.0) {
    /*jupiter_radii1 = gas_radius_300Myr_875K_25core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_875K_50core_mass(total_earth_masses, the_planet);*/
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 25.0, 50.0);
  } else if (core_earth_masses <= 100.0) {
    /*jupiter_radii1 = gas_radius_300Myr_875K_50core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_875K_100core_mass(total_earth_masses, the_planet);*/
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii2 =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 50.0, 100.0);
  } else {
    /*upper_fraction = core_earth_masses / 100.0;
    jupiter_radii = gas_radius_300Myr_875K_100core_mass(total_earth_masses,
    the_planet) * pow1_4(upper_fraction);*/
    /*jupiter_radii1 = gas_radius_300Myr_875K_50core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_875K_100core_mass(total_earth_masses, the_planet);
    jupiter_radii = planet_radius_helper2(core_earth_masses, 50.0,
    jupiter_radii1, 100.0, jupiter_radii2);*/
    jupiter_radii =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 875k Gas Giants", the_planet,
                jupiter_radii, core_mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_260K_0core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  if (total_earth_masses < 17.0) {
    // jupiter_radii = quad_trend(-0.0037408327, 0.1520647441, 0,
    // total_earth_masses);
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(3.6381052E-4, -0.0326442006, 1.953810171,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(8.1888669E-5, -0.0117819838, 1.590694828,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(2.3610571E-5, -0.0046137777, 1.384273805,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.811594E-6, 6.2318841E-4, 1.131755435,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-4.623209E-7, 1.5903837E-4, 1.169177531,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(2.4088908E-7, -2.157725E-4, 1.217255994,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(5.3007574E-8, -6.884918E-5, 1.189533702,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(2.9542666E-8, -3.979963E-5, 1.181106609,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.379453E-8, 7.0395017E-5, 1.127768988,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-4.915612E-9, 5.3382705E-6, 1.180308408,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.663741752, -0.0644607785, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 260k Gas Giants with 0 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_260K_10core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[10] =
      radius_improved(10.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 10.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[10];
  } else if (total_earth_masses < 17.0) {
    /*double x[] = {10, 17, 28};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.727, 0.921}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-4.491466E-4, 0.0378479624, 0.2133880181,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-5.526297E-5, 0.0087005706, 0.7207101895,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-1.065054E-5, 0.0032132425, 0.878727391,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-5.279225E-6, 0.0021067512, 0.9320806856,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.281238E-6, 7.3144355E-4, 1.042964864,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-2.991084E-8, 6.4486167E-5, 1.128518103,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-4.767774E-8, 7.8379887E-5, 1.12589656,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(1.1597452E-8, 4.9971931E-6, 1.147184417,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.770889E-8, 8.6204101E-5, 1.107877759,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-5.320172E-9, 9.0525693E-6, 1.170184852,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.629757403, -0.0605540647, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 260k Gas Giants with 10 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_260K_25core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[25] =
      radius_improved(25.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 25.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[25];
  } else if (total_earth_masses < 28.0) {
    /*double x[] = {25, 28, 46};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.433, 0.754}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-2.526882E-4, 0.0365322581, -0.3917956989,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-4.15857E-5, 0.0105666537, 0.3559292654,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-9.605662E-6, 0.0039787664, 0.6735869565,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-2.284128E-6, 0.0014601586, 0.8766497149,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-5.07149E-7, 5.1302884E-4, 0.9981417598,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.421611E-7, 2.2760832E-4, 1.051996451,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.337242E-8, 6.8167958E-5, 1.098249096,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.358044E-8, 1.0991773E-4, 1.078040915,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-6.228682E-9, 1.5663572E-9, 1.154159978,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.593773054, -0.0566473508, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 260k Gas Giants with 25 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_260K_50core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[50] =
      radius_improved(50.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 50.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[50];
  } else if (total_earth_masses < 77.0) {
    /*double x[] = {50, 77, 129};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.693, 0.888}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.782103E-5, 0.0074211325, 0.2272336957,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-4.157901E-6, 0.0027210156, 0.6061806133,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.037265E-6, 0.0010577167, 0.8195384912,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-3.072889E-7, 4.8687525E-4, 0.9272479522,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-6.095055E-8, 1.819084E-4, 1.015716914,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-4.056852E-8, 1.3979912E-4, 1.0360991,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-7.541751E-9, 2.5988874E-5, 1.128011548,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.523804357, -0.0488339231, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 260k Gas Giants with 50 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_260K_100core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[100] =
      radius_improved(100.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 100.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[100];
  } else if (total_earth_masses < 129.0) {
    /*double x[] = {100, 129, 215};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.613, 0.839}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-8.664633E-6, 0.0056085409, 0.0336863924,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-2.106578E-6, 0.0021130972, 0.482060664,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-5.544961E-7, 8.9936934E-4, 0.7110734098,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.545424E-7, 4.0422677E-4, 0.8547111493,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-5.146447E-8, 1.9126768E-4, 0.9577899426,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.147746E-8, 5.3472442E-5, 1.069072516,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3584.0);
  } else {
    // jupiter_radii = ln_trend(1.400859137, -0.0351604246, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 260k Gas Giants with 100 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_260K(long double core_earth_masses,
                                   long double total_earth_masses,
                                   planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> core_mass_radii;
  core_mass_radii[0] = gas_radius_300Myr_260K_0core_mass(
      total_earth_masses, the_planet, gas_300Myr_260K_0core_mass);
  core_mass_radii[10] = gas_radius_300Myr_260K_10core_mass(
      total_earth_masses, the_planet, gas_300Myr_260K_10core_mass);
  core_mass_radii[25] = gas_radius_300Myr_260K_25core_mass(
      total_earth_masses, the_planet, gas_300Myr_260K_25core_mass);
  core_mass_radii[50] = gas_radius_300Myr_260K_50core_mass(
      total_earth_masses, the_planet, gas_300Myr_260K_50core_mass);
  core_mass_radii[100] = gas_radius_300Myr_260K_100core_mass(
      total_earth_masses, the_planet, gas_300Myr_260K_100core_mass);
  if (core_earth_masses <= 10.0) {
    /*jupiter_radii1 = gas_radius_300Myr_260K_0core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_260K_10core_mass(total_earth_masses, the_planet);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
    jupiter_radii2, 0.0, 10.0);*/
    jupiter_radii = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
  } else if (core_earth_masses <= 25.0) {
    /*jupiter_radii1 = gas_radius_300Myr_260K_10core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_260K_25core_mass(total_earth_masses, the_planet);*/
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 10.0, 25.0);
  } else if (core_earth_masses <= 50.0) {
    /*jupiter_radii1 = gas_radius_300Myr_260K_25core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_260K_50core_mass(total_earth_masses, the_planet);*/
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 25.0, 50.0);
  } else if (core_earth_masses <= 100.0) {
    /*jupiter_radii1 = gas_radius_300Myr_260K_50core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_260K_100core_mass(total_earth_masses, the_planet);*/
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii2 =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 50.0, 100.0);
  } else {
    /*upper_fraction = core_earth_masses / 100.0;
    jupiter_radii = gas_radius_300Myr_260K_100core_mass(total_earth_masses,
    the_planet) * pow1_4(upper_fraction);*/
    /*jupiter_radii1 = gas_radius_300Myr_260K_50core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_260K_100core_mass(total_earth_masses, the_planet);
    jupiter_radii = planet_radius_helper2(core_earth_masses, 50.0,
    jupiter_radii1, 100.0, jupiter_radii2);*/
    jupiter_radii =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 260k Gas Giants", the_planet,
                jupiter_radii, core_mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_78K_0core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  if (total_earth_masses < 17.0) {
    // jupiter_radii = quad_trend(-0.0018802521, 0.0866113445, 0,
    // total_earth_masses);
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-7.662835E-6, 0.0023448276, 0.8913524904,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-1.192305E-5, 0.0026600834, 0.8858653354,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-2.7953E-6, 0.0015373703, 0.9181958205,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-3.934303E-6, 0.0017720049, 0.906882107,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.136091E-6, 8.0941988E-4, 0.9844905224,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-2.961707E-7, 3.6174249E-4, 1.041915857,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.368313E-7, 2.3713903E-4, 1.065426713,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-7.715088E-8, 1.6325473E-4, 1.086860082,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-1.372624E-8, 3.2219414E-5, 1.150285234,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.292072E-9, -1.062873E-5, 1.184889125,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.545796532, -0.05078728, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 78k Gas Giants with 0 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_78K_10core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[10] =
      radius_improved(10.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 10.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[10];
  } else if (total_earth_masses < 17.0) {
    /*double x[] = {10, 17, 28};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.565, 0.733}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-3.08255E-4, 0.0291442006, 0.1586342738,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-6.868554E-5, 0.0114160632, 0.4671996928,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-1.791533E-5, 0.005171328, 0.6470277587,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-6.011641E-6, 0.0027191673, 0.765271405,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.801498E-6, 0.0012708782, 0.8820354446,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-5.050125E-7, 5.7985126E-4, 0.970676181,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-2.21624E-7, 3.5824147E-4, 1.012490718,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-8.730429E-8, 1.9195368E-4, 1.060729756,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-1.76406E-8, 4.8028498E-5, 1.130394005,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.998302E-9, -5.874874E-6, 1.17392603,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.526804357, -0.0488339231, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 78k Gas Giants with 10 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_78K_25core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[25] =
      radius_improved(25.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 25.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[25];
  } else if (total_earth_masses < 28.0) {
    /*double x[] = {25, 28, 46};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.394, 0.664}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-1.994733E-4, 0.029761027, -0.282921659,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-3.608479E-5, 0.0096642351, 0.2958005919,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-9.255658E-6, 0.0041374349, 0.5622943144,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-2.527832E-6, 0.0018230625, 0.7488905841,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-9.7477288E-8, 4.2377276E-4, 0.9283829688,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.124788E-6, 0.001379584, 0.7480353141,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(4.1230371E-8, -6.394642E-5, 1.166794407,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.127259E-8, 6.5184687E-5, 1.104290949,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-3.109091E-9, 2.5932789E-6, 1.154839378,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.475827834, -0.0429738523, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 78k Gas Giants with 25 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_78K_50core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[50] =
      radius_improved(50.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 50.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[50];
  } else if (total_earth_masses < 77.0) {
    /*double x[] = {50, 77, 129};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.635, 0.823}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.541313E-5, 0.0067904903, 0.2035167224,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-4.330525E-6, 0.0029780726, 0.5108928957,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.259994E-6, 0.0013414798, 0.7208250777,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-4.85778E-7, 7.0695223E-4, 0.8405511733,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.411399E-7, 3.2634415E-4, 0.9509631802,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.518046E-8, 8.6771865E-5, 1.066923586,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-5.731731E-9, 1.97151545E-5, 1.121048776,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 1292, mass_radii[1292], 2154.0,
                             mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 1292, mass_radii[1292], 2154.0,
                             mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.421851312, -0.0371137816, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 78k Gas Giants with 50 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_78K_100core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[100] =
      radius_improved(100.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 100.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[100];
  } else if (total_earth_masses < 129.0) {
    /*double x[] = {100, 129, 215};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.587, 0.810}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-8.069112E-6, 0.0053687976, 0.02870319,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-2.115925E-6, 0.0021957491, 0.4357225711,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-6.702018E-7, 0.0010651937, 0.6490418913,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-2.027975E-7, 4.8654714E-4, 0.8169036124,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.887424E-8, 1.4788175E-4, 0.9808281498,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-9.66744E-9, 4.7235112E-5, 1.062109745,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 1292, mass_radii[1292], 2154.0,
                             mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.298906092, -0.0234402831, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 78k Gas Giants with 100 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr_78K(long double core_earth_masses,
                                  long double total_earth_masses,
                                  planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> core_mass_radii;
  core_mass_radii[0] = gas_radius_300Myr_78K_0core_mass(
      total_earth_masses, the_planet, gas_300Myr_78K_0core_mass);
  core_mass_radii[10] = gas_radius_300Myr_78K_10core_mass(
      total_earth_masses, the_planet, gas_300Myr_78K_10core_mass);
  core_mass_radii[25] = gas_radius_300Myr_78K_25core_mass(
      total_earth_masses, the_planet, gas_300Myr_78K_25core_mass);
  core_mass_radii[50] = gas_radius_300Myr_78K_50core_mass(
      total_earth_masses, the_planet, gas_300Myr_78K_50core_mass);
  core_mass_radii[100] = gas_radius_300Myr_78K_100core_mass(
      total_earth_masses, the_planet, gas_300Myr_78K_100core_mass);
  if (core_earth_masses <= 10.0) {
    /*jupiter_radii1 = gas_radius_300Myr_78K_0core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_78K_10core_mass(total_earth_masses, the_planet);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
    jupiter_radii2, 0.0, 10.0);*/
    jupiter_radii = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
  } else if (core_earth_masses <= 25.0) {
    /*jupiter_radii1 = gas_radius_300Myr_78K_10core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_78K_25core_mass(total_earth_masses, the_planet);*/
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 10.0, 25.0);
  } else if (core_earth_masses <= 50.0) {
    /*jupiter_radii1 = gas_radius_300Myr_78K_25core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_78K_50core_mass(total_earth_masses, the_planet);*/
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 25.0, 50.0);
  } else if (core_earth_masses <= 100.0) {
    /*jupiter_radii1 = gas_radius_300Myr_78K_50core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_78K_100core_mass(total_earth_masses, the_planet);*/
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii2 =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 50.0, 100.0);
  } else {
    /*upper_fraction = core_earth_masses / 100.0;
    jupiter_radii = gas_radius_300Myr_78K_100core_mass(total_earth_masses,
    the_planet) * pow1_4(upper_fraction);*/
    /*jupiter_radii1 = gas_radius_300Myr_78K_50core_mass(total_earth_masses,
    the_planet); jupiter_radii2 =
    gas_radius_300Myr_78K_100core_mass(total_earth_masses, the_planet);
    jupiter_radii = planet_radius_helper2(core_earth_masses, 50.0,
    jupiter_radii1, 100.0, jupiter_radii2);*/
    jupiter_radii =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old 78k Gas Giants", the_planet,
                jupiter_radii, core_mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_300Myr(long double temperature,
                              long double core_earth_masses,
                              long double total_earth_masses,
                              planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> temperature_radii;
  temperature_radii[1960] = gas_radius_300Myr_1960K(
      core_earth_masses, total_earth_masses, the_planet);
  temperature_radii[1300] = gas_radius_300Myr_1300K(
      core_earth_masses, total_earth_masses, the_planet);
  temperature_radii[875] =
      gas_radius_300Myr_875K(core_earth_masses, total_earth_masses, the_planet);
  temperature_radii[260] =
      gas_radius_300Myr_260K(core_earth_masses, total_earth_masses, the_planet);
  temperature_radii[78] =
      gas_radius_300Myr_78K(core_earth_masses, total_earth_masses, the_planet);
  temperature_radii[0] = 0.0;
  /*if (temperature > 1960.0)
  {
    upper_fraction = temperature / 1960.0;
    jupiter_radii = gas_radius_300Myr_1960K(core_earth_masses,
  total_earth_masses, the_planet) * pow1_4(upper_fraction);

  }
  else if (temperature > 1300.0)
  {
    range = 1960.0 - 1300.0;
    upper_fraction = (temperature - 1300.0) / (long double)range;
    lower_fraction = 1.0 - upper_fraction;
    jupiter_radii = (upper_fraction * gas_radius_300Myr_1960K(core_earth_masses,
  total_earth_masses, the_planet)) + (lower_fraction *
  gas_radius_300Myr_1300K(core_earth_masses, total_earth_masses, the_planet));
  }
  else if (temperature > 875)
  {
    range = 1300.0 - 875.0;
    upper_fraction = (temperature - 875.0) / (long double)range;
    lower_fraction = 1.0 - upper_fraction;
    jupiter_radii = (upper_fraction * gas_radius_300Myr_1300K(core_earth_masses,
  total_earth_masses, the_planet)) + (lower_fraction *
  gas_radius_300Myr_875K(core_earth_masses, total_earth_masses, the_planet));
  }
  else if (temperature > 260)
  {
    range = 875.0 - 260.0;
    upper_fraction = (temperature - 260.0) / (long double)range;
    lower_fraction = 1.0 - upper_fraction;
    jupiter_radii = (upper_fraction * gas_radius_300Myr_875K(core_earth_masses,
  total_earth_masses, the_planet)) + (lower_fraction *
  gas_radius_300Myr_260K(core_earth_masses, total_earth_masses, the_planet));
  }
  else if (temperature > 78)
  {
    range = 260.0 - 78.0;
    upper_fraction = (temperature - 78.0) / (long double)range;
    lower_fraction = 1.0 - upper_fraction;
    jupiter_radii = (upper_fraction * gas_radius_300Myr_260K(core_earth_masses,
  total_earth_masses, the_planet)) + (lower_fraction *
  gas_radius_300Myr_78K(core_earth_masses, total_earth_masses, the_planet));
  }
  else
  {
    lower_fraction = temperature / 78.0;
    jupiter_radii = gas_radius_300Myr_78K(core_earth_masses, total_earth_masses,
  the_planet) * pow1_4(lower_fraction);
    //jupiter_radii = gas_radius_300Myr_78K(core_earth_masses,
  total_earth_masses);
  }*/
  if (temperature <= 78.0) {
    jupiter_radii1 = planet_radius_helper(
        temperature, 0.0, temperature_radii[0], 78.0, temperature_radii[78],
        260.0, temperature_radii[260], false);
    jupiter_radii2 =
        planet_radius_helper2(temperature, 78.0, temperature_radii[78], 260.0,
                              temperature_radii[260]);
    jupiter_radii =
        rangeAdjust(temperature, jupiter_radii1, jupiter_radii2, 0.0, 78.0);
  } else if (temperature <= 260.0) {
    // jupiter_radii1 = planet_radius_helper(temperature, 0.0,
    // temperature_radii[0], 78.0, temperature_radii[78], 260.0,
    // temperature_radii[260], false);
    jupiter_radii1 =
        planet_radius_helper2(temperature, 78.0, temperature_radii[78], 260.0,
                              temperature_radii[260]);
    jupiter_radii2 = planet_radius_helper(
        temperature, 78.0, temperature_radii[78], 260.0, temperature_radii[260],
        875.0, temperature_radii[875], false);
    jupiter_radii =
        rangeAdjust(temperature, jupiter_radii1, jupiter_radii2, 78.0, 260.0);
  } else if (temperature <= 875.0) {
    jupiter_radii1 = planet_radius_helper(
        temperature, 78.0, temperature_radii[78], 260.0, temperature_radii[260],
        875.0, temperature_radii[875], false);
    jupiter_radii2 = planet_radius_helper(
        temperature, 260.0, temperature_radii[260], 875.0,
        temperature_radii[875], 1300.0, temperature_radii[1300], false);
    jupiter_radii =
        rangeAdjust(temperature, jupiter_radii1, jupiter_radii2, 260.0, 875.0);
  } else if (temperature <= 1300.0) {
    jupiter_radii1 = planet_radius_helper(
        temperature, 260.0, temperature_radii[260], 875.0,
        temperature_radii[875], 1300.0, temperature_radii[1300], false);
    jupiter_radii2 = planet_radius_helper(
        temperature, 875.0, temperature_radii[875], 1300.0,
        temperature_radii[1300], 1960.0, temperature_radii[1960], false);
    jupiter_radii =
        rangeAdjust(temperature, jupiter_radii1, jupiter_radii2, 875.0, 1300.0);
  } else if (temperature <= 1960.0) {
    jupiter_radii1 = planet_radius_helper(
        temperature, 875.0, temperature_radii[875], 1300.0,
        temperature_radii[1300], 1960.0, temperature_radii[1960], false);
    jupiter_radii2 =
        planet_radius_helper3(temperature, 1300.0, temperature_radii[1300],
                              1960.0, temperature_radii[1960]);
    jupiter_radii = rangeAdjust(temperature, jupiter_radii1, jupiter_radii2,
                                1300.0, 1960.0);
  } else {
    jupiter_radii =
        planet_radius_helper3(temperature, 1300.0, temperature_radii[1300],
                              1960.0, temperature_radii[1960]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("300 million year old Gas Giants", the_planet, jupiter_radii,
                temperature_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_1960K_0core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-0.0016532091, 0.1095041408, 0,
    // total_earth_masses);
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(1.6183893E-4, -0.024809414, 2.337781874,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(4.1002721E-5, -0.0099465604, 1.909780023,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(8.5102797E-6, -0.0032531176, 1.587032609,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(5.4116627E-7, -5.117426E-4, 1.366009246,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(6.2171815E-7, -5.546767E-4, 1.371516579,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(5.8240497E-8, -1.140372E-4, 1.2888374324,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(7.1630436E-8, -1.30614E-4, 1.293183133,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-1.595282E-8, 5.0333039E-5, 1.20559917,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.035267E-8, 3.1034937E-5, 1.221184205,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.854679146, -0.0800876339, total_earth_masses);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 1960k Gas Giants with 0 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_1960K_10core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[10] =
      radius_improved(10.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 10.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[10];
  } else if (total_earth_masses < 17.0) {
    /*double x[] = {10, 17, 28};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.909, 1.150}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-6.194706E-4, 0.0497852665, 0.2416774643,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-8.708214E-5, 0.0103885232, 0.973937532,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(7.825346E-6, -0.0012850982, 1.263556085,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.863447E-6, 7.1079308E-4, 1.167317308,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-6.259848E-7, 2.8510622E-4, 1.201638311,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(1.9495458E-7, -1.524545E-4, 1.257765938,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-3.537068E-8, 2.7659875E-5, 1.223780985,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(4.978943E-8, -7.776821E-5, 1.254365008,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-1.986718E-8, 6.6142122E-5, 1.184707949,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.045556E-8, 3.370968E-5, 1.210900186,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.804702623, -0.0742275631, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 1960k Gas Giants with 10 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_1960K_25core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[25] =
      radius_improved(25.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 25.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[25];
  } else if (total_earth_masses < 28.0) {
    /*double x[] = {25, 28, 46};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.461, 0.838}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-3.063053E-4, 0.043611038, -0.5199656938,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-4.857395E-5, 0.0119100795, 0.3929188167,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-9.751497E-6, 0.003912654, 0.7785422241,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.92574E-6, 0.0012205939, 0.9955896132,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-4.772381E-7, 4.4854267E-4, 1.094623657,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.227799E-7, 1.7135633E-4, 1.146924678,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(2.791812E-8, -1.1520779E-5, 1.201045757,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.993547E-8, 1.0431773E-4, 1.143191703,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.166574E-8, 4.1360238E-5, 1.194035774,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.783710449, -0.0722742062, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 1960k Gas Giants with 25 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_1960K_50core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[50] =
      radius_improved(50.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 50.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[50];
  } else if (total_earth_masses < 77.0) {
    /*double x[] = {50, 77, 129};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.746, 0.958}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.993726E-5, 0.008183998, 0.2340401338,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-4.445209E-6, 0.002854733, 0.6637121282,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.014298E-6, 0.0010260577, 0.8982835195,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-3.409153E-7, 4.9947244E-4, 0.9976424774,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-2.122439E-8, 1.0369515E-4, 1.112454977,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.748182E-8, 1.37283E-4, 1.096197418,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.318109E-8, 5.354269E-5, 1.163825566,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.697749577, -0.0625074216, total_earth_masses);
    // this was set but never used
    // jupiter_radii2 = planet_radius_helper2(total_earth_masses, 2154.0,
    // mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 1960k Gas Giants with 50 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_1960K_100core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[100] =
      radius_improved(100.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 100.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[100];
  } else if (total_earth_masses < 129.0) {
    /*double x[] = {100, 129, 215};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.640, 0.888}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-9.658564E-6, 0.0062062668, 1.197411E-4,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-2.296993E-6, 0.0022825493, 0.5034303716,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-6.278539E-7, 9.7728311E-4, 0.7497150685,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.273012E-7, 3.575989E-4, 0.9294815511,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-5.257452E-8, 2.0321354E-4, 1.004208648,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.71168E-8, 8.1026257E-5, 1.102886534,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.572804357, -0.0488339231, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 1960k Gas Giants with 100 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_1960K(long double core_earth_masses,
                                  long double total_earth_masses,
                                  planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> core_mass_radii;
  core_mass_radii[0] = gas_radius_1Gyr_1960K_0core_mass(
      total_earth_masses, the_planet, gas_1Gyr_1960K_0core_mass);
  core_mass_radii[10] = gas_radius_1Gyr_1960K_10core_mass(
      total_earth_masses, the_planet, gas_1Gyr_1960K_10core_mass);
  core_mass_radii[25] = gas_radius_1Gyr_1960K_25core_mass(
      total_earth_masses, the_planet, gas_1Gyr_1960K_25core_mass);
  core_mass_radii[50] = gas_radius_1Gyr_1960K_50core_mass(
      total_earth_masses, the_planet, gas_1Gyr_1960K_50core_mass);
  core_mass_radii[100] = gas_radius_1Gyr_1960K_100core_mass(
      total_earth_masses, the_planet, gas_1Gyr_1960K_100core_mass);
  if (core_earth_masses <= 10.0) {
    jupiter_radii = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
  } else if (core_earth_masses <= 25.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 10.0, 25.0);
  } else if (core_earth_masses <= 50.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 25.0, 50.0);
  } else if (core_earth_masses <= 100.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii2 =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 50.0, 100.0);
  } else {
    jupiter_radii =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 1960k Gas Giants", the_planet,
                jupiter_radii, core_mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_1300K_0core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  if (total_earth_masses < 17.0) {
    // jupiter_radii = quad_trend(-0.0038412911, 0.1529490069, 0.0,
    // total_earth_masses);
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(5.17938E-4, -0.0432163009, 2.074993034,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(7.4098457E-5, -0.0103721747, 1.503327701,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(1.9559628E-5, -0.0036638988, 1.31015117,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-2.310674E-6, 8.4138342E-4, 1.092913462,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-6.056762E-7, 2.5486422E-4, 1.140201572,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(1.9041454E-7, -1.694521E-4, 1.194630292,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(3.7987146E-8, -5.025389E-5, 1.172139326,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(2.2548094E-8, -3.114035E-5, 1.166594607,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.380102E-8, -6.4616923E-5, 1.120245122,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-5.110893E-9, 2.1074347E-7, 1.172259148,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.77867132, -0.0820409908, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 1300k Gas Giants with 0 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_1300K_10core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[10] =
      radius_improved(10.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 10.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[10];
  } else if (total_earth_masses < 17.0) {
    /*double x[] = {10, 17, 28};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.698, 0.888}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-4.289446E-4, 0.0365752351, 0.2001859979,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-5.387316E-5, 0.0088199473, 0.6832780338,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-1.345332E-5, 0.0038483064, 0.8264451254,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-5.444505E-6, 0.0021984911, 0.9059966555,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.36307E-6, 7.99447748E-4, 1.019195254,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.078927E-7, 1.2546796E-4, 1.105011728,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-4.060361E-8, 7.2847912E-5, 1.11490363,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.624546E-9, 2.4591833E-5, 1.128939148,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.631647E-8, 7.5605347E-5, 1.104247027,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-5.515452E-9, 3.9250423E-6, 1.162135591,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.744686973, -0.078134277, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 1300k Gas Giants with 10 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_1300K_25core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[25] =
      radius_improved(25.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 25.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[25];
  } else if (total_earth_masses < 28.0) {
    /*double x[] = {25, 28, 46};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.426, 0.739}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-2.436179E-4, 0.0354166118, -0.3746687148,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-4.15857E-5, 0.0105666537, 0.3409292654,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-9.437142E-6, 0.0039440512, 0.660260896,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-2.304436E-6, 0.0014904006, 0.858086454,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-6.126381E-7, 5.8867202E-4, 0.9737547114,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.200665E-7, 2.0348106E-4, 1.04643463,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-2.659442E-8, 8.7762597E-5, 1.080003826,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.134737E-8, 9.7582195E-5, 1.075250837,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-7.229582E-9, 1.4472305E-5, 1.142369863,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.724684797, -0.0761809201, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 1300k Gas Giants with 25 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_1300K_50core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[50] =
      radius_improved(50.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 50.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[50];
  } else if (total_earth_masses < 77.0) {
    /*double x[] = {50, 77, 129};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.684, 0.877}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.754232E-5, 0.0073252573, 0.2239636288,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-4.106532E-6, 0.0027033447, 0.5966053321,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.076256E-6, 0.0010882076, 0.8037853037,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-3.14363E-7, 4.9240722E-4, 0.9162041491,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-6.638075E-8, 1.8540517E-4, 1.00526351,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.833545E-8, 1.2746359E-4, 1.033309032,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-8.542652E-9, 2.4797607E-5, 1.116221433,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.6547261, -0.0683674924, total_earth_masses);
    // this was set but never used
    // jupiter_radii1 = planet_radius_helper2(total_earth_masses, 2154.0,
    // mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 1300k Gas Giants with 50 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_1300K_100core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[100] =
      radius_improved(100.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 100.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[100];
  } else if (total_earth_masses < 129.0) {
    /*double x[] = {100, 129, 215};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.607, 0.831}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-8.592956E-6, 0.0055606279, 0.032674372,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-2.095094E-6, 0.0020972676, 0.4769331781,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-5.394756E-7, 8.8077405E-4, 0.7064677861,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.638685E-7, 4.1577247E-4, 0.8413618123,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-5.09127E-8, 1.8240572E-4, 0.954318557,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.116879E-8, 4.5448211E-5, 1.064924573,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.515788706, -0.52740637, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 1300k Gas Giants with 100 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_1300K(long double core_earth_masses,
                                  long double total_earth_masses,
                                  planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> core_mass_radii;
  core_mass_radii[0] = gas_radius_1Gyr_1300K_0core_mass(
      total_earth_masses, the_planet, gas_1Gyr_1300K_0core_mass);
  core_mass_radii[10] = gas_radius_1Gyr_1300K_10core_mass(
      total_earth_masses, the_planet, gas_1Gyr_1300K_10core_mass);
  core_mass_radii[25] = gas_radius_1Gyr_1300K_25core_mass(
      total_earth_masses, the_planet, gas_1Gyr_1300K_25core_mass);
  core_mass_radii[50] = gas_radius_1Gyr_1300K_50core_mass(
      total_earth_masses, the_planet, gas_1Gyr_1300K_50core_mass);
  core_mass_radii[100] = gas_radius_1Gyr_1300K_100core_mass(
      total_earth_masses, the_planet, gas_1Gyr_1300K_100core_mass);
  if (core_earth_masses <= 10.0) {
    jupiter_radii = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
  } else if (core_earth_masses <= 25.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 10.0, 25.0);
  } else if (core_earth_masses <= 50.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 25.0, 50.0);
  } else if (core_earth_masses <= 100.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii2 =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 50.0, 100.0);
  } else {
    jupiter_radii =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 1300k Gas Giants", the_planet,
                jupiter_radii, core_mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_875K_0core_mass(long double total_earth_masses,
                                            planet *the_planet,
                                            map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  if (total_earth_masses < 17.0) {
    // jupiter_radii = quad_trend(-0.0030548128, 0.1282847594, 0,
    // total_earth_masses);
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(1.825148E-4, -0.0173949843, 1.540967955,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(6.4881867E-5, -0.008690147, 1.389456733,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(1.5037819E-5, -0.0025593291, 1.212909115,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-3.059293E-6, 0.0011686759, 1.033150502,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-8.207091E-7, 3.98603E-4, 1.095237633,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(1.2845637E-7, -1.073022E-4, 1.160132077,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(2.2094565E-8, -2.412726E-5, 1.144438179,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(1.4756291E-8, -1.504248E-5, 1.141802741,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.548231E-8, 6.8090476E-5, 1.101563814,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-4.404663E-9, -4.54311E-6, 1.160222243,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.774663495, -0.0839943477, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 875k Gas Giants with 0 EU core", the_planet,
                jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_875K_10core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[10] =
      radius_improved(10.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 10.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[10];
  } else if (total_earth_masses < 17.0) {
    /*double x[] = {10, 17, 28};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.665, 0.847}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-4.038662E-4, 0.0347194357, 0.1914869383,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-4.728988E-5, 0.0083327847, 0.6507572965,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-1.641305E-5, 0.004539338, 0.760123053,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-5.580618E-6, 0.0023034543, 0.8677215719,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.567949E-6, 9.2309526E-4, 0.979012945,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.308599E-7, 1.5712698E-4, 1.077266699,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-6.357033E-8, 1.0450652E-4, 1.087195414,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-5.520447E-9, 3.2640765E-5, 1.108042315,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.799776E-8, 7.90789E-5, 1.085565719,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-4.809222E-9, -8.288115E-7, 1.150098686,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.740679146, -0.0800876339, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 875k Gas Giants with 10 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_875K_25core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[25] =
      radius_improved(25.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 25.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[25];
  } else if (total_earth_masses < 28.0) {
    /*double x[] = {25, 28, 46};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.420, 0.719}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-2.310365E-4, 0.0377078122, -0.3426861239,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-3.917905E-5, 0.0101093456, 0.3368729708,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-9.547328E-6, 0.0040052112, 0.6312048495,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-2.324745E-6, 0.0015206426, 0.8315231931,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-6.631126E-7, 6.3499242E-4, 0.9451290097,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.209387E-7, 2.110124E-4, 1.02512786,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-3.671774E-8, 1.0674689E-4, 1.055374627,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.162975E-8, 9.623509E-5, 1.060462663,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-6.523352E-9, 9.718451E-6, 1.130332958,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.720686972, -0.078134277, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 875k Gas Giants with 25 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_875K_50core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[50] =
      radius_improved(50.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 50.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[50];
  } else if (total_earth_masses < 77.0) {
    /*double x[] = {50, 77, 129};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.670, 0.859}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.698491E-5, 0.007133507, 0.221423495,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-4.106532E-6, 0.0027033447, 0.5786053321,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.076256E-6, 0.0010882076, 0.7857853037,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-2.931406E-7, 4.758113E-4, 0.9013355583,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-8.27315E-8, 2.1532482E-4, 0.9769010435,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292) {
    // jupiter_radii = quad_trend(-3.721891E-8, 1.2129582E-4, 1.022413993,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-7.534752E-9, 1.9004198E-5, 1.105024066,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.6357261, -0.0683674924, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 875k Gas Giants with 50 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_875K_100core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[100] =
      radius_improved(100.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 100.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[100];
  } else if (total_earth_masses < 129.0) {
    /*double x[] = {100, 129, 215};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.600, 0.818}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-8.275185E-6, 0.0053815473, 0.0434877485,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-2.08361E-6, 0.0020814381, 0.4668056922,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-5.244552E-7, 8.6217876E-4, 0.6968621625,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.685316E-7, 4.2154533E-4, 0.824871439,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-4.895551E-8, 1.7450117E-4, 0.9442641716,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.096651E-8, 4.3591061E-5, 1.049986351,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.51278088, -0.0546939939, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 875k Gas Giants with 100 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_875K(long double core_earth_masses,
                                 long double total_earth_masses,
                                 planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> core_mass_radii;
  core_mass_radii[0] = gas_radius_1Gyr_875K_0core_mass(
      total_earth_masses, the_planet, gas_1Gyr_875K_0core_mass);
  core_mass_radii[10] = gas_radius_1Gyr_875K_10core_mass(
      total_earth_masses, the_planet, gas_1Gyr_875K_10core_mass);
  core_mass_radii[25] = gas_radius_1Gyr_875K_25core_mass(
      total_earth_masses, the_planet, gas_1Gyr_875K_25core_mass);
  core_mass_radii[50] = gas_radius_1Gyr_875K_50core_mass(
      total_earth_masses, the_planet, gas_1Gyr_875K_50core_mass);
  core_mass_radii[100] = gas_radius_1Gyr_875K_100core_mass(
      total_earth_masses, the_planet, gas_1Gyr_875K_100core_mass);
  if (core_earth_masses <= 10.0) {
    jupiter_radii = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
  } else if (core_earth_masses <= 25.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 10.0, 25.0);
  } else if (core_earth_masses <= 50.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 25.0, 50.0);
  } else if (core_earth_masses <= 100.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii2 =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 50.0, 100.0);
  } else {
    jupiter_radii =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 875k Gas Giants", the_planet, jupiter_radii,
                core_mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_260K_0core_mass(long double total_earth_masses,
                                            planet *the_planet,
                                            map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  if (total_earth_masses < 17.0) {
    // jupiter_radii = quad_trend(-0.0028449198, 0.120657754, 0,
    // total_earth_masses);
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(1.5238593E-4, -0.0142210031, 1.42671752,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(5.4165752E-5, -0.0069527101, 1.300209933,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(1.0912135E-5, 0.0016325152, 1.14700562,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-3.448186E-6, 0.001325711, 1.0043645448,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-8.410178E-7, 4.28845E-4, 1.076674372,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(5.0474541E-8, -4.632041E-5, 1.137625702,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(3.6242839E-8, -3.519121E-5, 1.135525786,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(4.632964E-9, 3.94181E-6, 1.124173542,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.324275E-8, 6.153304E-5, 1.096297602,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-4.606943E-9, -2.685961E-6, 1.148160465,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.75067132, -0.0820409908, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 260k Gas Giants with 0 EU core", the_planet,
                jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_260K_10core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[10] =
      radius_improved(10.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 10.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[10];
  } else if (total_earth_masses < 17.0) {
    /*double x[] = {10, 17, 28};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.646, 0.823}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-3.786137E-4, 0.0331285266, 0.1922344131,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-5.098383E-5, 0.0088839149, 0.6142217102,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-1.711561E-5, 0.0047181231, 0.7341829651,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-5.775064E-6, 0.0023819709, 0.8468285953,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.526734E-6, 9.2054532E-4, 0.9646560333,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-2.088418E-7, 2.1810877E-4, 1.054760324,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-4.942205E-8, 9.3442566E-5, 1.07828302,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.564377E-8, 5.1625057E-5, 1.090414015,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.57582E-8, 7.2521464E-5, 1.080299507,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-5.011502E-9, 1.0283379E-6, 1.138036908,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.716686972, -0.078134277, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 260k Gas Giants with 10 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_260K_25core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[25] =
      radius_improved(25.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 25.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[25];
  } else if (total_earth_masses < 28.0) {
    /*double x[] = {25, 28, 46};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.416, 0.709}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-2.255504E-4, 0.03296851, -0.3302867384,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-3.840175E-5, 0.0099492212, 0.3325939191,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-9.463068E-6, 0.0039878536, 0.620041806,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-2.386268E-6, 0.0015534345, 0.8163168439,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-6.356053E-7, 6.2033104E-4, 0.9360096831,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.28885E-7, 2.2407571E-4, 1.010777287,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-4.061365E-8, 1.1479582E-4, 1.042478694,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.162975E-8, 9.623509E-5, 1.051462663,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-6.221682E-9, 8.678896E-6, 1.122172496,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.696694797, -0.0761809201, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 260k Gas Giants with 25 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_260K_50core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[50] =
      radius_improved(50.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 50.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[50];
  } else if (total_earth_masses < 77.0) {
    /*double x[] = {50, 77, 129};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 663, 0.850}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.67062E-5, 0.0070376319, 0.2201534281,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-4.106532E-6, 0.0027033447, 0.5696053321,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.076256E-6, 0.0010882076, 0.7767853037,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-2.931406E-7, 4.758113E-4, 0.8923355583,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-8.27315E-8, 2.1532482E-4, 0.9679010435,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.721891E-8, 1.2129582E-4, 1.013413993,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-7.233082E-9, 1.7964643E-5, 1.096863604,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.611733926, -0.0664141354, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 260k Gas Giants with 50 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_260K_100core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[100] =
      radius_improved(100.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 100.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[100];
  } else if (total_earth_masses < 129.0) {
    /*double x[] = {100, 129, 215};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.595, 0.811}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-8.203507E-6, 0.0053336344, 0.0434757282,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-2.044619E-6, 0.0020509472, 0.4645588798,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-5.244552E-7, 8.6217876E-4, 0.6888621625,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.685316E-7, 4.2154533E-4, 0.8166871439,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-4.895551E-8, 1.7450117E-4, 0.9362641716,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.096651E-8, 4.3591061E-5, 1.041986351,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.50478088, -0.0546939939, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 260k Gas Giants with 100 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_260K(long double core_earth_masses,
                                 long double total_earth_masses,
                                 planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> core_mass_radii;
  core_mass_radii[0] = gas_radius_1Gyr_260K_0core_mass(
      total_earth_masses, the_planet, gas_1Gyr_260K_0core_mass);
  core_mass_radii[10] = gas_radius_1Gyr_260K_10core_mass(
      total_earth_masses, the_planet, gas_1Gyr_260K_10core_mass);
  core_mass_radii[25] = gas_radius_1Gyr_260K_25core_mass(
      total_earth_masses, the_planet, gas_1Gyr_260K_25core_mass);
  core_mass_radii[50] = gas_radius_1Gyr_260K_50core_mass(
      total_earth_masses, the_planet, gas_1Gyr_260K_50core_mass);
  core_mass_radii[100] = gas_radius_1Gyr_260K_100core_mass(
      total_earth_masses, the_planet, gas_1Gyr_260K_100core_mass);
  if (core_earth_masses <= 10.0) {
    jupiter_radii = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
  } else if (core_earth_masses <= 25.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 10.0, 25.0);
  } else if (core_earth_masses <= 50.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 25.0, 50.0);
  } else if (core_earth_masses <= 100.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii2 =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 50.0, 100.0);
  } else {
    jupiter_radii =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 260k Gas Giants", the_planet, jupiter_radii,
                core_mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_78K_0core_mass(long double total_earth_masses,
                                           planet *the_planet,
                                           map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  if (total_earth_masses < 17.0) {
    // jupiter_radii = quad_trend(-0.0017354851, 0.0799150115, 0,
    // total_earth_masses);
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(5.2246604E-7, 0.0017946708, 0.8263396029,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-7.790213E-6, 0.0024098091, 0.8156328725,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-6.367903E-6, 0.002234865, 0.8206706927,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-3.234295E-6, 0.0015893417, 0.8517968227,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.2896E-6, 9.2036673E-4, 0.9057329327,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-3.581289E-7, 4.238924E-4, 0.9694176408,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.456497E-7, 2.5773368E-4, 1.00076937,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-7.951249E-8, 1.7585582E-4, 1.024521621,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-1.679996E-8, 4.6291721E-5, 1.087234658,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-5.518952E-9, 7.4173805E-6, 1.118629332,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.6337261, -0.0683674924, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 78k Gas Giants with 0 EU core", the_planet,
                jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_78K_10core_mass(long double total_earth_masses,
                                            planet *the_planet,
                                            map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[10] =
      radius_improved(10.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 10.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[10];
  } else if (total_earth_masses < 17.0) {
    /*double x[] = {10, 17, 28};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.532, 0.683}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-2.664577E-4, 0.0257178683, 0.1718025078,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-6.254115E-5, 0.0106280448, 0.4344470046,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-1.845347E-5, 0.0052052602, 0.5906055637,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-5.285707E-6, 0.0024927018, 0.7214009197,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.821807E-6, 0.0013011202, 0.8174721837,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-5.55487E-7, 6.2617166E-4, 0.9040504793,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-2.15422E-7, 3.6024083E-4, 0.9542277508,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-9.199743E-8, 2.074412E-4, 0.9985539604,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-1.931541E-8, 5.7280146E-5, 1.071236565,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-5.923512E-9, 1.1131679E-5, 1.108505775,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.599741752, -0.0644607785, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 78k Gas Giants with 10 EU core", the_planet,
                jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_78K_25core_mass(long double total_earth_masses,
                                            planet *the_planet,
                                            map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[25] =
      radius_improved(25.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 25.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[25];
  } else if (total_earth_masses < 28.0) {
    /*double x[] = {25, 28, 46};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.386, 0.631}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-1.796869E-4, 0.0269079438, -0.2265478751,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-3.288589E-5, 0.0088514156, 0.2934214177,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-8.140831E-6, 0.0037539343, 0.5392140468,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-2.579201E-6, 0.0018407335, 0.6934658653,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(8.1453624E-8, 4.2260464E-4, 0.8753748095,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.059376E-6, 0.0013147336, 0.7070430821,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(3.107696E-8, -3.524747E-5, 1.098664081,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.518695E-8, 8.0993771E-5, 1.04239972,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-6.832022E-9, 1.7742682E-5, 1.093480902,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.564757403, -0.0605540647, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 78k Gas Giants with 25 EU core", the_planet,
                jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_78K_50core_mass(long double total_earth_masses,
                                            planet *the_planet,
                                            map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[50] =
      radius_improved(50.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 50.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[50];
  } else if (total_earth_masses < 77.0) {
    /*double x[] = {50, 77, 129};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.610, 0.784}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.413627E-5, 0.0062582251, 0.211930602,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-3.992445E-6, 0.00276875, 0.4932695331,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.170529E-6, 0.0012646685, 0.6862039668,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-4.335574E-7, 6.8835694E-4, 0.7949455497,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.318138E-7, 3.1479844E-4, 0.9033125171,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.993547E-8, 1.0431773E-4, 1.005191703,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-8.950711E-9, 3.2004244E-5, 1.063591617,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.51078088, -0.0546939939, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 78k Gas Giants with 50 EU core", the_planet,
                jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_78K_100core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[100] =
      radius_improved(100.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 100.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[100];
  } else if (total_earth_masses < 129.0) {
    /*double x[] = {100, 129, 215};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.570, 0.775}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-7.321275E-6, 0.0049022394, 0.0594444444,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.92551E-6, 0.002026297, 0.4283528635,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 315.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-6.322147E-7, 0.0010149398, 0.6191812173,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 315.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.942385E-7, 4.7272535E-4, 0.7764742136,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-4.251272E-8, 1.5925985E-4, 0.9282012278,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.187852E-8, 5.3694403E-5, 1.013455219,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.38883566, -0.0410204954, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 78k Gas Giants with 100 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr_78K(long double core_earth_masses,
                                long double total_earth_masses,
                                planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> core_mass_radii;
  core_mass_radii[0] = gas_radius_1Gyr_78K_0core_mass(
      total_earth_masses, the_planet, gas_1Gyr_78K_0core_mass);
  core_mass_radii[10] = gas_radius_1Gyr_78K_10core_mass(
      total_earth_masses, the_planet, gas_1Gyr_78K_10core_mass);
  core_mass_radii[25] = gas_radius_1Gyr_78K_25core_mass(
      total_earth_masses, the_planet, gas_1Gyr_78K_25core_mass);
  core_mass_radii[50] = gas_radius_1Gyr_78K_50core_mass(
      total_earth_masses, the_planet, gas_1Gyr_78K_50core_mass);
  core_mass_radii[100] = gas_radius_1Gyr_78K_100core_mass(
      total_earth_masses, the_planet, gas_1Gyr_78K_100core_mass);
  if (core_earth_masses <= 10.0) {
    jupiter_radii = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
  } else if (core_earth_masses <= 25.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 10.0, 25.0);
  } else if (core_earth_masses <= 50.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 25.0, 50.0);
  } else if (core_earth_masses <= 100.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii2 =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 50.0, 100.0);
  } else {
    jupiter_radii =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old 78k Gas Giants", the_planet, jupiter_radii,
                core_mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_1Gyr(long double temperature,
                            long double core_earth_masses,
                            long double total_earth_masses,
                            planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> temperature_radii;
  temperature_radii[1960] =
      gas_radius_1Gyr_1960K(core_earth_masses, total_earth_masses, the_planet);
  temperature_radii[1300] =
      gas_radius_1Gyr_1300K(core_earth_masses, total_earth_masses, the_planet);
  temperature_radii[875] =
      gas_radius_1Gyr_875K(core_earth_masses, total_earth_masses, the_planet);
  temperature_radii[260] =
      gas_radius_1Gyr_260K(core_earth_masses, total_earth_masses, the_planet);
  temperature_radii[78] =
      gas_radius_1Gyr_78K(core_earth_masses, total_earth_masses, the_planet);
  temperature_radii[0] = 0.0;
  if (temperature <= 78.0) {
    jupiter_radii1 = planet_radius_helper(
        temperature, 0.0, temperature_radii[0], 78.0, temperature_radii[78],
        260.0, temperature_radii[260], false);
    jupiter_radii2 =
        planet_radius_helper2(temperature, 78.0, temperature_radii[78], 260.0,
                              temperature_radii[260]);
    jupiter_radii =
        rangeAdjust(temperature, jupiter_radii1, jupiter_radii2, 78.0, 260.0);
  } else if (temperature <= 260.0) {
    // jupiter_radii1 = planet_radius_helper(temperature, 0.0,
    // temperature_radii[0], 78.0, temperature_radii[78], 260.0,
    // temperature_radii[260], false);
    jupiter_radii1 =
        planet_radius_helper2(temperature, 78.0, temperature_radii[78], 260.0,
                              temperature_radii[260]);
    jupiter_radii2 = planet_radius_helper(
        temperature, 78.0, temperature_radii[78], 260.0, temperature_radii[260],
        875.0, temperature_radii[875], false);
    jupiter_radii =
        rangeAdjust(temperature, jupiter_radii1, jupiter_radii2, 78.0, 260.0);
  } else if (temperature <= 875.0) {
    jupiter_radii1 = planet_radius_helper(
        temperature, 78.0, temperature_radii[78], 260.0, temperature_radii[260],
        875.0, temperature_radii[875], false);
    jupiter_radii2 = planet_radius_helper(
        temperature, 260.0, temperature_radii[260], 875.0,
        temperature_radii[875], 1300.0, temperature_radii[1300], false);
    jupiter_radii =
        rangeAdjust(temperature, jupiter_radii1, jupiter_radii2, 260.0, 875.0);
  } else if (temperature <= 1300.0) {
    jupiter_radii1 = planet_radius_helper(
        temperature, 260.0, temperature_radii[260], 875.0,
        temperature_radii[875], 1300.0, temperature_radii[1300], false);
    jupiter_radii2 = planet_radius_helper(
        temperature, 875.0, temperature_radii[875], 1300.0,
        temperature_radii[1300], 1960.0, temperature_radii[1960], false);
    jupiter_radii =
        rangeAdjust(temperature, jupiter_radii1, jupiter_radii2, 875.0, 1300.0);
  } else if (temperature <= 1960.0) {
    jupiter_radii1 = planet_radius_helper(
        temperature, 875.0, temperature_radii[875], 1300.0,
        temperature_radii[1300], 1960.0, temperature_radii[1960], false);
    jupiter_radii2 =
        planet_radius_helper3(temperature, 1300.0, temperature_radii[1300],
                              1960.0, temperature_radii[1960]);
    jupiter_radii = rangeAdjust(temperature, jupiter_radii1, jupiter_radii2,
                                1300.0, 1960.0);
  } else {
    jupiter_radii =
        planet_radius_helper3(temperature, 1300.0, temperature_radii[1300],
                              1960.0, temperature_radii[1960]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("1 billion year old Gas Giants", the_planet, jupiter_radii,
                temperature_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_1960K_0core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-0.00117641848, 0.0813324707, 0,
    // total_earth_masses);
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(7.1355424E-5, -0.0110025236, 1.607128008,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(2.8438817E-5, -0.005723781, 1.455117388,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.059734E-6, 3.5292059E-4, 1.162108278,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-4.521665E-7, 1.4391737E-4, 1.178959162,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(2.523727E-7, -2.31602E-4, 1.227128508,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(4.6805591E-8, -7.084855E-5, 1.19679668,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(3.4235799E-8, -5.528714E-5, 1.192282405,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.296037E-8, 6.2880146E-5, 1.135085775,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-6.821523E-9, 7.2656677E-6, 1.179999679,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);

  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.853640017, -0.0898544185, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 1960k Gas Giants with 0 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_1960K_10core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[10] =
      radius_improved(10.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 10.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[10];
  } else if (total_earth_masses < 17.0) {
    /*double x[] = {10, 17, 28};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.726, 0.934}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-4.892024E-4, 0.0409231975, 0.1716851271,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-6.148051E-5, 0.0092717797, 0.7225908858,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-8.782026E-6, 0.0027898667, 0.9092489013,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-5.000519E-6, 0.002010876, 0.9468106187,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.281238E-6, 7.3144355E-4, 1.049964864,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-8.492542E-8, 9.3808937E-5, 1.131756756,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-3.88593E-8, 5.7785233E-5, 1.138553904,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(1.6290584E-8, -1.049032E-5, 1.158360213,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.687474E-8, 7.868923E-5, 1.115194546,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-7.226082E-9, 1.0979967E-5, 1.169876123,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.819655669, -0.0859477047, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 1960k Gas Giants with 10 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_1960K_25core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[25] =
      radius_improved(25.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 25.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[25];
  } else if (total_earth_masses < 28.0) {
    /*double x[] = {25, 28, 46};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.430, 0.756}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-2.563821E-4, 0.0370833882, -0.4073312852,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-4.275165E-5, 0.0108068403, 0.349347843,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-9.521402E-6, 0.0039614088, 0.679423913,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-2.345651E-6, 0.0014929505, 0.8784433657,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-5.621635E-7, 5.4325161E-4, 1.000380413,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.262685E-7, 2.0148169E-4, 1.064697598,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.257519E-8, 6.0729373E-5, 1.105528959,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.190564E-8, 1.0066608E-4, 1.086198356,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-8.940212E-9, 2.1527229E-5, 1.150110395,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.799663495, -0.0839943477, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 1960k Gas Giants with 25 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_1960K_50core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[50] =
      radius_improved(50.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 50.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[50];
  } else if (total_earth_masses < 77.0) {
    /*double x[] = {50, 77, 129};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.695, 0.891}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.779186E-5, 0.0074343548, 0.2280426421,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-4.280948E-6, 0.0027865995, 0.6027679149,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.064772E-6, 0.0010723781, 0.8226578179,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-3.134909E-7, 4.8487588E-4, 0.9335109194,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-5.39259E-8, 1.6353445E-4, 1.026730044,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-4.113328E-8, 1.371049E-4, 1.039522764,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-9.447662E-9, 2.7916272E-5, 1.127702819,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.713702623, -0.0742275631, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 1960k Gas Giants with 50 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_1960K_100core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[100] =
      radius_improved(100.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 100.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[100];
  } else if (total_earth_masses < 129.0) {
    /*double x[] = {100, 129, 215};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.613, 0.841}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-8.736311E-6, 0.0056564538, 0.0286984127,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-2.173076E-6, 0.0021582494, 0.4774268031,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-5.465498E-7, 8.8630602E-4, 0.7174239831,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.553096E-7, 4.0195069E-4, 0.8579324135,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-5.286988E-8, 1.9031025E-4, 0.9603729424,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.257775E-8, 5.146358E-5, 1.072504642,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.574765229, -0.0586007077, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 1960k Gas Giants with 100 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_1960K(long double core_earth_masses,
                                        long double total_earth_masses,
                                        planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> core_mass_radii;
  core_mass_radii[0] = gas_radius_4point5Gyr_1960K_0core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_1960K_0core_mass);
  core_mass_radii[10] = gas_radius_4point5Gyr_1960K_10core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_1960K_10core_mass);
  core_mass_radii[25] = gas_radius_4point5Gyr_1960K_25core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_1960K_25core_mass);
  core_mass_radii[50] = gas_radius_4point5Gyr_1960K_50core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_1960K_50core_mass);
  core_mass_radii[100] = gas_radius_4point5Gyr_1960K_100core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_1960K_100core_mass);
  if (core_earth_masses <= 10.0) {
    jupiter_radii = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
  } else if (core_earth_masses <= 25.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 10.0, 25.0);
  } else if (core_earth_masses <= 50.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 25.0, 50.0);
  } else if (core_earth_masses <= 100.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii2 =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 50.0, 100.0);
  } else {
    jupiter_radii =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 1960k Gas Giants", the_planet,
                jupiter_radii, core_mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_1300K_0core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  if (total_earth_masses < 17.0) {
    // jupiter_radii = quad_trend(-0.0024406035, 0.1063726127, 0,
    // total_earth_masses);
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(6.7398119E-5, -0.0064874608, 1.193808777,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(3.7853851E-5, -0.004301185, 1.15575576,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(4.2975874E-6, -1.737645E-4, 1.036899474,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-3.555132E-6, 0.0024438957, 0.9588984114,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.066205E-6, 5.8770477E-4, 1.027928803,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-5.047454E-8, 4.6320406E-5, 1.097374298,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(2.0350257E-8, -9.064586E-6, 1.107824639,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-7.821887E-9, 2.5812529E-5, 1.097707008,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.296686E-8, 5.7102052E-5, 1.082561909,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-4.301773E-9, -7.217854E-6, 1.134506262,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.788640017, -0.0898544185, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 1300k Gas Giants with 0 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_1300K_10core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  // pretty sure this is wrong
  // mass_radii[10] = jupiter_radii = radius_improved(10.0 /
  // SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(), the_planet->getRmf(),
  // the_planet->getCmf(), the_planet->getGasGiant(),
  // the_planet->getOrbitZone(), the_planet) / KM_JUPITER_RADIUS;
  mass_radii[10] =
      radius_improved(10.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 10.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[10];
  } else if (total_earth_masses < 17.0) {
    /*double x[] = {10, 17, 28};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.599, 0.775}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-3.544061E-4, 0.0319482759, 0.158302682,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-6.016385E-5, 0.0101743472, 0.5372867384,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-1.836378E-5, 0.0050329382, 0.6853425962,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-5.687563E-5, 0.002421638, 0.8112554348,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.741767E-6, 0.0010642841, 0.9206920943,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-2.983072E-7, 2.9492007E-4, 1.019381435,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-5.029421E-8, 1.0097391E-4, 1.05597625,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-2.809863E-8, 7.3495776E-5, 1.063947482,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.548231E-8, 6.8090476E-5, 1.066563814,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-5.008003E-9, -2.464E-6, 1.123543167,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.769647843, -0.0879010616, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 1300k Gas Giants with 10 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_1300K_25core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[25] =
      radius_improved(25.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 25.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[25];
  } else if (total_earth_masses < 28.0) {
    /*double x[] = {25, 28, 46};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.403, 0.686}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-2.155292E-4, 0.0316713847, -0.3148238607,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-3.762444E-5, 0.0097890968, 0.3153148674,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-9.126027E-6, 0.0039184232, 0.5983896321,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-2.529624E-6, 0.0016492603, 0.7813408846,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-6.860799E-7, 6.6665144E-4, 0.9073839815,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.368313E-7, 2.3713903E-4, 0.9884267135,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-4.917259E-8, 1.2861761E-4, 1.019908093,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.135386E-8, 9.1804101E-5, 1.037726971,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-5.916513E-9, 4.1470028E-6, 1.108518294,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    /// jupiter_radii = ln_trend(1.734663495, -0.0839943477,
    /// total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 1300k Gas Giants with 25 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_1300K_50core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[50] =
      radius_improved(50.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 50.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[50];
  } else if (total_earth_masses < 77.0) {
    /*double x[] = {50, 77, 129};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.648, 0.831}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.614879E-5, 0.0068458816, 0.2166132943,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-4.055163E-6, 0.0026856738, 0.5520300509,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.08774E-6, 0.0011040371, 0.7549127896,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-3.08161E-7, 4.9440659E-4, 0.8699411819,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-8.506302E-8, 2.1821125E-4, 0.9500637093,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.845194E-8, 1.2168549E-4, 0.996785166,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-7.229582E-9, 1.4472305E-5, 1.083369863,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.665694797, -0.0761809201, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 1300k Gas Giants with 50 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_1300K_100core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[100] =
      radius_improved(100.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 100.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[100];
  } else if (total_earth_masses < 129.0) {
    /*double x[] = {100, 129, 215};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.587, 0.798}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-7.94726E-6, 0.0051873457, 0.0500827554,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-2.033136E-6, 0.0020351177, 0.4544313939,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-5.165089E-7, 8.4911544E-4, 0.6782127358,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.692987E-7, 4.1926925E-4, 0.8029084081,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-4.952027E-8, 1.7180685E-4, 0.9226878251,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-9.855721E-9, 3.5122909E-5, 1.033073003,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.527757403, -0.0605540647, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 1300k Gas Giants with 100 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_1300K(long double core_earth_masses,
                                        long double total_earth_masses,
                                        planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> core_mass_radii;
  core_mass_radii[0] = gas_radius_4point5Gyr_1300K_0core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_1300K_0core_mass);
  core_mass_radii[10] = gas_radius_4point5Gyr_1300K_10core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_1300K_10core_mass);
  core_mass_radii[25] = gas_radius_4point5Gyr_1300K_25core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_1300K_25core_mass);
  core_mass_radii[50] = gas_radius_4point5Gyr_1300K_50core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_1300K_50core_mass);
  core_mass_radii[100] = gas_radius_4point5Gyr_1300K_100core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_1300K_100core_mass);
  if (core_earth_masses <= 10.0) {
    jupiter_radii = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
  } else if (core_earth_masses <= 25.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 10.0, 25.0);
  } else if (core_earth_masses <= 50.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 25.0, 50.0);
  } else if (core_earth_masses <= 100.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii2 =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 50.0, 100.0);
  } else {
    jupiter_radii =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 1300k Gas Giants", the_planet,
                jupiter_radii, core_mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_875K_0core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  if (total_earth_masses < 17.0) {
    // jupiter_radii = quad_trend(-0.0023768144, 0.1032293736, 0,
    // total_earth_masses);
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(8.6381052E-5, -0.0076144201, 1.172481017,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(3.745154E-5, -0.0039936362, 1.109459805,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(1.4200723E-6, 4.3823433E-4, 0.9818363479,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-3.357445E-6, 0.0014224028, 0.9343812709,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.158191E-6, 6.658597E-4, 0.995377562,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.3994E-7, 1.2313171E-4, 1.064995409,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(1.9478103E-8, -1.533247E-6, 1.088517869,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.561369E-8, 4.1910394E-5, 1.075915142,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.380751E-8, 5.8838828E-5, 1.067721256,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-3.797823E-9, -1.011456E-5, 1.123407579,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.773640017, -0.0898544185, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 875k Gas Giants with 0 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_875K_10core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[10] =
      radius_improved(10.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 10.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[10];
  } else if (total_earth_masses < 17.0) {
    /*double x[] = {10, 17, 28};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.592, 0.755}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-3.136538E-4, 0.0289326019, 0.1907917102,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-6.148051E-5, 0.0102717797, 0.5155908858,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-1.735478E-5, 0.0048443152, 0.6718842118,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-5.574136E-6, 0.0024175028, 0.7889013378,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.823599E-6, 0.001127318, 0.8929224842,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-3.487817E-7, 3.4124048E-4, 0.9937557337,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-5.82405E-8, 1.1403722E-4, 1.036625676,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-3.199453E-8, 8.1544708E-5, 1.046051549,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.632296E-8, 6.9827253E-5, 1.051723161,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-4.202383E-9, -6.40026E-6, 1.113284022,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.739655669, -0.0859477047, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 875k Gas Giants with 10 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_875K_25core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[25] =
      radius_improved(25.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 25.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[25];
  } else if (total_earth_masses < 28.0) {
    /*double x[] = {25, 28, 46};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.404, 0.675}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-2.058737E-4, 0.0302902129, -0.2827209421,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-3.552423E-5, 0.0093372223, 0.3206570451,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-8.902414E-6, 0.003853128, 0.5850915552,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-2.539778E-6, 0.0016643813, 0.7615592541,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-6.975635E-7, 6.8248095E-4, 0.8875114673,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.377034E-7, 2.4467036E-4, 0.9701199433,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-5.929592E-8, 1.476019E-4, 0.9982788934,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.079559E-8, 8.8720219E-5, 1.026779451,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-5.110893E-9, 2.1074347E-7, 1.098259148,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.70467132, -0.0820409908, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 875k Gas Giants with 25 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_875K_50core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[50] =
      radius_improved(50.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 50.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[50];
  } else if (total_earth_masses < 77.0) {
    /*double x[] = {50, 77, 129};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.639, 0.817}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.545202E-5, 0.0066061938, 0.2219381271,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-4.055163E-6, 0.0026856738, 0.5380300509,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.08774E-6, 0.0011040371, 0.7409127896,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-3.010869E-7, 4.8887461E-4, 0.856984985,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-9.129045E-8, 2.2914661E-4, 0.9323304424,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.778367E-8, 1.1860161E-4, 0.9858376464,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-6.725632E-9, 1.15756E-5, 1.07227118,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.650694797, -0.0761809201, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 875k Gas Giants with 50 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_875K_100core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[100] =
      radius_improved(100.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 100.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[100];
  } else if (total_earth_masses < 129.0) {
    /*double x[] = {100, 129, 215};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.582, 0.788}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-7.742381E-6, 0.0050587279, 0.058265064,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.955154E-6, 0.0019741359, 0.4539377689,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-5.165089E-7, 8.4911544E-4, 0.6662127358,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.716303E-7, 4.2215568E-4, 0.7900710739,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-4.896201E-8, 1.6872307E-4, 0.9127403055,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-9.351771E-9, 3.2226204E-5, 1.022974319,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.513757404, -0.0605540647, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 875k Gas Giants with 100 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_875K(long double core_earth_masses,
                                       long double total_earth_masses,
                                       planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> core_mass_radii;
  core_mass_radii[0] = gas_radius_4point5Gyr_875K_0core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_875K_0core_mass);
  core_mass_radii[10] = gas_radius_4point5Gyr_875K_10core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_875K_10core_mass);
  core_mass_radii[25] = gas_radius_4point5Gyr_875K_25core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_875K_25core_mass);
  core_mass_radii[50] = gas_radius_4point5Gyr_875K_50core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_875K_50core_mass);
  core_mass_radii[100] = gas_radius_4point5Gyr_875K_100core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_875K_100core_mass);
  if (core_earth_masses <= 10.0) {
    jupiter_radii = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
  } else if (core_earth_masses <= 25.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 10.0, 25.0);
  } else if (core_earth_masses <= 50.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 25.0, 50.0);
  } else if (core_earth_masses <= 100.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii2 =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 50.0, 100.0);
  } else {
    jupiter_radii =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 875k Gas Giants", the_planet,
                jupiter_radii, core_mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_260K_0core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  if (total_earth_masses < 17.0) {
    // jupiter_radii = quad_trend(-0.0021984339, 0.0970204354, 0,
    // total_earth_masses);
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(4.6673633E-5, -0.0040094044, 1.068671195,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(2.9771048E-5, -0.0027586131, 1.0469900666,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-1.846094E-6, 0.0011302954, 0.9349127478,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-3.412538E-6, 0.0014529828, 0.9193532609,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.116977E-6, 6.6330976E-4, 0.9830206503,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.904145E-7, 1.6945211E-4, 1.046369708,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(4.4576753E-9, 1.7062043E-5, 1.075123492,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.561369E-8, 4.1910394E-5, 1.067915142,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.464816E-8, 6.0575605E-5, 1.058880602,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-2.992203E-9, -1.405082E-5, 1.119148433,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.749647843, -0.0879010616, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 260k Gas Giants with 0 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_260K_10core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[10] =
      radius_improved(10.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 10.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[10];
  } else if (total_earth_masses < 17.0) {
    /*double x[] = {10, 17, 28};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.576, 0.738}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-3.028561E-4, 0.0283557994, 0.1814768373,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-6.4699E-5, 0.0107321703, 0.4882232463,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-1.813208E-5, 0.0050044396, 0.6531632635,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-5.489876E-6, 0.0024001452, 0.7787382943,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.833753E-6, 0.001142439, 0.8801408538,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-3.877727E-7, 3.7173137E-4, 0.9790025462,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-5.116636E-8, 1.0850524E-4, 1.028669479,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-3.589043E-8, 8.9593641E-5, 1.034155616,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.632296E-8, 6.9827253E-5, 1.043723161,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-4.202383E-9, -6.40026E-6, 1.105284022,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.731655669, -0.0859477047, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 260k Gas Giants with 10 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_260K_25core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[25] =
      radius_improved(25.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 25.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[25];
  } else if (total_earth_masses < 28.0) {
    /*double x[] = {25, 28, 46};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.400, 0.666}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-2.002048E-4, 0.0295929339, -0.2716415771,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-3.575593E-5, 0.0093657209, 0.3108363778,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-8.6788E-6, 0.0037878328, 0.5797934783,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-2.549932E-6, 0.0016795023, 0.7497776237,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-7.365544E-7, 7.1297185E-4, 0.8737582798,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.377034E-7, 2.4467036E-4, 0.9621199433,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-5.929592E-8, 1.476019E-4, 0.9902788934,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.079559E-8, 8.8720219E-5, 1.018779451,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-5.110893E-9, 2.1074347E-7, 1.090259148,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.69667132, -0.0820409908, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 260k Gas Giants with 25 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_260K_50core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[50] =
      radius_improved(50.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 50.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[50];
  } else if (total_earth_masses < 77) {
    /*double x[] = {50, 77, 129};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.633, 0.810}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.539693E-5, 0.0065756138, 0.2179661371,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-3.99364E-6, 0.0026528819, 0.5342364001,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.08774E-6, 0.0011040371, 0.7329127896,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-2.940128E-7, 4.8334264E-4, 0.8500287881,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-9.751787E-8, 2.4008197E-4, 0.9205971755,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-3.638476E-8, 1.1378095E-4, 0.9817307806,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-6.423962E-9, 1.0536045E-5, 1.065110718,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.627702623, -0.0742275631, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 260k Gas Giants with 50 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_260K_100core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[100] =
      radius_improved(100.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 100.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[100];
  } else if (total_earth_masses < 129.0) {
    /*double x[] = {100, 129, 215};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.578, 0.782}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-7.619334E-6, 0.004993144, 0.0606777624,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.982661E-6, 0.0019887973, 0.4460570955,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-5.014885E-7, 8.3052015E-4, 0.6646071121,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.739619E-7, 4.250421E-4, 0.7822337397,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-4.756309E-8, 1.6390241E-4, 0.9086334397,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-9.351771E-9, 3.2226204E-5, 1.014974319,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.505757403, -0.0605540647, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 260k Gas Giants with 100 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_260K(long double core_earth_masses,
                                       long double total_earth_masses,
                                       planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> core_mass_radii;
  core_mass_radii[0] = gas_radius_4point5Gyr_260K_0core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_260K_0core_mass);
  core_mass_radii[10] = gas_radius_4point5Gyr_260K_10core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_260K_10core_mass);
  core_mass_radii[25] = gas_radius_4point5Gyr_260K_25core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_260K_25core_mass);
  core_mass_radii[50] = gas_radius_4point5Gyr_260K_50core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_260K_50core_mass);
  core_mass_radii[100] = gas_radius_4point5Gyr_260K_100core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_260K_100core_mass);
  if (core_earth_masses <= 10.0) {
    jupiter_radii = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
  } else if (core_earth_masses <= 25.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 10.0, 25.0);
  } else if (core_earth_masses <= 50.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 25.0, 50.0);
  } else if (core_earth_masses <= 100.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii2 =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 50.0, 100.0);
  } else {
    jupiter_radii =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 260k Gas Giants", the_planet,
                jupiter_radii, core_mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_78K_0core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  if (total_earth_masses < 17.0) {
    // jupiter_radii = quad_trend(-0.0015823147, 0.0738405271, 0,
    // total_earth_masses);
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-1.619645E-5, 0.0033652038, 0.7454723093,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 0.0, mass_radii[0], 17.0,
                             mass_radii[17], 28.0, mass_radii[28]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-1.327628E-5, 0.0031491113, 0.7492334869,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-8.07199E-6, 0.0025089838, 0.7676670752,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-3.013922E-6, 0.0014670219, 0.8179088629,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-9.921382E-7, 7.7152808E-4, 0.8739830482,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-4.796417E-7, 4.9836746E-4, 0.9090224331,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-1.359591E-7, 2.2960769E-4, 0.9597334837,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-6.003298E-8, 1.3561116E-4, 0.9870012845,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-1.427802E-8, 4.1081391E-5, 1.032756619,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-6.125792E-9, 1.2988829E-5, 1.055443997,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.534749577, -0.0625074216, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 78k Gas Giants with 0 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_78K_10core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[10] =
      radius_improved(10.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 10.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[10];
  } else if (total_earth_masses < 17.0) {
    /*double x[] = {10, 17, 28};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.508, 0.653}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
  } else if (total_earth_masses < 28.0) {
    // jupiter_radii = quad_trend(-2.514803E-4, 0.0244984326, 0.1642044584,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 10.0, mass_radii[10], 17.0,
                             mass_radii[17], 28.0, mass_radii[28], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 17.0, 28.0);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-6.422354E-5, 0.0106414308, 0.405391193,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 17.0, mass_radii[17], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-1.751173E-5, 0.0048958788, 0.5708444049,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-4.702367E-6, 0.0022571492, 0.6980798495,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-1.688606E-6, 0.0012204153, 0.7816665126,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-5.99018E-7, 6.3966492E-4, 0.8561616467,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-2.057314E-7, 3.3211484E-4, 0.9141918645,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-7.251792E-8, 1.6719654E-4, 0.9620336238,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-1.679346E-8, 5.2069816E-5, 1.017758524,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-6.832022E-9, 1.7742682E-5, 1.045480902,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.516757403, -0.0605540647, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 78k Gas Giants with 10 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_78K_25core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[25] =
      radius_improved(25.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 25.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[25];
  } else if (total_earth_masses < 28.0) {
    /*double x[] = {25, 28, 46};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.378, 0.611}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46], false);
  } else if (total_earth_masses < 46.0) {
    // jupiter_radii = quad_trend(-1.726648E-4, 0.025721637, -0.2068366615,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 25.0, mass_radii[25], 28.0,
                             mass_radii[28], 46.0, mass_radii[46]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 28.0, 46.0);
  } else if (total_earth_masses < 77.0) {
    // jupiter_radii = quad_trend(-3.108464E-5, 0.0083072812, 0.2946401537,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 28.0, mass_radii[28], 46.0,
                             mass_radii[46], 77.0, mass_radii[77]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 46.0, 77.0);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-7.307952E-6, 0.0034092842, 0.5308139632,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 46.0, mass_radii[46], 77.0,
                             mass_radii[77], 129.0, mass_radii[129]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-2.374322E-6, 0.0017121157, 0.6676481738,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-5.608282E-9, 4.4959116E-4, 0.8295971443,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-9.904761E-7, 0.0012197578, 0.684277931,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(4.2764664E-8, -5.939427E-5, 1.055351879,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.350566E-8, 7.7520217E-5, 0.989081027,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-7.236581E-9, 2.1456981E-5, 1.034357345,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.481773054, -0.0566473508, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 78k Gas Giants with 25 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_78K_50core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[50] =
      radius_improved(50.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 50.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[50];
  } else if (total_earth_masses < 77.0) {
    /*double x[] = {50, 77, 129};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.594, 0.754}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
  } else if (total_earth_masses < 129.0) {
    // jupiter_radii = quad_trend(-1.294366E-5, 0.0057433175, 0.2285075251,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 50.0, mass_radii[50], 77.0,
                             mass_radii[77], 129.0, mass_radii[129], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 77.0, 129.0);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-3.69558E-6, 0.0025619773, 0.4850030821,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 77.0, mass_radii[77], 129.0,
                             mass_radii[129], 215.0, mass_radii[215]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.085603E-6, 0.0011708593, 0.6634472108,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-4.088464E-7, 6.4163566E-4, 0.7633040398,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.123343E-7, 2.7455378E-4, 0.8697921805,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-2.909482E-8, 1.0258095E-4, 0.9530323566,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-8.851321E-9, 3.2821838E-5, 1.009369377,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.428796532, -0.05078728, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 78k Gas Giants with 50 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_78K_100core_mass(
    long double total_earth_masses, planet *the_planet,
    map<int, long double> &mass_radii) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  mass_radii[100] =
      radius_improved(100.0 / SUN_MASS_IN_EARTH_MASSES, the_planet->getImf(),
                      the_planet->getRmf(), the_planet->getCmf(),
                      the_planet->getGasGiant(), the_planet->getOrbitZone(),
                      the_planet) /
      KM_JUPITER_RADIUS;
  if (total_earth_masses < 100.0) {
    // jupiter_radii = radius_improved(the_planet->getMass(),
    // the_planet->getImf(), the_planet->getRmf(), the_planet->getCmf(),
    // the_planet->getGasGiant(), the_planet->getOrbitZone(), the_planet) /
    // KM_JUPITER_RADIUS;
    jupiter_radii = mass_radii[100];
  } else if (total_earth_masses < 129.0) {
    /*double x[] = {100, 129, 215};
    double y[] = {radius_improved(the_planet->getMass(), the_planet->getImf(),
    the_planet->getRmf(), the_planet->getCmf(), the_planet->getGasGiant(),
    the_planet->getOrbitZone()) / KM_JUPITER_RADIUS, 0.558, 0.746}; double
    coeff[3]; polynomialfit(3, 3, x, y, coeff); jupiter_radii =
    quad_trend(coeff[2], coeff[1], coeff[0], total_earth_masses);*/
    jupiter_radii =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
  } else if (total_earth_masses < 215.0) {
    // jupiter_radii = quad_trend(-6.634961E-6, 0.0044684732, 0.0919793497,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 100.0, mass_radii[100], 129.0,
                             mass_radii[129], 215.0, mass_radii[215], false);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 129.0, 215.0);
  } else if (total_earth_masses < 318.0) {
    // jupiter_radii = quad_trend(-1.845125E-6, 0.0019154904, 0.4194604624,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 129.0, mass_radii[129], 215.0,
                             mass_radii[215], 318.0, mass_radii[318]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 215.0, 318.0);
  } else if (total_earth_masses < 464.0) {
    // jupiter_radii = quad_trend(-5.765906E-7, 9.234966E-4, 0.6066352304,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 215.0, mass_radii[215], 318.0,
                             mass_radii[318], 464.0, mass_radii[464]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 318.0, 464.0);
  } else if (total_earth_masses < 774.0) {
    // jupiter_radii = quad_trend(-1.692987E-7, 4.1926925E-4, 0.7529084081,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 318.0, mass_radii[318], 464.0,
                             mass_radii[464], 774.0, mass_radii[774]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 464.0, 774.0);
  } else if (total_earth_masses < 1292.0) {
    // jupiter_radii = quad_trend(-4.11138E-8, 1.5443919E-4, 0.881094362,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 464.0, mass_radii[464], 774.0,
                             mass_radii[774], 1292.0, mass_radii[1292]);
    jupiter_radii2 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 774.0, 1292.0);
  } else if (total_earth_masses < 2154.0) {
    // jupiter_radii = quad_trend(-1.127518E-8, 5.1615293E-5, 0.9641342947,
    // total_earth_masses);
    jupiter_radii1 =
        planet_radius_helper(total_earth_masses, 774.0, mass_radii[774], 1292.0,
                             mass_radii[1292], 2154.0, mass_radii[2154]);
    jupiter_radii2 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 1292.0, 2154.0);
  } else if (total_earth_masses < 3594.0) {
    jupiter_radii1 = planet_radius_helper(
        total_earth_masses, 1292.0, mass_radii[1292], 2154.0, mass_radii[2154],
        3594.0, mass_radii[3594]);
    jupiter_radii2 = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
    jupiter_radii = rangeAdjust(total_earth_masses, jupiter_radii1,
                                jupiter_radii2, 2154.0, 3594.0);
  } else {
    // jupiter_radii = ln_trend(1.307851312, -0.0371137816, total_earth_masses);
    jupiter_radii = planet_radius_helper2(
        total_earth_masses, 2154.0, mass_radii[2154], 3594.0, mass_radii[3594]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 78k Gas Giants with 100 EU core",
                the_planet, jupiter_radii, mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr_78K(long double core_earth_masses,
                                      long double total_earth_masses,
                                      planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> core_mass_radii;
  core_mass_radii[0] = gas_radius_4point5Gyr_78K_0core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_78K_0core_mass);
  core_mass_radii[10] = gas_radius_4point5Gyr_78K_10core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_78K_10core_mass);
  core_mass_radii[25] = gas_radius_4point5Gyr_78K_25core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_78K_25core_mass);
  core_mass_radii[50] = gas_radius_4point5Gyr_78K_50core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_78K_50core_mass);
  core_mass_radii[100] = gas_radius_4point5Gyr_78K_100core_mass(
      total_earth_masses, the_planet, gas_4point5Gyr_78K_100core_mass);
  if (core_earth_masses <= 10.0) {
    jupiter_radii = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
  } else if (core_earth_masses <= 25.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 0.0, core_mass_radii[0], 10.0, core_mass_radii[10],
        25.0, core_mass_radii[25], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 10.0, 25.0);
  } else if (core_earth_masses <= 50.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 10.0, core_mass_radii[10], 25.0, core_mass_radii[25],
        50.0, core_mass_radii[50], false);
    jupiter_radii2 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 25.0, 50.0);
  } else if (core_earth_masses <= 100.0) {
    jupiter_radii1 = planet_radius_helper(
        core_earth_masses, 25.0, core_mass_radii[25], 50.0, core_mass_radii[50],
        100.0, core_mass_radii[100], false);
    jupiter_radii2 =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
    jupiter_radii = rangeAdjust(core_earth_masses, jupiter_radii1,
                                jupiter_radii2, 50.0, 100.0);
  } else {
    jupiter_radii =
        planet_radius_helper2(core_earth_masses, 50.0, core_mass_radii[50],
                              100.0, core_mass_radii[100]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old 78k Gas Giants", the_planet,
                jupiter_radii, core_mass_radii);
  }
  return jupiter_radii;
}

long double gas_radius_4point5Gyr(long double temperature,
                                  long double core_earth_masses,
                                  long double total_earth_masses,
                                  planet *the_planet) {
  long double jupiter_radii = 0.0;
  long double jupiter_radii1 = 0.0;
  long double jupiter_radii2 = 0.0;
  map<int, long double> temperature_radii;
  temperature_radii[1960] = gas_radius_4point5Gyr_1960K(
      core_earth_masses, total_earth_masses, the_planet);
  temperature_radii[1300] = gas_radius_4point5Gyr_1300K(
      core_earth_masses, total_earth_masses, the_planet);
  temperature_radii[875] = gas_radius_4point5Gyr_875K(
      core_earth_masses, total_earth_masses, the_planet);
  temperature_radii[260] = gas_radius_4point5Gyr_260K(
      core_earth_masses, total_earth_masses, the_planet);
  temperature_radii[78] = gas_radius_4point5Gyr_78K(
      core_earth_masses, total_earth_masses, the_planet);
  temperature_radii[0] = 0.0;
  if (temperature <= 78.0) {
    jupiter_radii1 = planet_radius_helper(
        temperature, 0.0, temperature_radii[0], 78.0, temperature_radii[78],
        260.0, temperature_radii[260], false);
    jupiter_radii2 =
        planet_radius_helper2(temperature, 78.0, temperature_radii[78], 260.0,
                              temperature_radii[260]);
    jupiter_radii =
        rangeAdjust(temperature, jupiter_radii1, jupiter_radii2, 78.0, 260.0);
  } else if (temperature <= 260.0) {
    // jupiter_radii1 = planet_radius_helper(temperature, 0.0,
    // temperature_radii[0], 78.0, temperature_radii[78], 260.0,
    // temperature_radii[260], false);
    jupiter_radii1 =
        planet_radius_helper2(temperature, 78.0, temperature_radii[78], 260.0,
                              temperature_radii[260]);
    jupiter_radii2 = planet_radius_helper(
        temperature, 78.0, temperature_radii[78], 260.0, temperature_radii[260],
        875.0, temperature_radii[875], false);
    jupiter_radii =
        rangeAdjust(temperature, jupiter_radii1, jupiter_radii2, 78.0, 260.0);
  } else if (temperature <= 875.0) {
    jupiter_radii1 = planet_radius_helper(
        temperature, 78.0, temperature_radii[78], 260.0, temperature_radii[260],
        875.0, temperature_radii[875], false);
    jupiter_radii2 = planet_radius_helper(
        temperature, 260.0, temperature_radii[260], 875.0,
        temperature_radii[875], 1300.0, temperature_radii[1300], false);
    jupiter_radii =
        rangeAdjust(temperature, jupiter_radii1, jupiter_radii2, 260.0, 875.0);
  } else if (temperature <= 1300.0) {
    jupiter_radii1 = planet_radius_helper(
        temperature, 260.0, temperature_radii[260], 875.0,
        temperature_radii[875], 1300.0, temperature_radii[1300], false);
    jupiter_radii2 = planet_radius_helper(
        temperature, 875.0, temperature_radii[875], 1300.0,
        temperature_radii[1300], 1960.0, temperature_radii[1960], false);
    jupiter_radii =
        rangeAdjust(temperature, jupiter_radii1, jupiter_radii2, 875.0, 1300.0);
  } else if (temperature <= 1960.0) {
    jupiter_radii1 = planet_radius_helper(
        temperature, 875.0, temperature_radii[875], 1300.0,
        temperature_radii[1300], 1960.0, temperature_radii[1960], false);
    jupiter_radii2 =
        planet_radius_helper3(temperature, 1300.0, temperature_radii[1300],
                              1960.0, temperature_radii[1960]);
    jupiter_radii = rangeAdjust(temperature, jupiter_radii1, jupiter_radii2,
                                1300.0, 1960.0);
  } else {
    jupiter_radii =
        planet_radius_helper3(temperature, 1300.0, temperature_radii[1300],
                              1960.0, temperature_radii[1960]);
  }
  if (flag_verbose & 0x80000) {
    radiusDebug("4.5 billion year old Gas Giants", the_planet, jupiter_radii,
                temperature_radii);
  }
  return jupiter_radii;
}

long double mini_neptune_radius(planet *the_planet) {
  long double core_radius = the_planet->getCoreRadius();
  long double core_radius_eu, env_radius_eu, total_radius_eu, total_radius,
      flux, atmospere_radius;
  if (core_radius <= 0.0) {
    core_radius = radius_improved(
        the_planet->getDustMass(), the_planet->getImf(), the_planet->getRmf(),
        the_planet->getCmf(), the_planet->getGasGiant(),
        the_planet->getOrbitZone(), the_planet);
    the_planet->setCoreRadius(core_radius);
  }
  core_radius_eu = core_radius / KM_EARTH_RADIUS;
  if (the_planet->getTheSun().getAge() == 0) {
    the_planet->setTheSun(the_sun_clone);
  }
  flux = calcLuminosity(
      the_planet);  // I'm guessing this how to calculate the flux...
  env_radius_eu =
      2.06 * std::pow(the_planet->getMass() * SUN_MASS_IN_EARTH_MASSES, -0.21) *
      std::pow((the_planet->getGasMass() / the_planet->getMass()) / 0.05, 0.59) *
      std::pow(flux, 0.044) * std::pow(the_planet->getTheSun().getAge() / 5.0E9, -0.18);
  total_radius_eu = core_radius_eu + env_radius_eu;
  total_radius = total_radius_eu * KM_EARTH_RADIUS;
  return total_radius;
}

long double gas_dwarf_radius(planet *the_planet) {
  long double gas_density;
  long double atmosphere_height;
  long double radius;
  std::vector<double> x = {
      48.1,   60.3,   540.1,  166.3, 239.9, 347.9,  969.8, 106.9, 318.2,
      581.0,  407.7,  409.7,  237.2, 984.1, 709.9,  549.9, 684.9, 406.5,
      171.8,  340.0,  1123.6, 790.9, 93.1,  89.8,   875.5, 635.7, 239.0,
      1474.7, 1485.2, 861.5,  436.2, 650.3, 1186.0, 506.4, 754.4, 621.4,
      367.1,  418.5,  1076.0, 585.7, 331.7, 299.2,  907.4, 419.2, 282.9,
      355.1,  528.8,  355.0,  245.3, 959.7, 697.5,  911.1, 729.8, 759.6,
      771.9,  605.5,  534.5,  584.9, 701.2, 1128.3, 559.9, 685.9, 1045.8,
      425.4,  74.6,   153.3,  532.4, 759.5, 600.2,  478.2, 634.3, 509.8,
      751.7,  519.6,  796.3,  556.9, 770.9, 330.4,  391.9, 636.3, 630.8,
      1336.0, 386.9,  417.3,  928.2, 520.3, 386.4,  79.8,  617.8, 581.9,
      560.1,  769.4,  522.8,  465.9, 680.0, 828.0,  459.9, 397.3, 479.9,
      746.3,  1102.9, 817.0,  842.9, 801.2, 1001.4, 595.0};
  int array_size = sizeof(x) / sizeof(double);
  std::vector<double> y = {1.638,
                1.27,
                0.09 * EARTH_DENSITY,
                0.09 * EARTH_DENSITY,
                0.1 * EARTH_DENSITY,
                0.1 * EARTH_DENSITY,
                0.1 * EARTH_DENSITY,
                0.11 * EARTH_DENSITY,
                0.07 * EARTH_DENSITY,
                0.11 * EARTH_DENSITY,
                0.11 * EARTH_DENSITY,
                0.12 * EARTH_DENSITY,
                0.12 * EARTH_DENSITY,
                0.13 * EARTH_DENSITY,
                0.13 * EARTH_DENSITY,
                0.13 * EARTH_DENSITY,
                0.14 * EARTH_DENSITY,
                0.14 * EARTH_DENSITY,
                0.14 * EARTH_DENSITY,
                0.14 * EARTH_DENSITY,
                0.14 * EARTH_DENSITY,
                0.2 * EARTH_DENSITY,
                0.15 * EARTH_DENSITY,
                0.15 * EARTH_DENSITY,
                0.15 * EARTH_DENSITY,
                0.15 * EARTH_DENSITY,
                0.15 * EARTH_DENSITY,
                0.38 * EARTH_DENSITY,
                0.15 * EARTH_DENSITY,
                0.15 * EARTH_DENSITY,
                0.15 * EARTH_DENSITY,
                0.34 * EARTH_DENSITY,
                0.17 * EARTH_DENSITY,
                0.17 * EARTH_DENSITY,
                0.17 * EARTH_DENSITY,
                0.17 * EARTH_DENSITY,
                0.17 * EARTH_DENSITY,
                0.17 * EARTH_DENSITY,
                0.17 * EARTH_DENSITY,
                0.17 * EARTH_DENSITY,
                0.18 * EARTH_DENSITY,
                0.18 * EARTH_DENSITY,
                0.07 * EARTH_DENSITY,
                0.18 * EARTH_DENSITY,
                0.18 * EARTH_DENSITY,
                0.18 * EARTH_DENSITY,
                0.18 * EARTH_DENSITY,
                0.18 * EARTH_DENSITY,
                0.19 * EARTH_DENSITY,
                0.19 * EARTH_DENSITY,
                0.19 * EARTH_DENSITY,
                0.1 * EARTH_DENSITY,
                0.05 * EARTH_DENSITY,
                0.2 * EARTH_DENSITY,
                0.2 * EARTH_DENSITY,
                0.2 * EARTH_DENSITY,
                0.21 * EARTH_DENSITY,
                0.21 * EARTH_DENSITY,
                0.21 * EARTH_DENSITY,
                0.21 * EARTH_DENSITY,
                0.21 * EARTH_DENSITY,
                0.21 * EARTH_DENSITY,
                0.21 * EARTH_DENSITY,
                0.21 * EARTH_DENSITY,
                0.21 * EARTH_DENSITY,
                0.21 * EARTH_DENSITY,
                0.22 * EARTH_DENSITY,
                0.22 * EARTH_DENSITY,
                0.22 * EARTH_DENSITY,
                0.22 * EARTH_DENSITY,
                0.14 * EARTH_DENSITY,
                0.22 * EARTH_DENSITY,
                0.22 * EARTH_DENSITY,
                0.22 * EARTH_DENSITY,
                0.22 * EARTH_DENSITY,
                0.22 * EARTH_DENSITY,
                0.23 * EARTH_DENSITY,
                0.23 * EARTH_DENSITY,
                0.23 * EARTH_DENSITY,
                0.23 * EARTH_DENSITY,
                0.23 * EARTH_DENSITY,
                0.23 * EARTH_DENSITY,
                0.24 * EARTH_DENSITY,
                0.24 * EARTH_DENSITY,
                0.24 * EARTH_DENSITY,
                0.24 * EARTH_DENSITY,
                0.24 * EARTH_DENSITY,
                0.24 * EARTH_DENSITY,
                0.25 * EARTH_DENSITY,
                0.25 * EARTH_DENSITY,
                0.25 * EARTH_DENSITY,
                0.25 * EARTH_DENSITY,
                0.25 * EARTH_DENSITY,
                0.25 * EARTH_DENSITY,
                0.25 * EARTH_DENSITY,
                0.25 * EARTH_DENSITY,
                0.26 * EARTH_DENSITY,
                0.26 * EARTH_DENSITY,
                0.26 * EARTH_DENSITY,
                0.26 * EARTH_DENSITY,
                0.26 * EARTH_DENSITY,
                0.26 * EARTH_DENSITY,
                0.27 * EARTH_DENSITY,
                0.27 * EARTH_DENSITY,
                0.27 * EARTH_DENSITY,
                0.27 * EARTH_DENSITY};
  double coeff[3];
  //polynomialfit(array_size, 3, x, y, coeff);
  polyRegression(x, y, coeff);
  gas_density =
      quad_trend(coeff[2], coeff[1], coeff[0], the_planet->getEstimatedTemp());
  atmosphere_height = volume_radius(the_planet->getGasMass(), gas_density);
  radius = the_planet->getCoreRadius() + atmosphere_height;
  return radius;
}