# WS_ENDPOINT_ADDRESS structure

## Description

Represents the network address of an endpoint.

## Members

### `url`

The URL portion of the address.

The URL is always in escaped form.

If this string is zero-length, then
the URL is assumed to be the anonymous address. The anonymous
address string is automatically mapped to/from the zero-length string
when the endpoint address is serialized or deserialized
using [WS_ENDPOINT_ADDRESS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type).

The value of this field corresponds to the Address element of the
WS-Addressing specifications.

### `headers`

A [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) handle to a set of header elements
that represent the reference parameters for the endpoint address.

The headers are required to properly interact with the endpoint.
They are used to further qualify the address (URL).

The headers should be treated as opaque values to the user of
the endpoint address.

See [WsAddressMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsaddressmessage) for information on how to
add the headers to a message being sent.

This field may be **NULL** if there are no headers.

This value of this field corresponds to the content of the
ReferenceParameters element of the WS-Addressing specifications.

### `extensions`

A [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) handle to a set of extension elements.
Extension elements are used to include additional information within an
endpoint address. This field may be **NULL** if there are no extension elements.

This value of this field corresponds to the other elements
defined by WS-Addressing and any extension elements. The elements must
appear in the correct order according to the specification, followed
by extension elements. This field should not contain elements for Address
or ReferenceParameters, or Identity, since these values are represented directly by
other fields of this structure.

If the ReferenceProperties element is present (as defined by
[WS_ADDRESSING_VERSION_0_9](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version)), it must be the first element
within the [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer).

### `identity`

The security identity of the endpoint represented by this endpoint address.

This field corresponds to the Identity element, which is an extension
of the base WS-Addressing specifications.

## Remarks

Only the URL field is required (other fields may be **NULL**).