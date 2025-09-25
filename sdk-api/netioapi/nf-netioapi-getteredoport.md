# GetTeredoPort function

## Description

The
**GetTeredoPort** function retrieves the dynamic UDP port number used by the Teredo client on the local computer.

## Parameters

### `Port` [out]

A pointer to the UDP port number. On successful return, this parameter will be filled with the port number used by the Teredo client.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Port* parameter. |
| **ERROR_NOT_READY** | The device is not ready. This error is returned if the Teredo client is not started on the local computer. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if no IPv6 stack is on the local computer. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **GetTeredoPort** function is defined on Windows Vista and later.

The **GetTeredoPort** function retrieves the current UDP port number used by the Teredo client for the Teredo service port. The Teredo port is dynamic and can change any time the Teredo client is restarted on the local computer. An application can register to be notified when the Teredo service port changes by calling the [NotifyTeredoPortChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyteredoportchange) function.

The Teredo client also uses static UDP port 3544 for listening to multicast traffic sent on multicast IPv4 address 224.0.0.253 as defined in RFC 4380. For more information, see [http://www.ietf.org/rfc/rfc4380.txt](https://www.ietf.org/rfc/rfc4380.txt).

The **GetTeredoPort** function is used primarily by firewall applications in order to configure the appropriate exceptions to allow incoming and outgoing Teredo traffic.

## See also

[NotifyStableUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifystableunicastipaddresstable)

[NotifyTeredoPortChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyteredoportchange)