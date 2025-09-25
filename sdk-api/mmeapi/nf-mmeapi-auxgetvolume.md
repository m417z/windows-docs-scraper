# auxGetVolume function

## Description

The **auxGetVolume** function retrieves the current volume setting of the specified auxiliary output device.

## Parameters

### `uDeviceID`

Identifier of the auxiliary output device to be queried.

### `pdwVolume`

Pointer to a variable to be filled with the current volume setting. The low-order word of this location contains the left channel volume setting, and the high-order word contains the right channel setting. A value of 0xFFFF represents full volume, and a value of 0x0000 is silence.

If a device does not support both left and right volume control, the low-order word of the specified location contains the volume level.

The full 16-bit setting(s) set with the [auxSetVolume](https://learn.microsoft.com/previous-versions/dd756717(v=vs.85)) function are returned, regardless of whether the device supports the full 16 bits of volume-level control.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_BADDEVICEID** | Specified device identifier is out of range. |

## Remarks

Not all devices support volume control. To determine whether a device supports volume control, use the AUXCAPS_VOLUME flag to test the **dwSupport** member of the [AUXCAPS](https://learn.microsoft.com/previous-versions/dd756711(v=vs.85)) structure (filled by the [auxGetDevCaps](https://learn.microsoft.com/previous-versions/dd756712(v=vs.85)) function).

To determine whether a device supports volume control on both the left and right channels, use the AUXCAPS_LRVOLUME flag to test the **dwSupport** member of the [AUXCAPS](https://learn.microsoft.com/previous-versions/dd756711(v=vs.85)) structure (filled by [auxGetDevCaps](https://learn.microsoft.com/previous-versions/dd756712(v=vs.85))).

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)