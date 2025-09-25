# _D3DDDIARG_SETCONVOLUTIONKERNELMONO structure

## Description

The D3DDDIARG_SETCONVOLUTIONKERNELMONO structure describes parameters for setting the monochrome convolution kernel.

## Members

### `Width` [in]

The width, which is the resolution of the filter kernel in the horizontal direction. Valid values for this member are from 1 to 7.

### `Height` [in]

The height, which is the resolution of the filter kernel in the vertical direction. Valid values for this member are from 1 to 7.

### `pKernelRow` [in]

A pointer to weights in the horizontal direction of a separable filter. In Microsoft Direct3D 9.L and later, **pKernelRow** must be **NULL**, which indicates that all of the weights are 1.0.

### `pKernelCol` [in]

A pointer to weights in the vertical direction of a separable filter. In Direct3D 9.L and later, **pKernelCol** must be **NULL**, which indicates that all of the weights are 1.0.

## See also

[SetConvolutionKernelMono](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setconvolutionkernelmono)