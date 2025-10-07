# MODM\_GETVOLUME function

WINMM sends the `MODM_GETVOLUME` message to the [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) function of a MIDI output driver to request the current volume level setting for a MIDI device.

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential and have an initial value of zero and a final value that is equal to one less than the number of devices that the driver supports.

- *uMsg*
WINMM sets this parameter to **MODM\_GETVOLUME** when it calls **modMessage** to process this message.

- *dwUser*
Use this parameter to return instance data to the driver. Drivers that support multiple clients can use this instance data to track the client that is associated with the message.

- *dwParam1*
This parameter specifies a far pointer to a **DWORD** location. The driver fills this location with the current volume level setting. The high-order word contains the right channel setting and the low-order word contains the left channel setting. A value of zero is silence, and a value of 0xFFFF is full volume. If the driver does not support both left and right channel volume changes, it returns the volume level setting in the low-order word.

- *dwParam2*
Not used.

## Return value

The **modMessage** message returns MMSYSERR\_NOERROR, if the operation is successful. Otherwise, it returns one of the error messages in the following table.

| Return code | Description |
| --- | --- |
| **MMSYSERR_NOTENABLED** | The driver failed to load or initialize. |
| **MMSYSERR_NOTSUPPORTED** | The driver does not support changes to volume level settings. |

## Remarks

Only drivers for internal synthesizer devices can support volume level changes. Drivers for MIDI output ports should return an MMSYSERR\_NOTSUPPORTED error for this message. Support for volume level changes by internal synthesizer devices is optional. However, if a driver supports changes to the volume level with the [**MODM\_SETVOLUME**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-setvolume) message, it must support queries with the `MODM_GETVOLUME` message.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available in Windows XP and later Windows operating systems. |
| Header | Mmddk.h (include Mmddk.h, Mmsystem.h, or Windows.h) |

## See also

[**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message)

[**MODM\_SETVOLUME**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-setvolume)