# HTTP_REQUEST_CHANNEL_BIND_STATUS structure

## Description

The **HTTP_REQUEST_CHANNEL_BIND_STATUS** structure contains secure channel endpoint binding information.

## Members

### `ServiceName`

A pointer to an [HTTP_SERVICE_BINDING_W](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_binding_w) structure cast to a pointer to an [HTTP_SERVICE_BINDING_BASE](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_binding_base) structure containing the service name from the client. This is populated if the request's Channel Binding Token (CBT) is not configured to retrieve service names.

### `ChannelToken`

A pointer to a buffer that contains the secure channel endpoint binding.

### `ChannelTokenSize`

The length of the **ChannelToken** buffer in bytes.

### `Flags`

Reserved