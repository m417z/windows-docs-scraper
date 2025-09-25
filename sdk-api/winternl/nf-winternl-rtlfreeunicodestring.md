# RtlFreeUnicodeString function

## Description

Frees the string buffer allocated by
[RtlAnsiStringToUnicodeString](https://learn.microsoft.com/windows/desktop/api/winternl/nf-winternl-rtlansistringtounicodestring) or by **RtlUpcaseUnicodeString**.

## Parameters

### `UnicodeString` [in, out]

A pointer to the Unicode string whose
buffer was previously allocated by [RtlAnsiStringToUnicodeString](https://learn.microsoft.com/windows/desktop/api/winternl/nf-winternl-rtlansistringtounicodestring).

## Remarks

This routine does not release the ANSI string buffer passed to [RtlAnsiStringToUnicodeString](https://learn.microsoft.com/windows/desktop/api/winternl/nf-winternl-rtlansistringtounicodestring) or **RtlUpcaseUnicodeString**.

Because there is no import library for this function, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).