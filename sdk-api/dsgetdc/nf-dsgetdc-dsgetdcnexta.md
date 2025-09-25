# DsGetDcNextA function

## Description

The **DsGetDcNext** function retrieves the next domain controller in a domain controller enumeration operation.

## Parameters

### `GetDcContextHandle` [in]

Contains the domain controller enumeration context handle provided by the [DsGetDcOpen](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcopena) function.

### `SockAddressCount` [out, optional]

Pointer to a **ULONG** value that receives the number of elements in the *SockAddresses* array.
If this parameter is **NULL**, socket addresses are not retrieved.

### `SockAddresses` [out, optional]

Pointer to an array of [SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address) structures that receives the socket address data for the domain controller. *SockAddressCount* receives the number of elements in this array.

All returned addresses will be of type **AF_INET** or **AF_INET6**.
The **sin_port** member contains the port from the server record.
A port of 0 indicates no port is available from DNS.

The caller must free this memory when it is no longer required by calling [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree).

This parameter is ignored if *SockAddressCount* is **NULL**.

### `DnsHostName` [out, optional]

Pointer to a string pointer that receives the DNS name of the domain controller.
This parameter receives **NULL** if no host name is known. The caller must free this memory when it is no longer required by calling [NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree).

## Return value

Returns **ERROR_SUCCESS** if successful or a Win32 or RPC error otherwise. Possible error values include the following.

## Remarks

To reset the enumeration, close the current enumeration by calling [DsGetDcClose](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcclosew) and then reopen the enumeration by calling [DsGetDcOpen](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcopena) again.

The DC returned by **DsGetDcNext** will not be a Read-only DC (RODC) because those DCs only register site-specific and CName records, and both **DsGetDcNext** and [DsGetDcOpen](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcopena) look for DNS SRV records.

The following procedure shows how to get a complete DC list from a computer running Windows Server 2008.

**To obtain a complete list of domain controllers**

1. Use [DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) to get a domain controller name.
2. Use [DsBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) to connect to that domain controller.
3. Call [DsGetDomainControllerInfo](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsgetdomaincontrollerinfoa) with InfoLevel 3 (**DS_DOMAIN_CONTROLLER_INFO_3**) to get the complete list, including RODCs.

> [!NOTE]
> The dsgetdc.h header defines DsGetDcNext as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Directory Service Functions](https://learn.microsoft.com/windows/desktop/AD/directory-service-functions)

[DsGetDcClose](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcclosew)

[DsGetDcOpen](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcopena)

[Enumerating Domain Controllers](https://learn.microsoft.com/windows/desktop/AD/enumerating-domain-controllers)

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)

[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree)

[SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address)