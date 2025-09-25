# HTTP_EQUAL_VERSION macro

## Syntax

```cpp
int HTTP_EQUAL_VERSION(
    HTTP_VERSION version,
    USHORT major,
    USHORT minor
);
```

## Return value

Type: **int**

Returns an integer that is either zero (false) or non-zero (true), that indicates if the version combination, passed in the _major_ and _minor_ parameters is, exactly equal to the value of the _version_ parameter.

## Description

The
**HTTP_EQUAL_VERSION** macro returns a non-zero value if an [HTTP_VERSION](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_version) structure is equal to a specified major/minor version combination, or zero otherwise.

## Parameters

### `version`

The [HTTP_VERSION](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_version) structure to be examined.

### `major`

A major portion of the version to be compared.

### `minor`

A minor portion of the version to be compared.

## See also

[HTTP Server API Version 1.0 Macros](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-macros)