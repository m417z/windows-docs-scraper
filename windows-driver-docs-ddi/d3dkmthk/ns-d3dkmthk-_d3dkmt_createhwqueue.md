# D3DKMT_CREATEHWQUEUE structure

## Description

**D3DKMT_CREATEHWQUEUE** is the structure passed to [**D3DKMTCreateHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatehwqueue) and [**PFND3DKMT_CREATEHWQUEUE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_createhwqueue) when creating a new hardware queue.

## Members

### `hHwContext`

[in] Handle to the hardware context that the queue belongs to.

### `Flags`

[in] A bit field of [**D3DDDI_CREATEHWQUEUEFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_createhwqueueflags) values specifying the hardware queue creation flags.

### `PrivateDriverDataSize`

[in] Size of private driver data, in bytes.

### `pPrivateDriverData`

[in/out] Pointer to the private driver data.

### `hHwQueue`

[out] Handle to the created hardware queue object to submit work to.

### `hHwQueueProgressFence`

[out] Handle to the monitored fence object used to monitor the queue progress.

### `HwQueueProgressFenceCPUVirtualAddress`

[out] Read-only mapping of the queue progress fence value for the CPU.

### `HwQueueProgressFenceGPUVirtualAddress`

[out] Read/write mapping of the queue progress fence value for the GPU.

## See also

[**D3DDDI_CREATEHWQUEUEFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_createhwqueueflags)

[**PFND3DKMT_CREATEHWQUEUE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_createhwqueue)