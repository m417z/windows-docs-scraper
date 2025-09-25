# RtlxAnsiStringToUnicodeSize function

## Description

The **RtlxAnsiStringToUnicodeSize** routine returns the number of bytes that are required for a null-terminated Unicode string that is equivalent to a specified ANSI string.

## Parameters

### `AnsiString` [in]

Pointer to the ANSI string for which to compute the number of bytes that are required for an equivalent null-terminated Unicode string.

## Return value

**RtlxAnsiStringToUnicodeSize** returns the number of bytes that are required for an equivalent null-terminated Unicode string, if the ANSI string can be translated into a Unicode string by using the current system locale information. Otherwise, this routine returns zero.

## Remarks

The ANSI string is interpreted for the current system locale.

## See also

[RtlAnsiStringToUnicodeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlansistringtounicodesize)