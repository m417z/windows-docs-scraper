# MODM\_GETDEVCAPS function

WINMM sends the `MODM_GETDEVCAPS` message to the [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) function of a MIDI output driver to retrieve information about the capabilities of a specific MIDI output device.

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential and have an initial value of zero and a final value that is equal to one less than the number of devices that the driver supports.

- *uMsg*
WINMM sets this parameter to **MODM\_GETDEVCAPS** when it calls **modMessage** to process this message.

- *dwUser*
Use this parameter to return instance data to the driver. Drivers that support multiple clients can use this instance data to track the client that is associated with the message.

- *dwParam1*
For Plug and Play (PnP) drivers, this parameter specifies a pointer to an [**MDEVICECAPSEX**](https://learn.microsoft.com/windows/win32/api/mmddk/ns-mmddk-mdevicecapsex) structure. The driver fills this structure with the capabilities of the device.

 For drivers that are not Plug and Play, this parameter specifies a far pointer to a [MIDIOUTCAPS](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midioutcaps) data structure. The driver fills this structure with the capabilities of the device.

- *dwParam2*
For Plug and Play drivers, this parameter specifies a device node. For drivers that are not Plug and Play, this parameter specifies the size of the **MIDIOUTCAPS** structure in bytes.

## Return value

If the operation is successful, **modMessage** returns MMSYSERR\_NOERROR. Otherwise, it returns MMSYSERR\_NOTENABLED to indicate that the driver failed to load or initialize.

## Remarks

For drivers that are not Plug and Play, the driver must only write *dwParam2* or less bytes to the location pointed to by *dwParam1*.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available in Windows XP and later Windows operating systems. |
| Header | Mmddk.h (include Mmddk.h, Mmsystem.h, or Windows.h) |

## See also

[**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message)

[**MDEVICECAPSEX**](https://learn.microsoft.com/windows/win32/api/mmddk/ns-mmddk-mdevicecapsex)

[MIDIOUTCAPS](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midioutcaps)