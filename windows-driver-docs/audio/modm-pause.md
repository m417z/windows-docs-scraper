# MODM\_PAUSE function

WINMM sends the `MODM_PAUSE` message to the [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) function of a MIDI output driver to temporarily pause output requests. Playback of streams stops but no buffers are marked as done.

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential and have an initial value of zero and a final value that is equal to one less than the number of devices that the driver supports.

- *uMsg*
WINMM sets this parameter to **MODM\_PAUSE** when it calls **modMessage** to process this message.

- *dwUser*
Use this parameter to return instance data to the driver. Drivers that support multiple clients can use this instance data to track the client that is associated with the message.

- *dwParam1*
Not used.

- *dwParam2*
Not used.

## Return value

The **modMessage** function returns MMSYSERR\_NOERROR if the operation was successful. Otherwise, it returns MMSYSERR\_NOTENABLED to indicate that the driver failed to load or initialize.

## Remarks

The driver must halt MIDI playback in the current position. The driver must then turn off all notes that are currently on.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available in Windows XP and later Windows operating systems. |
| Header | Mmddk.h (include Mmddk.h, Mmsystem.h, or Windows.h) |

## See also

[**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message)