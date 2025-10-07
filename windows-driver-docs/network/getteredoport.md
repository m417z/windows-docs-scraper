# GetTeredoPort function

The **GetTeredoPort** function retrieves the dynamic UDP port number that the Teredo client uses on a local computer.

## Parameters

- *Port* \[out\]
A pointer to the UDP port number. On successful return, this parameter is filled with the port number that the Teredo client uses.

## Return value

**GetTeredoPort** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **GetTeredoPort** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Port* parameter. |
| **ERROR_NOT_READY** | The device is not ready. This error is returned if the Teredo client is not started on the local computer. |
| **STATUS_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv6 stack is located on the local computer. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetTeredoPort** function retrieves the current UDP port number that the Teredo client uses for the Teredo service port. The Teredo port is dynamic and can change any time that the Teredo client is restarted on the local computer. A driver can register to be notified when the Teredo service port changes by calling the [**NotifyTeredoPortChange**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyteredoportchange) function.

The Teredo client also uses static UDP port 3544 for listening to multicast traffic that is sent on multicast IPv4 address 224.0.0.253 as defined in RFC 4380. For more information, see [Teredo: Tunneling IPv6 over UDPthrough Network Address Translations (NATs)](https://go.microsoft.com/fwlink/p/?linkid=84066).

The **GetTeredoPort** function is used primarily by firewall drivers in order to configure the appropriate exceptions to enable incoming and outgoing Teredo traffic.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**NotifyTeredoPortChange**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyteredoportchange)

[**NotifyStableUnicastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/notifystableunicastipaddresstable)