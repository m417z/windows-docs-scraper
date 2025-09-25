# ConvertInterfaceLuidToNameA function

## Description

The
**ConvertInterfaceLuidToNameA** function converts a locally unique identifier (LUID) for a network interface to the ANSI interface name.

## Parameters

### `InterfaceLuid` [in]

A pointer to a [NET_LUID](https://learn.microsoft.com/windows/desktop/api/ifdef/ns-ifdef-net_luid_lh) for a network interface.

### `InterfaceName` [out]

A pointer to a buffer to hold the **NULL**-terminated ANSI string containing the interface name when the function returns successfully.

### `Length` [in]

The length, in bytes, of the buffer pointed to by the *InterfaceName* parameter. This value must be large enough to accommodate the interface name
and the terminating null character. The maximum required length is
**NDIS_IF_MAX_STRING_SIZE** + 1.

## Return value

On success,
**ConvertInterfaceLuidToNameA** returns **NETIO_ERROR_SUCCESS**. Any nonzero return value indicates failure.

| Error code | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the parameters was invalid. This error is returned if either the *InterfaceLuid* or the *InterfaceName* parameter was **NULL** or if the *InterfaceLuid* parameter was invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough storage is available to process this command. This error is returned if the size of the buffer pointed to by *InterfaceName* parameter was not large enough as specified in the *Length* parameter to hold the interface name. |

## Remarks

The **ConvertInterfaceLuidToNameA** function is available on Windows Vista and later.

The **ConvertInterfaceLuidToNameA** function is protocol independent and works with network interfaces for both the IPv6 and IPv4 protocol. The **ConvertInterfaceLuidToNameA** converts a network interface LUID to an ANSI interface name.

The [ConvertInterfaceLuidToNameW](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtonamew) converts a network interface LUID to a Unicode interface name.

The maximum length of an interface name, **NDIS_IF_MAX_STRING_SIZE**, without the terminating **NULL** is declared in the *Ntddndis.h* header file. The **NDIS_IF_MAX_STRING_SIZE** is defined to be the **IF_MAX_STRING_SIZE** constant defined in the *Ifdef.h* header file. The *Ntddndis.h* and *Ifdef.h* header files are automatically included in the *Netioapi.h* header file which is automatically included by the *Iphlpapi.h* header file. The *Ntddndis.h*, *Ifdef.h*, and  *Netioapi.h* header files should never be used directly.

## See also

[ConvertInterfaceAliasToLuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfacealiastoluid)

[ConvertInterfaceGuidToLuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceguidtoluid)

[ConvertInterfaceIndexToLuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceindextoluid)

[ConvertInterfaceLuidToAlias](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtoalias)

[ConvertInterfaceLuidToGuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtoguid)

[ConvertInterfaceLuidToIndex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtoindex)

[ConvertInterfaceLuidToNameW](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtonamew)

[ConvertInterfaceNameToLuidA](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfacenametoluida)

[ConvertInterfaceNameToLuidW](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfacenametoluidw)

[NET_LUID](https://learn.microsoft.com/windows/desktop/api/ifdef/ns-ifdef-net_luid_lh)

[if_indextoname](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-if_indextoname)

[if_nametoindex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-if_nametoindex)