# HTTP_SET_VERSION macro

## Syntax

```cpp
void HTTP_SET_VERSION(
    HTTP_VERSION version,
    USHORT major,
    USHORT minor
);
```

## Description

The **HTTP_SET_VERSION** macro sets a specified [HTTP_VERSION](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_version) structure to a specified major/minor version combination.

## Parameters

### `version`

The [HTTP_VERSION](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_version) structure to be set.

### `major`

The major portion of the version to be used in the [HTTP_VERSION](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_version) structure.

### `minor`

The minor portion of the version to be used in the [HTTP_VERSION](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_version) structure.

## See also

[HTTP Server API Version 1.0 Macros](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-1-0-macros)

[HTTP_VERSION](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_version)