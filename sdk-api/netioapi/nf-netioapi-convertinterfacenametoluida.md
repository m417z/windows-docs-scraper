# ConvertInterfaceNameToLuidA function

## Description

The
**ConvertInterfaceNameToLuidA** function converts an ANSI network interface name to the locally unique identifier (LUID) for the interface.

## Parameters

### `InterfaceName` [in]

A pointer to a **NULL**-terminated ANSI string containing the network interface name.

### `InterfaceLuid` [out]

A pointer to the [NET_LUID](https://learn.microsoft.com/windows/desktop/api/ifdef/ns-ifdef-net_luid_lh) for this interface.

## Return value

On success,
**ConvertInterfaceNameToLuidA** returns **NETIO_ERROR_SUCCESS**. Any nonzero return value indicates failure.

| Error code | Meaning |
| --- | --- |
| **ERROR_BUFFER_OVERFLOW** | The length of the ANSI interface name was invalid. This error is returned if the *InterfaceName* parameter exceeded the maximum allowed string length for this parameter. |
| **ERROR_INVALID_NAME** | The interface name was invalid. This error is returned if the *InterfaceName* parameter contained an invalid name. |
| **ERROR_INVALID_PARAMETER** | One of the parameters was invalid. This error is returned if the *InterfaceLuid* parameter was **NULL**. |

## Remarks

The **ConvertInterfaceNameToLuidA** function is available on Windows Vista and later.

The **ConvertInterfaceNameToLuidA** function is protocol independent and works with network interfaces for both the IPv6 and IPv4 protocol. The **ConvertInterfaceNameToLuidA** converts an ANSI interface name to a LUID.

The [ConvertInterfaceNameToLuidW](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfacenametoluidw) converts a Unicode interface name to a LUID.

The maximum length of an interface name, **NDIS_IF_MAX_STRING_SIZE**, without the terminating **NULL** is declared in the *Ntddndis.h* header file. The **NDIS_IF_MAX_STRING_SIZE** is defined to be the **IF_MAX_STRING_SIZE** constant defined in the *Ifdef.h* header file. The *Ntddndis.h* and *Ifdef.h* header files are automatically included in the *Netioapi.h* header file which is automatically included by the *Iphlpapi.h* header file. The *Ntddndis.h*, *Ifdef.h*, and  *Netioapi.h* header files should never be used directly.

## See also

[ConvertInterfaceAliasToLuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfacealiastoluid)

[ConvertInterfaceGuidToLuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceguidtoluid)

[ConvertInterfaceIndexToLuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceindextoluid)

[ConvertInterfaceLuidToAlias](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtoalias)

[ConvertInterfaceLuidToGuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtoguid)

[ConvertInterfaceLuidToIndex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtoindex)

[ConvertInterfaceLuidToNameA](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtonamea)

[ConvertInterfaceLuidToNameW](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtonamew)

[ConvertInterfaceNameToLuidW](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfacenametoluidw)

[NET_LUID](https://learn.microsoft.com/windows/desktop/api/ifdef/ns-ifdef-net_luid_lh)

[if_indextoname](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-if_indextoname)

[if_nametoindex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-if_nametoindex)