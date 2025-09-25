# _DXVAHDDDI_BLT_STATE_ALPHA_FILL_DATA structure

## Description

The DXVAHDDDI_BLT_STATE_ALPHA_FILL_DATA structure describes data that specifies the alpha-fill mode of the output.

## Members

### `Mode` [in]

A [DXVAHDDDI_ALPHA_FILL_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_alpha_fill_mode)-typed value that indicates the type of alpha-fill mode to set. The default value is DXVAHDDDI_ALPHA_FILL_MODE_BACKGROUND, which indicates to fill the output with the alpha value of the background color.

### `StreamNumber` [in]

A zero-based stream index number. This number must be less than the number, which the driver sets in the **MaxStreamStates** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure. The driver should refer to this number only when the **Mode** member is set to DXVAHD_ALPHA_FILL_MODE_SOURCE_STREAM. The default value is zero.

## Remarks

The Direct3D runtime specifies the DXVAHDDDI_BLT_STATE_ALPHA_FILL state in the **State** member of the [D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessbltstate) structure in a call to the driver's [SetVideoProcessBltState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessbltstate) function only when the output format is a format type with alpha (for example, D3DDDIFMT_A8R8G8B8 from the [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration).

The DXVAHD_ALPHA_FILL_MODE_SOURCE_STREAM mode requires the following conditions:

* The DXVAHDDDI_BLT_STATE_ALPHA_FILL state only affects alpha within the destination rectangle. The rest of the output remains unchanged.
* If the input format type is without alpha, the source alpha is considered as opaque.
* If the input stream is disabled or unavailable, the output remains unchanged.

## See also

[D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessbltstate)

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[DXVAHDDDI_ALPHA_FILL_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_alpha_fill_mode)

[DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps)

[SetVideoProcessBltState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessbltstate)