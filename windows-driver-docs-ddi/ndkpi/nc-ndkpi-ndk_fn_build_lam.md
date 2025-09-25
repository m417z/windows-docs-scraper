# NDK_FN_BUILD_LAM callback function

## Description

The *NdkBuildLam* (*NDK_FN_BUILD_LAM*) function gets an adapter logical address mapping (LAM) from the NDK provider for a virtually contiguous memory region.

## Parameters

### `pNdkAdapter` [in]

A pointer to an NDK adapter object ([NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)).

### `Mdl` [in]

 A memory descriptor list (MDL) or chain of MDLs. The portion of the MDL chain from the starting virtual address up to the number of bytes in the *Length* parameter must represent a virtually contiguous memory region.

### `Length` [in]

The number of bytes to map starting from the first MDL's virtual address. The MDL virtual address can be obtained with the [MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress) macro. *Length* must not exceed the total number of bytes represented by the MDL chain.

### `RequestCompletion` [in]

A pointer to a *NdkRequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)) callback function.

### `RequestContext` [in, optional]

A context value for the provider to pass back to the *NdkRequestCompletion* callback function that is specified in the *RequestCompletion* parameter.

### `pNdkLAM`

A pointer to a buffer that will hold an [NDK_LOGICAL_ADDRESS_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_logical_address_mapping) structure that contains an adapter page array. The adapter page array is stored in the **AdapterPageArray** member and the **AdapterPageCount** member contains the number of adapter page elements.

### `pLAMSize`

The size, in bytes, of the buffer at the *pNdkLAM* parameter for input, or the actual number of bytes written for output.

### `pFBO` [out]

The first byte offset (FBO) value is returned in this location. The FBO is the starting offset within the first adapter page.

## Return value

The
*NdkBuildLam* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_PENDING** | The request is pending, the function specified at the *RequestCompletion* parameter([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)) will be called when the LAM build operation is complete. |
| **STATUS_INVALID_PARAMETER** | The portion of the MDL chain from the starting virtual address up to the number of bytes specified in the *Length* parameter does not represent a virtually contiguous memory region. |
| **STATUS_INSUFFICIENT_RESOURCES** | The request failed due to insufficient resources. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **STATUS_BUFFER_TOO_SMALL** | The buffer size indicated by the **pLAMSize* parameter is too small to hold the LAM. In this case, the value of **pLAMSize* is updated with the required buffer size. |
| **Other status codes** | An error occurred. |

## Remarks

The part of the MDL chain from the starting virtual address up to the number of bytes specified in the *Length* parameter must represent a virtually contiguous memory region. Otherwise, the NDK provider must fail the request. It is the responsibility of the NDK consumer to ensure that the MDL chain is locked. That is, the pages of the MDL change are pinned in physical memory.

**Important** The NDK consumer must not use the MDL chain while *NdkBuildLam* is pending completion.

An adapter accesses physical memory with logical addresses. This is similar to a CPU accessing physical memory with virtual addresses. If an NDK consumer will use physical memory pages directly as local data buffers in send, receive, read, or write requests, it must get an NDK adapter logical address mapping from the NDK provider and use the logical addresses rather than physical addresses. Similarly, an NDK consumer must also use logical addresses in fast-register requests.

An NDK consumer can call the *NdkGetPrivilegedMemoryRegionToken* ([NDK_FN_GET_PRIVILEGED_MEMORY_REGION_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_privileged_memory_region_token)) function to get a privileged memory region token from an NDK provider.

All adapter pages returned by an NDK provider must be of **PAGE_SIZE** bytes in length, where **PAGE_SIZE** is the memory page size that is supported by the host platform as defined in wdm.h.

The provider must treat the virtual address value that the [MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress) macro returns for the MDL as an index to the start of the memory region being mapped. The provider must not use the virtual address value as a valid virtual address for reading or writing buffer contents.

If a provider has an error while processing an *NdkBuildLam* request, the provider must release any partial mappings it built internally thus far before completing the request with failure.

## See also

[MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress)

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)

[NDK_ADAPTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter_dispatch)

[NDK_FN_GET_PRIVILEGED_MEMORY_REGION_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_privileged_memory_region_token)

[NDK_FN_RELEASE_LAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_release_lam)

[NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)

[NDK_LOGICAL_ADDRESS_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_logical_address_mapping)