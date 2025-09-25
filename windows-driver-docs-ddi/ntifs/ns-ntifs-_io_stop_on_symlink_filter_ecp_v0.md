# IO_STOP_ON_SYMLINK_FILTER_ECP_v0 structure

The **IO_STOP_ON_SYMLINK_FILTER_ECP_v0** structure contains the extra create parameter (ECP) context to restrict the behavior of IO_STOP_ON_SYMLINK to act on specified reparse tags only.

## Description

## Members

### `Out`

The structure in which the I/O manager returns information to the caller. The information is returned in this structure's members.

### `Out.ReparseCount`

Member of Out. The number of name-grafting reparses.

### `Out.RemainingPathLength`

Member of Out. The portion of the path remaining after the last reparse.

## Remarks

A zero length ECP context or an ECP with just the **Out** portion tells the I/O manager to honor the IO_STOP_ON_SYMLINK flag only for reparse points with the IO_REPARSE_TAG_SYMLINK tag. Microsoft reserves the right to modify this in the future to allow filtering based on arbitrary reparse tags.

The system-defined ECP_TYPE_IO_STOP_ON_SYMLINK_FILTER_GUID value is used with this ECP context structure when calling ECP-related support routines such as [**FltAllocateExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter) and [**FsRtlRemoveExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveextracreateparameter).