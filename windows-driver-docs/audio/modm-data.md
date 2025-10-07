# MODM\_DATA function

MMSYSTEM sends the `MODM_DATA` message to the [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) function of a MIDI output driver when the client wants to make a single MIDI event available as output.

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential and have an initial value of zero and a final value that is equal to one less than the number of devices that the driver supports.

- *uMSG*
WINMM sets this parameter to **MODM\_DATA** when it calls **modMessage** to process this message.

- *dwUser*
Use this parameter to return instance data to the driver. Drivers that support multiple clients can use this instance data to track the client that is associated with the message.

- *dwParam1*
Specifies the MIDI event that will be available at the output. The low-order byte is the first byte of the event.

- *dwParam2*
Not used.

## Return value

If the operation is successful, **modMessage** returns MMSYSERR\_NOERROR. Otherwise, it returns one of the error messages in the following table.

| Return code | Description |
| --- | --- |
| **MMSYSERR_NOTENABLED** | The driver failed to load or initialize. |
| **MIDIERR_NOTREADY** | The MIDI hardware is busy processing other data. |

## Remarks

This message is used to make all MIDI events available as output, except system-exclusive events. System-exclusive events are communicated with the [**MODM\_LONGDATA**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-longdata) message. MIDI events that are communicated with `MODM_DATA` can be one, two, or three bytes long. The driver must parse the event to determine how many bytes to transfer. Unused bytes are not guaranteed to be zero.

The driver developer can develop a driver to not return until the message has been sent to the output device. Alternatively, the driver can return immediately and the MIDI data can be output in the background.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available in Windows XP and later Windows operating systems. |
| Header | Mmddk.h (include Mmddk.h, Mmsystem.h, or Windows.h) |

## See also

[**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message)

[**MODM\_LONGDATA**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-longdata)