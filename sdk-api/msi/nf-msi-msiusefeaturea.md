# MsiUseFeatureA function

## Description

The
**MsiUseFeature** function increments the usage count for a particular feature and indicates the installation state for that feature. This function should be used to indicate an application's intent to use a feature.

## Parameters

### `szProduct` [in]

Specifies the product code for the product that owns the feature to be used.

### `szFeature` [in]

Identifies the feature to be used.

## Return value

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_ABSENT** | The feature is not installed. |
| **INSTALLSTATE_ADVERTISED** | The feature is advertised |
| **INSTALLSTATE_BADCONFIG** | The configuration data is corrupt. |
| **INSTALLSTATE_INVALIDARG** | Invalid function argument. |
| **INSTALLSTATE_LOCAL** | The feature is locally installed and available for use. |
| **INSTALLSTATE_SOURCE** | The feature is installed from the source and available for use. |
| **INSTALLSTATE_UNKNOWN** | The feature is not published. |

## Remarks

The
**MsiUseFeature** function should only be used on features known to be published. INSTALLSTATE_UNKNOWN indicates that the program is trying to use a feature that is not published. The application should determine whether the feature is published before calling
**MsiUseFeature** by calling
[MsiQueryFeatureState](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiqueryfeaturestatea) or
[MsiEnumFeatures](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msienumfeaturesa). The application should make these calls while it initializes. An application should only use features that are known to be published.

> [!NOTE]
> The msi.h header defines MsiUseFeature as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Application-Only Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)