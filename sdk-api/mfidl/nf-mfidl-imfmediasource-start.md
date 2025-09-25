# IMFMediaSource::Start

## Description

Starts, seeks, or restarts the media source by specifying where to start playback.

## Parameters

### `pPresentationDescriptor` [in]

Pointer to the [IMFPresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationdescriptor) interface of the media source's presentation descriptor. To get the presentation descriptor, call [IMFMediaSource::CreatePresentationDescriptor](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-createpresentationdescriptor). You can modify the presentation descriptor before calling **Start**, to select or deselect streams or change the media types.

### `pguidTimeFormat` [in]

Pointer to a GUID that specifies the time format. The time format defines the units for the *pvarStartPosition* parameter. If the value  is **GUID_NULL**, the time format is 100-nanosecond units. Some media sources might support additional time format GUIDs. This parameter can be **NULL**. If the value is **NULL**, it is equivalent to **GUID_NULL**.

### `pvarStartPosition` [in]

Specifies where to start playback. The units of this parameter are indicated by the time format given in *pguidTimeFormat*. If the time format is **GUID_NULL**, the variant type must be **VT_I8** or **VT_EMPTY**. Use **VT_I8** to specify a new starting position, in 100-nanosecond units. Use **VT_EMPTY** to start from the current position. Other time formats might use other **PROPVARIANT** types.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ASF_OUTOFRANGE** | The start position is past the end of the presentation (ASF media source). |
| **MF_E_HW_MFT_FAILED_START_STREAMING** | A hardware device was unable to start streaming. This error code can be returned by a media source that represents a hardware device, such as a camera. For example, if the camera is already being used by another application, the method might return this error code. |
| **MF_E_INVALIDREQUEST** | The start request is not valid. For example, the start position is past the end of the presentation. |
| **MF_E_SHUTDOWN** | The media source's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-shutdown) method has been called. |
| **MF_E_UNSUPPORTED_TIME_FORMAT** | The media source does not support the time format specified in *pguidTimeFormat*. |

## Remarks

This method is asynchronous. If the operation succeeds, the media source sends the following events:

* For each new stream, the source sends an [MENewStream](https://learn.microsoft.com/windows/desktop/medfound/menewstream) event. This event is sent for the first **Start** call in which the stream appears. The event data is a pointer to the stream's [IMFMediaStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediastream) interface.
* For each *updated* stream, the source sends an [MEUpdatedStream](https://learn.microsoft.com/windows/desktop/medfound/meupdatedstream) event. A stream is updated if the stream already existed when **Start** was called (for example, if the application seeks during playback). The event data is a pointer to the stream's [IMFMediaStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediastream) interface.
* If the previous state was stopped, the source sends an [MESourceStarted](https://learn.microsoft.com/windows/desktop/medfound/mesourcestarted) event.
* If the previous state was started or paused and the starting position is the current position (**VT_EMPTY**), the source sends an [MESourceStarted](https://learn.microsoft.com/windows/desktop/medfound/mesourcestarted) event.
* If the previous state was started or paused, and a new starting position is specified, the source sends an [MESourceSeeked](https://learn.microsoft.com/windows/desktop/medfound/mesourceseeked) event.
* If the source sends an [MESourceStarted](https://learn.microsoft.com/windows/desktop/medfound/mesourcestarted) event, each media stream sends an [MEStreamStarted](https://learn.microsoft.com/windows/desktop/medfound/mestreamstarted) event. If the source sends an [MESourceSeeked](https://learn.microsoft.com/windows/desktop/medfound/mesourceseeked) event, each stream sends an [MEStreamSeeked](https://learn.microsoft.com/windows/desktop/medfound/mestreamseeked) event.

If the start operation fails asynchronously (after the method returns **S_OK**), the media source sends an [MESourceStarted](https://learn.microsoft.com/windows/desktop/medfound/mesourcestarted) event that contains a failure code, without sending any of the other events listed here. If the method fails synchronously (returns an error code), no events are raised.

A call to **Start** results in a *seek* if the previous state was started or paused, and the new starting position is not **VT_EMPTY**. Not every media source can seek. If a media source can seek, the [IMFMediaSource::GetCharacteristics](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-getcharacteristics) method returns the **MFMEDIASOURCE_CAN_SEEK** flag.

Events from the media source are not synchronized with events from the media streams. If you seek a media source, therefore, you can still receive samples from the earlier position after getting the [MESourceSeeked](https://learn.microsoft.com/windows/desktop/medfound/mesourceseeked) event. If you need to synchronize the operations, wait for the stream event, [MEStreamSeeked](https://learn.microsoft.com/windows/desktop/medfound/mestreamseeked), which marks the exact point in the stream where the seek occurs.

### End of Stream

When a stream plays to the end, the stream sends an [MEEndOfStream](https://learn.microsoft.com/windows/desktop/medfound/meendofstream) event. When all of the selected streams have reached the end, the media source sends an [MEEndOfPresentation](https://learn.microsoft.com/windows/desktop/medfound/meendofpresentation) event.

If the starting position is past the end of a selected stream (but before the end of the presentation), the stream should send [MEEndOfStream](https://learn.microsoft.com/windows/desktop/medfound/meendofstream) immediately after [MEStreamStarted](https://learn.microsoft.com/windows/desktop/medfound/mestreamstarted)/[MEStreamSeeked](https://learn.microsoft.com/windows/desktop/medfound/mestreamseeked). If playback reaches the end of the presentation and **Start** is called again from the current position, the streams re-send the MEEndOfStream event and the media source re-sends the [MEEndOfPresentation](https://learn.microsoft.com/windows/desktop/medfound/meendofpresentation) event. These events inform the pipeline not to request any more data.

During reverse playback, the start of the file is considered the end of the stream. For more information, see [Implementing Rate Control](https://learn.microsoft.com/windows/desktop/medfound/implementing-rate-control).

### Implementing Start

When a media source executes a seek, it should start at the first key frame before the seek time, so that the decoder can decode the samples for the target start time. The pipeline will discard any decoded samples that are too early.

If the start time is **VT_EMPTY** and the previous state was started or paused, the source should resume from its current position. In this case, it is not necessary to resend the previous key frame, because the decoder will still have the data that was previously sent.

When validating the *pPresentationDescriptor* parameter, the media source should check only for the information that it needs to function correctly. In particular, the client can add private attributes to the presentation descriptor. The presence of additional attributes should not cause the **Start** method to fail.

After **Start** is called, each stream on the media source must do one of the following:

* Deliver media data in response to [IMFMediaStream::RequestSample](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediastream-requestsample) calls.
* Send [MEStreamTick](https://learn.microsoft.com/windows/desktop/medfound/mestreamtick) events to indicate a gap in the stream.
* Send an [MEEndOfStream](https://learn.microsoft.com/windows/desktop/medfound/meendofstream) event to indicate the end of the stream.

For more information, see [Writing a Custom Media Source](https://learn.microsoft.com/windows/desktop/medfound/writing-a-custom-media-source).

#### Examples

The following example starts playback at 1 second into the presentation.

```
PROPVARIANT var;
PropVariantInit(&var);
var.vt = VT_I8;
var.hVal.QuadPart = 10000000; // 10^7 = 1 second.

hr = pSource->Start(pPresentationDescriptor, NULL, &var);

```

## See also

[IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource)

[Media Sources](https://learn.microsoft.com/windows/desktop/medfound/media-sources)