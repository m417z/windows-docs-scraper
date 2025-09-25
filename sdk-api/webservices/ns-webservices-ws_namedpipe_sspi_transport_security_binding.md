# WS_NAMEDPIPE_SSPI_TRANSPORT_SECURITY_BINDING structure

## Description

The security binding subtype for specifying the use of the Windows Integrated Authentication protocol (such as Kerberos, NTLM or SPNEGO) with the named pipe transport. A specific SSP package may be chosen using the security binding property [WS_SECURITY_BINDING_PROPERTY_WINDOWS_INTEGRATED_AUTH_PACKAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_property_id); if that property is not specified, SPNEGO is used by default.

This security binding operates at the transport security level and is supported only with the [WS_NAMEDPIPE_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding). The NamedPipe/Windows SSPI combination uses the wire form defined by the [NegotiateStream](https://learn.microsoft.com/openspecs/windows_protocols/mc-nmf/0aab922d-8023-48bb-8ba2-c4d3404cc69d) protocol and the [.Net Message Framing](https://learn.microsoft.com/openspecs/windows_protocols/ms-nns/93df08eb-a6c4-4dff-81c3-519cf7236df4) specification.

On the client side, the security identity of the target server is specified using the identity field of the [WS_ENDPOINT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_address) parameter supplied during [WsOpenChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenchannel).

The named pipe binding supports only this one transport security binding and does not support any message security bindings.

With this security binding, the following security binding properties may be specified:

* [WS_SECURITY_BINDING_PROPERTY_WINDOWS_INTEGRATED_AUTH_PACKAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_property_id)
* [WS_SECURITY_BINDING_PROPERTY_REQUIRE_SERVER_AUTH](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_property_id) (client side only)
* [WS_SECURITY_BINDING_PROPERTY_ALLOW_ANONYMOUS_CLIENTS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_property_id) (server side only)
* [WS_SECURITY_BINDING_PROPERTY_ALLOWED_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_property_id) (client side only)

This type derives from the base type [WS_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_binding). For an instance of this type, the type selector field **bindingType** must have the value [WS_NAMEDPIPE_SSPI_TRANSPORT_SECURITY_BINDING_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_type).

## Members

### `binding`

The [base type](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_binding) from which this security binding subtype and all other security binding subtypes derive.

### `clientCredential`

The [WS_WINDOWS_INTEGRATED_AUTH_CREDENTIAL](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_windows_integrated_auth_credential) structure to be used to authenticate the client. This is required on the client and must not be specified on the server.