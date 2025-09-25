# HTTP_RESPONSE_INFO structure

## Description

The **HTTP_RESPONSE_INFO** structure extends the [HTTP_RESPONSE](https://learn.microsoft.com/windows/desktop/Http/http-response) structure with additional information for the response.

## Members

### `Type`

A member of the [HTTP_RESPONSE_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_response_info_type) enumeration specifying the type of information contained in this structure.

### `Length`

The length, in bytes, of the **pInfo** member.

### `pInfo`

A pointer to the [HTTP_MULTIPLE_KNOWN_HEADERS](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_multiple_known_headers) structure when the **InfoType** member is **HttpResponseInfoTypeMultipleKnownHeaders**; otherwise **NULL**.

## Remarks

Starting with the HTTP Server API version 2.0, the HTTP_RESPONSE structure is extended to include an array of **HTTP_RESPONSE_INFO** structures in the **pRequestInfo** member. These structures contain additional information for the response.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_RESPONSE](https://learn.microsoft.com/windows/desktop/Http/http-response)

[HTTP_RESPONSE_V2](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_response_v2)