# RtlxUnicodeStringToAnsiSize function

## Description

The **RtlxUnicodeStringToAnsiSize** routine returns the number of bytes required for a null-terminated ANSI string that is equivalent to a specified Unicode string.

## Parameters

### `UnicodeString` [in]

Pointer to the Unicode string for which to compute the number of bytes required for an equivalent null-terminated ANSI string.

## Return value

If the Unicode string can be translated into an ANSI string using the current system locale information, **RtlxUnicodeStringToAnsiSize** returns the number of bytes required for an equivalent null-terminated ANSI string. Otherwise, it returns zero.

## Remarks

The Unicode string is interpreted for the current system locale.

## See also

[RtlUnicodeStringToAnsiSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlunicodestringtoansisize)