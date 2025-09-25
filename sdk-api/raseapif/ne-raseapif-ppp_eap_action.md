# PPP_EAP_ACTION enumeration

## Description

The
**PPP_EAP_ACTION** enumerated type specifies actions that the Connection Manager should take on behalf of the authentication protocol.

## Constants

### `EAPACTION_NoAction`

Directs the Connection Manager to be passive.

### `EAPACTION_Authenticate`

Directs the Connection Manager to invoke the authentication provider to authenticate the user.

### `EAPACTION_Done`

Directs the Connection Manager Service to end the authentication session. **EAPACTION_Done** indicates that the **dwAuthResultCode** member of the
[PPP_EAP_OUTPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_output) structure is set with an appropriate value.

### `EAPACTION_SendAndDone`

Directs the Connection Manager to send a message (without a time out), then end the authentication session. **EAPACTION_SendAndDone** indicates that the **dwAuthResultCode** member of the
[PPP_EAP_OUTPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_output) structure is set with an appropriate value.

### `EAPACTION_Send`

Directs the Connection Manager to send a message without setting a time out to wait for a reply.

### `EAPACTION_SendWithTimeout`

Directs the Connection Manager to send a message and set a time out to wait for a reply.

### `EAPACTION_SendWithTimeoutInteractive`

Directs the Connection Manager to send a message and set a time out to wait for a reply, but instructs the Connection Manager not to increment the retry counter.

### `EAPACTION_IndicateTLV`

Reserved for system use.

### `EAPACTION_IndicateIdentity`

Reserved for system use.

## See also

[EAP Enumerations](https://learn.microsoft.com/windows/win32/eap/eap-enumerations)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[PPP_EAP_INPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_input)

[PPP_EAP_OUTPUT](https://learn.microsoft.com/windows/desktop/api/raseapif/ns-raseapif-ppp_eap_output)