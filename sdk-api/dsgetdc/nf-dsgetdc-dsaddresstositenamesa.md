# DsAddressToSiteNamesA function

## Description

The **DsAddressToSiteNames** function obtains the site names corresponding to the specified addresses.

## Parameters

### `ComputerName` [in, optional]

Pointer to a null-terminated string that specifies the name of the remote server to process this function. This parameter must be the name of a domain controller. A non-domain controller can call this function by calling
[DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) to find the domain controller.

### `EntryCount` [in]

Contains the number of elements in the *SocketAddresses* array.

### `SocketAddresses` [in]

Contains an array of [SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address) structures that contain the addresses to convert. Each address in this array must be of the type **AF_INET**. *EntryCount* contains the number of elements in this array.

### `SiteNames` [out]

Receives an array of null-terminated string pointers that contain the site names for the addresses. Each element in this array corresponds to the same element in the *SocketAddresses* array. An element is **NULL** if the corresponding address does not map to any known site or if the address entry is not of the proper form. The caller must free this array when it is no longer required by calling [NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree).

## Return value

Returns **NO_ERROR** if successful or a Win32 or RPC error otherwise. The following list lists possible error codes.

## See also

[Directory Service Functions](https://learn.microsoft.com/windows/desktop/AD/directory-service-functions)

[DsAddressToSiteNamesEx](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsaddresstositenamesexa)

[DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea)

[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree)

## Remarks

> [!NOTE]
> The dsgetdc.h header defines DsAddressToSiteNames as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).