# HRESULT_FROM_NT macro

## Description

Maps an NT status value to an **HRESULT** value.

## Parameters

### `x`

The NT status value.

## Remarks

This macro is defined as follows:

``` syntax
#define HRESULT_FROM_NT(x)      ((HRESULT) ((x) | FACILITY_NT_BIT))
```

## See also

[Error Handling](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com)