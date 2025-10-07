# MULTICAST\_LOOPBACK\_MODE enumeration

\[**MULTICAST\_LOOPBACK\_MODE** is not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API provides similar functionality.\]

The **MULTICAST\_LOOPBACK\_MODE** enum describes the multicast loopback mode.

## Constants

**MM\_NO\_LOOPBACK**

Multicast loopback is disabled. That means two applications on the same machine joining the same multicast group can get each other's packets.

**MM\_FULL\_LOOPBACK**

All the packets sent out are looped back as well. This mode is useful only for testing.

**MM\_SELECTIVE\_LOOPBACK**

Selective loopback is enabled. That means enabled multiple applications on one machine can join the same multicast group without confusion. The packets are looped back from the stack and each RTP session is responsible for filtering out unwanted packets.

## Requirements

| Requirement | Value |
|-------------------------|---------------------------------------------------------------------------------------|
| TAPI version<br> | Requires TAPI 3.0 or later<br> |
| Header<br> | Confpriv.h |

## See also

[**IMulticastControl::get\_LoopbackMode**](https://learn.microsoft.com/windows/win32/tapi/imulticastcontrol-get-loopbackmode)

[**IMulticastControl::put\_LoopbackMode**](https://learn.microsoft.com/windows/win32/tapi/imulticastcontrol-put-loopbackmode)

