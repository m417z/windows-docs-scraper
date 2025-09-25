# mmioStringToFOURCC function

## Description

The **mmioStringToFOURCC** function converts a null-terminated string to a four-character code.

## Parameters

### `sz`

Pointer to a null-terminated string to convert to a four-character code.

### `uFlags`

Flags for the conversion. The following value is defined:

| Value | Meaning |
| --- | --- |
| MMIO_TOUPPER | Converts all characters to uppercase. |

## Return value

Returns the four-character code created from the given string.

## Remarks

This function copies the string to a four-character code and pads it with space characters or truncates it if necessary. It does not check whether the code it returns is valid.