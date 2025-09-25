# auxSetVolume function

## Description

The **auxSetVolume** function sets the volume of the specified auxiliary output device.

## Parameters

### `uDeviceID`

Identifier of the auxiliary output device to be queried. Device identifiers are determined implicitly from the number of devices present in the system. Device identifier values range from zero to one less than the number of devices present. Use the [auxGetNumDevs](https://learn.microsoft.com/previous-versions/dd756713(v=vs.85)) function to determine the number of auxiliary devices in the system.

### `dwVolume`

Specifies the new volume setting. The low-order word specifies the left-channel volume setting, and the high-order word specifies the right-channel setting. A value of 0xFFFF represents full volume, and a value of 0x0000 is silence.

If a device does not support both left and right volume control, the low-order word of *dwVolume* specifies the volume level, and the high-order word is ignored.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_BADDEVICEID** | Specified device identifier is out of range. |

## Remarks

Not all devices support volume control. To determine whether the device supports volume control, use the AUXCAPS_VOLUME flag to test the **dwSupport** member of the [AUXCAPS](https://learn.microsoft.com/previous-versions/dd756711(v=vs.85)) structure (filled by the [auxGetDevCaps](https://learn.microsoft.com/previous-versions/dd756712(v=vs.85)) function).

To determine whether the device supports volume control on both the left and right channels, use the AUXCAPS_LRVOLUME flag to test the **dwSupport** member of the [AUXCAPS](https://learn.microsoft.com/previous-versions/dd756711(v=vs.85)) structure (filled by [auxGetDevCaps](https://learn.microsoft.com/previous-versions/dd756712(v=vs.85))).

Most devices do not support the full 16 bits of volume-level control and will use only the high-order bits of the requested volume setting. For example, for a device that supports 4 bits of volume control, requested volume level values of 0x4000, 0x4FFF, and 0x43BE will produce the same physical volume setting, 0x4000. The [auxGetVolume](https://learn.microsoft.com/previous-versions/dd756714(v=vs.85)) function will return the full 16-bit setting set with **auxSetVolume**.

Volume settings are interpreted logarithmically. This means the perceived volume increase is the same when increasing the volume level from 0x5000 to 0x6000 as it is from 0x4000 to 0x5000.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)