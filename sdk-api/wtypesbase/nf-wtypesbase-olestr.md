# OLESTR macro

## Description

Transforms string literals into Unicode strings.

## Parameters

### `str`

A string literal.

## Remarks

This macro is defined as follows:

``` syntax
#define OLESTR(str) L##str

```

## See also

[Error Handling](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com)