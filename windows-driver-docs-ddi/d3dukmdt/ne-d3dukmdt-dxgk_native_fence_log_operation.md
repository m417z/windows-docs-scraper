## Description

A **DXGK_NATIVE_FENCE_LOG_OPERATION** value identifies the native log entry operation being logged.

## Constants

### `DXGK_NATIVE_FENCE_LOG_OPERATION_SIGNAL_EXECUTED:0`

The log entry is for a signal operation that has been executed on the GPU.

### `DXGK_NATIVE_FENCE_LOG_OPERATION_WAIT_UNBLOCKED:1`

The log entry is for a wait condition that has been satisfied on the GPU.

## Remarks

For more information about native GPU fences and log buffer usage, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGK_NATIVE_FENCE_LOG_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_native_fence_log_entry)

[**DxgkDdiSetNativeFenceLogBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setnativefencelogbuffer)