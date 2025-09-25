# IDirect3DDevice9Ex::SetConvolutionMonoKernel

## Description

Prepare the texture sampler for monochrome convolution filtering on a single-color texture.

## Parameters

### `width` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The width of the filter kernel; ranging from 1 - [D3DCONVOLUTIONMONO_MAXWIDTH](https://learn.microsoft.com/windows/desktop/direct3d9/d3dconvolutionmono). The default value is 1.

### `height` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The height of the filter kernel; ranging from 1 - [D3DCONVOLUTIONMONO_MAXHEIGHT](https://learn.microsoft.com/windows/desktop/direct3d9/d3dconvolutionmono). The default value is 1.

### `rows` [in]

Type: **float***

An array of weights, one weight for each kernel sub-element in the width. This parameter must be **NULL**, which will set the weights equal to the default value.

### `columns` [in]

Type: **float***

An array of weights, one weight for each kernel sub-element in the height. This parameter must be **NULL**, which will set the weights equal to the default value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the method succeeds, the return value is D3D_OK.

## Remarks

This method is designed to filter a single color texture. A monochrome convolution filter is a 2D box filter with all of the weights set to 1.0; the filter kernel resolution ranges from 1 x 1 to 7 x 7. When monochrome texture filtering is set to a texture sampler and texture sampling is performed at location, then Direct3D performs convolution.

Restrictions include:

* The filter specified by this method is recorded in state blocks as a part of [D3DSBT_PIXELSTATE](https://learn.microsoft.com/windows/desktop/direct3d9/d3dstateblocktype).
* The only texture address mode supported is: [D3DPTADDRESSCAPS_BORDER](https://learn.microsoft.com/windows/desktop/direct3d9/d3dptfiltercaps); the border color is always 0.
* This method is not supported for mipmaps.
* Using a non-monochrome texture with convolution filtering will generate a driver error.

## See also

[IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex)