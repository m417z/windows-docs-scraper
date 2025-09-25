# FltCheckAndGrowNameControl function

## Description

The **FltCheckAndGrowNameControl** routine checks whether the buffer in a [FLT_NAME_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_name_control) structure is large enough to hold the specified number of bytes. If not, **FltCheckAndGrowNameControl** replaces it with a larger system-allocated buffer.

## Parameters

### `NameCtrl` [in, out]

Pointer to a [FLT_NAME_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_name_control) structure containing file name information.

### `NewSize` [in]

Required size, in bytes, of the new name control buffer.

## Return value

**FltCheckAndGrowNameControl** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | There is insufficient memory in the free pool to satisfy the request. |

## Remarks

Minifilter drivers must not attempt to free or replace the buffer in the **Name** member of a [FLT_NAME_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_name_control) structure directly. Instead, minifilter drivers should call **FltCheckAndGrowNameControl** to obtain a larger name buffer.

If the size, in bytes, of the buffer in the *NameCtrl* structure is less than the value of the *NewSize* parameter, **FltCheckAndGrowNameControl** replaces it with a larger system-allocated buffer. **FltCheckAndGrowNameControl** copies the contents of the old buffer into the new one and frees the old buffer.

If the size, in bytes, of the buffer in the *NameCtrl* structure is greater than or equal to the value of the *NewSize* parameter, **FltCheckAndGrowNameControl** returns STATUS_SUCCESS and does not replace the buffer.

## See also

[FLT_NAME_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_name_control)

[FltGetFileNameFormat](https://learn.microsoft.com/previous-versions/ff543030(v=vs.85))

[FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformation)

[FltGetFileNameInformationUnsafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformationunsafe)

[FltGetFileNameQueryMethod](https://learn.microsoft.com/previous-versions/ff543040(v=vs.85))