# IMSVidStreamBufferSink::get_ContentRecorder

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_ContentRecorder** method creates a new content recording object.

## Parameters

### `pszFilename` [in]

Specifies the name of the file to hold the recording.

### `pRecordingIUnknown` [out]

Receives a pointer to the recording object's [IMSVidStreamBufferRecordingControl](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambufferrecordingcontrol) interface.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The caller must release the returned [IMSVidStreamBufferRecordingControl](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambufferrecordingcontrol) interface.

## See also

[IMSVidStreamBufferSink Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidstreambuffersink)