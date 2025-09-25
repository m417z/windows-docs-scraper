# FltFreeOpenReparseList function

## Description

This routine deallocates any information copied into a create operation by
a previous call to [FltCopyOpenReparseList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcopyopenreparselist).

## Parameters

### `Filter` [in]

The filter to dereference.

### `EcpList` [in]

The ECP list whose open reparse information should
be deallocated.

## Return value

This routine does not return a value.