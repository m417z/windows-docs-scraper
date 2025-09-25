## Description

Each listener property is of type [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property), is identified by an ID, and has an associated value. If a property is not specified when the listener is created, then its default value is used.

## Constants

### `WS_LISTENER_PROPERTY_LISTEN_BACKLOG:0`

Used with [WsCreateListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscreatelistener) or [WsGetListenerProperty](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wsgetlistenerproperty) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_binding).

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property) structure is a **ULONG**.

This controls the maximum length of the queue of pending connections. If set to SOMAXCONN, the backlog will be set to a maximum reasonable value.

### `WS_LISTENER_PROPERTY_IP_VERSION:1`

Used with [WsCreateListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscreatelistener) or [WsGetListenerProperty](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wsgetlistenerproperty) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_binding) or **WS_UDP_CHANNEL_BINDING**.

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property) structure is an [WS_IP_VERSION](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_ip_version) value.

This property specifies which IP version that the listener should use.

The default value is [WS_IP_VERSION_AUTO](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_ip_version).

### `WS_LISTENER_PROPERTY_STATE:2`

Used with [WsGetListenerProperty](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wsgetlistenerproperty) for all channel types.

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property) structure is a [WS_LISTENER_STATE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_listener_state) value.

Returns the current [WS_LISTENER_STATE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_listener_state) of the listener. The returned value is a snapshot of the current state, so it is possible that the state may have changed before the caller has had a chance to examine the value.

### `WS_LISTENER_PROPERTY_ASYNC_CALLBACK_MODEL:3`

Used with [WsCreateListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscreatelistener) or [WsGetListenerProperty](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wsgetlistenerproperty) for all channel types.

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property) structure is a [WS_CALLBACK_MODEL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_callback_model) value.

This value indicates the preferred async callback model when issuing async operations for the listener or channels that are created for it using [WsCreateChannelForListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscreatechannelforlistener).

The default is [WS_LONG_CALLBACK](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_callback_model).

The [WS_SERVICE_HOST](https://learn.microsoft.com/windows/desktop/wsw/ws-service-host) only supports [WS_LONG_CALLBACK](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_callback_model) as an acceptable value for this property.

### `WS_LISTENER_PROPERTY_CHANNEL_TYPE:4`

Used with [WsGetListenerProperty](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wsgetlistenerproperty) for all channel types.

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property) structure is a [WS_CHANNEL_TYPE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_type) value.

This property specifies the message exchange pattern of the channel being used.

### `WS_LISTENER_PROPERTY_CHANNEL_BINDING:5`

Used with [WsGetListenerProperty](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wsgetlistenerproperty) for all channel types.

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property) structure is a [WS_CHANNEL_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_binding) value.

This property specifies the binding of the channel being used.

### `WS_LISTENER_PROPERTY_CONNECT_TIMEOUT:6`

Used with [WsCreateListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscreatelistener) or [WsGetListenerProperty](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wsgetlistenerproperty) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_binding) and **WS_NAMEDPIPE_CHANNEL_BINDING**.

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property) structure is a **ULONG**.

An accept operation will wait for an infinite amount of time to accept the underlying TCP socket or named pipe. This timeout corresponds to the amount of time dedicated to the net.tcp or net.pipe handshake that takes place between the client and service once the client connects. The timeout value is in milliseconds, where the value INFINITE indicates no timeout. Use the [WS_CHANNEL_PROPERTY_CONNECT_TIMEOUT](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_property_id) to set the corresponding value on the client side.

The default value is 15000 (15 seconds).

### `WS_LISTENER_PROPERTY_IS_MULTICAST:7`

Used with [WsCreateListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscreatelistener) or [WsGetListenerProperty](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wsgetlistenerproperty) for [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_binding) with [WS_CHANNEL_TYPE_DUPLEX](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_type) to indicate that the listener is listening on a multicast address.

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property) structure is a **BOOL**.

Note that setting this property is not sufficient when listening on a multicast address. The set of interfaces must also be specified using the [WS_LISTENER_PROPERTY_MULTICAST_INTERFACES](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_listener_property_id) property.

The channel does not validate that the address is in fact a multicast address, but it sets the reuse of the socket such that another process can also open the same port.

The default value is **FALSE**.

### `WS_LISTENER_PROPERTY_MULTICAST_INTERFACES:8`

Used with [WsCreateListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscreatelistener) or [WsSetListenerProperty](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wssetlistenerproperty) for [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_binding) with [WS_CHANNEL_TYPE_DUPLEX](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_type).

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property) structure is an array of **ULONG** values.

The size of the property is sizeof(ULONG) multiplied by the number of values. Each value represents the interface index of an adapter. The indices of adapters can be obtained using the GetAdaptersAddresses function.

This value of the [WS_LISTENER_PROPERTY_IS_MULTICAST](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_listener_property_id) property must be **TRUE** in order to use this property.

The default value is an empty list (no interfaces).

### `WS_LISTENER_PROPERTY_MULTICAST_LOOPBACK:9`

Used with [WsCreateListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscreatelistener) for [WS_UDP_CHANNEL_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_binding)
with [WS_CHANNEL_TYPE_DUPLEX](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_type).

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property) structure is a **BOOL**.

This indicates whether or not messages sent on the loopback interface are received by this channel. If **TRUE**, then messages are received (otherwise, they will not be seen by the channel).

This value of the [WS_LISTENER_PROPERTY_IS_MULTICAST](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_listener_property_id) property must be **TRUE** in order to use this property.

