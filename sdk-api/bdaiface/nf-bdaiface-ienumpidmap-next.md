# IEnumPIDMap::Next

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Next` method retrieves the next *n* elements in the collection.

## Parameters

### `cRequest` [in]

The number of elements to retrieve.

### `pPIDMap` [in, out]

Address of an array allocated by the caller, containing *cRequest* elements. The array is filled with [PID_MAP](https://learn.microsoft.com/windows/desktop/DirectShow/pid-map) structures that describe the PID mapping.

### `pcReceived` [out]

Pointer to a variable that receives the number of elements actually retrieved. This parameter cannot be **NULL**. If *cRequest* equals zero, this parameter receives the total number of items in the collection.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument; *pPidMap* and *pcReceived* cannot be **NULL**. |
| **S_FALSE** | Reached the end of the collection. |
| **S_OK** | Success. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IEnumPIDMap Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ienumpidmap)