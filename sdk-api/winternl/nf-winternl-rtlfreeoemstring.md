# RtlFreeOemString function

## Description

Frees the string buffer allocated by
[RtlUnicodeStringToOemString](https://learn.microsoft.com/windows/desktop/api/winternl/nf-winternl-rtlunicodestringtooemstring).

## Parameters

### `OemString` [in, out]

Address of the OEM string whose buffer
was previously allocated by [RtlUnicodeStringToOemString](https://learn.microsoft.com/windows/desktop/api/winternl/nf-winternl-rtlunicodestringtooemstring).

## Remarks

This routine releases the **Buffer** member of the [OEM_STRING](https://learn.microsoft.com/windows/desktop/api/winternl/ns-winternl-string) structure. The **Length** and **MaximumLength** members are not affected by this routine.