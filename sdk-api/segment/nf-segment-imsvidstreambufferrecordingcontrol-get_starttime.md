# IMSVidStreamBufferRecordingControl::get_StartTime

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_StartTime** method retrieves the start time of the recording.

## Parameters

### `rtStart` [out]

Pointer to a variable that receives the start time, in hundredths of seconds.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | The method succeeded. |

## See also

[IMSVidStreamBufferRecordingControl Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambufferrecordingcontrol)