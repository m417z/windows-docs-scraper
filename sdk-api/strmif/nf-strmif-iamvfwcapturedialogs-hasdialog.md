# IAMVfwCaptureDialogs::HasDialog

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `HasDialog` method determines if the specified dialog box exists in the driver.

## Parameters

### `iDialog` [in]

Desired dialog box. This is a member of the [VfwCaptureDialogs](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-vfwcapturedialogs) enumeration.

## Return value

Returns S_OK if the driver contains the dialog box or S_FALSE otherwise.

## Remarks

This method calls the Video for Windows **videoDialog** function to query for the existence of the appropriate dialog box.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVfwCaptureDialogs Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvfwcapturedialogs)