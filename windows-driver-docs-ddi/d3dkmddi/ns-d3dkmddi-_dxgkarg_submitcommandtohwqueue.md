# _DXGKARG_SUBMITCOMMANDTOHWQUEUE structure

## Description

Arguments used to submit a command to the hardware queue.

## Members

### `hHwQueue` [in]

Hardware queue being submitted to.

### `HwQueueProgressFenceId`

Hardware queue progress fence ID that will be signaled when the Present Blt is done on the GPU.

### `DmaBufferVirtualAddress`

The virtual address of the DMA buffer to be executed on the GPU.

### `DmaBufferSize`

The size of the DMA buffer to be executed on the GPU.

### `DmaBufferPrivateDataSize`

The buffer's private data size.

### `pDmaBufferPrivateData`

Binary data that is passed by the user mode DDI callback pfnSubmitToHwQueueCb, for command submissions from user mode, or for kernel mode submissions such as Present Blt, private driver data buffer filled out by DdiPresent.

> [!Important]
> The private driver data buffer will be freed upon the return from DxgkDdiSubmitCommandToHwQueue. This is different from WDDM 2.0-2.3, where the private driver data lifetime is extended until the command buffer completion on the GPU.

### `Flags`

These will be set to zero for user mode driver generated command buffers. Kernel mode driver DdiPresentToHwQueue generated command buffers will have Present flag set to 1.

### `HwQueueProgressFenceGpuVa`

GPU VA (video acceleration) of the fence that will be signaled upon this DMA buffer completion.

### `HwQueueProgressFenceCpuVa`

Kernel mode CPU VA of the fence that will be signaled upon this DMA buffer completion.

If the node being submitted to has *RingBufferFenceRelease* cap set to 0, the fence update is inserted by the user mode driver as the last instruction at the end of the DMA buffer, or for kernel submissions, by the kernel mode driver in response to DdiSignalMonitoredFence call.

If the node being submitted to has *RingBufferFenceRelease* cap set to 1, the fence update is performed after the DMA buffer is no longer in use by either GPU or CPU. Exact mechanics of the fence update are up to the KMD/GPU. As an example, it can be done by the context management processor hardware when retiring the DMA buffer, or by the KMD.