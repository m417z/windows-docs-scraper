# IMemoryData::GetInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Retrieves information describing an audio data object.

## Parameters

### `pdwLength` [out]

Length of memory in bytes, if non-**NULL**.

### `ppbData` [out]

Pointer to the memory, if non-**NULL**.

### `pcbActualData` [out]

Length of data in bytes, if non-**NULL**.

## Return value

Returns an **HRESULT** value.

## Remarks

This method determines how much data the object currently contains as last set by [SetActual](https://learn.microsoft.com/windows/desktop/api/austream/nf-austream-imemorydata-setactual).

## See also

[IMemoryData Interface](https://learn.microsoft.com/windows/desktop/api/austream/nn-austream-imemorydata)