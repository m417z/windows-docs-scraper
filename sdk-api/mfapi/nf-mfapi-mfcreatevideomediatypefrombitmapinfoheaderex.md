# MFCreateVideoMediaTypeFromBitMapInfoHeaderEx function

## Description

Creates a video media type from a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure.

## Parameters

### `pbmihBitMapInfoHeader` [in]

A pointer to the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure to convert.

### `cbBitMapInfoHeader` [in]

The size of the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure in bytes, including the size of any palette entries or color masks that follow the structure.

### `dwPixelAspectRatioX`

The X dimension of the pixel aspect ratio.

### `dwPixelAspectRatioY`

The Y dimension of the pixel aspect ratio.

### `InterlaceMode`

A member of the [MFVideoInterlaceMode](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfvideointerlacemode) enumeration, specifying how the video is interlaced.

### `VideoFlags`

A bitwise **OR** of flags from the [MFVideoFlags](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfvideoflags) enumeration.

### `dwFramesPerSecondNumerator`

The numerator of the
frame rate in frames per second.

### `dwFramesPerSecondDenominator`

The denominator of the frame rate in frames per second

### `dwMaxBitRate`

The approximate data rate of the video stream, in bits per second. If the rate is unknown, set this parameter to zero.

### `ppIVideoMediaType` [out]

Receives a pointer to the
[IMFVideoMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfvideomediatype) interface. The caller must release the interface.

## Return value

If the function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)