# _D3DDDIARG_DXVAHD_GETVIDEOPROCESSBLTSTATEPRIVATE structure

## Description

The D3DDDIARG_DXVAHD_GETVIDEOPROCESSBLTSTATEPRIVATE structure describes the private bit-block transfer (bitblt) state of the video processor to retrieve.

## Members

### `hVideoProcessor` [in]

A handle to the video processor whose private bitblt state the runtime requests.

### `pData` [in/out]

A pointer to [DXVAHDDDI_BLT_STATE_PRIVATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_private_data) structure that identifies the private bitblt state to retrieve. The driver uses DXVAHDDDI_BLT_STATE_PRIVATE_DATA to return the private bitblt data.

## See also

[DXVAHDDDI_BLT_STATE_PRIVATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_blt_state_private_data)

[GetVideoProcessBltStatePrivate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_getvideoprocessbltstateprivate)