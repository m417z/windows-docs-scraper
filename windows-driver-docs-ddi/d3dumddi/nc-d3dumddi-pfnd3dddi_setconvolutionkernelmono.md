# PFND3DDDI_SETCONVOLUTIONKERNELMONO callback function

## Description

The *SetConvolutionKernelMono* function defines the resolution and weights of the kernel filter, which is used when the D3DTEXF_CONVOLUTIONMONO texture filtering mode is set.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETCONVOLUTIONKERNELMONO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setconvolutionkernelmono) structure that describes parameters for setting the monochrome convolution kernel.

## Return value

*SetConvolutionKernelMono* returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The monochrome convolution kernel is successfully set.|
|E_OUTOFMEMORY|SetConvolutionKernelMono could not allocate the required memory for it to complete.|

## Remarks

D3DTEXF_CONVOLUTIONMONO is a texture filter mode that is used for sampling monochrome textures (that is, textures that are formatted as one bit per pixel (D3DDDIFMT_A1)). In the Direct3D 9.L runtime, the convolution filter is a two-dimensional box filter (that is, all weights = 1.0). However, the *SetConvolutionKernelMono* function is defined to support a more general filter. When D3DTEXF_CONVOLUTIONMONO is set to a texture sampler, the texture sampler states D3DTSS_MIPFILTER, D3DTSS_MINFILTER and D3DTSS_MAGFILTER are ignored. The texture address D3DTADDRESS_BORDER with border color 0 should be applied in this filtering mode. The user-mode display driver should return an error or ignore the rendered primitive if this filtering mode is used with a non-monochrome texture.

The following formula is used to perform the convolution:

Result = Sum(i=0, i v)[ (Ri*(1 - alpha) + Ri+1*alpha) * S)]

Rₖ = Sum(j=0, j u)[Tk,j*(1 - beta) + Tk,j+1*beta], where 0 < k < Nv

S = 1 / (Nu * Nv)

Nu and Nv are the width and height of the filter kernel.

Ti,j are texture samples from a monochrome texture at location (i, j).

The precision of the filter operations must be at least 6 bits.

The interpolated texture coordinate values (U, V) at a pixel center are the coordinates of the center of the filter kernel.

The coordinates of the upper left filter kernel sample (Uf,Vf) are computed as:

Uf = U * TextureWidth - Nu * 0.5

Vf = V * TextureHeight - Nv * 0.5

Then

beta = Uf - truncate(Uf)

alpha = Vf - truncate(Vf)

## See also

[D3DDDIARG_SETCONVOLUTIONKERNELMONO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setconvolutionkernelmono)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)