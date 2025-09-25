# D3D11_TEXTURE_LAYOUT enumeration

## Description

Specifies texture layout options.

## Constants

### `D3D11_TEXTURE_LAYOUT_UNDEFINED:0`

The texture layout is undefined, and is selected by the driver.

### `D3D11_TEXTURE_LAYOUT_ROW_MAJOR:1`

Data for the texture is stored in row major (sometimes called pitch-linear) order.

### `D3D11_TEXTURE_LAYOUT_64K_STANDARD_SWIZZLE:2`

A default texture uses the standardized swizzle pattern.

## Remarks

This enumeration controls the swizzle pattern of default textures and enable map support on default textures. Callers must query [D3D11_FEATURE_DATA_D3D11_OPTIONS2](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options2) to ensure that each option is supported.

The standard swizzle formats applies within each page-sized chunk, and pages are laid out in linear order with respect to one another. A 16-bit interleave pattern defines the conversion from pre-swizzled intra-page location to the post-swizzled location.

![Standard swizzle patterns](https://learn.microsoft.com/windows/win32/api/d3d11_3/images/d3d11_standardswizzle.png)
To demonstrate, consider the 32bpp swizzle format above. This is represented by the following interleave masks, where bits on the left are most-significant.

``` syntax
UINT xBytesMask = 1010 1010 1000 1111
UINT yMask =      0101 0101 0111 0000

```

To compute the swizzled address, the following code could be used (where the _pdep_u32 instruction is supported):

``` syntax
UINT swizzledOffset = resourceBaseOffset +
                      _pdep_u32(xOffset, xBytesMask) +
                      _pdep_u32(yOffset, yBytesMask);

```

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-enums)