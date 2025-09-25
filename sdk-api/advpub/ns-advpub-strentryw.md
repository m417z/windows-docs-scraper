# STRENTRYW structure

## Description

Represents a registry string replacement.

## Members

### `pszName`

The name of the string to substitute.

### `pszValue`

The replacement string.

## Remarks

> [!NOTE]
> The advpub.h header defines STRENTRY as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).