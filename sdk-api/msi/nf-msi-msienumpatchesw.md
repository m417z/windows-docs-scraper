# MsiEnumPatchesW function

## Description

The
**MsiEnumPatches** function enumerates all of the patches that have been applied to a product. The function returns the patch code GUID for each patch that has been applied to the product and returns a list of transforms from each patch that apply to the product. Note that patches may have many transforms only some of which are applicable to a particular product. The list of transforms are returned in the same format as the value of the
[TRANSFORMS](https://learn.microsoft.com/windows/desktop/Msi/transforms) property.

**Note** *pcchTransformsBuf* is not set to the number of characters copied to *lpTransformsBuf* upon a successful return of
**MsiEnumPatches**.

## Parameters

### `szProduct` [in]

Specifies the product code of the product for which patches are to be enumerated.

### `iPatchIndex` [in]

Specifies the index of the patch to retrieve. This parameter should be zero for the first call to the
**MsiEnumPatches** function and then incremented for subsequent calls.

### `lpPatchBuf` [out]

Pointer to a buffer that receives the patch's GUID. This argument is required.

### `lpTransformsBuf` [out]

Pointer to a buffer that receives the list of transforms in the patch that are applicable to the product. This argument is required and cannot be Null.

### `pcchTransformsBuf` [in, out]

Set to the number of characters copied to *lpTransformsBuf* upon an unsuccessful return of the function. Not set for a successful return. On input, this is the full size of the buffer, including a space for a terminating null character. If the buffer passed in is too small, the count returned does not include the terminating null character.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_NO_MORE_ITEMS** | There are no patches to return. |
| **ERROR_SUCCESS** | A value was enumerated. |
| **ERROR_MORE_DATA** | A buffer is too small to hold the requested data. |

## Remarks

To enumerate patches, an application should initially call the
**MsiEnumPatches** function with the *iPatchIndex* parameter set to zero. The application should then increment the *iPatchIndex* parameter and call
**MsiEnumPatches** until there are no more products (until the function returns ERROR_NO_MORE_ITEMS).

If the buffer is too small to hold the requested data,
**MsiEnumPatches** returns ERROR_MORE_DATA and *pcchTransformsBuf* contains the number of characters copied to *lpTransformsBuf*, without counting the Null character.

> [!NOTE]
> The msi.h header defines MsiEnumPatches as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).