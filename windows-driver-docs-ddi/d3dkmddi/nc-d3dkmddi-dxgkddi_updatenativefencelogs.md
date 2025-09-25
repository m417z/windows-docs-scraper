## Description

**DxgkDdiUpdateNativeFenceLogs** synchronously flushes pending native fence log writes on demand.

## Parameters

### `pUpdateNativeFenceLog`

[in] Pointer to a [**DXGKARG_UPDATENATIVEFENCELOGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_updatenativefencelogs) structure that contains the native fence log information.

## Return value

**DxgkDdiUpdateNativeFenceLogs** returns STATUS_SUCCESS if the flush was successful. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

A native fence log buffer can be read/written to asynchronously. To force a synchronous flush of the log buffer, the KMD can call **DxgkDdiUpdateNativeFenceLogs**.

The KMD should insert a memory barrier to the given HWQueue, which ensures that all log entry writes are committed.

For more information about native GPU fences and log buffer usage, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGKARG_UPDATENATIVEFENCELOGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_updatenativefencelogs)

[**DxgkDdiSetNativeFenceLogBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setnativefencelogbuffer)