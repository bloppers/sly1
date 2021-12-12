#include <util.h>
#include <math.h>

/* Clamp the float to fall inside range given by the limit */
float GLimitLm(LM* plm, float g)
{
	float result = plm->gMin;

	if ((result <= g) &&
		(result = plm->gMax, g <= plm->gMax))
	{
		result = g;
	}

	return result;
}

/* Clamp the float to fall within the range [-absLimit, absLimit] */
float GLimitAbs(float g, float absLimit)
{
	if (g <= absLimit)
	{
		if (g < -absLimit)
		{
			g = -absLimit;
		}
		return g;
	}
	return absLimit;
}

/* Return true if the float falls within the given limit, otherwise false */
BOOL FCheckLm(LM* plm, float g)

{
	if ((plm->gMin < g) && (g < plm->gMax))
	{
		return true;
	}
	return false;
}


float GModPositive(float gDividend, float gDivisor)
{
	float result;

	result = fmodf(gDividend, gDivisor);
	if (result < 0.0) {
		result = result + gDivisor;
	}
	return result;
}