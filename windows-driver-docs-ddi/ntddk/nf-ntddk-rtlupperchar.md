# RtlUpperChar function

## Description

The **RtlUpperChar** routine converts the specified character to uppercase.

## Parameters

### `Character` [in]

Specifies the character to convert.

## Return value

**RtlUpperChar** returns the uppercase version of the specified character or returns the value specified by the caller for *Character* if the specified character cannot be converted.

## Remarks

**RtlUpperChar** returns the input *Character* unconverted if it is the lead byte of a multibyte character or if the uppercase equivalent of *Character* is a double-byte character. To convert such characters, use **RtlUpcaseUnicodeChar**.

**RtlUpperChar** is not recommended because the function is designed to work for ASCII range A-Z letters. Instead, use [**RtlUpcaseUnicodeChar**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlupcaseunicodechar).

## See also

[RtlUpcaseUnicodeChar](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlupcaseunicodechar)

[RtlUpperString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlupperstring)