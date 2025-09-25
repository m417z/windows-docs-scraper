# NdisFreeMemoryWithTagPriority function

## Description

The
**NdisFreeMemoryWithTagPriority** function releases memory that was allocated with the
[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority) function.

## Parameters

### `NdisHandle` [in]

An NDIS driver or instance handle that was obtained during caller initialization. This should be
the same handle that the driver passed to the
[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority) function. For example, a miniport driver can use the NDIS handle
that it obtained from the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) or
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
Other NDIS drivers can use the handles from the following functions:

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

### `VirtualAddress` [in]

A pointer to the base virtual address of the allocated memory. This address was returned by the
[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority) function.

### `Tag` [in]

A string, delimited by single quotation marks, with up to four characters, usually specified in
reversed order. The NDIS-supplied default tag for this call is 'maDN', but the caller can override this
default by supplying an explicit value.

## Remarks

Because noncached memory and contiguous memory are seldom released until the allocating miniport
driver is unloading, a caller of
**NdisFreeMemoryWithTagPriority** usually is running at IRQL = PASSIVE_LEVEL for these types of
de-allocations. In any case:

* When a caller of
  **NdisFreeMemoryWithTagPriority** releases contiguous memory, it must be running at IRQL =
  PASSIVE_LEVEL.
* When a caller of
  **NdisFreeMemoryWithTagPriority** releases noncached memory, it must be running at IRQL <
  DISPATCH_LEVEL.
* When a caller of
  **NdisFreeMemoryWithTagPriority** releases memory that is neither contiguous nor noncached, it must
  be running at IRQL <= DISPATCH_LEVEL.

## See also

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)