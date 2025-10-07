# if\_nametoindex function

The **if\_nametoindex** function converts the ANSI interface name for a network interface to the local index for the interface.

## Parameters

- *InterfaceName* \[in\]
A pointer to a NULL-terminated ANSI string that contains the interface name.

## Return value

If the function succeeds, **if\_nametoindex** returns the local interface index. If the function fails, **if\_nametoindex** returns zero.

## Remarks

The **if\_nametoindex** function maps an interface name into its corresponding index. This function is designed as part of basic socket extensions for IPv6 as described by the IETF in [RFC 2553](https://www.ietf.org/rfc/rfc2553.txt).

The **if\_nametoindex** function is implemented for portability of drivers with Unix environments, but the **ConvertInterface*Xxx*** functions are the preferred method to convert network interface identifiers. You can replace the **if\_nametoindex** function by a call to the [**ConvertInterfaceNameToLuidA**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfacenametoluida) function to convert the ANSI interface name to a [**NET\_LUID**](https://learn.microsoft.com/windows-hardware/drivers/network/net-luid-value) union, followed by a call to the [**ConvertInterfaceLuidToIndex**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtoindex) function to convert NET\_LUID to the local interface index.

If the **if\_nametoindex** function fails and returns zero, you cannot determine an error code.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | PASSIVE_LEVEL |

## See also

[**ConvertInterfaceLuidToIndex**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtoindex)

[**ConvertInterfaceNameToLuidA**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfacenametoluida)

[**NET\_LUID**](https://learn.microsoft.com/windows-hardware/drivers/network/net-luid-value)