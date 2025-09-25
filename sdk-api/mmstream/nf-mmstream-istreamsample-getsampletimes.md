# IStreamSample::GetSampleTimes

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Retrieves the current sample's start and end times. If the sample is updating, this method returns the times after the update completes.

## Parameters

### `pStartTime` [out]

Pointer to a STREAM_TIME value that will contain the sample's start time.

### `pEndTime` [out]

Pointer to a STREAM_TIME value that will contain the sample's end time.

### `pCurrentTime` [out]

Pointer to a STREAM_TIMEvalue that will contain the media stream's current media time.

## Return value

Returns S_OK if successful or E_POINTER if one of the parameters is invalid.

## Remarks

For streams that have a clock, the start and end times will be relative to the stream's current time. If the stream doesn't have a clock, the times are media-relative and the current time will be zero.

The *pCurrentTime* parameter enables you to conveniently track the media stream's current time, so you don't have to call [IMultiMediaStream::GetTime](https://learn.microsoft.com/windows/desktop/api/mmstream/nf-mmstream-imultimediastream-gettime). Unlike **GetTime**, however, this method returns S_OK if the stream doesn't have a clock; **GetTime** returns S_FALSE. The value assigned to *pCurrentTime* is the same as the value produced by the following code fragment.

```cpp

IMediaStream *pMediaStream = 0;
hr = pSample->GetMediaStream(&pMediaStream);
if (SUCCEEDED(hr))
{
  IMultiMediaStream *pMultiMediaStream = 0;
  hr = pMediaStream->GetMultiMediaStream(&pMultiMediaStream);
  pMediaStream->Release();
  if (SUCCEEDED(hr))
  {
    STREAM_TIME CurrentTime = 0;
    hr = pMultiMediaStream->GetTime(&CurrentTime);
    pMultiMediaStream->Release();
  }
}

```

## See also

[IStreamSample Interface](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-istreamsample)

[Multimedia Streaming Data Types](https://learn.microsoft.com/windows/desktop/DirectShow/multimedia-streaming-data-types)