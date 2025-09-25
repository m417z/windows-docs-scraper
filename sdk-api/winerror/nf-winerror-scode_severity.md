# SCODE_SEVERITY macro

## Description

Extracts the severity field of the specified **SCODE**.

## Parameters

### `sc`

The status code.

## Remarks

This macro is defined as follows:

``` syntax
#define SCODE_SEVERITY(sc)    (((sc) >> 31) & 0x1)
```

## See also

[Error Handling](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com)