# mixerClose function

## Description

The **mixerClose** function closes the specified mixer device.

## Parameters

### `hmx`

Handle to the mixer device. This handle must have been returned successfully by the [mixerOpen](https://learn.microsoft.com/previous-versions/dd757308(v=vs.85)) function. If **mixerClose** is successful, *hmx* is no longer valid.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |

## See also

[Audio Mixer Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-functions)

[Audio Mixers](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixers)