# _DXVAHDDDI_STREAM_STATE_LUMA_KEY_DATA structure

## Description

The DXVAHDDDI_STREAM_STATE_LUMA_KEY_DATA structure describes stream-state data that specifies the luma key of the input. The driver assumes that a pixel that has a luma value within the luma-key range is transparent.

## Members

### `Enable` [in]

A Boolean value that specifies whether the luma key is enabled. The default value is **FALSE**, which indicates that the luma key is disabled.

### `Lower` [in]

A FLOAT value in the 0.0 to 1.0 range that describes the lower luma-key value. The default value is 0.0.

### `Upper` [in]

A FLOAT value in the 0.0 to 1.0 range that describes the upper luma-key value. The default value is 0.0.

## Remarks

The Direct3D runtime specifies the DXVAHDDDI_STREAM_STATE_LUMA_KEY state in the **State** member of the [D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessstreamstate) structure in a call to the driver's [SetVideoProcessStreamState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessstreamstate) function. This happens only when the driver has previously set the DXVAHDDDI_FEATURE_CAPS_LUMA_KEY value in the **FeatureCaps** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_DXVAHD_GETVPDEVCAPS value set.

If the driver does not set the DXVAHDDDI_INPUT_FORMAT_CAPS_RGB_LUMA_KEY value in the **InputFormatCaps** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_DXVAHD_GETVPDEVCAPS value set, the driver ignores the luma-key data.

## See also

[D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessstreamstate)

[DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)

[SetVideoProcessStreamState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessstreamstate)