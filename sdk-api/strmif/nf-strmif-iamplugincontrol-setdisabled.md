# IAMPluginControl::SetDisabled

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Adds a class identifier (CLSID) to the blocked list, or removes a CLSID from the list.

## Parameters

### `clsid` [in]

The CLSID to add or remove.

### `disabled` [in]

Specifies whether to add or remove the CSLID. If the value is **TRUE**, the method adds the CLSID to the blocked list. Otherwise, the method removes it from the list.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAMPluginControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamplugincontrol)

[Intelligent Connect](https://learn.microsoft.com/windows/desktop/DirectShow/intelligent-connect)