The default value is **TRUE**.

### `WS_LISTENER_PROPERTY_CLOSE_TIMEOUT:10`

Used with [WsCreateListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscreatelistener) or [WsGetListenerProperty](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wsgetlistenerproperty) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_binding) with [WS_CHANNEL_TYPE_REPLY](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_type).

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property) structure is a **ULONG**.

This indicates the number of milliseconds to wait for clients to receive data from responses when [WsCloseListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscloselistener) is called.

The purpose of this timeout is to allow clients time to continue receiving data from HTTP responses sent by the server before the HTTP server disconnects the client connections.

The calculation of the timeout value used is as follows:

* At the time that [WsCloseListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscloselistener) is called, determine the
  time the last response was sent (the last response time). For the purposes of
  this timeout calculation, a response is recorded as sent once [WsWriteMessageEnd](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wswritemessageend) has been called for the response.
* Calculate the difference between the current time and the last response time.
* If the difference is more than the timeout value, then the actual
  timeout used is zero.
* If the difference is less than or equal to the timeout value, then the
  actual timeout used is the timeout value minus the difference.

The default timeout value is 5000 (5 seconds).

### `WS_LISTENER_PROPERTY_TO_HEADER_MATCHING_OPTIONS:11`

Used with [WsCreateListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscreatelistener) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_binding),
**WS_HTTP_CHANNEL_BINDING**, **WS_UDP_CHANNEL_BINDING**, or **WS_NAMEDPIPE_CHANNEL_BINDING**.

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property) structure is a **ULONG**.

The property value contains a set of flags (see [WS_URL_MATCHING_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_buffer_property_id)) which specify how to match the URL in the [WS_TO_HEADER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_header_type) of any received messages.

The default value is:

```
WS_MATCH_URL_THIS_HOST |
WS_MATCH_URL_EXACT_PATH |
WS_MATCH_URL_PORT |
WS_MATCH_URL_NO_QUERY
```

### `WS_LISTENER_PROPERTY_TRANSPORT_URL_MATCHING_OPTIONS:12`

Used with [WsCreateListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscreatelistener) for [WS_TCP_CHANNEL_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_binding) or
**WS_HTTP_CHANNEL_BINDING**.

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property) structure is a **ULONG**.

The property value contains a set of flags (see [WS_URL_MATCHING_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_buffer_property_id)) which specify how to match the transport URL of any accepted channels. See [WS_CHANNEL_PROPERTY_TRANSPORT_URL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_property_id) for more information on the transport URL.

The default value is:

```
WS_MATCH_URL_THIS_HOST |
WS_MATCH_URL_EXACT_PATH |
WS_MATCH_URL_PORT |
WS_MATCH_URL_NO_QUERY
```

This property controls only the verification of the message once it has been received by the process, not the routing of the message to the process (which is determined by the URL passed to [WsOpenListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wsopenlistener)).

### `WS_LISTENER_PROPERTY_CUSTOM_LISTENER_CALLBACKS:13`

Used with [WsCreateListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscreatelistener) for [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_binding).

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_custom_listener_callbacks) structure is a [WS_CUSTOM_LISTENER_CALLBACKS](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_custom_listener_callbacks) structure.

This property is used to specify callbacks that define the implementation of a custom listener.

This property must be specified when [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_binding) is used.

### `WS_LISTENER_PROPERTY_CUSTOM_LISTENER_PARAMETERS:14`

Used with [WsCreateListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscreatelistener) for [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_binding).

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property) structure is a pointer to an arbitrary sized data type. The size of the property is the size of the data type.

This property is used to specify parameters used to create the custom listener implementation.

The value of this property will be passed to the [WS_CREATE_LISTENER_CALLBACK](https://learn.microsoft.com/windows/win32/api/webservices/nc-webservices-ws_create_listener_callback).

If this property is not specified, its value is **NULL** and size is zero.

### `WS_LISTENER_PROPERTY_CUSTOM_LISTENER_INSTANCE:15`

Used with [WsGetChannelProperty](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wsgetchannelproperty) for [WS_CUSTOM_CHANNEL_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_binding).

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_listener_property) structure is a void* and size the property is sizeof(void*).

The value corresponds to the listenerInstance value returned by the [WS_CREATE_LISTENER_CALLBACK](https://learn.microsoft.com/windows/win32/api/webservices/nc-webservices-ws_create_listener_callback).

This property can be used to obtain the underlying listener instance for a custom listener. This allows a caller to directly interact with the instance for cases when the existing set of listener properties or listener functions is insufficient.

### `WS_LISTENER_PROPERTY_DISALLOWED_USER_AGENT:16`

Used with [WsCreateListener](https://learn.microsoft.com/windows/win32/api/webservices/nf-webservices-wscreatelistener) for [WS_HTTP_CHANNEL_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_channel_binding).

The accompanying **value** member of the [WS_LISTENER_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_disallowed_user_agent_substrings) structure is a pointer to [WS_DISALLOWED_USER_AGENT_SUBSTRINGS](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_disallowed_user_agent_substrings) which specifies the list of disallowed user
agents sub-strings.

* Upon receiving the HTTP request, the UserAgent header value is extracted.
* Each sub-string in the list, is searched in the extracted UserAgent string value.
* If the substring is found the request is rejected.

The list by default contains the following entry

* Web Browser(s): Mozilla

This property does not apply to listeners configured with [WS_ENCODING_RAW](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_encoding) encoding.