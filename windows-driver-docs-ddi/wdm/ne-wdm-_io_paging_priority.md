# _IO_PAGING_PRIORITY enumeration

## Description

The **IO_PAGING_PRIORITY** enumeration describes the priority value for a paging I/O IRP.

## Constants

### `IoPagingPriorityInvalid`

The IRP is not a paging I/O IRP.

### `IoPagingPriorityNormal`

The associated IRP has a normal priority level for paging I/O.

### `IoPagingPriorityHigh`

The associated IRP has a high priority level for paging I/O.

### `IoPagingPriorityReserved1`

Reserved for system use.

### `IoPagingPriorityReserved2`

Reserved for system use.

## Remarks

The [IoGetPagingIoPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetpagingiopriority) routine returns an **IO_PAGING_PRIORITY** value to indicate the priority value of a paging I/O IRP.

## See also

[IoGetPagingIoPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetpagingiopriority)