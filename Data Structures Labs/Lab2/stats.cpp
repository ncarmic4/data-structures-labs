/*
* Class: CS 3305 Section 01
* Term: Spring 2020
* Name: Nicholas Carmichael
* Instructor: Deepa Muralidhar
* Assignment: Lab 2
*/

#include <cstdlib>;
#include "stats.h";

// implementation of stats.h statistician class

statistician::statistician() {
	reset();
}

void statistician::next(double r) {
	count++;
	total += r;

	// if there is only one number, it is both largest and tinyest
	if (count == 1) {
		largest = r;
		tinyest = r;
	}

	if (r > largest)
		largest = r;

	if (r < tinyest)
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
