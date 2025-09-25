# WS_MESSAGE_PROPERTY_ID enumeration

## Description

Each message property is of type [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property), is identified by an ID, and has an associated
value.

## Constants

### `WS_MESSAGE_PROPERTY_STATE:0`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty).

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is the current [WS_MESSAGE_STATE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state) of the message.

This property is available in all message states.

### `WS_MESSAGE_PROPERTY_HEAP:1`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty).

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is the [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) of the message. The heap is
owned by the message. A user of a message is free to make additional
allocations within this heap. Allocations within the heap are freed
when a message is reset/freed.

The user of the returned heap should not call [WsResetHeap](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetheap) on the heap. This will result in undefined behavior.

The message object will not use the heap object unless one of
the message APIs is invoked.

This property is available in all message states except [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).
Using the heap of an empty message will result in undefined behavior.

### `WS_MESSAGE_PROPERTY_ENVELOPE_VERSION:2`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty).

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is the [WS_ENVELOPE_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_envelope_version) of the message.

When creating a message using [WsCreateMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemessage), the
envelope version is specified as an explicit parameter (instead
of as a property).

This property may be specified when message properties are specified using
the [WS_MESSAGE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_properties) structure.

This property is available in all message states except [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `WS_MESSAGE_PROPERTY_ADDRESSING_VERSION:3`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty).

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is the [WS_ADDRESSING_VERSION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_addressing_version) of the message.

When creating a message using [WsCreateMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemessage), the
addressing version is specified as an explicit parameter (instead
of as a property).

This property may be specified when message properties are specified using
the [WS_MESSAGE_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_properties) structure.

This property is available in all message states except [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `WS_MESSAGE_PROPERTY_HEADER_BUFFER:4`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty).

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is a [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) that holds the headers
of the message (as well as the envelope and body elements).

This buffer is valid until the message is reset/freed.

This property is available in all message states except [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `WS_MESSAGE_PROPERTY_HEADER_POSITION:5`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty).

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is the [WS_XML_NODE_POSITION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_node_position) of the header element within the header buffer (the element that contains all
the message headers as children). The header buffer itself can be
obtained using [WS_MESSAGE_PROPERTY_HEADER_BUFFER](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_property_id).

