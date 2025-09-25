# _D3DDDIARG_DXVAHD_GETVIDEOPROCESSSTREAMSTATEPRIVATE structure

## Description

The D3DDDIARG_DXVAHD_GETVIDEOPROCESSSTREAMSTATEPRIVATE structure describes the private stream-state of the video processor to retrieve.

## Members

### `hVideoProcessor` [in]

A handle to the video processor whose private stream-state is the runtime requests.

### `StreamNumber` [in]

A zero-based stream index number. This number must be less than the number that the driver set in the **MaxStreamStates** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure.

### `pData` [in/out]

A pointer to a [DXVAHDDDI_STREAM_STATE_PRIVATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_private_data) structure that identifies the private stream state to retrieve. The driver uses DXVAHDDDI_STREAM_STATE_PRIVATE_DATA to return the private stream-state data.

## See also

[DXVAHDDDI_STREAM_STATE_PRIVATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_private_data)

[DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps)

[GetVideoProcessStreamStatePrivate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_getvideoprocessstreamstateprivate)