# _D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE structure

## Description

The D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE structure describes the bit-block transfer (bitblt) state of the video processor to change and the data that is used to change the state.

## Members

### `hVideoProcessor` [in]

A handle to the video processor whose bitblt state is changed.

### `State` [in]

A [DXVAHDDDI_BLT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_blt_state)-typed value that indicates the type of bitblt to set.

### `DataSize` [in]

The size, in bytes, of the data that is used to change the bitblt state.

### `pData` [in]

A pointer to the data that is used to change the bitblt state. For more information about the types of data that **pData** can point to, see the values of the [DXVAHDDDI_BLT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_blt_state) enumeration.

## See also

[DXVAHDDDI_BLT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_blt_state)

[SetVideoProcessBltState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessbltstate)