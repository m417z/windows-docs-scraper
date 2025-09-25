# MFCreateVideoMediaTypeFromBitMapInfoHeader function

## Description

This function is not implemented.

## Parameters

### `pbmihBitMapInfoHeader`

Reserved.

### `dwPixelAspectRatioX`

Reserved.

### `dwPixelAspectRatioY`

Reserved.

### `InterlaceMode`

Reserved.

### `VideoFlags`

Reserved.

### `qwFramesPerSecondNumerator`

Reserved.

### `qwFramesPerSecondDenominator`

Reserved.

### `dwMaxBitRate`

Reserved.

### `ppIVideoMediaType`

Reserved.

## Return value

Returns **E_FAIL**.

## Remarks

**Note** Prior to Windows 7, this function was exported from evr.dll. Starting in Windows 7, this function is exported from mfplat.dll, and evr.dll exports a stub function that calls into mfplat.dll. For more information, see [Library Changes in Windows 7](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-headers-and-libraries).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)