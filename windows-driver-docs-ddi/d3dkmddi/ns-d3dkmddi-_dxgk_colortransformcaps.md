# DXGK_COLORTRANSFORMCAPS structure

## Description

This structure replaces the DXGK_GAMMARAMPCAPS structure in the DXGK_DRIVERCAPS structure to describe both the gamma and color transform capabilities of the display pipelines.

## Members

### `Gamma_Rgb256x3x16`

Indicates support for a GDI compatible gamma ramp.

### `Gamma_Dxgi1`

Indicates support for a DXGI1 gamma ramp. These gamma ramps have been defined since WDDM 1.0 but were always required to be supported by any WDDM driver.
Full WDDM drivers are still required to support DXGI1 gamma so should set this flag but drivers for display-only and indirect display will be able to indicate support through this flag.

### `Transform_3x4Matrix`

Indicates support for a 3 by 4 matrix color transform in the display pipeline hardware.

### `Transform_3x4Matrix_WideColor`

Indicates support for a 3 by 4 matrix color transform in the display pipeline hardware when scanning out WideColor data. Drivers which support this capability must also support Transform_3x4Matrix. The OS will NOT engage WideColorGamut mode unless both this bit and the WideColorSpace cap bits are set.

### `Transform_3x4Matrix_HighColor`

Indicates support for a 3 by 4 matrix color transform in the display pipeline hardware when scanning out HighColor data. Drivers which support this capability must also support Transform_3x4Matrix_WideColor.

### `Transform_Matrix_V2`

Indicates support for a colorspace transform matrix.

### `Reserved`

This value is reserved for system use.

### `Value`

The combined UINT value.