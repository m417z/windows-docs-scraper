# DRV\_QUERYDEVICEINTERFACESIZE function

The DRV\_QUERYDEVICEINTERFACESIZE message queries for the size of the buffer required to hold the device-interface name.

## Parameters

- *uDeviceID*
Specifies the ID of the target device.

- *uMsg*
Caller sets this parameter to DRV\_QUERYDEVICEINTERFACESIZE when it calls **xxxMessage** to process this device message.

- *dwParam1*
Pointer to buffer size. This parameter points to a ULONG variable into which the function writes the required buffer size in bytes. The size includes storage space for the name string's terminating null. The size is zero if the device ID identifies a device that has no device interface.

- *dwParam2*
Unused. Set this parameter to zero.

## Return value

The **xxxMessage** function returns MMSYSERR\_NOERROR if the message is handled successfully. Otherwise, it returns an appropriate error code.

## Remarks

This message is valid only for the [**waveInMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveinmessage), [**waveOutMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveoutmessage), [**midiInMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-midiinmessage), [**midiOutMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-midioutmessage), and [**mixerMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-mixermessage) functions. The system intercepts this message and returns the appropriate value without sending the message to the device driver. For general information about system-intercepted **xxxMessage** functions, see [System-Intercepted Device Messages](https://learn.microsoft.com/windows-hardware/drivers/audio/system-intercepted-device-messages).

The buffer size retrieved by this message is expressed as a byte count. It specifies the size of the buffer needed to hold the null-terminated Unicode string that contains the device-interface name. The caller allocates a buffer of the specified size and uses the [**DRV\_QUERYDEVICEINTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/audio/drv-querydeviceinterface) message to retrieve the device-interface name string.

For more information, see [Obtaining a Device Interface Name](https://learn.microsoft.com/windows-hardware/drivers/audio/obtaining-a-device-interface-name).

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Supported in Microsoft Windows Me and Windows 2000 and later operating systems. |
| Header | Mmddk.h (include Mmddk.h) |

## See also

[**DRV\_QUERYDEVICEINTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/audio/drv-querydeviceinterface)

[**midiInMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-midiinmessage)

[**midiOutMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-midioutmessage)

[**mixerMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-mixermessage)

[Obtaining a Device Interface Name](https://learn.microsoft.com/windows-hardware/drivers/audio/obtaining-a-device-interface-name)

[System-Intercepted Device Messages](https://learn.microsoft.com/windows-hardware/drivers/audio/system-intercepted-device-messages)

[**waveInMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveinmessage)

[**waveOutMessage**](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveoutmessage)