# HTTP_SERVICE_BINDING_BASE structure

## Description

The **HTTP_SERVICE_BINDING_BASE** structure is a placeholder for the [HTTP_SERVICE_BINDING_A](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_binding_a) structure and the [HTTP_SERVICE_BINDING_W](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_binding_w) structure.

## Members

### `Type`

Pointer to an [HTTP_SERVICE_BINDING_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_binding_type) value that indicates whether the data is in ASCII or Unicode.

## Remarks

**Note**

The first member of both the [HTTP_SERVICE_BINDING_A](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_binding_a) structure and the [HTTP_SERVICE_BINDING_W](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_binding_w) structure is a **HTTP_SERVICE_BINDING_BASE** structure. Therefore, an array of either of the first two structures can be indicated by a pointer to a **HTTP_SERVICE_BINDING_BASE** structure.

The **ServiceNames** member of the [HTTP_CHANNEL_BIND_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_channel_bind_info) structure is cast to a pointer to a **HTTP_SERVICE_BINDING_BASE** structure for this purpose.

## See also

[HTTP_CHANNEL_BIND_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_channel_bind_info)

[HTTP_SERVICE_BINDING_A](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_binding_a)

[HTTP_SERVICE_BINDING_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_service_binding_type)

[HTTP_SERVICE_BINDING_W](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_binding_w)