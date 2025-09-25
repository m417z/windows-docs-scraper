# FltCopyOpenReparseList function

## Description

This routine copies any open reparse information from a previous create into
a new ECP list that can be used to issue a second create.

## Parameters

### `Filter` [in]

The filter to reference.

### `Data` [in]

The create operation from which open reparse
information should be copied.

### `EcpList` [in, out]

A new ECP list to copy open reparse information
to.

## Return value

The following NT status codes are returned.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER_2** | Status code if *Data* is not a create operation. This is an error code. |
| **STATUS_SUCCESS** | The operation completed successfully. |

## See also

[FltFreeOpenReparseList](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreeopenreparselist)