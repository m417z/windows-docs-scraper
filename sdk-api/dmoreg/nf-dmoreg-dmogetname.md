# DMOGetName function

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DMOGetName** function retrieves the name of a DMO from the registry.

## Parameters

### `clsidDMO`

Class identifier (CLSID) of the DMO.

### `szName`

Array of 80 Unicode characters that receives the name of the DMO. The caller must allocate the array. The name is a NULL-terminated string.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure |
| **S_FALSE** | No name was registered for this DMO, or the name has zero length. |
| **S_OK** | Success |

## Remarks

If the method returns S_FALSE, *szName* is set to '\0'.

## See also

[DMO Functions](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-functions)