# MODM\_PREPARE function

WINMM sends the `MODM_PREPARE` message to the [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) function of a MIDI output driver to request that the driver configure a system-exclusive data block for output. If data blocks are accessed at interrupt time, they must be page-locked to ensure that the memory is not swapped out to disk.

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential and have an initial value of zero and a final value that is equal to one less than the number of devices that the driver supports.

- *uMsg*
WINMM sets this parameter to **MODM\_PREPARE** when it calls **modMessage** to process this message.

- *dwUser*
Use this parameter to return instance data to the driver. Drivers that support multiple clients can use this instance data to track the client that is associated with the message.

- *dwParam1*
Specifies a far pointer to the [MIDIHDR](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midihdr) structure that identifies the data block.

- *dwParam2*
Specifies the size of the **MIDIHDR** structure.

## Return value

The **modMessage** function returns MMSYSERR\_NOERROR if the operation is successful. Otherwise, it returns one of the error messages in the following table.

| Return code | Description |
| --- | --- |
| **MMSYSERR_NOTENABLED** | The driver failed to load or initialize. |
| **MMSYSERR_NOTSUPPORTED** | The driver does not support this message. |

## Remarks

Driver support for this message is optional. If a driver supports this message, it must also support [**MODM\_UNPREPARE**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-unprepare).

The default response for this message is to return MMSYSERR\_NOTSUPPORTED. In this case, WINMM converts the memory segment to page-locked memory for the driver. If a driver has to perform other operations so that it can prepare a data block for output, it must set the MHDR\_PREPARED bit in the **dwFlags** field of the **MIDIHDR** structure and return MMSYSERR\_NOERROR. In this case, WINMM assumes the driver has prepared the data block and does not page-lock the memory.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available in Windows XP and later Windows operating systems. |
| Header | Mmddk.h (include Mmddk.h, Mmsystem.h, or Windows.h) |

## See also

[**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message)

[MIDIHDR](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midihdr)

[**MODM\_UNPREPARE**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-unprepare)