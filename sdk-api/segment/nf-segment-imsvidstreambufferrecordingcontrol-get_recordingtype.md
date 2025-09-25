# IMSVidStreamBufferRecordingControl::get_RecordingType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_RecordingType** method retrieves the type of recording, either content recording or reference recording.

## Parameters

### `dwType` [out]

Pointer to a variable that receives one of the following values.

| Value | Description |
| --- | --- |
| CONTENT | Content recording |
| REFERENCE | Reference recording |

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[Creating Stream Buffer Recordings](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/creating-stream-buffer-recordings)

[IMSVidStreamBufferRecordingControl Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambufferrecordingcontrol)