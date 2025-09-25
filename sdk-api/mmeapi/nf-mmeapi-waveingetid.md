# waveInGetID function

## Description

The **waveInGetID** function gets the device identifier for the given waveform-audio input device.

This function is supported for backward compatibility. New applications can cast a handle of the device rather than retrieving the device identifier.

## Parameters

### `hwi`

Handle to the waveform-audio input device.

### `puDeviceID`

Pointer to a variable to be filled with the device identifier.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | The *hwi* parameter specifies an invalid handle. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)