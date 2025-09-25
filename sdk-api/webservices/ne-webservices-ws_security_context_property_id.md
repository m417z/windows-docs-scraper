# WS_SECURITY_CONTEXT_PROPERTY_ID enumeration

## Description

Identifies a property of a security context object. This enumeration is used with [WsGetSecurityContextProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetsecuritycontextproperty).

## Constants

### `WS_SECURITY_CONTEXT_PROPERTY_IDENTIFIER:1`

On the wire, a security context is identified by an absolute URI, which is unique to both sender and
recipient. See [WS-SecureConversation](https://docs.oasis-open.org/ws-sx/ws-secureconversation/200512/ws-secureconversation-1.3-os.html).
This property is a [WS_UNIQUE_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_unique_id) structure that represents that URI.

### `WS_SECURITY_CONTEXT_PROPERTY_USERNAME:2`

If a [WS_USERNAME_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_username_message_security_binding) is used as bootstrap security, this property
is a [WS_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_string) that represents the username that was used during the establishment of the security context.

### `WS_SECURITY_CONTEXT_PROPERTY_MESSAGE_SECURITY_WINDOWS_TOKEN:3`

If a [WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_kerberos_apreq_message_security_binding) is used as bootstrap security, this property
is a **HANDLE** that represents the token that was used during the establishment of the security context.

### `WS_SECURITY_CONTEXT_PROPERTY_SAML_ASSERTION:4`

If a [WS_SAML_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_saml_message_security_binding) is used as bootstrap security, this property
is a pointer to a [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) that represents the SAML assertion that was used during the establishment of the security context.