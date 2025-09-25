# NDK_FN_REGISTER_MR callback function

## Description

The *NdkRegisterMr* (*NDK_FN_REGISTER_MR*) function registers a virtually contiguous memory region with an NDK adapter.

## Parameters

### `pNdkMr` [in]

A pointer to an NDK memory region (MR) object
([NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)).

### `Mdl` [in]

An MDL or chain of MDLs that represent a virtually contiguous memory region from the starting virtual address up to the number of bytes specified in the *Length* parameter.

### `Length` [in]

The number of bytes to register starting from the first MDL's virtual address. The first MDL's virtual address can be obtained by calling the [MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress) macro. The length must not exceed the total number of bytes represented by the MDL chain.

### `Flags` [in]

A bitmask of flags that specify the access permissions for the registered memory region. The following flags can be set:

| Value | Meaning |
| --- | --- |
| **NDK_MR_FLAG_ALLOW_LOCAL_READ**<br><br>0x00000000 |  |
| **NDK_MR_FLAG_ALLOW_LOCAL_WRITE**<br><br>0x00000001 |  |
| **NDK_MR_FLAG_ALLOW_REMOTE_READ**<br><br>0x00000002 |  |
| **NDK_MR_FLAG_ALLOW_REMOTE_WRITE**<br><br>0x00000005 |  |
| **NDK_MR_FLAG_RDMA_READ_SINK**<br><br>0x00000008 |  |

### `RequestCompletion` [in]

A pointer to a request completion callback routine *NdkRequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)).

### `RequestContext` [in, optional]

A context value to pass to the *Context* parameter of the callback function that is specified in the *RequestCompletion* parameter.

## Return value

The
*NdkRegisterMr* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The MR registration was completed successfully. |
| **STATUS_PENDING** | The operation is pending and will be completed later. The driver will call the specified *RequestCompletion* ([NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)) function to complete the pending operation. |
| **STATUS_INVALID_PARAMETER** | The part of the MDL chain from the starting virtual address up to the length in bytes does not represent a virtually contiguous memory region. |
| **STATUS_INSUFFICIENT_RESOURCES** | The request failed due to insufficient resources. <br><br>**Important** The request can fail inline as well as asynchronously with this status code. |
| **Other status codes** | An error occurred. |

## Remarks

On an [NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr) object that was created with the *FastRegister* parameter set to FALSE, *NdkRegisterMr* is used to register a virtually contiguous memory region with the adapter.

The NDK consumer must pass an MDL or chain of MDLs that represent virtually contiguous memory region that is pinned in physical memory. The base virtual address for the memory region being registered is the virtual address indicated by the [MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress) macro. If the MDL chain does not represent a virtually contiguous memory region from the starting virtual address up to the specified length in bytes, the NDK provider must fail the request.

The provider must treat the virtual address that [MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress) returns as an index to the start of the memory region being registered. The provider must not use the virtual address as a valid virtual address for reading or writing buffer contents.

The NDK consumer must not use the MDL chain while the registration request is pending.

*NdkRegisterMr* does not support zero-based virtual addresses.

An NDK consumer must pass the **NDK_MR_FLAG_RDMA_READ_SINK** flag when it registers memory that might be used as the sink buffer for an RDMA read request. Certain NDK providers might require enabling special access rights on the sink buffer for an RDMA read request on adapters for which the **NDK_ADAPTER_FLAG_RDMA_READ_SINK_NOT_REQUIRED** flag is not set in the **AdapterFlags** member of the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure. The **NDK_MR_FLAG_RDMA_READ_SINK** flag allows such providers to support registration requests appropriately.

**Note** Buffers can be registered for multiple purposes. Therefore, the **NDK_MR_FLAG_RDMA_READ_SINK** flag might be accompanied by other flags.

If an NDK consumer passes the **NDK_MR_FLAG_RDMA_READ_SINK** flag on an adapter for which the **NDK_ADAPTER_FLAG_RDMA_READ_SINK_NOT_REQUIRED** flag is set in the **AdapterFlags** member of the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure, the provider is not required to handle the **NDK_MR_FLAG_RDMA_READ_SINK** flag and must not fail the request due to the presence of this flag.

To deregister the memory region, use the *NdkDeregisterMr* ([NDK_FN_DEREGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_deregister_mr)) function.

## See also

[MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress)

[NDKPI Object Lifetime Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-object-lifetime-requirements)

[NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info)

[NDK_FN_DEREGISTER_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_deregister_mr)

[NDK_FN_REQUEST_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_request_completion)

[NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)