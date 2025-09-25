# IAMResourceControl::Reserve

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Reserve` method reserves or unreserves a device resource.

## Parameters

### `dwFlags` [in]

Flag indicating whether to reserve or unreserve this device. The value must be a member of the [AMRESCTL_RESERVEFLAGS](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-_amresctl_reserveflags) enumeration.

### `pvReserved` [in]

Must be **NULL**.

## Return value

Returns S_OK if the device was successfully reserved or unreserved, S_FALSE if the device is currently reserved and will continue to be held, or an **HRESULT** error code if the device can't be reserved.

## Remarks

A resource can be reserved multiple times. If the method returns S_OK, the filter increments an internal reserve count. For every call to reserve a device that returns S_OK, the caller must make a matching call to unreserve the device.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMResourceControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamresourcecontrol)