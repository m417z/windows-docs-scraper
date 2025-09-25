# _DXVAHDDDI_STREAM_STATE_ALPHA_DATA structure

## Description

The DXVAHDDDI_STREAM_STATE_ALPHA_DATA structure describes stream-state data that specifies the alpha blend level per-plane.

## Members

### `Enable` [in]

A Boolean value that specifies whether the driver should alpha blend. The default value is **FALSE**, which indicates that alpha blend is disabled.

### `Alpha` [in]

A FLOAT value in the 0.0 to 1.0 range that describes the alpha level (that is, the transparency level). The default value is 1.0 for opaque.

## Remarks

The driver multiplies the alpha value with each source pixel and blends the result with the destination pixel. For example, the driver uses the following values to perform the following calculation:

Cs = source pixel color value

Cd = destination pixel color value

As = per-pixel source alpha value [0.0, 1.0]

Ap = per-plane alpha value [0.0, 1.0]

Ae = per-entry palette alpha value [0.0, 1.0] or 1.0 if the driver did not set the DXVAHDDDI_FEATURE_CAPS_ALPHA_PALETTE value in the **FeatureCaps** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_DXVAHD_GETVPDEVCAPS value set.

Cd = Cs * (As * Ap * Ae) + Cd * (1.0 - As * Ap * Ae)

Ad = per-pixel destination alpha value [0.0, 1.0]

The Ad parameter is set with values from the [DXVAHDDDI_ALPHA_FILL_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_alpha_fill_mode) enumeration.

## See also

[DXVAHDDDI_ALPHA_FILL_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_alpha_fill_mode)