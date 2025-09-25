# NDK_FN_QUERY_ADAPTER_INFO callback function

## Description

The *NdkQueryAdapterInfo* (*NDK_FN_QUERY_ADAPTER_INFO*) function retrieves information about limits and capabilities of an NDK adapter.

## Parameters

### `pNdkAdapter` [in]

A pointer to an NDK adapter ([NDK_ADAPTER)](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter) instance.

### `pInfo`

A pointer to a buffer that contains an [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure. If the request completes with STATUS_SUCCESS, the NDK provider fills the structure with adapter information.

### `pBufferSize`

On input, this parameter is a pointer to a variable that holds the size, in bytes, of the buffer that the *pInfo* parameter points to. On output, the variable receives the size, in bytes, of the adapter information that was written into the buffer.

## Return value

The
*NdkQueryAdapterInfo* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The request completed successfully. |
| **STATUS_BUFFER_TOO_SMALL** | The value in the **pBufferSize* parameter specified a buffer size that was too small to hold the adapter information. **pBufferSize* is updated with the required size. |
| **Other status codes** | An error occurred. |

## Remarks

*NdkQueryAdapterInfo* retrieves the adapter information in an [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure. The structure contains information on various limits and capabilities of the adapter.

*NdkQueryAdapterInfo* requires an IRQL equal to PASSIVE_LEVEL and it blocks until the request is completed.

## See also

[NDK_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter)

[NDK_ADAPTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_adapter_dispatch)

[NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info)