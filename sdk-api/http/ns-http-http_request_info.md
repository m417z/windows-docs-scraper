# HTTP_REQUEST_INFO structure

## Description

The **HTTP_REQUEST_INFO** structure extends the [HTTP_REQUEST](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa364545(v=vs.85)) structure with additional information about the request.

## Members

### `InfoType`

A member of the [HTTP_REQUEST_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_request_info_type) enumeration specifying the type of information contained in this structure.

### `InfoLength`

The length, in bytes, of the **pInfo** member.

### `pInfo`

A pointer to the [HTTP_REQUEST_AUTH_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_auth_info) structure when the **InfoType** member is **HttpRequestInfoTypeAuth**; otherwise **NULL**.

## Remarks

Starting with the HTTP Server API version 2.0, the HTTP_REQUEST structure is extended to include an array of **HTTP_REQUEST_INFO** structures in the **pRequestInfo** member. These structures contain additional information for the request.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_REQUEST_AUTH_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_auth_info)

[HTTP_REQUEST_V2](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_request_v2)