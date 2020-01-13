#include <cstdlib>;
#include <iostream>;
#include "stats.h";

statistician::statistician() {
	//make sure object is reset
	reset();
}

void statistician::next(double r) {
	count++;
	total += r;

	//if there is only one number, it is both largest and tinyest
	if (count == 1) {
		largest = r;
		tinyest = r;
	}

	if (r >= largest)
		largest = r;

	if (r <= tinyest)
		tinyest = r;
}

void statistician::reset() {
	count = 0;
	total = 0;
	tinyest = 0;
	largest = 0;
}

int statistician::length() const {
	return count;
}

double statistician::sum() const {
	return total;
}

double statistician::mean() const {
	if (count > 0) {
		double mean = total / count;
		return mean;
	}
}

double statistician::minimum() const {
	if (count > 0)
		return tinyest;
}

double statistician::maximum() const {
	if (count > 0)
		return largest;
}
