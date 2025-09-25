# _DXVAHDDDI_BLT_STATE_PRIVATE_DATA structure

## Description

The DXVAHDDDI_BLT_STATE_PRIVATE_DATA structure describes data that specifies the private bit-block transfer (bitblt) state.

## Members

### `Guid` [in]

A GUID that identifies the private bitblt state.

### `DataSize` [in]

The size, in bytes, of the private bitblt state data.

### `pData` [in/out]

A pointer to the private bitblt state data. The caller sets **pData** to **NULL** to retrieve the size of the private bitblt state data.

## Remarks

Unlike other bitblt states ([DXVAHDDDI_BLT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_blt_state)), the Direct3D runtime does not maintain the private bitblt state. An application and the driver communicate the private bitblt state directly in a proprietary manner, which consists of setting and retrieving the private bitblt state. To set private bitblt state, the application causes the Direct3D runtime to specify the DXVAHDDDI_BLT_STATE_PRIVATE state in the **State** member of the [D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessbltstate) structure in a call to the driver's [SetVideoProcessBltState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessbltstate) function. To retrieve private bitblt state, the application causes the Direct3D runtime to call the driver's [GetVideoProcessBltStatePrivate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_getvideoprocessbltstateprivate) function.

## See also

[D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessbltstate)

[DXVAHDDDI_BLT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_blt_state)

[GetVideoProcessBltStatePrivate](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_getvideoprocessbltstateprivate)

[SetVideoProcessBltState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessbltstate)