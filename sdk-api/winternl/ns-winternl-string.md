# STRING structure

## Description

Used with the [RtlUnicodeStringToOemString](https://learn.microsoft.com/windows/desktop/api/winternl/nf-winternl-rtlunicodestringtooemstring) function.

## Members

### `Length`

The length of the buffer.

### `MaximumLength`

The maximum length of the buffer.

### `Buffer`

The address of the buffer.

## Remarks

The data type used in the **DestinationString** parameter of the [RtlUnicodeStringToOemString](https://learn.microsoft.com/windows/desktop/api/winternl/nf-winternl-rtlunicodestringtooemstring) function,  `POEM_STRING`, is defined as:

`typedef PSTRING POEM_STRING;`