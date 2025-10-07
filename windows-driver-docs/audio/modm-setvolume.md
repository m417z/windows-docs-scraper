# MODM\_SETVOLUME function

WINMM sends the `MODM_SETVOLUME` message to the [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) function of a MIDI output driver to set the volume for a MIDI device.

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential and have an initial value of zero and a final value that is equal to one less than the number of devices that the driver supports.

- *uMsg*
WINMM sets this parameter to **MODM\_SETVOLUME** when it calls **modMessage** to process this message.

- *dwUser*
Use this parameter to return instance data to the driver. Drivers that support multiple clients can use this instance data to track the client that is associated with the message.

- *dwParam1*
This parameter specifies the new volume level. The high-order word contains the right channel setting and the low-order word contains the left channel setting. A value of zero is silence, and a value of 0xFFFF is full volume. If the driver does not support both left and right channel volume changes, it uses the volume specified in the low-order word. The driver will typically not support the full 16 bits of volume control and must truncate the lower bits if necessary. However, the original volume level set with MODM\_SETVOLUME must be returned with [**MODM\_GETVOLUME**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-getvolume).

- *dwParam2*
Not used.

## Return value

The **modMessage** function returns MMSYSERR\_NOERROR if the operation was successful. Otherwise, it returns one of the error messages in the following table.

| Return code | Description |
| --- | --- |
| **MMSYSERR_NOTENABLED** | The driver failed to load or initialize. |
| **MMSYSERR_NOTSUPPORTED** | The driver does not support changes to volume level. |

## Remarks

This volume level is the final output volume; therefore, only drivers for internal synthesizer devices can support volume level changes. Drivers for MIDI output ports must return an MMSYSERR\_NOTSUPPORTED error for this message. Support for volume level changes is optional for internal synthesizer devices. When a driver receives a [**MODM\_GETDEVCAPS**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-getdevcaps) message, it must indicate support for volume level changes by setting or clearing the MIDICAPS\_VOLUME and MIDICAPS\_LRVOLUME bits in the **dwSupport** field of the [MIDIOUTCAPS](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midioutcaps) data structure. If a driver supports the **MODM\_SETVOLUME** message, it must also support **MODM\_GETVOLUME**.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available in Windows XP and later Windows operating systems. |
| Header | Mmddk.h (include Mmddk.h, Mmsystem.h, or Windows.h) |

## See also

[**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message)

[**MODM\_GETDEVCAPS**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-getdevcaps)

[MIDIOUTCAPS](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midioutcaps)