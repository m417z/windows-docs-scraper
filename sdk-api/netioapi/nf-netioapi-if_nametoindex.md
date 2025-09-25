# if_nametoindex function

## Description

The
**if_nametoindex** function converts the ANSI interface name for a network interface to the local index for the interface.

## Parameters

### `InterfaceName` [in]

A pointer to a **NULL**-terminated ANSI string containing the interface name.

## Return value

On success,
**if_nametoindex** returns the local interface index. On failure, zero is returned.

## Remarks

The **if_nametoindex** function is available on Windows Vista and later.

The **if_nametoindex** function maps an interface name into its corresponding
index. This function is designed as part of basic socket extensions for IPv6 as described by the IETF in RFC 2553. For more information, see [http://www.ietf.org/rfc/rfc2553.txt](http://tools.ietf.org/html/rfc2553).

The **if_nametoindex** function is implemented for portability of applications with Unix environments, but the ConvertInterface functions are preferred. The **if_nametoindex** function can be replaced by a call to the [ConvertInterfaceNameToLuidA](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfacenametoluida) function to convert the ANSI interface name to a [NET_LUID](https://learn.microsoft.com/windows/desktop/api/ifdef/ns-ifdef-net_luid_lh) followed by a call to the [ConvertInterfaceLuidToIndex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtoindex) to convert the NET_LUID to the local interface index.

If the **if_nametoindex** function fails and returns zero, it is not possible to determine an error code.

## See also

[ConvertInterfaceAliasToLuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfacealiastoluid)

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