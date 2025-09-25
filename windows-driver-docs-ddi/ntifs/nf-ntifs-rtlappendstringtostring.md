# RtlAppendStringToString function

## Description

The **RtlAppendStringToString** routine concatenates two counted strings. It copies bytes from the source up to the length of the destination buffer.

## Parameters

### `Destination` [in, out]

A pointer to a counted string to which the string at *Source* should be appended.

### `Source` [in]

A pointer to a counted string to be appended to the string at *Destination*.

## Return value

The **RtlAppendStringToString** routine returns STATUS_SUCCESS if it appended the string at *Source* to the string at *Destination*. **RtlAppendStringToString** returns STATUS_BUFFER_TOO_SMALL if the **MaximumLength** of the *Destination* string is too small to allow the source string to be appended.

## Remarks

The sum of the **Length** members of the *Destination* and *Source* strings must be less than or equal to the **MaximumLength** of the *Destination* string.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[RtlAppendUnicodeStringToString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlappendunicodestringtostring)

[RtlAppendUnicodeToString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlappendunicodetostring)

[RtlInitString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitstring)