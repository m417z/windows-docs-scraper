# RtlFreeAnsiString function

## Description

Frees the string buffer allocated by [RtlUnicodeStringToAnsiString](https://learn.microsoft.com/windows/desktop/api/winternl/nf-winternl-rtlunicodestringtoansistring).

## Parameters

### `AnsiString` [in]

A pointer to an ANSI string whose buffer was previously allocated by [RtlUnicodeStringToAnsiString](https://learn.microsoft.com/windows/desktop/api/winternl/nf-winternl-rtlunicodestringtoansistring).

## Remarks

This routine does not release the Unicode string buffer passed to [RtlUnicodeStringToAnsiString](https://learn.microsoft.com/windows/desktop/api/winternl/nf-winternl-rtlunicodestringtoansistring).