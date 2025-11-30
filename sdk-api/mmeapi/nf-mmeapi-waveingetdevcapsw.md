## Description

The **waveInGetDevCapsW** function retrieves the capabilities of a given waveform-audio input device. This is the Unicode version of this function.

## Parameters

### `uDeviceID`

Identifier of the waveform-audio input device. It can be either a device identifier or a handle of an open waveform-audio input device.

### `pwic`

Pointer to a [WAVEINCAPSW](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-waveincapsw) structure to be filled with information about the capabilities of the device.

### `cbwic`

Size, in bytes, of the **WAVEINCAPSW** structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
|-------------|-------------|
| MMSYSERR_BADDEVICEID | Specified device identifier is out of range. |
| MMSYSERR_NODRIVER | No device driver is present. |
| MMSYSERR_NOMEM | Unable to allocate or lock memory. |

## Remarks

## See also