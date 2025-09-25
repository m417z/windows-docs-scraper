# _DXVAHDDDI_BLT_STATE_CONSTRICTION_DATA structure

## Description

The DXVAHDDDI_BLT_STATE_CONSTRICTION_DATA structure describes data that specifies the down-sampling of the output. If constriction is enabled, the composed target rectangle is down-sampled to the specified size and then scaled back to the target rectangle.

## Members

### `Enable` [in]

A Boolean value that specifies whether constriction is enabled. The default value is **FALSE**, which indicates that constriction is disabled.

### `Size` [in]

A [SIZE](https://learn.microsoft.com/windows-hardware/customize/desktop/unattend/microsoft-windows-smbserver-size) structure that specifies the sampling size to which the output image is reduced. **Size** should be from (1, 1) to (width, height) of the target rectangle. **Size** should be (0, 0) to represent no constriction. The default value is (1, 1).

## Remarks

The Direct3D runtime specifies the DXVAHDDDI_BLT_STATE_CONSTRICTION state in the **State** member of the [D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessbltstate) structure in a call to the driver's [SetVideoProcessBltState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessbltstate) function. This is specified only if the driver has previously set the DXVAHDDDI_FEATURE_CAPS_CONSTRICTION value in the **FeatureCaps** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure when the driver's [GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) function is called with the D3DDDICAPS_DXVAHD_GETVPDEVCAPS value set.

Sampling sizes of (0, anything) and (anything, 0) are invalid and the driver's [SetVideoProcessBltState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessbltstate) function should return an error if these sampling sizes are supplied.

If the supplied sampling size is larger than the size of the target rectangle, then the driver rounds the sampling size to the size of the target rectangle.

## See also

[D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessbltstate)

[DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)

[SIZE](https://learn.microsoft.com/windows-hardware/customize/desktop/unattend/microsoft-windows-smbserver-size)

[SetVideoProcessBltState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessbltstate)