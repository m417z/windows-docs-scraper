# HTTP_CHANNEL_BIND_INFO structure

## Description

The **HTTP_CHANNEL_BIND_INFO** structure is used to set or query channel bind authentication.

## Members

### `Hardening`

An [HTTP_AUTHENTICATION_HARDENING_LEVELS](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_authentication_hardening_levels) value indicating the hardening level levels to be set or queried per server session or URL group.

### `Flags`

A bitwise OR combination of flags that determine the behavior of authentication.

The following values are supported.

|  |  |  |
| --- | --- | --- |
| Name | Value | Meaning |
| HTTP_CHANNEL_BIND_PROXY | 0x1 | The exact Channel Bind Token (CBT) match is bypassed. CBT is checked not to be equal to ‘unbound’. Service Principle Name (SPN) check is enabled. |
| HTTP_CHANNEL_BIND_PROXY_COHOSTING | Ox20 | This flag is valid only if HTTP_CHANNEL_BIND_PROXY is also set. With the flag set, the CBT check (comparing with ‘unbound’) is skipped. The flag should be set if both secure channel traffic passed through proxy and traffic originally sent through insecure channel have to be authenticated. |
| HTTP_CHANNEL_BIND_NO_SERVICE_NAME_CHECK | 0x2 | SPN check always succeeds. |
| HTTP_CHANNEL_BIND_DOTLESS_SERVICE | 0x4 | Enables dotless service names. Otherwise configuring CBT properties with dotless service names will fail. |
| HTTP_CHANNEL_BIND_SECURE_CHANNEL_TOKEN | 0x8 | Server session, URL group, or response is configured to retrieve secure channel endpoint binding for each request and pass it to user the mode application. When set, a pointer to a buffer with the secure channel endpoint binding is stored in an [HTTP_REQUEST_CHANNEL_BIND_STATUS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_channel_bind_status) structure. |
| HTTP_CHANNEL_BIND_CLIENT_SERVICE | 0x10 | Server session, URL group, or response is configured to retrieve SPN for each request and pass it to the user mode application. The SPN is stored in the **ServiceName** field of the [HTTP_REQUEST_CHANNEL_BIND_STATUS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_channel_bind_status) structure. The type is always **HttpServiceBindingTypeW** (Unicode). |

### `ServiceNames`

 Pointer to a buffer holding an array of 1 or more service names. Each service name is represented by either an [HTTP_SERVICE_BINDING_A](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_binding_a) structure or an [HTTP_SERVICE_BINDING_W](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_binding_w) structure, dependent upon whether the name is ASCII or Unicode. Regardless of which structure type is used, the array is cast into a pointer to an [HTTP_SERVICE_BINDING_BASE](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_service_binding_base) structure.

### `NumberOfServiceNames`

The number of names in **ServiceNames**.

## Remarks

**Note**

This structure is used to set server session or URL group properties by passing it to [HttpSetServerSessionProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetserversessionproperty) or [HttpSetUrlGroupProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpseturlgroupproperty).

The **HTTP_CHANNEL_BIND_INFO** structure is also returned when server session or URL group properties are queried