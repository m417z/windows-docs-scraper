# STRTABLEA structure

## Description

Represents a table of registry string replacements.

## Members

### `cEntries`

The number of entries in the table.

### `pse`

And array of entries.

## Remarks

> [!NOTE]
> The advpub.h header defines STRTABLE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).