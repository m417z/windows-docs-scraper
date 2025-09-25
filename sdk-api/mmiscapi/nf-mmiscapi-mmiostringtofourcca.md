# mmioStringToFOURCCA function

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

> [!NOTE]
> The mmiscapi.h header defines mmioStringToFOURCC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).