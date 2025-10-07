# MOM\_OPEN function

WINMM sends the **MOM\_OPEN** message to the [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) function of a MIDI output driver.

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential and have an initial value of zero and a final value that is equal to one less than the number of devices that the driver supports.

- *uMsg*
WINMM sets this parameter to **MOM\_OPEN** when it calls [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) to process this message.

- *dwUser*
The driver sets this parameter to match the instance data from the client that called it.

- *dwParam1*
Not used.

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