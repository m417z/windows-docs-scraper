# IAMVfwCompressDialogs::ShowDialog

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ShowDialog` method displays the specified dialog box.

## Parameters

### `iDialog` [in]

Dialog box to display. This is a member of the [VfwCompressDialogs](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-vfwcompressdialogs) enumeration.

### `hwnd` [in]

Handle of the dialog box's parent window.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

This method returns an error when asked to display a dialog box while the driver is streaming or displaying another dialog box. While the driver displays the dialog box you can't stream (pause or run) the filter.

`IAMVfwCompressDialogs::ShowDialog` calls the Video for Windows video compression manager (VCM) functions [ICConfigure](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icconfigure), [ICAbout](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icabout), [ICQueryConfigure](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icqueryconfigure), and [ICQueryAbout](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icqueryabout) to display the appropriate dialog box or determine if one exists.

The VfwCompressDialog_QueryConfig and VfwCompressDialog_QueryAbout members of the [VfwCompressDialogs](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-vfwcompressdialogs) enumeration tell you whether or not the configure dialog or about dialog is available. If passed one of these flags, the filter will return S_OK if the dialog exists, and S_FALSE if it does not. If a dialog is available, you call `ShowDialog` with the value VfwCompressDialog_Config or VfwCompressDialog_About to bring up the dialog.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVfwCompressDialogs Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvfwcompressdialogs)