# GetUniDirectionalAdapterInfo function

## Description

The
**GetUniDirectionalAdapterInfo** function retrieves information about the unidirectional adapters installed on the local computer. A unidirectional adapter is an adapter that can receive datagrams, but not transmit them.

## Parameters

### `pIPIfInfo` [out]

Pointer to an
[IP_UNIDIRECTIONAL_ADAPTER_ADDRESS](https://learn.microsoft.com/windows/win32/api/ipexport/ns-ipexport-ip_unidirectional_adapter_address) structure that receives information about the unidirectional adapters installed on the local computer.

### `dwOutBufLen` [out]

Pointer to a **ULONG** variable that receives the size of the structure pointed to by the *pIPIfInfo* parameter.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, use
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error.

## See also

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[IP_UNIDIRECTIONAL_ADAPTER_ADDRESS](https://learn.microsoft.com/windows/win32/api/ipexport/ns-ipexport-ip_unidirectional_adapter_address)