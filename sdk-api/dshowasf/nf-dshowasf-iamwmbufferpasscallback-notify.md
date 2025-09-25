# IAMWMBufferPassCallback::Notify

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Notify** method is called by the pin for each buffer that is delivered during streaming.

## Parameters

### `pNSSBuffer3` [in]

Pointer to the [INSSBuffer3](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer3) interface exposed on the media sample.

### `pPin` [in]

Pointer to the pin associated with the media stream that the sample belongs to.

### `prtStart` [in]

Start time of the sample.

### `prtEnd` [in]

End time of the sample.

## Return value

No particular return value is specified. The calling pin ignores the **HRESULT**.

## Remarks

This method enables an application to examine and act on information in the media buffer before the buffer contents are processed. The application is responsible for knowing the media type on the pin. This information can be obtained by first getting the stream information from the profile and then calling [IConfigAsfWriter2::StreamNumFromPin](https://learn.microsoft.com/windows/desktop/wmformat/iconfigasfwriter2-streamnumfrompin) method to determine which pin is associated with each stream.

## See also

[DirectShow QASF Reference](https://learn.microsoft.com/windows/desktop/wmformat/directshow-qasf-reference)

[IAMWMBufferPassCallback Interface](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd798277(v=vs.85))

[INSSBuffer3 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer3)