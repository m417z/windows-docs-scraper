# MODM\_GETPOS function

WINMM sends the `MODM_GETPOS` message to the [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) function of a MIDI output driver to request the current position of the stream pointer in the data stream.

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential and have an initial value of zero and a final value that is equal to one less than the number of devices that the driver supports.

- *uMsg*
WINMM sets this parameter to **MODM\_GETPOS** when it calls **modMessage** to process this message.

- *dwUser*
Use this parameter to return instance data to the driver. Drivers that support multiple clients can use this instance data to track the client that is associated with the message.

- *dwParam1*
Specifies a far pointer to an [MMTIME](https://learn.microsoft.com/previous-versions//dd757347(v=vs.85)) structure.

- *dwParam2*
Specifies the size, in bytes, of the **MMTIME** structure.

## Return value

The **modMessage** function returns MMSYSERR\_NOERROR if the operation is successful. Otherwise, it returns MMSYSERR\_NOTENABLED to indicate that the driver failed to load or initialize.

## Remarks

The driver should return the position in the time format specified in the **wType** member of **MMTIME**. If the time format specified in **wType** is not supported, the driver must change **wType** to the default time format and return the position in that format.

Time is measured relative to the start of the first buffer that was sent while the driver was in the last stopped state. The stopped state is entered whenever a [**MODM\_OPEN**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-open), [**MODM\_RESET**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-reset), or [**MODM\_STOP**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-stop) message is received. Time spent between a [**MODM\_PAUSE**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-pause) and the matching [**MODM\_RESTART**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-restart) is not counted, but the clock should not be reset. Likewise, the time during which the driver is starved for data must not be counted; the returned time must be as if the stream played perfectly with no interruptions or pauses.

If the device is paused or starved, the time returned must be the time of the last event played.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available in Windows XP and later Windows operating systems. |
| Header | Mmddk.h (include Mmddk.h, Mmsystem.h, or Windows.h) |

## See also

[**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message)

[MMTIME](https://learn.microsoft.com/previous-versions//dd757347(v=vs.85))

[**MODM\_OPEN**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-open)

[**MODM\_RESET**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-reset)

[**MODM\_STOP**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-stop)

[**MODM\_PAUSE**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-pause)

[**MODM\_RESTART**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-restart)