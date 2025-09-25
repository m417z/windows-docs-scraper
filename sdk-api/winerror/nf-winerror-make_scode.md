# MAKE_SCODE macro

## Description

Creates an **SCODE** value from its component pieces.

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
#define MAKE_SCODE(sev,fac,code) \
    ((SCODE) (((unsigned long)(sev)<<31) | ((unsigned long)(fac)<<16) | ((unsigned long)(code))) )
```

## See also

[Error Handling](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com)