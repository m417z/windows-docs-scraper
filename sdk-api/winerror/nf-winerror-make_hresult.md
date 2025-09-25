# MAKE_HRESULT macro

## Description

Creates an **HRESULT** value from its component pieces.

## Parameters

### `sev`

The severity.

### `fac`

The facility.

### `code`

The code.

## Remarks

This macro is defined as follows:

``` syntax
#define MAKE_HRESULT(sev,fac,code) \
    ((HRESULT) (((unsigned long)(sev)<<31) | ((unsigned long)(fac)<<16) | ((unsigned long)(code))) )
```

## See also

[Error Handling](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com)