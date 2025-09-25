# IMFMediaSink::GetCharacteristics

## Description

Gets the characteristics of the media sink.

## Parameters

### `pdwCharacteristics` [out]

Receives a bitwise **OR** of zero or more flags. The following flags are defined:

| Value | Meaning |
| --- | --- |
| ****MEDIASINK_FIXED_STREAMS****<br><br>0x00000001 | The media sink has a fixed number of streams. It does not support the [IMFMediaSink::AddStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-addstreamsink) and [IMFMediaSink::RemoveStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-removestreamsink) methods. This flag is a hint to the application. |
| ****MEDIASINK_CANNOT_MATCH_CLOCK****<br><br>0x00000002 | The media sink cannot match rates with an external clock.<br><br>For best results, this media sink should be used as the time source for the presentation clock. If any other time source is used, the media sink cannot match rates with the clock, with poor results (for example, glitching).<br><br>This flag should be used sparingly, because it limits how the pipeline can be configured.<br><br>For more information about the presentation clock, see [Presentation Clock](https://learn.microsoft.com/windows/desktop/medfound/presentation-clock). |
| ****MEDIASINK_RATELESS****<br><br>0x00000004 | The media sink is rateless. It consumes samples as quickly as possible, and does not synchronize itself to a presentation clock.<br><br>Most archiving sinks are rateless. |
| ****MEDIASINK_CLOCK_REQUIRED****<br><br>0x00000008 | The media sink requires a presentation clock. The presentation clock is set by calling the media sink's [IMFMediaSink::SetPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-setpresentationclock) method.<br><br>This flag is obsolete, because all media sinks must support the [SetPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-setpresentationclock) method, even if the media sink ignores the clock (as in a rateless media sink). |
| ****MEDIASINK_CAN_PREROLL****<br><br>0x00000010 | The media sink can accept preroll samples before the presentation clock starts. The media sink exposes the [IMFMediaSinkPreroll](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasinkpreroll) interface. |
| ****MEDIASINK_REQUIRE_REFERENCE_MEDIATYPE****<br><br>0x00000020 | The first stream sink (index 0) is a reference stream. The reference stream must have a media type before the media types can be set on the other stream sinks. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****MF_E_SHUTDOWN**** | The media sink's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method has been called. |

## Remarks

The characteristics of a media sink are fixed throughout the life time of the sink.

## See also

[IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)