#ifndef SINUSOID_H
#define SINUSOID_H
// Logic Layer: Represents and evaluates sinusoidal functions.
class Sinusoid
{
public:
	Sinusoid(float amplitude=1.0, float frequency = 1.0, float phase=0.0):
	amplitude_(amplitude),
	frequency_(frequency),
	phase_(phase)
	{}

	float evaluate(float x) const;

private:
	float amplitude_;
	float frequency_;
	float phase_;
};

#endif