# HTTPAPI_VERSION_GREATER_OR_EQUAL macro

## Syntax

```cpp
int HTTP_GREATER_EQUAL_VERSION(
    HTTP_VERSION version,
    USHORT major,
    USHORT minor
);
```

## Return value

Type: **int**

Returns an integer that is either zero (false) or non-zero (true), that indicates whether or not the value of the _version_ parameter is greater than or equal to the version combination passed in the _major_ and _minor_ parameters.

## Description

The **HTTPAPI_VERSION_GREATER_OR_EQUAL** returns a non-zero value if an [HTTPAPI_VERSION](https://learn.microsoft.com/windows/desktop/api/http/ns-http-httpapi_version) structure is greater than or equal to a specified major/minor version combination, or zero otherwise.

## Parameters

### `version`

The [HTTPAPI_VERSION](https://learn.microsoft.com/windows/desktop/api/http/ns-http-httpapi_version) structure to be examined.

### `major`

The major portion of the version to be compared.

### `minor`

The minor portion of the version to be compared.

## See also

[HTTP Server API Version 1.0 Macros](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-macros)