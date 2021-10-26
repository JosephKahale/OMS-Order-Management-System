#ifndef THREEDAYSHIP_H
#define THREEDAYSHIP_H

#include "Package.h"

class ThreeDayPackage : public Package {
private:
	double flatFlee;
public:
	ThreeDayPackage(const string& = "N/A", const string& = "N/A", const string& = "N/A", const string& = "N/A", int = 0, const string& = "N/A", const string& = "N/A", const string& = "N/A", const string& = "N/A", int = 0, double = 0, double = 0, double = 0);
	ThreeDayPackage& setFlatFee(double);
	virtual double calculateCost() const;
	double getFlatFee() const;

};
#endif // !THREEDAYSHIP_H
