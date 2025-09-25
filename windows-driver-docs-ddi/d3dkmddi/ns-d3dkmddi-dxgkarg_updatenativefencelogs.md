## Description

**DXGKARG_UPDATENATIVEFENCELOGS** is the input structure for [**DxgkDdiUpdateNativeFenceLogs**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updatenativefencelogs).

## Members

### `NumberOfQueues`

[in] Number of elements in the array that hHWQueue points to.

### `hHWQueue`

[in] Array of KMD handles of HWQueues whose pending native fence log writes (for both wait and signal logs) must be flushed to the OS log buffer.

### `Flags`

[in] A [**DXGKARG_UPDATENATIVEFENCELOGS_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_updatenativefencelogs_flags) structure that contains flags for the flush.

### `Reserved[32]`

Reserved for system use.

## Remarks

For more information about native GPU fences and log buffer usage, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DxgkDdiUpdateNativeFenceLogs**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updatenativefencelogs)