## Description

The **DXGK_NATIVE_FENCE_LOG_HEADER** structure contains the header information for the native fence log buffer.

## Members

### `FirstFreeEntryIndex`

Index of the first free entry in the log. **FirstFreeEntryIndex** is the same value as the LowPart of **AtomicWraparoundAndEntryIndex**.

### `WraparoundCount`

The number of times the log entries have wrapped around. Same value as the HighPart of **AtomicWraparoundAndEntryIndex**.

### `AtomicWraparoundAndEntryIndex`

A 64-bit integer that contains the **FirstFreeEntryIndex** in the LowPart and the **WraparoundCount** in the HighPart.

### `Type`

A [**DXGK_NATIVE_FENCE_LOG_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_native_fence_log_type) enumeration that specifies the type of the native fence log entries.

### `NumberOfEntries`

Number of [**DXGK_NATIVE_FENCE_LOG_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_native_fence_log_entry) structures in the **Entries** array of the [native fence log buffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_native_fence_log_buffer).

### `Reserved[2]`

Reserved for system use.

## Remarks

For more information about native GPU fences and log buffer usage, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGK_NATIVE_FENCE_LOG_BUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_native_fence_log_buffer)

[**DXGK_NATIVE_FENCE_LOG_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_native_fence_log_entry)

[**DXGK_NATIVE_FENCE_LOG_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_native_fence_log_type)

[**DxgkDdiSetNativeFenceLogBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setnativefencelogbuffer)