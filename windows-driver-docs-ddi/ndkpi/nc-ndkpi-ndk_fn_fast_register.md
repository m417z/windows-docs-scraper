# NDK_FN_FAST_REGISTER callback function

## Description

The *NdkFastRegister* (*NDK_FN_FAST_REGISTER*) function fast-registers an array of adapter logical pages over an existing memory region.

## Parameters

### `pNdkQp` [in]

A pointer to an NDK queue pair (QP) object ([NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)).

### `RequestContext` [in, optional]

A context value to return in the **RequestContext** member of the [NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result) structure for this request.

### `pMr` [in]

A pointer to an NDK memory region (MR) object ([NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)) that was initialized for fast registration.

### `AdapterPageCount` [in]

The number of pages in the *AdapterPageArray* parameter. The size of each page in the *AdapterPageArray* is **PAGE_SIZE** bytes.

### `FBO` [in]

The first byte offset (FBO) within the first page. The registered region starts at this offset.

### `Length` [in]

The length, in bytes, of the region being registered starting at the FBO. The length must be less than or equal to the total number of bytes that are represented by the first set (*AdapterPageCount*) of pages that are contained in the *AdapterPageArray* array minus the FBO.

### `BaseVirtualAddress` [in]

The consumer-specified virtual address value to refer to the first byte location of the memory region. This value must be a multiple of **PAGE_SIZE** plus FBO. So, the allowed values include FBO, or FBO plus n times the **PAGE_SIZE** where n is greater than or equal to zero. Zero is a valid value only if FBO is zero.

### `Flags` [in]

A bitwise OR of flags which specifies the operations that are allowed. The following flags are supported:

| Value | Meaning |
| --- | --- |
| **NDK_OP_FLAG_SILENT_SUCCESS**<br><br>0x00000001 | Indicates the successful completion of this request does not generate a completion event in the outbound completion queue. However, requests that fail do generate an event in the completion queue. |
| **NDK_OP_FLAG_READ_FENCE**<br><br>0x00000002 | Indicates that all prior read requests must be complete before the hardware begins processing this request. |
| **NDK_OP_FLAG_ALLOW_REMOTE_READ**<br><br>0x00000008 | Enable read access to the memory region for any connected peer. To access the memory region, the connected peers must have a valid token. |
| **NDK_OP_FLAG_ALLOW_LOCAL_WRITE**<br><br>0x00000010 | Allow local write access to the memory region. |
| **NDK_OP_FLAG_ALLOW_REMOTE_WRITE**<br><br>0x00000030 | Enable write access to the memory region for any connected peer. To access the memory region, the connected peers must have a valid token. |
| **NDK_OP_FLAG_DEFER**<br><br>0x00000200 | Indicates to the NDK provider that it may defer indicating the request to hardware for processing. For more information about this flag, see [NDKPI Deferred Processing Scheme](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-deferred-processing-scheme).<br><br>**Note** This flag is supported only in NDKPI 1.2 (Windows Server 2012 R2) and later. |

### `AdapterPageArray`

An array of adapter logical addresses ([NDK_LOGICAL_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_logical_address_mapping)) where each address is the starting logical address for a page. Each address must be aligned pages that are **PAGE_SIZE** bytes in length. Consecutive addresses in the array are not necessarily consecutive in terms of the logical address space, but the array as a whole represents a virtually contiguous memory region from the perspective of the host system.

## Return value

The
*NDK_FN_FAST_REGISTER* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The request was posted successfully. A completion entry will be queued to the CQ when the work request is completed. |
| **STATUS_CONNECTION_INVALID** | The QP is not connected. |
| **STATUS_ACCESS_VIOLATION** | The memory region was not initialized for remote access during fast-register initialization but the fast-register work request specified **NDK_OP_FLAG_ALLOW_REMOTE_READ** or **NDK_OP_FLAG_ALLOW_REMOTE_WRITE**. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkFastRegister* fast-registers an array of adapter logical pages over an existing memory region that is initialized for fast registration.

After this call returns, the memory region token for remote access is available with the *NdkGetRemoteTokenFromMr* ([NDK_FN_GET_REMOTE_TOKEN_FROM_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_remote_token_from_mr)) function of the MR.

*NdkFastRegister* does not support zero-based virtual addresses.

If the **NDK_ADAPTER_FLAG_RDMA_READ_SINK_NOT_REQUIRED** flag is not set in the **AdapterFlags** member of the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure, an NDK consumer must pass the **NDK_OP_FLAG_RDMA_READ_SINK** flag when it registers memory that might be used as the sink buffer for an RDMA read request. Certain NDK providers might require the enabling of special access rights on the sink buffer for an RDMA read request. This flag allows such providers to support registration requests appropriately. Note that buffers might be registered for multiple purposes, therefore this flag might be accompanied by others.

If an NDK consumer passes the **NDK_OP_FLAG_RDMA_READ_SINK** flag on an adapter for which the **NDK_ADAPTER_FLAG_RDMA_READ_SINK_NOT_REQUIRED** flag is set in the **AdapterFlags** member of the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure, the provider is not required to handle the **NDK_OP_FLAG_RDMA_READ_SINK** flag and must not fail the request due to the presence of this flag.

## See also

[NDKPI Deferred Processing Scheme](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-deferred-processing-scheme)

[NDKPI Work Request Posting Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-work-request-posting-requirements)

[NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info)

[NDK_FN_GET_REMOTE_TOKEN_FROM_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_remote_token_from_mr)

[NDK_LOGICAL_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_logical_address_mapping)

[NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)

[NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)

[NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result)