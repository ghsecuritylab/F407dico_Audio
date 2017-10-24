/*
 * Example code demonstrating calculation of Max energy bin of
 * frequency domain of input signal.
 */

/**
 * Frequency Bin Example
 *
 * Demonstrates the calculation of the maximum energy bin in the frequency
 * domain of the input signal with the use of Complex FFT, Complex
 * Magnitude, and Maximum functions.
 *
 * Algorithm:
 * The input test signal contains a 10 kHz signal with uniformly distributed white noise.
 * Calculating the FFT of the input signal will give us the maximum energy of the
 * bin corresponding to the input frequency of 10 kHz.
 *
 * Block Diagram:
 * The figure below shows the time domain signal of 10 kHz signal with
 * uniformly distributed white noise, and the next figure shows the input
 * in the frequency domain. The bin with maximum energy corresponds to 10 kHz signal.
 * FFTBinInput.gif "Input signal in Time domain"
 * FFTBinOutput.gif "Input signal in Frequency domain"
 *
 * Variables Description:
 * testInput_f32_10khz points to the input data
 * testOutput points to the output data
 * fftSize length of FFT
 * ifftFlag flag for the selection of CFFT/CIFFT
 * doBitReverse Flag for selection of normal order or bit reversed order
 * refIndex reference index value at which maximum energy of bin ocuurs
 * testIndex calculated index value at which maximum energy of bin ocuurs
 *
 * CMSIS DSP Software Library Functions Used:
 * - arm_cfft_f32()
 * - arm_cmplx_mag_f32()
 * - arm_max_f32()
 */

#include "arm_math.h"
#include "arm_const_structs.h"

#define TEST_LENGTH_SAMPLES 2048

extern float32_t testInput_f32_10khz[TEST_LENGTH_SAMPLES];
static float32_t testOutput[TEST_LENGTH_SAMPLES/2];

uint32_t fftSize = 1024;
uint32_t ifftFlag = 0;
uint32_t doBitReverse = 1;

/* Reference index at which max energy of bin ocuurs */
uint32_t refIndex = 213, testIndex = 0;

/* Max magnitude FFT Bin test */

int32_t main(void)
{

  arm_status status;
  float32_t maxValue;

  status = ARM_MATH_SUCCESS;

  /* Process the data through the CFFT/CIFFT module */
  arm_cfft_f32(&arm_cfft_sR_f32_len1024, testInput_f32_10khz, ifftFlag, doBitReverse);

  /* Process the data through the Complex Magnitude Module for
  calculating the magnitude at each bin */
  arm_cmplx_mag_f32(testInput_f32_10khz, testOutput, fftSize);

  /* Calculates maxValue and returns corresponding BIN value */
  arm_max_f32(testOutput, fftSize, &maxValue, &testIndex);

  if(testIndex !=  refIndex)
  {
    status = ARM_MATH_TEST_FAILURE;
  }

  if( status != ARM_MATH_SUCCESS)
  {
    while(1);
  }

  while(1);
}

