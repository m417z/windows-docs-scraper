# IMSVidStreamBufferRecordingControl::get_RecordingStopped

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_RecordingStopped** method queries whether the recording has stopped.

## Parameters

### `phResult` [out]

Pointer to a variable that receives one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_FALSE | The recording has not stopped. |
| VARIANT_TRUE | The recording has stopped. |

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMSVidStreamBufferRecordingControl Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambufferrecordingcontrol)