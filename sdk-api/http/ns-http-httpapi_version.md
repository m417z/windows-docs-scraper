# HTTPAPI_VERSION structure

## Description

The
**HTTPAPI_VERSION** structure defines the version of the HTTP Server API. This is not to be confused with the version of the HTTP protocol used, which is stored in an
**HTTP_VERSION** structure.

## Members

### `HttpApiMajorVersion`

Major version of the HTTP Server API.

### `HttpApiMinorVersion`

Minor version of the HTTP Server API.

## Remarks

Constants that represents the version of the API are pre-defined in the Http.h header file as follows:

"#define HTTPAPI_VERSION_1 {1, 0}"

"#define HTTPAPI_VERSION_2 {2, 0}"