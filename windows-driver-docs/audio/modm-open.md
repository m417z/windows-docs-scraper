# MODM\_OPEN function

WINMM sends the `MODM_OPEN` message to the [**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message) function of a MIDI output driver to allocate a specified device that a client application can use.

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential and have an initial value of zero and a final value equal that is to one less than the number of devices that the driver supports.

- *uMsg*
WINMM sets this parameter to **MODM\_OPEN** when it calls **modMessage** to process this message.

- *dwUser*
The MIDI output driver must fill this location with its instance data, but only in response to the `MODM_OPEN`.

- *dwParam1*
This parameter specifies a far pointer to a [**MIDIOPENDESC**](https://learn.microsoft.com/windows/win32/api/mmddk/ns-mmddk-midiopendesc) structure. This structure contains additional information for the driver such as instance data from the client and a callback function for the client.

- *dwParam2*
This parameter specifies option flags that determine how the device is opened. The flags can be any of the values in the following table.

| Flag | Meaning |
| --- | --- |
| CALLBACK_EVENT | If this flag is specified, **dwCallback** in the **MIDIOPENDESC** structure is assumed to be an event handle. |
| CALLBACK_FUNCTION | If this flag is specified, **dwCallback** in the **MIDIOPENDESC** structure is assumed to be the address of a callback function. |
| CALLBACK_THREAD | If this flag is specified, **dwCallback** in the **MIDIOPENDESC** structure is assumed to be a handle to a thread. |
| CALLBACK_WINDOW | If this flag is specified, **dwCallback** in the **MIDIOPENDESC** structure is assumed to be a window handle. |
| MIDI_IO_COOKED | If this flag is specified, the device is opened in stream mode and the driver receives stream messages. The driver must be able to handle any contingencies that arise. For example, the driver must be able to play short messages and system-exclusive messages asynchronously to the stream. |

## Return value

The **modMessage** function returns MMSYSERR\_NOERROR if the operation is successful. Otherwise it returns one of the error messages in the following table.

| Return code | Description |
| --- | --- |
| **MMSYSERR_NOTENABLED** | The driver failed to load or initialize. |
| **MMSYSERR_ALLOCATED** | The MIDI device is already allocated by the maximum number of clients that the driver supports or the device cannot be opened because of system resource limitations other than memory. |
| **MMSYSERR_NOMEM** | The device cannot be opened because of a failure to allocate or lock memory. |

## Remarks

The driver must be able to determine the number of clients it can allow to use a particular device. After a device is opened for the maximum number of clients that the driver supports, the driver returns MMSYSERR\_ALLOCATED for any additional requests to open the device. If the open operation is successful, the driver uses the [DriverCallback](https://learn.microsoft.com/windows/win32/api/mmiscapi/nf-mmiscapi-drivercallback) function to send the client a [**MOM\_OPEN**](https://learn.microsoft.com/windows-hardware/drivers/audio/mom-open) message.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available in Windows XP and later Windows operating systems. |
| Header | Mmddk.h (include Mmddk.h, Mmsystem.h, or Windows.h) |

## See also

[**modMessage**](https://learn.microsoft.com/windows-hardware/drivers/audio/mod-message)

[**MIDIOPENDESC**](https://learn.microsoft.com/windows/win32/api/mmddk/ns-mmddk-midiopendesc)

[DriverCallback](https://learn.microsoft.com/windows/win32/api/mmiscapi/nf-mmiscapi-drivercallback)

[**MOM\_OPEN**](https://learn.microsoft.com/windows-hardware/drivers/audio/mom-open)