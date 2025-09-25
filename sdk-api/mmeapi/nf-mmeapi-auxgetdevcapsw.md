# auxGetDevCapsW function

## Description

The **auxGetDevCaps** function retrieves the capabilities of a given auxiliary output device.

## Parameters

### `uDeviceID`

Identifier of the auxiliary output device to be queried. Specify a valid device identifier (see the following comments section), or use the following constant:

| Value | Meaning |
| --- | --- |
| AUX_MAPPER | Auxiliary audio mapper. The function returns an error if no auxiliary audio mapper is installed. |

### `pac`

Pointer to an [AUXCAPS](https://learn.microsoft.com/previous-versions/dd756711(v=vs.85)) structure to be filled with information about the capabilities of the device.

### `cbac`

Size, in bytes, of the [AUXCAPS](https://learn.microsoft.com/previous-versions/dd756711(v=vs.85)) structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_BADDEVICEID** | Specified device identifier is out of range. |

## Remarks

The device identifier in *uDeviceID* varies from zero to one less than the number of devices present. AUX_MAPPER may also be used. Use the [auxGetNumDevs](https://learn.microsoft.com/previous-versions/dd756713(v=vs.85)) function to determine the number of auxiliary output devices present in the system.

> [!NOTE]
> The mmeapi.h header defines auxGetDevCaps as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)