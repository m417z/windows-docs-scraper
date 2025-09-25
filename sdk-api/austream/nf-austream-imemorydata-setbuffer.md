# IMemoryData::SetBuffer

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Initializes a memory buffer with a pointer to memory and length.

## Parameters

### `cbSize` [in]

Size of memory pointed to by *pbData*, in bytes.

### `pbData` [in]

Pointer to memory that this object will use.

### `dwFlags` [in]

Reserved for flag data. Must be zero.

## Return value

Returns S_OK if successful or E_INVALIDARG if *cbSize* is zero or *pbData* is **NULL**.

## Remarks

This method can be called as often as needed. When using [IStreamSample::Update](https://learn.microsoft.com/windows/desktop/api/mmstream/nf-mmstream-istreamsample-update) to update samples asynchronously, make sure that SetBuffer is never called before an update is completed.

## See also

[IMemoryData Interface](https://learn.microsoft.com/windows/desktop/api/austream/nn-austream-imemorydata)