# D2D1_GAMMA enumeration

## Description

Specifies which gamma is used for interpolation.

## Constants

### `D2D1_GAMMA_2_2:0`

Interpolation is performed in the standard RGB (sRGB) gamma.

### `D2D1_GAMMA_1_0:1`

Interpolation is performed in the linear-gamma color space.

### `D2D1_GAMMA_FORCE_DWORD:0xffffffff`

## Remarks

Interpolating in a linear gamma space (**D2D1_GAMMA_1_0**) can avoid changes in perceived brightness caused by the effect of gamma correction in spaces where the gamma is not 1.0, such as the default sRGB color space, where the gamma is 2.2. For an example of the differences between these two blending modes, consider the following illustration, which shows two gradients, each of which blends from red to blue to green:

![Illustration of two gradients from red to blue to green, blended by using sRGB gamma and linear-gamma](https://learn.microsoft.com/windows/win32/api/d2d1/images/D2D1_GAMMA.png)

The first gradient is interpolated linearly in the space of the render target (sRGB in this case), and one can see the dark bands between each color. The second gradient uses a gamma-correct linear interpolation, and thus does not exhibit the same variations in brightness.