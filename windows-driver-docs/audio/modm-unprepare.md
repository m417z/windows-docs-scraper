# MODM\_UNPREPARE function

WINMM sends the `MODM_UNPREPARE` message to the [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) function of a MIDI output driver to clean up the memory segment that was configured by [**MODM\_PREPARE**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-prepare).

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential and have an initial value of zero and a final value that is equal to one less than the number of devices that the driver supports.

- *uMsg*
WINMM sets this parameter to **MODM\_UNPREPAE** when it calls **modMessage** to process this message.

- *dwUser*
Use this parameter to return instance data to the driver. Drivers that support multiple clients can use this instance data to track the client that is associated with the message.

- *dwParam1*
Specifies a far pointer to a [MIDIHDR](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midihdr) structure that identifies the data block.

- *dwParam2*
Specifies the size of the **MIDIHDR** structure.

## Return value

The **modMEssage** function returns MMSYSERR\_NOERROR if the operation is successful. Otherwise, it returns MMSYSERR\_NOTENABLED to indicate that the driver failed to load or initialize.

## Remarks

Driver support for this message is optional. If a driver supports the [**MODM\_PREPARE**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-prepare) message, it must also support `MODM_UNPREPARE`.

The default response for this message is to return MMSYSERR\_NOTSUPPORTED. In this case, Mmsystem.dll cleans up the preparation that was previously done on the memory block. If a driver performs the PREPARE operation, it must clean up the preparation and reset the MHDR\_PREPARED flag in the **dwFlags** field of the **MIDIHDR** structure.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available in Windows XP and later Windows operating systems. |
| Header | Mmddk.h (include Mmddk.h, Mmsystem.h, or Windows.h) |

## See also

[**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message)

[**MODM\_PREPARE**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-prepare)

[MIDIHDR](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midihdr)