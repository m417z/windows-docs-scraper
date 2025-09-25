# SCODE_CODE macro

## Description

Extracts the code portion of the specified **SCODE**.

## Parameters

### `sc`

The status code.

## Remarks

This macro is defined as follows:

``` syntax
#define SCODE_CODE(sc)      ((sc) & 0xFFFF)
```

## See also

[Error Handling](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com)