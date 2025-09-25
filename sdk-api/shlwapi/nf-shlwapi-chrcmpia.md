# ChrCmpIA function

## Description

Performs a comparison between two characters. The comparison is not case-sensitive.

## Parameters

### `w1` [in]

Type: **WORD**

The first character to be compared.

### `w2` [in]

Type: **WORD**

The second character to be compared.

## Return value

Type: **BOOL**

Returns zero if the two characters are the same, or nonzero otherwise.

## Remarks

> [!NOTE]
> The shlwapi.h header defines ChrCmpI as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).