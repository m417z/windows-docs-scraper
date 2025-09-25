# IConfigAsfWriter::GetCurrentProfileGuid

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCurrentProfileGuid` method retrieves the GUID of the [WM ASF Writer](https://learn.microsoft.com/windows/desktop/DirectShow/wm-asf-writer-filter) filter's current system profile, if any. (Deprecated.)

## Parameters

### `pProfileGuid` [out]

Receives the **GUID** of the system profile.

## Return value

Returns S_OK if successful, or an **HRESULT** error code otherwise.

## Remarks

This method applies only when the WM ASF Writer filter is configured with a system profile. If the application provided its own ASF profile instead of a system profile (as is recommended), the profile GUID is GUID_NULL. Applications should call [IConfigAsfWriter::GetCurrentProfile](https://learn.microsoft.com/windows/desktop/api/dshowasf/nf-dshowasf-iconfigasfwriter-getcurrentprofile) to get the current profile.

## See also

[Creating ASF Files in DirectShow](https://learn.microsoft.com/windows/desktop/DirectShow/creating-asf-files-in-directshow)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IConfigAsfWriter Interface](https://learn.microsoft.com/windows/desktop/api/dshowasf/nn-dshowasf-iconfigasfwriter)