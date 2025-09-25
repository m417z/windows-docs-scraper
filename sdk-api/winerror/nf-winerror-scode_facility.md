# SCODE_FACILITY macro

## Description

Extracts the facility of the specified **SCODE**.

## Parameters

### `sc`

The status code.

## Remarks

This macro is defined as follows:

``` syntax
#define SCODE_FACILITY(sc)    (((sc) >> 16) & 0x1fff)
```

## See also

[Error Handling](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com)