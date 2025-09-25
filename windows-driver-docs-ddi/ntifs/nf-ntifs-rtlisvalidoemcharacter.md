# RtlIsValidOemCharacter function

## Description

The **RtlIsValidOemCharacter** routine determines if the specified Unicode character can be mapped to a valid OEM character.

## Parameters

### `Char` [in, out]

Pointer to the character. If the character can be mapped to a valid OEM character, this parameter receives the Unicode translation of the valid OEM character.

## Return value

**RtlIsValidOemCharacter** returns **TRUE** if the character can be mapped to a valid OEM character, **FALSE** otherwise.

## Remarks

**RtlIsValidOemCharacter** translates the Unicode character at *Char* using the OEM code page that was installed as the current system code page at system boot time, and converts the translated character to uppercase. **RtlIsValidOemCharacter** checks that the resulting character is a valid OEM character.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlOemStringToCountedUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemstringtocountedunicodestring)

[RtlOemStringToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtloemstringtounicodestring)

[RtlUnicodeToOemN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlunicodetooemn)