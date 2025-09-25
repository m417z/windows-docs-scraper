# waveInGetPosition function

## Description

[**waveInGetPosition** is no longer supported for use as of Windows Vista. Instead, use [IAudioClock::GetPosition](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclock-getposition).]

The **waveInGetPosition** function retrieves the current input position of the given waveform-audio input device.

## Parameters

### `hwi`

Handle to the waveform-audio input device.

### `pmmt`

Pointer to an [MMTIME](https://learn.microsoft.com/previous-versions/dd757347(v=vs.85)) structure.

### `cbmmt`

Size, in bytes, of the [MMTIME](https://learn.microsoft.com/previous-versions/dd757347(v=vs.85)) structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |

## Remarks

Before calling this function, set the **wType** member of the [MMTIME](https://learn.microsoft.com/previous-versions/dd757347(v=vs.85)) structure to indicate the time format you want. After calling this function, check **wType** to determine whether the desired time format is supported. If the format is not supported, the member will specify an alternative format.

The position is set to zero when the device is opened or reset.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)