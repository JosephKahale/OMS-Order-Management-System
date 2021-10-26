#ifndef ONEDAYSHIP_H
#define ONEDAYSHIP_H

#include "Package.h"

class OneDayPackage : public Package {
private:
	double flatFlee;
public:
	OneDayPackage(const string& = "N/A", const string& = "N/A", const string& = "N/A", const string& = "N/A", int = 0, const string& = "N/A", const string& = "N/A", const string& = "N/A", const string& = "N/A", int = 0, double = 0, double = 0, double = 0);
	OneDayPackage& setFlatFee(double);
	virtual double calculateCost() const;
	double getFlatFee() const;

};
#endif // !ONEDAYSHIP_H
