# SP_ORIGINAL_FILE_INFO_A structure

## Description

The
**SP_ORIGINAL_FILE_INFO** structure receives the original INF file name and catalog file information returned by
[SetupQueryInfOriginalFileInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueryinforiginalfileinformationa).

## Members

### `cbSize`

Size of this structure, in bytes.

### `OriginalInfName`

Original file name of the INF file stored in array of size MAX_PATH.

### `OriginalCatalogName`

Catalog name of the INF file stored in array of size MAX_PATH.

## See also

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[Structures](https://learn.microsoft.com/windows/desktop/SetupApi/structures--setup-api-)

## Remarks

> [!NOTE]
> The setupapi.h header defines SP_ORIGINAL_FILE_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).