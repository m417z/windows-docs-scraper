# _NDK_SGE structure

## Description

The **NDK_SGE** structure specifies the local buffers for NDK work requests.

## Members

### `VirtualAddress`

A virtual address.

### `LogicalAddress`

A logical address.

### `Length`

The length, in bytes, of the buffer.

### `MemoryRegionToken`

A memory region token. When **MemoryRegionToken** is set to the token returned by *NdkGetPrivilegedMemoryRegionToken* ([NDK_FN_GET_PRIVILEGED_MEMORY_REGION_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_privileged_memory_region_token)), the **NDK_SGE** must contain a **LogicalAddress**. When **MemoryRegionToken** is not equal to the token returned by *NdkGetPrivilegedMemoryRegionToken*, the **NDK_SGE** structure must contain a **VirtualAddress**. When an **NDK_SGE** structure is used in a work request with the **NDK_OP_FLAG_INLINE** flag, **MemoryRegionToken** might be invalid. See the remarks section for more information about the **MemoryRegionToken**.

## Remarks

The **NDK_SGE** structure specifies the local buffers for send, receive, read, and write work requests.

When the **MemoryRegionToken** member is set to the token returned by *NdkGetPrivilegedMemoryRegionToken* ([NDK_FN_GET_PRIVILEGED_MEMORY_REGION_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_privileged_memory_region_token)), the **NDK_SGE** must contain a logical address returned by the *NdkBuildLam* ([NDK_FN_BUILD_LAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_build_lam)) function with the [NDK_LOGICAL_ADDRESS_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_logical_address_mapping) structure. Note that consecutive entries in the **AdapterPageArray** member of an **NDK_LOGICAL_ADDRESS_MAPPING** are not necessarily contiguous pages in the adapter's logical address space. Therefore, an NDK consumer might use multiple SGEs to cover all of the pages in an adapter page array.

When the token in the **MemoryRegionToken** member is not equal to the token that is returned by *NdkGetPrivilegedMemoryRegionToken*, the **NDK_SGE** structure must contain a virtual address that falls within the virtual address span of a previously registered memory region.

When an **NDK_SGE** structure is used in a work request with the **NDK_OP_FLAG_INLINE** flag, the token in **MemoryRegionToken** might be invalid, so it must be ignored by the NDK provider. When the **NDK_OP_FLAG_INLINE** flag is specified, the **VirtualAddress** member of any **NDK_SGE** structure that is passed to the work request function must point to a buffer that can be accessed by the NDK provider at an IRQL less than or equal to **DISPATCH_LEVEL**, That is, the buffer must be guaranteed to be resident in physical memory until the work request function returns. The total size of inline data that is passed to the provider in a single call must not exceed the value in the *InlineDataSize* parameter that was specified when the queue pair (QP) was created.

## See also

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_FN_BUILD_LAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_build_lam)

[NDK_FN_GET_PRIVILEGED_MEMORY_REGION_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_privileged_memory_region_token)

[NDK_FN_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_read)

[NDK_FN_RECEIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_receive)

[NDK_FN_SEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_send)

[NDK_FN_SRQ_RECEIVE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_srq_receive)

[NDK_FN_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_write)

[NDK_LOGICAL_ADDRESS_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_logical_address_mapping)