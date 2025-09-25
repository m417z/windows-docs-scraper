# SP_INF_SIGNER_INFO_V2_A structure

## Description

The **SP_INF_SIGNER_INFO** structure stores information about an INF file's digital signature.

## Members

### `cbSize`

Size of this structure, in bytes.

### `CatalogFile`

Path to the catalog file, stored in an array of maximum size MAX_PATH characters.

### `DigitalSigner`

Path to the digital signer of the file, stored in an array of maximum size MAX_PATH characters.

### `DigitalSignerVersion`

Version of the digital signer, stored in an array of size MAX_PATH characters.

### `SignerScore`

## See also

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[Structures](https://learn.microsoft.com/windows/desktop/SetupApi/structures--setup-api-)

## Remarks

> [!NOTE]
> The setupapi.h header defines SP_INF_SIGNER_INFO_V2 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).