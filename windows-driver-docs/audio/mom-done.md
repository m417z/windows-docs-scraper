# MOM\_DONE function

WINMM sends the **MOM\_DONE** message to the [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) function of MIDI output driver, to return a system-exclusive data block to the client application.

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential that has an initial value of zero and a final value that is equal to one less than the number of devices that the driver supports.

- *uMsg*
WINMM sets this parameter to **MOM\_DONE** when it calls [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) to process this message.

- *dwUser*
The driver sets this parameter to match the instance data from the client that called it.

- *dwParam1*
Specifies a far pointer to a [MIDIHDR](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midihdr) structure that identifies the data block.

- *dwParam2*
Not used.

## Return value

None

## Remarks

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available in Windows XP and later Windows operating systems. |
| Header | Mmddk.h (include Mmddk.h, Mmsystem.h, or Windows.h) |

## See also

[MIDIHDR](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midihdr)