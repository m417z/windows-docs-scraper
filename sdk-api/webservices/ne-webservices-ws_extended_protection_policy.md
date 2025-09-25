# WS_EXTENDED_PROTECTION_POLICY enumeration

## Description

Defines if [Extended Protection](https://learn.microsoft.com/windows/desktop/wsw/extended-protection) data should be validated. This property is only available on the server,
and can only be set when [WS_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding) with [WS_SSL_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_ssl_transport_security_binding) and either [WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_kerberos_apreq_message_security_binding) or [WS_HTTP_HEADER_AUTH_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_header_auth_security_binding) is used.

## Constants

### `WS_EXTENDED_PROTECTION_POLICY_NEVER:1`

Extended protection data is not validated.

### `WS_EXTENDED_PROTECTION_POLICY_WHEN_SUPPORTED:2`

If the client system supports the extended protection feature, extended protection data is looked for and validated during authentication. Otherwise it is ignored.

A server can detect whether the client's operating system supports extended protection but chose not to include the extended protection data or
whether it does not support extended protection. The former case is insecure and thus rejected. The latter is allowed when using this flag.

NOTE: If the client supports the extended protection feature, but did not include extended protection data in the authentication data, this setting will cause requests to fail. This
scenario is possible when the operating system was patched but the client web services implementation does not send the necessary data.

This is the default.

### `WS_EXTENDED_PROTECTION_POLICY_ALWAYS:3`

Extended protection data is required to be present and is always validated. Clients that are not extended-protection-aware cannot authenticate to a server
setting this flag.