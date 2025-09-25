# RtlCharToInteger function

## Description

Converts a character string to an integer.

## Parameters

### `String` [in]

A pointer to the string to convert. The format of the string is as follows:

[whitespace] [{+ | -}] [0 [{x | o | b}]] [digits]

### `Base` [in, optional]

**ULONG** that contains the number base to use for the conversion, such as base 10. Only base 2, 8, 10, and 16 are supported.

### `Value` [out]

A pointer to a **ULONG** that receives the integer that resulted from the conversion.

## Return value

If the function succeeds, the function returns **STATUS_SUCCESS**.

## Remarks

When converting strings to integers the preferred function to use is [strtol, wcstol](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2010/w4z2wdyc(v=vs.100)).

There is no import library for this function. Use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) rather than linking to the function directly.