# MsiGetFeatureUsageA function

## Description

The
**MsiGetFeatureUsage** function returns the usage metrics for a product feature.

## Parameters

### `szProduct` [in]

Specifies the product code for the product that contains the feature.

### `szFeature` [in]

Specifies the feature code for the feature for which metrics are to be returned.

### `pdwUseCount` [out]

Indicates the number of times the feature has been used.

### `pwDateUsed` [out]

Specifies the date that the feature was last used. The date is in the MS-DOS date format, as shown in the following table.

| Bits | Meaning |
| --- | --- |
| 0 – 4 | Day of the month (1-31) |
| 5 – 8 | Month (1 = January, 2 = February, and so on) |
| 9 – 15 | Year offset from 1980 (add 1980 to get actual year) |

## Return value

The
**MsiGetFeatureUsage** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INSTALL_FAILURE** | No usage information is available or the product or feature is invalid. |
| **ERROR_SUCCESS** | The function completed successfully. |

## See also

[System Status Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)

## Remarks

> [!NOTE]
> The msi.h header defines MsiGetFeatureUsage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).