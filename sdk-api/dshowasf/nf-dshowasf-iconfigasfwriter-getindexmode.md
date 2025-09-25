# IConfigAsfWriter::GetIndexMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetIndexMode` method retrieves the current index mode.

## Parameters

### `pbIndexFile` [out]

Receives the index mode setting. A value of **TRUE** indicates that the WM ASF Writer is configured to write indexed files.

## Return value

Returns S_OK if successful, or an **HRESULT** error code otherwise.

## Remarks

Use this method to determine whether the WM ASF Writer is currently configured to write indexed ASF files. For more information, see [IConfigAsfWriter::SetIndexMode](https://learn.microsoft.com/windows/desktop/api/dshowasf/nf-dshowasf-iconfigasfwriter-setindexmode).

## See also

[Creating ASF Files in DirectShow](https://learn.microsoft.com/windows/desktop/DirectShow/creating-asf-files-in-directshow)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IConfigAsfWriter Interface](https://learn.microsoft.com/windows/desktop/api/dshowasf/nn-dshowasf-iconfigasfwriter)