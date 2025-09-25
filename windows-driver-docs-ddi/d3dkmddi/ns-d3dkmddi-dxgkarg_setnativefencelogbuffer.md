## Description

**DXGKARG_SETNATIVEFENCELOGBUFFER** is the input structure for [**DxgkDdiSetNativeFenceLogBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setnativefencelogbuffer).

## Members

### `hHwQueue`

[in] Driver handle of the HWQueue to which this log belongs.

### `NumberOfEntries`

[in] Number of entries in the array of log entries that **LogBufferCpuVa** points to.

### `LogBufferCpuVa`

[in] The read/write kernel-mode CPU virtual address of the [native fence log buffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_native_fence_log_buffer).

### `LogBufferGpuVa`

[in] The read/write GPU VA of the log buffer in user process address space.

### `LogBufferSystemProcessGpuVa`

[in] The read/write GPU VA of the log buffer in system address space.

### `Flags`

[in] A [**DXGKARG_SETNATIVEFENCELOGBUFFER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_setnativefencelogbuffer_flags) structure that contains flags for writing a payload into the native fence log buffer.

### `Reserved[32]`

Reserved for system use.

## Remarks

For more information about native GPU fences and log buffer usage, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGK_NATIVE_FENCE_LOG_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_native_fence_log_buffer)

[**DxgkDdiSetNativeFenceLogBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setnativefencelogbuffer)