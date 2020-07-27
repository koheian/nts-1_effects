// reference: https://github.com/kinoshita-lab/nts-1_simple_examples
#include <cstdint>
#include "userrevfx.h"

float volume = 0.f; // 0.0 - 1.0

void REVFX_INIT(uint32_t platform, uint32_t api) {
}

void REVFX_PROCESS(float *xn, uint32_t frames) {
    for (auto i = 0u; i < frames;  ++i) {
	float *l_input = xn++;
	float *r_input = xn++;

	*l_input = *l_input * volume;
	*r_input = *r_input * volume;
    }
}

void REVFX_PARAM(uint8_t index, uint32_t value) {
	const float valf = q31_to_f32(value);
	switch (index) {
		case k_user_revfx_param_time:
		volume = valf;
		break;
		default:
		break;
	}
}
