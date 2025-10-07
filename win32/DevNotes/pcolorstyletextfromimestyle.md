# PColorStyleTextFromIMEStyle function

Retrieves the text color style of the specified style.

## Parameters

*pimestyle* \[in\]

An **IMESTYLE** structure returned from [**PIMEStyleFromAttr**](https://learn.microsoft.com/windows/win32/devnotes/pimestylefromattr) function.

## Return value

Pointer to an **IMECOLORSTY** structure representing the text color style.

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

The **IMECOLORSTY** structure is defined as follows:

``` syntax
typedef struct {
    UINT colorId;
    union {
        COLORREF    rgb;
        UINT        colorWin;
        UINT        colorSpec;
        UINT        colorFund;
    };
} IMECOLORSTY;
```

## Requirements

| Requirement | Value |
|----------------|-----------------------------------------------------------------------------------------|
| DLL<br> | Imeshare.dll |

## See also

[**PIMEStyleFromAttr**](https://learn.microsoft.com/windows/win32/devnotes/pimestylefromattr)

