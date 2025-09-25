# MmIsRecursiveIoFault function

## Description

The **MmIsRecursiveIoFault** routine determines whether the current page fault is occurring during an I/O operation.

## Return value

**MmIsRecursiveIoFault** returns **TRUE** if a file system I/O operation is in progress for the current thread, **FALSE** otherwise.

## Remarks

When a page fault occurs, the file system can call **MmIsRecursiveIoFault** to determine whether an I/O operation is in progress for the current thread.

## See also

[MmIsAddressValid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmisaddressvalid)