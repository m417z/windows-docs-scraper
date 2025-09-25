# WS_SECURITY_HEADER_LAYOUT enumeration

## Description

The layout rules applied to the elements of the WS-Security
security header. This setting is relevant to message security
bindings and mixed-mode security bindings.

## Constants

### `WS_SECURITY_HEADER_LAYOUT_STRICT:1`

The elements of the security header must follow a 'declare before use'
layout. All security tokens must appear before their usage.

### `WS_SECURITY_HEADER_LAYOUT_LAX:2`

The elements of the security header can be in arbitrary order,
including security tokens appearing after usage.

### `WS_SECURITY_HEADER_LAYOUT_LAX_WITH_TIMESTAMP_FIRST:3`

The elements of the security header can be in arbitrary order as in [WS_SECURITY_HEADER_LAYOUT_LAX](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_header_layout), but the timestamp element must
be the first element.

### `WS_SECURITY_HEADER_LAYOUT_LAX_WITH_TIMESTAMP_LAST:4`

The elements of the security header can be in arbitrary order as in [WS_SECURITY_HEADER_LAYOUT_LAX](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_header_layout), but the timestamp element must
be the last element.