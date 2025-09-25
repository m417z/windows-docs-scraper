# PPP_EAP_PACKET structure

## Description

The
**PPP_EAP_PACKET** structure specifies information about a packet being processed by the authentication protocol.

## Members

### `Code`

Specifies the type of packet that is sent or received by the authentication protocol. This parameter is one of the four following values.

| Value | Meaning |
| --- | --- |
| **EAPCODE_Request** | The packet is a request. |
| **EAPCODE_Response** | The packet is a response. |
| **EAPCODE_Success** | The packet indicates success. |
| **EAPCODE_Failure** | The packet indicates failure. |

### `Id`

Specifies the identifier of the packet. The authentication protocol is responsible for maintaining packet counts for sessions, as that packet count pertains to EAP activity.

### `Length`

Specifies the length of the packet.

### `Data`

Specifies the data transmitted by this packet. If the packet is a request or a response packet, the first byte of this member signifies its type. For more information about packet types and requirements for type reservation, refer to
[RFC 2284](https://www.ietf.org/rfc/rfc2284.txt).

## See also

[EAP Structures](https://learn.microsoft.com/windows/win32/eap/eap-structures)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[PPP_EAP_INFO](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_info)

[PPP_EAP_INPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_input)

[PPP_EAP_OUTPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_output)

[RasEapGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapgetinfo)

[RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85))