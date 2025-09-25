# RtlCharToInteger function

## Description

The **RtlCharToInteger** routine converts a single-byte character string to an integer value in the specified base.

## Parameters

### `String` [in]

Pointer to a null-terminated, single-byte character string.

### `Base` [in, optional]

Specifies decimal, binary, octal, or hexadecimal base. If this parameter is not given, the routine will look for 0x, 0o, and 0b prefixes in the input string to determine if the base should be decimal (default), binary, octal, or hexadecimal.

### `Value` [out]

Pointer to a location to which the converted value is returned.

## Return value

**RtlCharToInteger** returns STATUS_SUCCESS if the given character string is converted. Otherwise, it can return STATUS_INVALID_PARAMETER.

## Remarks

**RtlCharToInteger** converts ANSI alphanumeric characters.

## See also

[RtlInitString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitstring)

[RtlIntegerToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlintegertounicodestring)