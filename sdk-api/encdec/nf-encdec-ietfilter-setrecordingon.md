# IETFilter::SetRecordingOn

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetRecordingOn** method signals to the Encrypter/Tagger filter that the Video Control is about to start or stop recording.

## Parameters

### `fRecState`

**TRUE** if recording is about to start, or **FALSE** if recording is about to stop.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The **SetRecordingOn** method enables the Video Control to enforce copy protection in the television broadcast signal. When the Video Control uses the Stream Buffer Engine to play television content, the Encrypter/Tagger filter is located in the Stream Buffer Sink graph. The Encrypter/Tagger sends data to the Stream Buffer Sink for both playback and recording. When **SetRecordingOn** is called with the value **TRUE**, the Encrypter/Tagger watches the video stream for the copy protection flags and sends a broadcast event if they change. The Video Control listens for the event and disallows the recording if indicated by the copy protection flag.

## See also

[IETFilter Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/encdec/nn-encdec-ietfilter)