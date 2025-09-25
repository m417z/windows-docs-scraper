# WS_ADDRESSING_VERSION enumeration

## Description

Identifies the version of the specification used for
the addressing headers.

## Constants

### `WS_ADDRESSING_VERSION_0_9:1`

The message addressing headers correspond to version 0.9 (August 2004)
of the addressing specification [Web Services Addressing (WS-Addressing)](https://www.w3.org/Submission/ws-addressing/).

### `WS_ADDRESSING_VERSION_1_0:2`

The message addressing headers correspond to version 1.0 (May 2006)
of the addressing specification [Web Services Addressing 1.0 - Core](https://www.w3.org/TR/ws-addr-core/).

### `WS_ADDRESSING_VERSION_TRANSPORT:3`

This addressing version indicates that the only addressing headers
supported are those that are natively supported by the underlying
transport (there are no addressing-related headers that are transmitted
as part of the SOAP envelope).

The [WS_ACTION_HEADER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_header_type) and **WS_TO_HEADER** are
automatically mapped to/from the transport-specific message locations
when messages are sent/received. Use of other **WS_HEADER_TYPE** are not supported for this addressing version.

This addressing version is only supported for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_binding).
Since the SOAP over HTTP protocol does not support sending an action on a reply,
the value of the [WS_ACTION_HEADER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_header_type) will not be transmitted by the channel.