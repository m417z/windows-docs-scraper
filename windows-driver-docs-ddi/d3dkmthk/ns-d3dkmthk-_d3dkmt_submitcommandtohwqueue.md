# _D3DKMT_SUBMITCOMMANDTOHWQUEUE structure

## Description

A structure that holds information to submit a command to the hardware queue.

## Members

### `hHwQueue`

Context queue to submit the command to.

### `HwQueueProgressFenceId`

Hardware queue progress fence value that will be signaled once the command is finished.

### `CommandBuffer`

GPU VA of the command buffer to be executed on the GPU.

### `CommandLength`

Length in bytes of the command buffer.

### `PrivateDriverDataSize`

Size of private driver data in bytes.

### `pPrivateDriverData`

Pointer to a buffer that contains optional private driver data.

### `NumPrimaries`

The number of primaries written by this command buffer.

### `WrittenPrimaries`

The array of primaries written by this command buffer.