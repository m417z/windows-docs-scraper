# IS_ERROR macro

## Description

Provides a generic test for errors on any status value.

## Parameters

### `Status`

The status code. This value can be an **HRESULT** or an **SCODE**.

## Remarks

This macro is defined as follows:

``` syntax
#define SEVERITY_ERROR     1
#define IS_ERROR(Status) (((unsigned long)(Status)) >> 31 == SEVERITY_ERROR)
```

## See also

[Error Handling](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com)