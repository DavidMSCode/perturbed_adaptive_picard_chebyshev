/*
*  AUTHORS:          David Stanley (davidms4@illinois.edu)
*  DATE WRITTEN:     Feb 2022
*  LAST MODIFIED:    Feb 2022
*  AFFILIATION:      Department of Aerospace Engineering, University of Illinois Urbana-Champaign
*  DESCRIPTION:      Class that stores orbit solution and properties
*  REFERENCE:        Woollands, R., and Junkins, J., "Nonlinear Differential Equation Solvers
*                    via Adaptive Picard-Chebyshev Iteration: Applications in Astrodynamics", JGCD, 2016.
*
*/


#include "Orbit.h"
#include <vector>


//Orbit Constructors
Orbit::Orbit(std::vector<std::vector<double > > Solution){
    SetSolution(Solution);
}
Orbit::Orbit(double area, double reflectivity, double mass, double Cd, bool compute_drag, bool compute_SRP, bool compute_third_body){
    SetProperties(area, reflectivity, mass, Cd, compute_drag, compute_SRP, compute_third_body);
    suborbital = false;
}

//Setter Functions
void Orbit::SetSolution(std::vector<std::vector<double > > Solution){
    Soln = Solution;
}

void Orbit::SetProperties(double area, double reflectance, double mass, double Cd, bool compute_drag, bool compute_SRP, bool compute_third_body){
    //Set satellite properties and flags for perturbations
    satproperties.Area = area;
    satproperties.Mass = mass;
    satproperties.Reflectance = reflectance;
    satproperties.Cd = Cd;
    //Perturbation flags
    Compute_Drag = compute_drag;
    Compute_SRP = compute_SRP;
    Compute_Third_Body = compute_third_body;
}

void Orbit::SetSubOrbital(){
    suborbital = true;
}