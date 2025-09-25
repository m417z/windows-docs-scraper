# WS_TCP_SSPI_TRANSPORT_SECURITY_BINDING structure

## Description

The security binding subtype for specifying the use of the Windows
Integrated Authentication protocol (such as Kerberos, NTLM or SPNEGO)
with the TCP transport. A specific SSP package may be chosen using
the security binding property
[WS_SECURITY_BINDING_PROPERTY_WINDOWS_INTEGRATED_AUTH_PACKAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id);
if that property is not specified, SPNEGO is used by default. The use
of NTLM is strongly discouraged due to its security weakness
(specifically, lack of server authentication). If NTLM is to be
allowed, the security binding property **WS_SECURITY_BINDING_PROPERTY_REQUIRE_SERVER_AUTH**
must be set to **FALSE**.

This security binding operates at the transport security level and is
supported only with the [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding). The
TCP/Windows SSPI combination uses the wire form defined by the
NegotiateStreamprotocol and the .Net Message Framing specification.

On the client side, the security identity of the target server is
specified using the identity field of the [WS_ENDPOINT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_address)
parameter supplied during [WsOpenChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenchannel). If the identity is a
[WS_SPN_ENDPOINT_IDENTITY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_spn_endpoint_identity) or a [WS_UPN_ENDPOINT_IDENTITY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_upn_endpoint_identity),
that string identity value is used directly with the SSP. If the identity is a
[WS_DNS_ENDPOINT_IDENTITY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_dns_endpoint_identity) and the value of its dns field is
'd1', or if no identity is specified in the **WS_ENDPOINT_ADDRESS**
and the host component (according to Section 3.2.2 of
RFC2396) the address URI
is 'd1', then the form 'host/d1' is used as the server SPN.
Specifying any other [WS_ENDPOINT_IDENTITY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_identity) subtype in
**WS_ENDPOINT_ADDRESS** will cause **WsOpenChannel** to fail.

With this security binding, the following security binding properties may be specified:

* [WS_SECURITY_BINDING_PROPERTY_WINDOWS_INTEGRATED_AUTH_PACKAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id)
* [WS_SECURITY_BINDING_PROPERTY_REQUIRE_SERVER_AUTH](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id) (client side only)
* [WS_SECURITY_BINDING_PROPERTY_ALLOW_ANONYMOUS_CLIENTS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id) (server side only)
* [WS_SECURITY_BINDING_PROPERTY_ALLOWED_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_binding_property_id) (client side only)

## Members

### `binding`

The base type from which this security binding subtype and all other security binding subtypes derive.

### `clientCredential`

The Windows Integrated Authentication credential to be used to
authenticate the client. This is required on the client and must not
be specified on the server.