# NDK_FN_BIND callback function

## Description

The *NdkBind* (*NDK_FN_BIND*) function binds a memory window to a specific sub-region of a memory region (MR).

## Parameters

### `pNdkQp` [in]

A pointer to an NDK queue pair (QP) object ([NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)).

### `RequestContext` [in, optional]

A context value to return in the **RequestContext** member of the [NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result) structure for this request.

### `pMr` [in]

A pointer to an NDK memory region (MR) object ([NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)).

### `pMw` [in]

A pointer to an NDK memory window (MW) object ([NDK_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mw)).

### `VirtualAddress` [in]

A virtual address that must be greater than or equal to the virtual address of the MDL for the MR and less than the virtual address of the MDL for the MR plus the value in the *Length* parameter.

Use the [MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress) macro to obtain the virtual address of the MDL for the MR.

### `Length` [in]

The length of the MR to bind to the MW.

### `Flags` [in]

A bitwise OR of flags which specifies the operations that are allowed. The following flags are supported:

| Value | Meaning |
| --- | --- |
| **NDK_OP_FLAG_SILENT_SUCCESS**<br><br>0x00000001 | Indicates the successful completion of this request does not generate a completion event in the outbound completion queue. However, requests that fail do generate a completion in the completion queue. |
| **NDK_OP_FLAG_READ_FENCE**<br><br>0x00000002 | Indicates that all prior read requests must be complete before the hardware begins processing this request. |
| **NDK_OP_FLAG_ALLOW_REMOTE_READ**<br><br>0x00000008 | Enable read access to the memory window for any connected peer. To access the memory window, the connected peers must have a valid token. |
| **NDK_OP_FLAG_ALLOW_REMOTE_WRITE**<br><br>0x00000030 | Enable write access to the memory window for any connected peer. To access the memory window, the connected peers must have a valid token. |
| **NDK_OP_FLAG_DEFER**<br><br>0x00000200 | Indicates to the NDK provider that it may defer indicating the request to hardware for processing. For more information about this flag, see [NDKPI Deferred Processing Scheme](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-deferred-processing-scheme).<br><br>**Note** This flag is supported only in NDKPI 1.2 (Windows Server 2012 R2) and later. |

## Return value

The
*NdkBind* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The request was posted successfully. A completion entry will be queued to the CQ when the work request is completed. |
| **STATUS_CONNECTION_INVALID** | The queue pair (QP) is not connected. |
| **STATUS_ACCESS_VIOLATION** | The memory region does not allow the type of access requested for the memory window. The NDK_OP_FLAG_ALLOW_WRITE flag requires a memory region that was registered with the NDK_MR_FLAG_ALLOW_LOCAL_WRITE flag. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkBind* binds a memory window (MW) to a specific sub-region of a memory region (MR).

The address in the *VirtualAddress* parameter must be an address within the virtually contiguous region that is described by the MDL chain that was specified during memory registration. The address must be treated by the provider as an index into the memory region. The address must not be used by the provider as a valid virtual address for reading or writing buffer contents.

After this call returns, the remote token will be available with the *NdkGetRemotetokenFromMw* function ([NDK_FN_GET_REMOTE_TOKEN_FROM_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_remote_token_from_mw)).

This function does not support a zero-based virtual address.

## See also

[MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress)

[NDKPI Deferred Processing Scheme](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-deferred-processing-scheme)

[NDKPI Work Request Posting Requirements](https://learn.microsoft.com/windows-hardware/drivers/network/ndkpi-work-request-posting-requirements)

[NDK_FN_GET_REMOTE_TOKEN_FROM_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_remote_token_from_mw)

[NDK_MR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mr)

[NDK_MW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_mw)

[NDK_QP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_qp)

[NDK_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_result)