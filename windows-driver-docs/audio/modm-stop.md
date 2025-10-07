# MODM\_STOP function

WINMM sends the `MODM_STOP` message to the [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) function of a MIDI output driver to stop output from the output queue and to turn off any notes that are playing.

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential and have an initial value of zero and a final value that is equal to one less than the number of devices that the driver supports.

- *uMsg*
WINMM sets this parameter to **MODM\_STOP** when it calls **modMessage** to process this message.

- *dwUser*
Use this parameter to return instance data to the driver. Drivers that support multiple clients can use this instance data to track the client that is associated with the message.

- *dwParam1*
Not used.

- *dwParam2*
Not used.

## Return value

The **modMessage** function returns MMSYSERR\_NOERROR if the operation is successful. Otherwise it returns MMSYSERR\_NOTENABLED to indicate that the driver failed to load or initialize.

## Remarks

If the output queue of the MIDI output driver is not empty, it must stop all pending data blocks and mark them as done by setting the MHDR\_DONE bit in the **dwFlags** field of the [MIDIHDR](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midihdr) structure for each block. The driver must then notify the client by using [DriverCallback](https://learn.microsoft.com/windows/win32/api/mmiscapi/nf-mmiscapi-drivercallback) to send a [**MOM\_DONE**](https://learn.microsoft.com/windows-hardware/drivers/audio/mom-done) message for each data block.

The driver should send a note-off event for all notes that are currently turned on. In addition, the driver should send a damper pedal off event (controller 0x40) for each channel. If the device is an internal synthesizer, the driver should turn off any notes that are playing.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available in Windows XP and later Windows operating systems. |
| Header | Mmddk.h (include Mmddk.h, Mmsystem.h, or Windows.h) |

## See also

[**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message)

[DriverCallback](https://learn.microsoft.com/windows/win32/api/mmiscapi/nf-mmiscapi-drivercallback)

[MIDIHDR](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midihdr)

[**MOM\_DONE**](https://learn.microsoft.com/windows-hardware/drivers/audio/mom-done)