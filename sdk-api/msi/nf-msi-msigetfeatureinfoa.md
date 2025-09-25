# MsiGetFeatureInfoA function

## Description

The
**MsiGetFeatureInfo** function returns descriptive information for a feature.

## Parameters

### `hProduct` [in]

Handle to the product that owns the feature. This handle is obtained from
[MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szFeature` [in]

Feature code for the feature about which information should be returned.

### `lpAttributes` [out, optional]

Pointer to a location containing one or more of the following Attribute flags.

#### INSTALLFEATUREATTRIBUTE_FAVORLOCAL (1)

#### INSTALLFEATUREATTRIBUTE_FAVORSOURCE (2)

#### INSTALLFEATUREATTRIBUTE_FOLLOWPARENT (4)

#### INSTALLFEATUREATTRIBUTE_FAVORADVERTISE (8)

#### INSTALLFEATUREATTRIBUTE_DISALLOWADVERTISE (16)

#### INSTALLFEATUREATTRIBUTE_NOUNSUPPORTEDADVERTISE (32)

For more information, see
[Feature Table](https://learn.microsoft.com/windows/desktop/Msi/feature-table). The values that **MsiGetFeatureInfo** returns are double the values in the Attributes column of the Feature Table.

### `lpTitleBuf` [out, optional]

Pointer to a buffer to receive the localized name of the feature, which corresponds to the Title field in the [Feature Table](https://learn.microsoft.com/windows/desktop/Msi/feature-table).

This parameter is optional and can be null.

### `pcchTitleBuf` [in, out, optional]

As input, the size of *lpTitleBuf*. As output, the number of characters returned in *lpTitleBuf*. On input, this is the full size of the buffer, and includes a space for a terminating null character. If the buffer that is passed in is too small, the count returned does not include the terminating null character.

### `lpHelpBuf` [out, optional]

Pointer to a buffer to receive the localized description of the feature, which corresponds to the Description field for the feature in the [Feature table](https://learn.microsoft.com/windows/desktop/Msi/feature-table).
This parameter is optional and can be null.

### `pcchHelpBuf` [in, out, optional]

As input, the size of *lpHelpBuf*. As output, the number of characters returned in *lpHelpBuf*. On input, this is the full size of the buffer, and includes a space for a terminating null character. If the buffer passed in is too small, the count returned does not include the terminating null character.

## Return value

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The product handle is invalid. |
| **ERROR_INVALID_PARAMETER** | One of the parameters is invalid. |
| **ERROR_MORE_DATA** | A buffer is too small to hold the requested data. |
| **ERROR_SUCCESS** | The function returns successfully. |
| **ERROR_UNKNOWN_FEATURE** | The feature is not known. |

## Remarks

The buffer sizes for the
**MsiGetFeatureInfo** function should include an extra character for the terminating null character. If a buffer is too small, the returned string is truncated with null, and the buffer size contains the number of characters in the whole string, not including the terminating null character. For more information, see
[Calling Database Functions From Programs](https://learn.microsoft.com/windows/desktop/Msi/calling-database-functions-from-programs).

> [!NOTE]
> The msi.h header defines MsiGetFeatureInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Product Query Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)