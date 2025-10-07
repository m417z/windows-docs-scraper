# DRV\_QUERYMAPPABLE function

The DRV\_QUERYMAPPABLE message queries for whether the specified device can be used by a mapper.

## Parameters

- *uDeviceID*
Specifies the ID of the target device.

- *uMsg*
Caller sets this parameter to DRV\_QUERYMAPPABLE when it calls **xxxMessage** to process this device message.

- *dwParam1*
Unused. Set this parameter to zero.

- *dwParam2*
Unused. Set this parameter to zero.

## Return value

The **xxxMessage** function returns MMSYSERR\_NOERROR if the device is mappable. Otherwise, it returns an appropriate error code.

## Remarks

This message is valid only for the [**waveInMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveinmessage), [**waveOutMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveoutmessage), [**midiInMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-midiinmessage), [**midiOutMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-midioutmessage), [**mixerMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-mixermessage) and [**auxOutMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-auxoutmessage) functions. The system intercepts this message and returns the appropriate value without sending the message to the device driver. For general information about system-intercepted **xxxMessage** functions, see [System-Intercepted Device Messages](https://learn.microsoft.com/windows-hardware/drivers/audio/system-intercepted-device-messages).

When an application program opens a mapper instead of a specific audio device, the system inserts a mapper between the application and the available devices. The mapper selects an appropriate device by mapping the application's requirements to one of the available devices. For more information about mappers, see the Microsoft Windows SDK documentation.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Supported in Microsoft Windows Me/98 and Windows 2000 and later operating systems. |
| Header | Mmddk.h (include Mmddk.h) |

## See also

[**auxOutMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-auxoutmessage)

[**midiInMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-midiinmessage)

[**midiOutMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-midioutmessage)

[**mixerMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-mixermessage)

[System-Intercepted Device Messages](https://learn.microsoft.com/windows-hardware/drivers/audio/system-intercepted-device-messages)

[**waveInMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveinmessage)

[**waveOutMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveoutmessage)