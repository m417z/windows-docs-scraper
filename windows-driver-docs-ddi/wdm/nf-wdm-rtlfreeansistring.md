# RtlFreeAnsiString function

## Description

The **RtlFreeAnsiString** routine releases storage that was allocated by **RtlUnicodeStringToAnsiString**.

## Parameters

### `AnsiString` [in, out]

Pointer to the ANSI string buffer previously allocated by **RtlUnicodeStringToAnsiString**.

## Return value

None

## Remarks

This routine does not release the Unicode string buffer passed to **RtlUnicodeStringToAnsiString**.

## See also

[RtlUnicodeStringToAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlunicodestringtoansistring)