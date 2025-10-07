# DRV\_QUERYDEVNODE function

The DRV\_QUERYDEVNODE message queries for the [*devnode*](https://learn.microsoft.com/windows-hardware/drivers/debuggercmds/-devnode) number assigned to the device by the Plug and Play manager.

## Parameters

- *uDeviceID*
Specifies the ID of the target device.

- *uMsg*
Caller sets this parameter to DRV\_QUERYDEVNODE when it calls **xxxMessage** to process this device message.

- *dwParam1*
Pointer to a caller-allocated DWORD variable into which the function writes the devnode number. If no devnode is assigned to the device, the function sets this variable to zero.

- *dwParam2*
Unused. Set this parameter to zero.

## Return value

The **xxxMessage** function returns MMSYSERR\_NOERROR if the message is handled successfully. Otherwise, it returns an appropriate error code.

## Remarks

In Windows 2000 and later, the message always returns MMSYSERR\_NOTSUPPORTED. This message is valid only for the [**waveInMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveinmessage), [**waveOutMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveoutmessage), [**midiInMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-midiinmessage), [**midiOutMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-midioutmessage), and [**mixerMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-mixermessage) functions. The system intercepts this message and returns the appropriate value without sending the message to the device driver. For general information about system-intercepted **xxxMessage** functions, see [System-Intercepted Device Messages](https://learn.microsoft.com/windows-hardware/drivers/audio/system-intercepted-device-messages).

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Supported in Microsoft Windows Me/98 and not supported Windows 2000 and later operating systems. |
| Header | Mmddk.h (include Mmddk.h) |

## See also

[**midiInMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-midiinmessage)

[**midiOutMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-midioutmessage)

[**mixerMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-mixermessage)

[System-Intercepted Device Messages](https://learn.microsoft.com/windows-hardware/drivers/audio/system-intercepted-device-messages)

[**waveInMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveinmessage)

[**waveOutMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveoutmessage)