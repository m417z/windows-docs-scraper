## Description

The **DXGK_NATIVE_FENCE_LOG_ENTRY** structure contains a native fence log entry.

## Members

### `FenceValue`

UMD payload: The newly signaled/unblocked fence value.

### `hNativeFence`

UMD payload: User-mode D3DKMT_HANDLE of the native fence to which this operation belongs.

### `OperationType`

UMD payload: A [**DXGK_FENCE_LOG_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_native_fence_log_operation) value that specifies the type of the operation.

### `Reserved0`

Reserved for alignment.

### `FenceObservedGpuTimestamp`

GPU Payload: When **OperationType** is OPERATION_WAIT_UNBLOCKED, specifies the GPU time at which an unresolved wait command was seen by the engine and stalled the HWQueue.

### `Reserved1`

Reserved for alignment.

### `FenceEndGpuTimestamp`

GPU Payload: GPU time at which the fence operation completed on the GPU.

## Remarks

For more information about native GPU fences and log buffer usage, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGK_NATIVE_FENCE_LOG_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_native_fence_log_buffer)

[**DXGK_NATIVE_FENCE_LOG_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_native_fence_log_header)

[**DXGK_FENCE_LOG_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_native_fence_log_operation)

[**DxgkDdiSetNativeFenceLogBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setnativefencelogbuffer)