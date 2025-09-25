# D2D1_CONVOLVEMATRIX_PROP enumeration

## Description

Identifiers for properties of the [Convolve matrix effect](https://learn.microsoft.com/windows/desktop/Direct2D/convolve-matrix).

## Constants

### `D2D1_CONVOLVEMATRIX_PROP_KERNEL_UNIT_LENGTH:0`

The size of one unit in the kernel. The units are in (DIPs/kernel unit), where a kernel unit is the size of the element in the convolution kernel.
A value of 1 (DIP/kernel unit) corresponds to one pixel in a image at 96 DPI.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_CONVOLVEMATRIX_PROP_SCALE_MODE:1`

The interpolation mode the effect uses to scale the image to the corresponding kernel unit length. There are six scale modes that range in quality and speed.

The type is [D2D1_CONVOLVEMATRIX_SCALE_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_convolvematrix_scale_mode).

The default value is D2D1_CONVOLVEMATRIX_SCALE_MODE_LINEAR.

### `D2D1_CONVOLVEMATRIX_PROP_KERNEL_SIZE_X:2`

The width of the kernel matrix. The units are specified in kernel units.

The type is UINT32.

The default value is 3.

### `D2D1_CONVOLVEMATRIX_PROP_KERNEL_SIZE_Y:3`

The height of the kernel matrix. The units are specified in kernel units.

The type is UINT32.

The default value is 3.

### `D2D1_CONVOLVEMATRIX_PROP_KERNEL_MATRIX:4`

The kernel matrix to be applied to the image. The kernel elements aren't bounded and are specified as floats.

The first set of KernelSizeX numbers in the FLOAT[] corresponds to the first row in the kernel.
The second set of KernelSizeX numbers correspond to the second row, and so on up to KernelSizeY rows.

The type is FLOAT[].

The default value is {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f}.

### `D2D1_CONVOLVEMATRIX_PROP_DIVISOR:5`

The kernel matrix is applied to a pixel and then the result is divided by this value.

0 behaves as a value of float epsilon.

The type is FLOAT.

The default value is 1.0f.

### `D2D1_CONVOLVEMATRIX_PROP_BIAS:6`

The effect applies the kernel matrix, the divisor, and then the bias is added to the result. The bias is unbounded and unitless.

The type is FLOAT.

The default value is 0.0f.

### `D2D1_CONVOLVEMATRIX_PROP_KERNEL_OFFSET:7`

Shifts the convolution kernel from a centered position on the output pixel to a position you specify left/right and up/down. The offset is defined in kernel units.

With some offsets and kernel sizes, the convolution kernel’s samples won't land on a pixel image center. The pixel values for the kernel sample are computed by bilinear interpolation.

The type is [D2D1_VECTOR_2F](https://learn.microsoft.com/windows/desktop/api/dcommon/ns-dcommon-d2d_vector_2f).

The default value is {0.0f, 0.0f}.

### `D2D1_CONVOLVEMATRIX_PROP_PRESERVE_ALPHA:8`

Specifies whether the convolution kernel is applied to the alpha channel or only the color channels.

If you set this to TRUE the convolution kernel is applied only to the color channels.

If you set this to FALSE the convolution kernel is applied to all channels.

The type is BOOL.

The default value is FALSE.

### `D2D1_CONVOLVEMATRIX_PROP_BORDER_MODE:9`

The mode used to calculate the border of the image, soft or hard.

The type is [D2D1_BORDER_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_border_mode).

The default value is D2D1_BORDER_MODE_SOFT.

### `D2D1_CONVOLVEMATRIX_PROP_CLAMP_OUTPUT:10`

Whether the effect clamps color values to between 0 and 1 before the effect passes the values to the next effect in the graph. The effect clamps the values before it premultiplies the alpha.

If you set this to TRUE the effect will clamp the values. If you set this to FALSE, the effect will not clamp the color values,
but other effects and the output surface may clamp the values if they are not of high enough precision.

The type is BOOL.

The default value is FALSE.

### `D2D1_CONVOLVEMATRIX_PROP_FORCE_DWORD:0xffffffff`