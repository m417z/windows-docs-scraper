# IConfigAsfWriter::ConfigureFilterUsingProfileId

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ConfigureFilterUsingProfileId` method sets a Windows Media Format 4.0 profile on the [WM ASF Writer](https://learn.microsoft.com/windows/desktop/DirectShow/wm-asf-writer-filter) filter. This method is deprecated. Applications should use the [IConfigAsfWriter::ConfigureFilterUsingProfile](https://learn.microsoft.com/windows/desktop/api/dshowasf/nf-dshowasf-iconfigasfwriter-configurefilterusingprofile) method to set the profile.

## Parameters

### `dwProfileId` [in]

Profile ID as defined in version 4.0 of the Windows Media Format SDK.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | The profile is invalid. |
| **VFW_E_WRONG_STATE** | The filter graph is stopped. |

## Remarks

This method is now obsolete because it assumes version 4.0 Windows Media Format SDK profiles.

## See also

[Creating ASF Files in DirectShow](https://learn.microsoft.com/windows/desktop/DirectShow/creating-asf-files-in-directshow)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IConfigAsfWriter Interface](https://learn.microsoft.com/windows/desktop/api/dshowasf/nn-dshowasf-iconfigasfwriter)