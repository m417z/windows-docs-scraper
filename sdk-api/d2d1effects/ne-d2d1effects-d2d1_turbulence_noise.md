# D2D1_TURBULENCE_NOISE enumeration

## Description

The turbulence noise mode for the [Turbulence effect](https://learn.microsoft.com/windows/desktop/Direct2D/turbulence).
Indicates whether to generate a bitmap based on Fractal Noise or the Turbulence function.

## Constants

### `D2D1_TURBULENCE_NOISE_FRACTAL_SUM:0`

Computes a sum of the octaves, shifting the output range from [-1, 1], to [0, 1].

### `D2D1_TURBULENCE_NOISE_TURBULENCE:1`

Computes a sum of the absolute value of each octave.

### `D2D1_TURBULENCE_NOISE_FORCE_DWORD:0xffffffff`