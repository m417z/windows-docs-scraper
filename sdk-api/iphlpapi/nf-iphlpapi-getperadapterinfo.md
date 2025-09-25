# GetPerAdapterInfo function

## Description

The
**GetPerAdapterInfo** function retrieves information about the adapter corresponding to the specified interface.

## Parameters

### `IfIndex` [in]

Index of an interface.
The **GetPerAdapterInfo** function retrieves information for the adapter corresponding to this interface.

### `pPerAdapterInfo` [out]

Pointer to an
[IP_PER_ADAPTER_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_per_adapter_info_w2ksp1) structure that receives information about the adapter.

### `pOutBufLen` [in]

Pointer to a **ULONG** variable that specifies the size of the
[IP_PER_ADAPTER_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_per_adapter_info_w2ksp1) structure. If this size is insufficient to hold the information,
**GetPerAdapterInfo** fills in this variable with the required size, and returns an error code of ERROR_BUFFER_OVERFLOW.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_BUFFER_OVERFLOW** | The buffer size indicated by the *pOutBufLen* parameter is too small to hold the adapter information. The *pOutBufLen* parameter points to the required size. |
| **ERROR_INVALID_PARAMETER** | The *pOutBufLen* parameter is **NULL**, or the calling process does not have read/write access to the memory pointed to by *pOutBufLen*, or the calling process does not have write access to the memory pointed to by the *pAdapterInfo* parameter. |
| **ERROR_NOT_SUPPORTED** | [GetPerAdapterInfo](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getperadapterinfo) is not supported by the operating system running on the local computer. |
| **Other** | If the function fails, use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

 An adapter index may change when the adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

## See also

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP_PER_ADAPTER_INFO](https://learn.microsoft.com/windows/desktop/api/iptypes/ns-iptypes-ip_per_adapter_info_w2ksp1)