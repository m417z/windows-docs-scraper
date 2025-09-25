# IAMPluginControl::GetPreferredClsid

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Searches the preferred list for a class identifier (CLSID) that matches a specified subtype.

## Parameters

### `subType` [in]

A media subtype GUID to match.

### `clsid` [out]

Receives a CLSID from the preferred list.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | No CLSID matching this subtype was found. |

## See also

[IAMPluginControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamplugincontrol)

[Intelligent Connect](https://learn.microsoft.com/windows/desktop/DirectShow/intelligent-connect)