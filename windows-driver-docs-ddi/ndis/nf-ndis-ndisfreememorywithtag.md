# NdisFreeMemoryWithTag function

## Description

The
**NdisFreeMemoryWithTag** function is deprecated for all NDIS versions. Use [NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority) instead.

## Parameters

### `VirtualAddress` [in]

A pointer to the base virtual address of the allocated memory. This address was returned by the
[NdisAllocateMemoryWithTag](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff550767(v=vs.85)) function.

### `Tag` [in]

A string, delimited by single quotation marks, with up to four characters, usually specified in
reversed order. The NDIS-supplied default tag for this call is 'maDN', but the caller can override this
default by supplying an explicit value.

## Remarks

Because noncached memory and contiguous memory are seldom released until the allocating miniport
driver is unloading, a caller of
**NdisFreeMemoryWithTag** usually is running at IRQL = PASSIVE_LEVEL for these types of de-allocations.
In any case:

* When a caller of
  **NdisFreeMemoryWithTag** releases contiguous memory, it must be running at IRQL = PASSIVE_LEVEL.
* When a caller of
  **NdisFreeMemoryWithTag** releases noncached memory, it must be running at IRQL <
  DISPATCH_LEVEL.
* When a caller of
  **NdisFreeMemoryWithTag** releases memory that is neither contiguous nor noncached, it must be
  running at IRQL <= DISPATCH_LEVEL.

## See also

[NdisAllocateMemoryWithTag](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff550767(v=vs.85))