# IConfigAsfWriter2::GetParam

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetParam` method retrieves the current value of the specified filter configuration parameter.

## Parameters

### `dwParam` [in]

Specifies the parameter to retrieve, as a member of the [_AM_ASFWRITERCONFIG_PARAM](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758054(v=vs.85)) enumeration.

### `pdwParam1` [out]

Receives the value of the parameter specified in *dwParam*.

### `pdwParam2` [out]

Reserved. Must be zero.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[Creating ASF Files in DirectShow](https://learn.microsoft.com/windows/desktop/DirectShow/creating-asf-files-in-directshow)

[IConfigAsfWriter2 Interface](https://learn.microsoft.com/windows/desktop/api/dshowasf/nn-dshowasf-iconfigasfwriter2)