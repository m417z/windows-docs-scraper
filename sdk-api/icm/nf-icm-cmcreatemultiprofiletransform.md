## Description

Accepts an array of profiles or a single [device link profile](https://learn.microsoft.com/windows/win32/wcs/d) and creates a color transform. This transform is a mapping from the color space specified by the first profile to that of the second profile and so on to the last one.

## Parameters

### `pahProfiles`

Points to an array of profile handles.

### `nProfiles`

Specifies the number of profiles in the array.

### `padwIntents`

Points to an array of rendering intents. Each rendering intent is represented by one of the following values:
INTENT\_PERCEPTUAL
INTENT\_SATURATION
INTENT\_RELATIVE\_COLORIMETRIC
INTENT\_ABSOLUTE\_COLORIMETRIC
For more information, see [Rendering intents](https://learn.microsoft.com/windows/win32/wcs/rendering-intents).

### `nIntents`

Specifies the number of intents in the intent array. Can be 1, or the same value as *nProfiles*.

### `dwFlags`

Specifies flags to used control creation of the transform. For details, see [CMM Transform Creation Flags](https://learn.microsoft.com/windows/win32/wcs/cmm-transform-creation-flags).

## Return value

If this function succeeds, the return value is a color transform in the range 256 to 65,535. Since only the low **WORD** of the transform is retained, valid transforms cannot exceed this range.

If this function fails, the return value is an error code having a value less than 256. When the return value is less than 256, signaling an error, the CMM should use **SetLastError** to set the last error to a valid error value as defined in Winerror.h.

## Remarks

Every CMM is required to export this function.

The array of intents specifies how profiles should be combined. The *n*th intent is used for combining the *n*th profile in the array. If only one intent is specified, it is used for the first profile, and all other profiles are combined using Match intent.

The profile handles used to create the color transform can be closed after the call to **CMCreateMultiProfileTransform** completes.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)