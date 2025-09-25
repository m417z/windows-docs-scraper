# _D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE structure

## Description

The D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE structure describes the stream state of the video processor to change and the data that is used to change the state.

## Members

### `hVideoProcessor` [in]

A handle to the video processor whose stream state is changed.

### `StreamNumber` [in]

A zero-based stream index number. This number must be less than the number that the driver set in the **MaxStreamStates** member of the [DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps) structure.

### `State` [in]

A [DXVAHDDDI_STREAM_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_stream_state)-typed value that indicates the stream state to modify.

### `DataSize` [in]

The size, in bytes, of the data that is used to change the stream state.

### `pData` [in]

A pointer to the data that is used to change the stream state. For more information about the types of data that **pData** can point to, see the values of the [DXVAHDDDI_STREAM_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_stream_state) enumeration.

## See also

[DXVAHDDDI_STREAM_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_stream_state)

[DXVAHDDDI_VPDEVCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_vpdevcaps)

[SetVideoProcessStreamState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessstreamstate)