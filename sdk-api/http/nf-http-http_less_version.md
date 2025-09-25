# HTTP_LESS_VERSION macro

## Syntax

```cpp
int HTTP_LESS_VERSION(
    HTTP_VERSION version,
    USHORT major,
    USHORT minor
);
```

## Return value

Type: **int**

Returns an integer that is either zero (false) or non-zero (true), that indicates whether or not the value of the _version_ parameter is less than or equal to the version combination passed in the _major_ and _minor_ parameters.

## Description

The **HTTP_LESS_VERSION** macro returns a non-zero value if an [HTTP_VERSION](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_version) structure is less than a specified major/minor version combination, or zero otherwise.

## Parameters

### `version`

The [HTTP_VERSION](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_version) structure to be examined.

### `major`

The major portion of the version to be compared.

### `minor`

The minor portion of the version to be compared.

## See also

[HTTP Server API Version 1.0 Macros](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-macros)