# joyGetDevCapsW function

## Description

The **joyGetDevCaps** function queries a joystick to determine its capabilities.

## Parameters

### `uJoyID`

Identifier of the joystick to be queried. Valid values for *uJoyID* range from -1 to 15. A value of -1 enables retrieval of the **szRegKey** member of the [JOYCAPS](https://learn.microsoft.com/previous-versions/dd757103(v=vs.85)) structure whether a device is present or not.

### `pjc`

Pointer to a [JOYCAPS](https://learn.microsoft.com/previous-versions/dd757103(v=vs.85)) structure to contain the capabilities of the joystick.

### `cbjc`

Size, in bytes, of the [JOYCAPS](https://learn.microsoft.com/previous-versions/dd757103(v=vs.85)) structure.

## Return value

Returns JOYERR_NOERROR if successful or one of the following error values:

| Return code | Description |
| --- | --- |
| **MMSYSERR_NODRIVER** | The joystick driver is not present, or the specified joystick identifier is invalid. The specified joystick identifier is invalid. |
| **MMSYSERR_INVALPARAM** | An invalid parameter was passed. |

## Remarks

Use the [joyGetNumDevs](https://learn.microsoft.com/previous-versions/dd757106(v=vs.85)) function to determine the number of joystick devices supported by the driver.

This method fails when passed an invalid value for the *cbjc* parameter.

> [!NOTE]
> The joystickapi.h header defines joyGetDevCaps as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Joysticks](https://learn.microsoft.com/windows/desktop/Multimedia/joysticks)

[Multimedia Joystick Functions](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-joystick-functions)