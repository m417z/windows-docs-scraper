# FltRemoveOpenReparseEntry function

## Description

This routine removes an [OPEN_REPARSE_LIST_ENTRY](https://learn.microsoft.com/previous-versions/mt734265(v=vs.85)) structure (added by [FltAddOpenReparseEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltaddopenreparseentry)) from a create operation.

**Important** *OpenReparseEntry* must be an entry added by [FltAddOpenReparseEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltaddopenreparseentry). All other entries are not valid.

## Parameters

### `Filter` [in]

The filter to dereference.

### `Data` [in]

The create operation to remove open reparse information
from.

### `OpenReparseEntry` [in]

The open reparse information to remove, of type [OPEN_REPARSE_LIST_ENTRY](https://learn.microsoft.com/previous-versions/mt734265(v=vs.85)).

## Return value

This routine does not return a value.