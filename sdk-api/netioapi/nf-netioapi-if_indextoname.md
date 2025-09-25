# if_indextoname function

## Description

The
**if_indextoname** function converts the local index for a network interface to the ANSI interface name.

## Parameters

### `InterfaceIndex` [in]

The local index for a network interface.

### `InterfaceName` [out]

A pointer to a buffer to hold the **NULL**-terminated ANSI string containing the interface name when the function returns successfully. The length, in bytes, of the buffer pointed to by this parameter must be equal to or greater than
**IF_NAMESIZE**.

## Return value

On success,
**if_indextoname** returns a pointer to **NULL**-terminated ANSI string containing the interface name. On failure, a **NULL** pointer is returned.

## Remarks

The **if_indextoname** function is available on Windows Vista and later.

The **if_indextoname** function maps an interface index into its corresponding
name. This function is designed as part of basic socket extensions for IPv6 as described by the IETF in RFC 2553. For more information, see [http://www.ietf.org/rfc/rfc2553.txt](http://tools.ietf.org/html/rfc2553).

The **if_indextoname** function is implemented for portability of applications with Unix environments, but the ConvertInterface functions are preferred. The **if_indextoname** function can be replaced by a call to the [ConvertInterfaceIndexToLuid](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceindextoluid) function to convert an interface index to a [NET_LUID](https://learn.microsoft.com/windows/desktop/api/ifdef/ns-ifdef-net_luid_lh) followed by a call to the [ConvertInterfaceLuidToNameA](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-convertinterfaceluidtonamea) to convert the NET_LUID to the ANSI interface name.

If the **if_indextoname** fails and returns a **NULL** pointer, it is not possible to determine an error code.

The length, in bytes, of the buffer pointed to by the *InterfaceName* parameter must be equal or greater than **IF_NAMESIZE**, a value declared in the *Netioapi.h* header file equal to **NDIS_IF_MAX_STRING_SIZE**. The maximum length of an interface name, **NDIS_IF_MAX_STRING_SIZE**, without the terminating **NULL** is declared in the *Ntddndis.h* header file. The **NDIS_IF_MAX_STRING_SIZE** is defined to be the **IF_MAX_STRING_SIZE** constant defined in the *Ifdef.h* header file. The *Ntddndis.h* and *Ifdef.h* header files are automatically included in the *Netioapi.h* header file which is automatically included by the *Iphlpapi.h* header file. The *Ntddndis.h*, *Ifdef.h*, and  *Netioapi.h* header files should never be used directly.

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

[if_nametoindex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-if_nametoindex)