An application can use the [WS_XML_NODE_POSITION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_node_position) returned as a starting
point when reading or writing headers manually (when not using [WsSetHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetheader),
[WsGetHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetheader), [WsGetCustomHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetcustomheader) or [WsAddCustomHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsaddcustomheader)).
For example, the position can be passed to [WsSetWriterPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetwriterposition) or
[WsSetReaderPosition](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetreaderposition) to position an [XML Reader](https://learn.microsoft.com/windows/desktop/wsw/xml-reader) or [XML Writer](https://learn.microsoft.com/windows/desktop/wsw/xml-writer) within the [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) containing the headers. Additionally,
[WsMoveReader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmovereader) or [WsMoveWriter](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsmovewriter) can be used to move relative
to the position that was set.

When the headers of a message are read (via [WsReadMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessagestart) or
[WsReadEnvelopeStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadenvelopestart), a header element is automatically added to the
header buffer if one is not present in the message being read. When a message is initialized
(via [WsInitializeMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsinitializemessage)), a header element is added automatically
to the message.

This property is available in all message states except [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

The header position is valid until the message is reset or freed.

### `WS_MESSAGE_PROPERTY_BODY_READER:6`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty).

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is a [WS_XML_READER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-reader) that can be used to read
the body of the message.

The reader is owned by the message object, and is valid only
until either [WsFreeMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreemessage) or [WsResetMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetmessage) are called.

This property is only available when the message is
in [WS_MESSAGE_STATE_READING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state) state.

### `WS_MESSAGE_PROPERTY_BODY_WRITER:7`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty).

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is a [WS_XML_WRITER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-writer) that can be used to write
the body of the message.

This property is only available when the message is in
[WS_MESSAGE_STATE_WRITING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state) state.

The writer is owned by the message object, and is valid only
until either [WsFreeMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreemessage) or [WsResetMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsresetmessage) are called.

### `WS_MESSAGE_PROPERTY_IS_ADDRESSED:8`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty).

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is a **BOOL** indicating whether the message has
been addressed.

When a message is created or reset, this property is
set to **FALSE**.

When a message is read ([WsReadMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessagestart) or
[WsReadEnvelopeStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadenvelopestart), then this property is
set to **TRUE**.

This property is available in all message states except [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

See [WsAddressMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsaddressmessage) for more information.

### `WS_MESSAGE_PROPERTY_HEAP_PROPERTIES:9`

This property is used with [WsCreateMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemessage) to specify the properties
of the [WS_HEAP](https://learn.microsoft.com/windows/desktop/wsw/ws-heap) associated with the message.

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is of type [WS_HEAP_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_heap_properties).

The heap is used to buffer the headers of the message.

The following heap properties may be specified:

* [WS_HEAP_PROPERTY_MAX_SIZE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_heap_property_id)
* [WS_HEAP_PROPERTY_TRIM_SIZE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_heap_property_id)

### `WS_MESSAGE_PROPERTY_XML_READER_PROPERTIES:10`

This property is used with [WsCreateMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemessage) to specify properties
that apply to [XML Readers](https://learn.microsoft.com/windows/desktop/wsw/xml-reader) that are used with the message.

These XML Reader properties are used by the message object when reading headers.
In addition, channels use these properties for the readers that they create to read
messages.

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is of type [WS_XML_READER_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_reader_properties).

The following properties may be specified:

* [WS_XML_READER_PROPERTY_MAX_DEPTH](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_reader_property_id)
* [WS_XML_READER_PROPERTY_MAX_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_reader_property_id)
* [WS_XML_READER_PROPERTY_READ_DECLARATION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_reader_property_id)
* [WS_XML_READER_PROPERTY_UTF8_TRIM_SIZE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_reader_property_id)
* [WS_XML_READER_PROPERTY_STREAM_BUFFER_SIZE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_reader_property_id)
* [WS_XML_READER_PROPERTY_STREAM_MAX_ROOT_MIME_PART_SIZE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_reader_property_id)
* [WS_XML_READER_PROPERTY_STREAM_MAX_MIME_HEADERS_SIZE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_reader_property_id)
* [WS_XML_READER_PROPERTY_MAX_MIME_PARTS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_reader_property_id)
* [WS_XML_READER_PROPERTY_ALLOW_INVALID_CHARACTER_REFERENCES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_reader_property_id)
* [WS_XML_READER_PROPERTY_MAX_NAMESPACES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_reader_property_id)

### `WS_MESSAGE_PROPERTY_XML_WRITER_PROPERTIES:11`

This property is used with [WsCreateMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemessage) to specify the properties
of the [XML Writers](https://learn.microsoft.com/windows/desktop/wsw/xml-writer) that are used with the message.

These XML Writer properties are used by the message object when writing headers.
In addition, channels use these properties for the writers that they create to write
messages.

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is of type [WS_XML_WRITER_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_writer_properties).

The following properties may be specified:

* [WS_XML_WRITER_PROPERTY_MAX_DEPTH](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_writer_property_id)
* [WS_XML_WRITER_PROPERTY_MAX_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_writer_property_id)
* [WS_XML_WRITER_PROPERTY_WRITE_DECLARATION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_writer_property_id)
* [WS_XML_WRITER_PROPERTY_BUFFER_TRIM_SIZE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_writer_property_id)
* [WS_XML_WRITER_PROPERTY_MAX_MIME_PARTS_BUFFER_SIZE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_writer_property_id)
* [WS_XML_WRITER_PROPERTY_ALLOW_INVALID_CHARACTER_REFERENCES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_writer_property_id)
* [WS_XML_WRITER_PROPERTY_MAX_NAMESPACES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_xml_writer_property_id)

### `WS_MESSAGE_PROPERTY_IS_FAULT:12`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty) or [WsSetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetmessageproperty) to indicate whether a message contains a fault.

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is a **BOOL**.

When a message is read ([WsReadMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadmessagestart) or [WsReadEnvelopeStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadenvelopestart)),
this property is set according to whether the first element of the body is a fault
element. An application can test this property as a way of deciding whether
to read the body as a fault. To read the body as a fault, use [WsReadBody](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreadbody)
with [WS_FAULT_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) to obtain a [WS_FAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_fault).

When a message is written ([WsWriteMessageStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswritemessagestart) or [WsWriteEnvelopeStart](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wswriteenvelopestart))
this property can be used to indicate whether or not the application will write a fault
in the body. Some channels will use this information in order to determine how to
send the message. For example, HTTP will send a 500 status code for faults instead of 200.

When a message is initialized using [WsInitializeMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsinitializemessage) with
[WS_FAULT_MESSAGE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_initialization), the property is set to **TRUE**.
For other **WS_MESSAGE_INITIALIZATION** values, the property is set to **FALSE**.

This property is available in all message states except [WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `WS_MESSAGE_PROPERTY_MAX_PROCESSED_HEADERS:13`

This property is used with [WsCreateMessage](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreatemessage) to specify the maximum number of headers
that will be allowed when processing the message headers.

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is a **ULONG**.

The purpose of this limit is to put an upper bound on the number of iterations
spent scanning for a header.

Since an application can directly modify the contents of the header buffer,
this limit is not enforced in all cases. It is only enforced when one of
the header access APIs are used ([WsSetHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetheader), [WsGetHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetheader),
[WsGetCustomHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetcustomheader), or [WsGetMappedHeader](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmappedheader)).

The default value is 64.

### `WS_MESSAGE_PROPERTY_USERNAME:14`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty) to retrieve the sender's
username from a received message, if username/password based security
is on, or if a custom channel has set the value.

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is a [WS_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_string) structure.

The returned value is good until the message is freed or reset.

A custom channel can use [WsSetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetmessageproperty) to set
the sender's username from the message if it supports username/password
based security. The function will make a copy of the value specified.

This property is available in all message states except
[WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `WS_MESSAGE_PROPERTY_ENCODED_CERT:15`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty) to retrieve the sender's
certificate from a received message as encoded bytes, if
a certificate-based security mode (such as SSL) is on,
or if a custom channel has set the value.

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is a [WS_BYTES](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_bytes) structure.

The returned value is good until the message is freed or reset.

A custom channel can use [WsSetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetmessageproperty) to set
the sender's certificate from a received message if it supports
a certificate-based security mode. The function will make a copy of the value specified.

This property is available in all message states except
[WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `WS_MESSAGE_PROPERTY_TRANSPORT_SECURITY_WINDOWS_TOKEN:16`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty) to retrieve the Windows
token representing the sender from a received message. This property is
available in the following cases:

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is a **HANDLE**.

* [WS_TCP_SSPI_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_tcp_sspi_transport_security_binding) is being used.
* [WS_SSL_TRANSPORT_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_ssl_transport_security_binding) is being used
  and the translation from client certificate to Windows token
  has been enabled at the http.sys config level.
* A custom channel implementation has set the value.

The returned value is good until the message is freed or reset.

A custom channel can use [WsSetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetmessageproperty) to set
the sender's certificate from a received message if it supports
a certificate-based security mode. The function will duplicate the handle specified.

This property is available in all message states except
[WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `WS_MESSAGE_PROPERTY_HTTP_HEADER_AUTH_WINDOWS_TOKEN:17`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty) to retrieve the Windows
token representing the sender from a received message, if the
[WS_HTTP_HEADER_AUTH_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_http_header_auth_security_binding) is used,
or if a custom channel has set the value.

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is a **HANDLE**.

The returned value is good until the message is freed or reset.

A custom channel can use [WsSetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetmessageproperty) to set
the windows token representing the sender from a received message.
The function will duplicate the handle specified.

This property is available in all message states except
[WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `WS_MESSAGE_PROPERTY_MESSAGE_SECURITY_WINDOWS_TOKEN:18`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty) to retrieve the Windows
token representing the sender from a received message, if a message security
binding such as [WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_kerberos_apreq_message_security_binding) is used,
or if a custom channel has set the value.

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is a **HANDLE**.

The returned value is good until the message is freed or reset.

A custom channel can use [WsSetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetmessageproperty) to set
the token representing the sender from a received message.
The function will duplicate the handle specified.

This property is available in all message states except
[WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `WS_MESSAGE_PROPERTY_SAML_ASSERTION:19`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty) to retrieve the SAML assertion
representing the sender from a received message, if the
[WS_SAML_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_saml_message_security_binding) is used on the server side,
or if a custom channel has set the value.

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is a [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer).

The returned value is good until the message is freed or reset.

A custom channel can use [WsSetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetmessageproperty) to set
the SAML assertion representing the sender from a received message.
The function will duplicate the buffer specified.

This property is available in all message states except
[WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).

### `WS_MESSAGE_PROPERTY_SECURITY_CONTEXT:20`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty) to retrieve the secure conversation handle if the
[WS_SECURITY_CONTEXT_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_security_context_message_security_binding) is used on the server side.

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is a [WS_SECURITY_CONTEXT](https://learn.microsoft.com/windows/desktop/wsw/ws-security-context).

The returned value is good until the message is freed or reset.

### `WS_MESSAGE_PROPERTY_PROTECTION_LEVEL:21`

This property is used with [WsGetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgetmessageproperty) to retrieve the message's security protection level.

The accompanying **value** member of the [WS_MESSAGE_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_message_property) structure is a [WS_PROTECTION_LEVEL](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_protection_level) value.

If the channel does not use security, or if security verification failed, the protection level is set to
[WS_PROTECTION_LEVEL_NONE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_protection_level). Otherwise it is set to the level requested by the application.

This property may be used to determine the status of the security verification when [WS_CHANNEL_PROPERTY_ALLOW_UNSECURED_FAULTS](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_channel_property_id)
is set to **FALSE**.

A custom channel can use [WsSetMessageProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wssetmessageproperty) to set
the protection level of a received message.

This property is available in all message states except
[WS_MESSAGE_STATE_EMPTY](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_message_state).