# RtlFreeUnicodeString function

## Description

The **RtlFreeUnicodeString** routine releases storage that was allocated by **RtlAnsiStringToUnicodeString** or **RtlUpcaseUnicodeString**.

## Parameters

### `UnicodeString` [in, out]

Pointer to the Unicode string buffer previously allocated by **RtlAnsiStringToUnicodeString** or **RtlUpcaseUnicodeString**.

## Return value

None

## Remarks

This routine does not release the ANSI string buffer passed to **RtlAnsiStringToUnicodeString**.

## See also

[RtlAnsiStringToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlansistringtounicodestring)

[RtlUpcaseUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlupcaseunicodestring)