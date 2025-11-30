## Description

The **waveOutGetDevCapsW** function retrieves the capabilities of a given waveform-audio output device. This is the Unicode version of the function.

## Parameters

### `uDeviceID`

Identifier of the waveform-audio output device. It can be either a device identifier or a handle of an open waveform-audio output device.

### `pwoc`

Pointer to a [WAVEOUTCAPSW](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-waveoutcapsw) structure to be filled with information about the capabilities of the device.

### `cbwoc`

Size, in bytes, of the **WAVEOUTCAPSW** structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
|-------------|-------------|
| **MMSYSERR_BADDEVICEID** | Specified device identifier is out of range. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |

## Remarks

Use the **waveOutGetNumDevs** function to determine the number of waveform-audio output devices present in the system. If the value specified by the *uDeviceID* parameter is a device identifier, it can vary from zero to one less than the number of devices present. The WAVE_MAPPER constant can also be used as a device identifier. Only *cbwoc* bytes (or less) of information is copied to the location pointed to by *pwoc*. If *cbwoc* is zero, nothing is copied and the function returns zero.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)