## Description

The **waveInGetDevCapsA** function retrieves the capabilities of a given waveform-audio input device. This is the ANSI version of this function.

## Parameters

### `uDeviceID`

Identifier of the waveform-audio input device. It can be either a device identifier or a handle of an open waveform-audio input device.

### `pwic`

Pointer to a [WAVEINCAPSA](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-waveincapsa) structure to be filled with information about the capabilities of the device.

### `cbwic`

Size, in bytes, of the **WAVEINCAPSA** structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
|-------------|-------------|
| MMSYSERR_BADDEVICEID | Specified device identifier is out of range. |
| MMSYSERR_NODRIVER | No device driver is present. |
| MMSYSERR_NOMEM | Unable to allocate or lock memory. |

## Remarks

Use this function to determine the number of waveform-audio input devices present in the system. If the value specified by the *uDeviceID* parameter is a device identifier, it can vary from zero to one less than the number of devices present. The WAVE_MAPPER constant can also be used as a device identifier. Only *cbwic* bytes (or less) of information is copied to the location pointed to by *pwic*. If *cbwic* is zero, nothing is copied and the function returns zero.

## See also