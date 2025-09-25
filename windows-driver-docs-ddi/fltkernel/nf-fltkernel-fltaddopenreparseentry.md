# FltAddOpenReparseEntry function

## Description

This routine adds a caller allocated open reparse structure, [OPEN_REPARSE_LIST_ENTRY](https://learn.microsoft.com/previous-versions/mt734265(v=vs.85)), into a create operation.

## Parameters

### `Filter` [in]

The filter to reference.

### `Data` [in]

The create operation to attach open reparse information to.

### `OpenReparseEntry` [in]

The open reparse information to add, of type [OPEN_REPARSE_LIST_ENTRY](https://learn.microsoft.com/previous-versions/mt734265(v=vs.85)).

## Return value

The following NT status codes are returned.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER_2** | Status code if *Data* is not a create operation. This is an error code. |
| **STATUS_SUCCESS** | The operation completed successfully. |

## Remarks

This routine adds an ECP list and/or ECP as needed. *Filter* is referenced
for the lifetime of the open reparse entry structure, not the ECP itself,
which is conceptually independent of any specific filter.

Use [FltRemoveOpenReparseEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveopenreparseentry) to remove the open reparse structure from the create operation.

## See also

[FltRemoveOpenReparseEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltremoveopenreparseentry)