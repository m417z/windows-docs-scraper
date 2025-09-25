# HRESULT_CODE macro

## Description

Extracts the code portion of the specified **HRESULT**.

## Parameters

### `hr`

The **HRESULT** value.

## Remarks

This macro is defined as follows:

``` syntax
#define HRESULT_CODE(hr)    ((hr) & 0xFFFF)
```

## See also

[Error Handling](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com)