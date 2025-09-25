# IMSVidStreamBufferRecordingControl::put_StopTime

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_StopTime** method sets the stop time for the recording.

## Parameters

### `rtStop` [in]

Specifies the stop time, in hundredths of seconds.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | The method succeeded. |

## See also

[IMSVidStreamBufferRecordingControl Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambufferrecordingcontrol)