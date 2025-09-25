## Description

The **ADDRESS_AND_SIZE_TO_SPAN_PAGES** macro returns the number of pages that a virtual range spans. The virtual range is defined by a virtual address and the size in bytes of a transfer request.

## Parameters

### `Va` [in]

Pointer to the virtual address that is the base of the range.

### `Size` [in]

Specifies the size in bytes of the transfer request.

## Return value

Returns the number of pages spanned by the virtual range starting at **Va**.

## Remarks

Drivers that make DMA transfers call **ADDRESS_AND_SIZE_TO_SPAN_PAGES** to determine whether a transfer request must be split into a sequence of device DMA operations.

A driver can use the system-defined constant PAGE_SIZE to determine whether the number of bytes to be transferred is less than the virtual memory page size of the current platform.

Callers of **ADDRESS_AND_SIZE_TO_SPAN_PAGES** can be running at any IRQL. The caller must ensure that the specified parameters do not cause memory overflow.