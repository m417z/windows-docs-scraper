# RtlDowncaseUnicodeChar function

## Description

The **RtlDowncaseUnicodeChar** routine converts the specified Unicode character to lowercase.

## Parameters

### `SourceCharacter` [in]

Specifies the character to convert.

## Return value

**RtlDowncaseUnicodeChar** returns the lowercase value of the Unicode character.

## Remarks

Ntoskrnl.lib supports the **RtlDowncaseUnicodeChar** routine in the WDK for Windows 7 and later versions of Windows. Ntdll.dll exports the **RtlDowncaseUnicodeChar** entry point in Windows XP and later versions of Windows.

## See also

[RtlDowncaseUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldowncaseunicodestring)

[RtlUpcaseUnicodeChar](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlupcaseunicodechar)