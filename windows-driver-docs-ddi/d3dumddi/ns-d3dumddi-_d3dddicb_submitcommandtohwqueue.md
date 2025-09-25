# _D3DDDICB_SUBMITCOMMANDTOHWQUEUE structure

## Description

A structure that holds information to queue hardware.

## Members

### `hHwQueue` [in]

Hardware queue being submitted to.

### `HwQueueProgressFenceId`

Hardware queue progress fence ID that will be signaled when the Present Blt is done on the GPU.

### `Commands`

GPU VA of the command buffer to be executed on the GPU.

### `CommandLength`

Length in bytes of the command buffer.

### `Flags`

Flags.

### `PrivateDriverDataSize`

The size of pPrivateDriverData.

### `pPrivateDriverData`

Private driver data to pass to [Present](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_present).

### `NumPrimaries`

The number of primaries written by this command buffer.

### `WrittenPrimaries`

The array of primaries written by this command buffer.