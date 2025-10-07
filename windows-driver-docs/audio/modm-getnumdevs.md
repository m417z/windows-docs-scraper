# MODM\_GETNUMDEVS function

WINMM sends the `MODM_GETNUMDEVS` message to the [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) function of a MIDI output driver to request the number of MIDI output devices available.

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential and have an initial value of zero and a final value that is equal to one less than the number of devices that the driver supports.

- *uMsg*
WINMM sets this parameter to **MODM\_GETNUMDEVS** when it calls **modMessage** to process this message.

- *dwUser*
Use this parameter to return instance data to the driver. Drivers that support multiple clients can use this instance data to keep track of the client that is associated with the message.

- *dwParam1*
Not used.

- *dwParam2*
Not used.

## Return value

The **modMessage** function returns the number of MIDI output devices that the driver supports.

## Remarks

Drivers can be structured in several ways. The simplest and most common drivers use one physical device to support one logical device. Drivers can also support multiple logical devices by using a single physical device. For example, a driver can use a single digital signal processor (DSP) to support two different types of internal synthesizers. Such a driver would return a value of "2" in response to the `MODM_GETNUMDEVS` message.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available in Windows XP and later Windows operating systems. |
| Header | Mmddk.h (include Mmddk.h, Mmsystem.h, or Windows.h) |

## See also

[**ModMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message)