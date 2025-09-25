# DMOUnregister function

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The DMOUnregister function unregisters a DMO.

## Parameters

### `clsidDMO`

Class identifier (CLSID) of the DMO.

### `guidCategory`

GUID that specifies the category from which to remove the DMO. Use GUID_NULL to unregister the DMO from every category. See [DMO GUIDs](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-guids) for a list of category GUIDs.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Result Code | Description |
| --- | --- |
| E_INVALIDARG | Invalid argument |
| S_FALSE | This CLSID was not registered in the specified category. |
| S_OK | Success |

## See also

[DMO Functions](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-functions)