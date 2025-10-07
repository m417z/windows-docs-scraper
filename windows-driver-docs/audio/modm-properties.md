# MODM\_PROPERTIES function

WINMM sends the `MODM_PROPERTIES` message to the [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) function of a MIDI output driver to change the properties of the output stream.

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential and have with an initial value of zero and a final value that is equal to one less than the number of devices that the driver supports.

- *uMsg*
WINMM sets this parameter to **MODM\_PROPERTIES** when it calls **modMessage** to process this message.

- *dwUser*
Use this parameter to return instance data to the driver. Drivers that support multiple clients can use this instance data to track the client that is associated with the message.

- *dwParam1*
Contains a far pointer to a structure that contains information about the stream.

- *dwParam2*
Contains flags that specify the operation and property. The property flags are set in the lower 30 bits of the value. These property bits are combined with one of the flags in the following table, by using the logical OR operator.

| Flag | Meaning |
| --- | --- |
| MIDIPROP_SET | Tells the driver to set the specified property. |
| MIDIPROP_GET | Tells the driver to read (get) the specified property. |

## Return value

The **modMessage** function returns MMSYSERR\_NOERROR if the operation is successful. Otherwise, it returns one of the error messages in the following table.

| Return code | Description |
| --- | --- |
| **MMSYSERR_NOTENABLED** | The driver failed to load or initialize. |
| **MMSYSERR_INVALIDPARAM** | The specified property or property value is invalid. |

## Remarks

For more information about the properties of a MIDI data stream, see [midiStreamProperties](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-midistreamproperty). Also see [MIDIPROPTEMPO](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midiproptimediv).

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available in Windows XP and later Windows operating systems. |
| Header | Mmddk.h (include Mmddk.h, Mmsystem.h, or Windows.h) |

## See also

[**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message)

[midiStreamProperties](https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-midistreamproperty)

[MIDIPROPTIMEDIV](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midiproptimediv)

[MIDIPROPTEMPO](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-midiproptempo)