# FltPropagateIrpExtension function

## Description

The **FltPropagateIrpExtension** routine copies the IRP extension from one minifilter's callback data to another's callback data.

## Parameters

### `SourceData` [in]

Pointer to the callback data context from which to copy the extension data.

### `TargetData` [in/out]

Pointer to the callback data context in which to copy the extension data.

### `Flags` [in]

Reserved; must be set to 0.

## Return value

**FltPropagateIrpExtension** returns STATUS_SUCCESS upon successful completion; otherwise, it returns one of the following **NTSTATUS** error values.

| Return code | Description |
| ----------- | ----------- |
| STATUS_INVALID_PARAMETER | *SourceData* or *TargetData* are not an IRP operation. |
| STATUS_INSUFFICIENT_RESOURCES | Could not allocate an extension in the target callback data. |

## Remarks

**FltPropagateIrpExtension** copies only those portions of the IRP extension data that are present.

## See also

[**FltFlushBuffers2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltflushbuffers2)