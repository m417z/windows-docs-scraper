# modMessage function

The **modMessage** function is the entry-point function for musical instrument digital interface (MIDI) output drivers and for internal synthesizer drivers. For more information about audio device messages related to MIDI, see [Audio Device Messages for MIDI](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-device-messages-for-midi)

## Parameters

- *uDeviceID*
Specifies the ID of the target device. Device IDs are sequential and have an initial value of zero and a final value equal to one less than the number of devices the driver supports.

- *uMsg*
Specifies the message that WINMM sends to the driver in response to a call from the client application.

- *dwUser*
For the [**MODM\_OPEN**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-open) message, the driver should fill this location with its instance data. For any other messages, the instance data is returned to the driver. Drivers that support multiple clients can use this instance data to track which client is associated with the message.

- *dwParam1*
Specifies a message-dependent parameter.

- *dwParam2*
Specifies a message-dependent parameter. If there are flags that provide additional information to the driver that works with **modMessage**, WINMM uses this parameter to pass the flags.

## Return value

The **modMessage** function returns MMSYSERR\_NOERROR if it can successfully process the message it received from MMSYSTEM. Otherwise, it returns one of the following error messages.

| Return code | Description |
| --- | --- |
| **MMSYSERR_ERROR** | Unspecified error. |
| **MMSYSERR_BADDEVICEID** | The specified device ID is out of range. |
| **MMSYSERR_NOTENABLED** | The driver failed to load or initialize. |
| **MMSYSERR_ALLOCATED** | The specified device is already allocated. |
| **MMSYSERR_INVALHANDLE** | The handle of the specified device is invalid. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Memory allocation error. |
| **MMSYSERR_NOTSUPPORTED** | The function requested by the message is not supported. |
| **MMSYSERR_BADERRNUM** | Error value is out of range. See Remarks section for more details. |
| **MMSYSERR_INVALFLAG** | An invalid flag was passed to **modMessage** (by using *dwParam2*). |
| **MMSYSERR_INVALPARAM** | An invalid parameter was passed to **modMessage**. |
| **MMSYSERR_HANDLEBUSY** | The specified handle is being used simultaneously by another thread (for example, a callback thread). |
| **MMSYSERR_INVALIDALIAS** | The specified alias was not found. |
| **MMSYSERR_BADDB** | Bad registry database. |
| **MMSYSERR_KEYNOTFOUND** | The specified registry key was not found. |
| **MMSYSERR_READERROR** | Registry read error. |
| **MMSYSERR_WRITEERROR** | Registry write error. |
| **MMSYSERR_DELETEERROR** | Registry delete error. |
| **MMSYSERR_VALNOTFOUND** | The specified registry value was not found. |
| **MMSYSERR_NODRIVERCB** | The driver that works with **modMessage** does not call [DriverCallback](https://learn.microsoft.com/windows/win32/api/mmiscapi/nf-mmiscapi-drivercallback). |
| **MMSYSERR_MOREDATA** | **modMessage** has more data to return. |
| **MMSYSERR_LASTERROR** | Indicates that this is the last error in the range of error values. See the Remarks section for more details. |

## Remarks

Audio device messages are system-defined constants. So when **modMessage** receives an audio device message, it uses a switch statement to determine the action to perform, based on the value of the message.

The range of error messages that **modMessage** can return depends on the message that it was processing when the error occurred. The numerical values of the MMSYSERR\_ error messages start with zero (for MMSYSERR\_NOERROR) and continue with MMSYSERR\_BASE + *n*, where *n* is an integer from 1 to 21. The value for MMSYSERR\_BASE is a defined constant. For more information about MSYSERR\_BASE and the MMSYSERR\_ error messages, see Mmsystem.h in the Windows SDK and Mmddk.h in the WDK respectively.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Version | Available with Windows XP and later Windows operating systems. |
| Header | Mmddk.h (include Mmddk.h, Mmsystem.h, or Windows.h) |

## See also

[**MODM\_OPEN**](https://learn.microsoft.com/windows-hardware/drivers/audio/modm-open)