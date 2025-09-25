# HRESULT_SEVERITY macro

## Description

Extracts the severity field of the specified **HRESULT**.

## Parameters

### `hr`

The **HRESULT**.

## Remarks

This macro is defined as follows:

``` syntax
#define HRESULT_SEVERITY(hr)  (((hr) >> 31) & 0x1)
```

## See also

[Error Handling](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com)