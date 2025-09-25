# IAMMediaTypeStream::CreateSample

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The `CreateSample` method creates a stream sample and optionally specifies the sample buffer.

## Parameters

### `lSampleSize` [in]

Size of the sample.

### `pbBuffer` [in]

[optional] Pointer to an array of bytes that contains the sample data, or **NULL**.

### `dwFlags` [in]

Reserved.

### `pUnkOuter` [in]

[optional] Pointer to the interface of an object that aggregates the stream sample.

### `ppAMMediaTypeSample` [in]

Address of an [IAMMediaTypeSample](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammediatypesample) interface pointer that receives a pointer to the created sample.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## Remarks

If *pUnkOuter* is non-**NULL**, the new stream sample is aggregated into the specified object. Filters that receive the sample can then query it for interfaces supported by the aggregating object.

## See also

[IAMMediaTypeStream Interface](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammediatypestream)