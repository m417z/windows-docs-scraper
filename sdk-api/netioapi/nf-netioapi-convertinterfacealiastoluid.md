# ConvertInterfaceAliasToLuid function

## Description

The
**ConvertInterfaceAliasToLuid** function converts an interface alias name for a network interface to the locally unique identifier (LUID) for the interface.

## Parameters

### `InterfaceAlias` [in]

A pointer to a **NULL**-terminated Unicode string containing the alias name of the network interface.

### `InterfaceLuid` [out]

A pointer to the [NET_LUID](https://learn.microsoft.com/windows/desktop/api/ifdef/ns-ifdef-net_luid_lh) for this interface.

## Return value

On success,
**ConvertInterfaceAliasToLuid** returns NO_ERROR. Any nonzero return value indicates failure and a **NULL** is returned in the *InterfaceLuid* parameter.

| Error code | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One of the parameters was invalid. This error is returned if either the *InterfaceAlias* or *InterfaceLuid* parameter was **NULL** or if the *InterfaceAlias* parameter was invalid. |

## Remarks

The **ConvertInterfaceAliasToLuid** function is available on Windows Vista and later.

The **ConvertInterfaceAliasToLuid** function is protocol independent and works with network interfaces for both the IPv6 and IPv4 protocol.

## See also

[ConvertInterfaceGuidToLuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceguidtoluid)

[ConvertInterfaceIndexToLuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceindextoluid)

[ConvertInterfaceLuidToAlias](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtoalias)

[ConvertInterfaceLuidToGuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtoguid)

[ConvertInterfaceLuidToIndex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtoindex)

[ConvertInterfaceLuidToNameA](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtonamea)

[ConvertInterfaceLuidToNameW](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtonamew)

[ConvertInterfaceNameToLuidA](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfacenametoluida)

[ConvertInterfaceNameToLuidW](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfacenametoluidw)

[NET_LUID](https://learn.microsoft.com/windows/desktop/api/ifdef/ns-ifdef-net_luid_lh)

[if_indextoname](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-if_indextoname)

[if_nametoindex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-if_nametoindex)