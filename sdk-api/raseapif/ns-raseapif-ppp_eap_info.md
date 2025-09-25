# PPP_EAP_INFO structure

## Description

The
**PPP_EAP_INFO** structure provides information to the Connection Manager about the authentication protocol, including pointers to functions located in the EAP DLL.

## Members

### `dwSizeInBytes`

Specifies the size of the
**PPP_EAP_INFO** structure. RAS passes in this value to the EAP DLL. The DLL uses this value to determine which version of the
**PPP_EAP_INFO** structure RAS is using.

### `dwEapTypeId`

Specifies a particular authentication protocol. This identifier must be unique throughout industry-wide implementation of EAP. The implementer of an authentication protocol must obtain this identifier from the Internet Assigned Numbers Authority (IANA).

### `RasEapInitialize`

Pointer to the
[RasEapInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363527(v=vs.85)) function for the authentication protocol. The authentication protocol sets the value of this member. The authentication protocol may set this member to **NULL**, in which case the protocol does not require RAS to call this function.

#### fInitialize

Specifies whether the authentication protocol should initialize or de-initialize. This parameter is **TRUE** if the protocol initializes and **FALSE** if the protocol does not initialize.

### `RasEapBegin`

Pointer to the
[RasEapBegin](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363520(v=vs.85)) function for the requested authentication protocol. The authentication protocol sets the value of this member. This member may be **NULL**, in which case, the authentication protocol does not require any initialization. If this member is **NULL**, RAS ignores the **RasEapEnd** member.

#### ppWorkBuffer

Pointer to a pointer that, on successful return, points to a work buffer. This buffer is opaque to RAS; the contents of the buffer are used only by the authentication protocol. The RAS connection manager passes a pointer to this buffer to the authentication protocol in subsequent calls to
[RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85)).

#### pPppEapInput

Pointer to a
[PPP_EAP_INPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_input) structure that specifies initialization information for the authentication session.

### `RasEapEnd`

Pointer to the
[RasEapEnd](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363521(v=vs.85)) function for the authentication protocol. The authentication protocol sets the value of this member.

#### pWorkBuffer

Pointer to the work buffer to free.

### `RasEapMakeMessage`

Pointer to the
[RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85)) function for the requested authentication protocol. The authentication protocol sets the value of this member.

#### pWorkBuf

Pointer to the work buffer. The authentication protocol provides RAS with a pointer to this buffer via the
[RasEapBegin](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363520(v=vs.85)) function.

#### pReceivePacket

Pointer to a
[PPP_EAP_PACKET](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_packet) structure that contains a received packet. A *pReceivePacket* value of **NULL** indicates either that RAS is initiating the dialog with the authentication protocol, or that a time out has occurred and the authentication protocol should resend the last packet. The authentication protocol must determine, based on context, which of these two cases is true.

#### pSendPacket

Pointer to a
[PPP_EAP_PACKET](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_packet) structure. The authentication protocol can use this structure to specify a packet to send.

#### cbSendPacket

Specifies the size, in bytes, of the buffer pointed to by *pSendPacket*.

#### pEapOutput

Pointer to a
[PPP_EAP_OUTPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_output) structure.

#### pEapInput

Pointer to a
[PPP_EAP_INPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_input) structure. This parameter may be **NULL**.

## Remarks

A given EAP DLL may implement more than one authentication protocol. Use the **dwEapTypeId** member to specify for which protocol to retrieve information.

## See also

[EAP Structures](https://learn.microsoft.com/windows/win32/eap/eap-structures)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[RasEapBegin](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363520(v=vs.85))

[RasEapEnd](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363521(v=vs.85))

[RasEapGetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapgetinfo)

[RasEapMakeMessage](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363532(v=vs.85))