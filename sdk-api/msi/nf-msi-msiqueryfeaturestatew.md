# MsiQueryFeatureStateW function

## Description

The
**MsiQueryFeatureState** function returns the installed state for a product feature.

## Parameters

### `szProduct` [in]

Specifies the product code for the product that contains the feature of interest.

### `szFeature` [in]

Identifies the feature of interest.

## Return value

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_ABSENT** | The feature is not installed. |
| **INSTALLSTATE_ADVERTISED** | The feature is advertised |
| **INSTALLSTATE_LOCAL** | The feature is installed locally. |
| **INSTALLSTATE_SOURCE** | The feature is installed to run from source. |
| **INSTALLSTATE_INVALIDARG** | An invalid parameter was passed to the function. |
| **INSTALLSTATE_UNKNOWN** | The product code or feature ID is unknown. |

## Remarks

The
**MsiQueryFeatureState** function does not validate that the feature is actually accessible.

> [!NOTE]
> The msi.h header defines MsiQueryFeatureState as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[System Status Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)