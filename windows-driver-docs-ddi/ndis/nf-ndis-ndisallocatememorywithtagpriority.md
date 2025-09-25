# NdisAllocateMemoryWithTagPriority function

## Description

NDIS drivers call the
**NdisAllocateMemoryWithTagPriority** function to allocate a pool of memory from the non-paged
pool.

## Parameters

### `NdisHandle` [in]

An NDIS handle that the caller obtained during initialization. For example, a miniport driver can
use the NDIS handle that it obtained from the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) or
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
Other NDIS drivers can use the handles from the following functions:

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

### `Length` [in]

The size to be allocated, in bytes.

### `Tag` [in]

A string, delimited by single quotation marks, with up to four characters, usually specified in
reversed order. The NDIS-supplied default tag for this call is 'maDN', but the caller can override this
default by supplying an explicit value.

### `Priority` [in]

The importance of this request. For more information, see
[ExAllocatePoolWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtagpriority).

## Return value

**NdisAllocateMemoryWithTagPriority** returns a pointer to a base virtual address of the allocated
memory, or **NULL** if sufficient nonpaged memory is currently unavailable.

## Remarks

To free memory that was allocated with
**NdisAllocateMemoryWithTagPriority**, call the
[NdisFreeMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememorywithtagpriority) or [NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory) function.

## See also

[ExAllocatePoolWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtagpriority)

[FilterAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-filter_attach)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisAllocateMemoryWithTag](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff550767(v=vs.85))

[NdisFRegisterFilterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfregisterfilterdriver)

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[NdisFreeMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememorywithtagpriority)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisOpenAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapterex)

[NdisRegisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocoldriver)