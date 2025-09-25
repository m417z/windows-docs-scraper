# _D3DDDICB_SUBMITPRESENTBLTTOHWQUEUE structure

## Description

A structure that contains information to present Blt to the hardware queue.

## Members

### `hSrcAllocation` [in]

The allocation of which content will be presented.

### `hDstAllocation` [in]

The destination allocation of the present, if non-zero.

### `hHwQueue` [in]

Hardware queue being submitted to.

### `HwQueueProgressFenceId`

Hardware queue progress fence ID that will be signaled when the Present Blt is done on the GPU.

### `PrivateDriverDataSize`

The size of pPrivateDriverData.

### `pPrivateDriverData`

Private driver data to pass to [Present](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_present).