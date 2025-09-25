# WS_EXTENDED_PROTECTION_SCENARIO enumeration

## Description

Defines how [Extended Protection](https://learn.microsoft.com/windows/desktop/wsw/extended-protection) is validated. For most configurations, the runtime can automatically determine what needs to
be validated based on the presence of the [WS_SSL_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_ssl_transport_security_binding). However, if the SSL connection is terminated at
an intermediary such as a proxy prior to reaching the server then the validation method must change, and this scenario cannot be automatically detected.

Only available on the server.

## Constants

### `WS_EXTENDED_PROTECTION_SCENARIO_BOUND_SERVER:1`

There is no SSL connection between the client and the server, or the SSL connection is terminated at the server. This is the default.

### `WS_EXTENDED_PROTECTION_SCENARIO_TERMINATED_SSL:2`

An SSL connection exists but is terminated at an intermediary. The connection between the intermediary and the server may or may not
use SSL. When this property is set, [WS_SECURITY_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_property_id) must be set as well.