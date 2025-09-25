# IDDrawExclModeVideo::SetCallbackInterface

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetCallbackInterface` method retrieves a pointer to the callback interface of the Overlay Mixer so that the calling application can be notified about adjustments to the display during video playback.

## Parameters

### `pCallback` [out]

Pointer to the object that implements the [IDDrawExclModeVideoCallback](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iddrawexclmodevideocallback) interface. If *pCallback* is **NULL**, the callback interface is set to **NULL** and no more callbacks are made. If there was a previous callback interface, it is released and no more callbacks are made to it. If *pCallback* is not **NULL** and this method returns S_OK, then the reference count of the object *pCallback* points to is incremented.

### `dwFlags` [in]

Must be zero.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Argument is invalid. |

## Remarks

An application should use this method to get notification about the overlay size, position, or color key change happening, so that it can hide or show the video, or adjust the video at the start, end, or during playback. By calling this method, an application can access the [IDDrawExclModeVideoCallback](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iddrawexclmodevideocallback) interface and pass the pointer to that interface to the Overlay Mixer.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDDrawExclModeVideo Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iddrawexclmodevideo)