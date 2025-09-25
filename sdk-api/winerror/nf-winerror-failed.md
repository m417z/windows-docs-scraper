# FAILED macro

## Description

Provides a generic test for failure on any status value.

## Parameters

### `hr`

The status code. This value can be an **HRESULT** or an **SCODE**. A negative number indicates failure.

## Remarks

This macro is defined as follows:

``` syntax
#define FAILED(hr) (((HRESULT)(hr)) < 0)
```

## See also

[Error Handling](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com)