## Description

The **RtlUnicodeStringToAnsiSize**> routine returns the number of bytes required for a null-terminated ANSI string that is equivalent to a specified Unicode string.

## Parameters

### `STRING` [in]

Pointer to the Unicode string for which to compute the number of bytes required for an equivalent null-terminated ANSI string.

## Remarks

If the Unicode string can be translated into an ANSI string using the current system locale information, **RtlUnicodeStringToAnsiSize** returns the number of bytes required for an equivalent null-terminated ANSI string. Otherwise, **RtlUnicodeStringToAnsiSize** returns zero.

The Unicode string is interpreted for the current system locale.

**RtlUnicodeStringToAnsiSize** performs the same operation as [**RtlxUnicodeStringToAnsiSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlxunicodestringtoansisize), but executes faster if the system does not use multibyte code pages.

## See also

[**RtlxUnicodeStringToAnsiSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlxunicodestringtoansisize)