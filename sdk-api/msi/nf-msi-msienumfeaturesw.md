# MsiEnumFeaturesW function

## Description

The
**MsiEnumFeatures** function enumerates the published features for a given product. This function retrieves one feature ID each time it is called.

## Parameters

### `szProduct` [in]

Null-terminated string specifying the product code of the product whose features are to be enumerated.

### `iFeatureIndex` [in]

Specifies the index of the feature to retrieve. This parameter should be zero for the first call to the
**MsiEnumFeatures** function and then incremented for subsequent calls. Because features are not ordered, any new feature has an arbitrary index. This means that the function can return features in any order.

### `lpFeatureBuf` [out]

Pointer to a buffer that receives the feature ID. The size of the buffer must hold a string value of length MAX_FEATURE_CHARS+1. The function returns **ERROR_MORE_DATA** if the length of the feature ID exceeds **MAX_FEATURE_CHARS**.

### `lpParentBuf` [out]

Pointer to a buffer that receives the feature ID of the parent of the feature. The size of the buffer must hold a string value of length MAX_FEATURE_CHARS+1. If the length of the feature ID of the parent feature exceeds **MAX_FEATURE_CHARS**, only the first **MAX_FEATURE_CHARS** characters get copied into the buffer.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_MORE_DATA** | A buffer is too small to hold the requested data. |
| **ERROR_NO_MORE_ITEMS** | There are no features to return. |
| **ERROR_SUCCESS** | A value was enumerated. |
| **ERROR_UNKNOWN_PRODUCT** | The specified product is unknown. |

## Remarks

To enumerate features, an application should initially call the
**MsiEnumFeatures** function with the *iFeatureIndex* parameter set to zero. The application should then increment the *iFeatureIndex* parameter and call
**MsiEnumFeatures** until there are no more features (that is, until the function returns ERROR_NO_MORE_ITEMS).

> [!NOTE]
> The msi.h header defines MsiEnumFeatures as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[System Status Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)