# UNIVERSAL_NAME_INFOW structure

## Description

The **UNIVERSAL_NAME_INFO** structure contains information about the UNC form of a universal name. It is used by the
[NPGetUniversalName](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npgetuniversalname) function.

## Members

### `lpUniversalName`

If the provider supports a universal name, it will return that here.

## Remarks

> [!NOTE]
> The winnetwk.h header defines UNIVERSAL_NAME_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).