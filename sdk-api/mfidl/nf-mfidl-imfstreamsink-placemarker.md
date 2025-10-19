# IMFStreamSink::PlaceMarker

## Description

Places a marker in the stream.

## Parameters

### `eMarkerType` [in]

Specifies the marker type, as a member of the [MFSTREAMSINK_MARKER_TYPE](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfstreamsink_marker_type) enumeration.

### `pvarMarkerValue` [in]

Optional pointer to a **PROPVARIANT** that contains additional information related to the marker. The meaning of this value depends on the marker type. This parameter can be **NULL**.

### `pvarContextValue` [in]

Optional pointer to a **PROPVARIANT** that is attached to the [MEStreamSinkMarker](https://learn.microsoft.com/windows/desktop/medfound/mestreamsinkmarker) event. Call [IMFMediaEvent::GetValue](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediaevent-getvalue) to get this value from the event. The caller can use this information for any purpose. This parameter can be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The media sink's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method has been called. |
| **MF_E_STREAMSINK_REMOVED** | This stream was removed from the media sink and is no longer valid. |

## Remarks

This method causes the stream sink to send an [MEStreamSinkMarker](https://learn.microsoft.com/windows/desktop/medfound/mestreamsinkmarker) event after the stream sink consumes all of the samples that were delivered up to this point (before the call to **PlaceMarker**).

## See also

[IMFStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamsink)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)