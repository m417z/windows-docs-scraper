## Description

A **DXGK_NATIVE_FENCE_LOG_TYPE** value identifies the type of a native log entry.

## Constants

### `DXGK_NATIVE_FENCE_LOG_TYPE_WAITS:1`

The log entry is for a wait.

### `DXGK_NATIVE_FENCE_LOG_TYPE_SIGNALS:2`

The log entry is for a signal.

## Remarks

For more information about native GPU fences and log buffer usage, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGK_NATIVE_FENCE_LOG_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_native_fence_log_header)

[**DxgkDdiSetNativeFenceLogBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setnativefencelogbuffer)