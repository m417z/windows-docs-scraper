# HTTP_REQUEST_PROPERTY enumeration

## Description

The **HTTP\_REQUEST\_PROPERTY** enumeration defines the properties that are configured by the HTTP Server API on a request.

## Constants

### `HttpRequestPropertyStreamError`

The HTTP/2 or HTTP/3 stream error on the request.

The [HTTP\_REQUEST\_PROPERTY\_STREAM\_ERROR](https://learn.microsoft.com/windows/win32/api/http/ns-http-http_request_property_stream_error) structure contains the configuration data for this property.

## Remarks

The **HTTP\_REQUEST\_PROPERTY** enumeration types are used to set or query the configurations on a request. A member of this enumeration together with the associated configuration structure is used by [HttpSetRequestProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetrequestproperty) to define the configuration parameters.

## See also

[HttpSetRequestProperty](https://learn.microsoft.com/windows/desktop/api/http/nf-http-httpsetrequestproperty)