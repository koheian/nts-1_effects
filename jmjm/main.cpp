// reference: https://github.com/kinoshita-lab/nts-1_simple_examples
#include <cstdint>
#include "userrevfx.h"

void REVFX_INIT(uint32_t platform, uint32_t api) {
}

void REVFX_PROCESS(float *xn, uint32_t frames) {
    for (auto i = 0u; i < frames;  ++i) {
	float *l_input = xn++;
	float *r_input = xn++;
	int volume;

	if (i <= frames/2) volume = 0;
	else               volume = 1;

	*l_input = *l_input * volume;
	*r_input = *r_input * volume;
    }
}

void REVFX_PARAM(uint8_t index, uint32_t value) {
}

