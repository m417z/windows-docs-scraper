## Description

**DXGK_NATIVE_FENCE_LOG_BUFFER** is a structure that represents a native fence log buffer.

## Members

### `Header`

A [**DXGK_NATIVE_FENCE_LOG_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_native_fence_log_header) structure that contains the header information for the native fence log buffer.

### `Entries[1]`

Array of **Header.NumberofEntries** [**DXGK_NATIVE_FENCE_LOG_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_native_fence_log_entry) structures that contain the native fence log entries.

## Remarks

For more information about native GPU fences and log buffer usage, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGK_NATIVE_FENCE_LOG_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_native_fence_log_entry)

[**DXGK_NATIVE_FENCE_LOG_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_native_fence_log_header)

[**DXGKARG_SETNATIVEFENCELOGBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_setnativefencelogbuffer)

[**DxgkDdiSetNativeFenceLogBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setnativefencelogbuffer)