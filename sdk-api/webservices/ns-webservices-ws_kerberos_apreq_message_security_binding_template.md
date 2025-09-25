# WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING_TEMPLATE structure

## Description

The security binding template for specifying the use of the Kerberos
AP_REQ ticket as a direct (i.e., without establishing a session)
security token with WS-Security.

See also [WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_kerberos_apreq_message_security_binding)

## Members

### `securityBindingProperties`

Application provided security binding properties that cannot be represented in policy.

### `clientCredential`

The Windows credential to be used to obtain the Kerberos ticket. This
field is required on the client side, but must be **NULL** on the server
side.