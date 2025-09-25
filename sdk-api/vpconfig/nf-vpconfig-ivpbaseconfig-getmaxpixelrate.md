# IVPBaseConfig::GetMaxPixelRate

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetMaxPixelRate` method retrieves the maximum pixel rate the device will output for a given width and height.

## Parameters

### `pamvpSize` [in, out]

Pointer to an [AMVPSIZE](https://learn.microsoft.com/previous-versions/windows/desktop/api/vptype/ns-vptype-amvpsize) structure containing the desired width and height.

### `pdwMaxPixelsPerSecond` [out]

Pointer to a variable that receives the maximum pixel rate, in pixels per second.

## Return value

Returns an **HRESULT** value.

## Remarks

This method retrieves the maximum pixels per second expected for a given size. If the device does not support this size, then it returns the rate and the size that it supports.

Include Dvp.h and Vptype.h before Vpconfig.h.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVPBaseConfig Interface](https://learn.microsoft.com/windows/desktop/api/vpconfig/nn-vpconfig-ivpbaseconfig)