# RegInstallW function

## Description

Updates the string registry values in the provided table.

## Parameters

### `hmod`

The module containing the values to be updated.

### `pszSection`

The sections containing the values to be updated.

### `pstTable`

The table of values to be updated.

## Return value

Returns S_OK on success. Returns E_FAIL on failure.

## Remarks

> [!NOTE]
> The advpub.h header defines RegInstall as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).