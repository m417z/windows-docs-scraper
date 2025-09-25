# _DXVAHDDDI_STREAM_STATE_PRIVATE_DATA structure

## Description

The DXVAHDDDI_STREAM_STATE_PRIVATE_DATA structure describes stream-state data that specifies a private stream state.

## Members

### `Guid` [in]

A GUID that identifies the private stream state.

### `DataSize` [in]

The size, in bytes, of the private stream-state data.

### `pData` [in/out]

A pointer to the private stream-state data. The caller sets **pData** to **NULL** to retrieve the size of the private stream-state data.

## Remarks

Unlike other stream states ([DXVAHDDDI_STREAM_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_stream_state)), the Direct3D runtime does not maintain the private stream state. An application and the driver communicates the private stream state directly through a proprietary manner, which consists of setting and retrieving the private stream state.

To set private stream state, the application causes the Direct3D runtime to specify the DXVAHDDDI_STREAM_STATE_PRIVATE state in the **State** member of the [D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessstreamstate) structure in a call to the driver's [SetVideoProcessStreamState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessstreamstate) function. To retrieve private stream state, the application causes the Direct3D runtime to call the driver's [GetVideoProcessStreamStatePrivate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_getvideoprocessstreamstateprivate) function.

## See also

[D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessstreamstate)

[DXVAHDDDI_STREAM_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_stream_state)

[GetVideoProcessStreamStatePrivate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_getvideoprocessstreamstateprivate)

[SetVideoProcessStreamState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessstreamstate)