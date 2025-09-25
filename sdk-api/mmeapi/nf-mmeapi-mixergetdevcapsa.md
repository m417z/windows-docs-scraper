# mixerGetDevCapsA function

## Description

The **mixerGetDevCaps** function queries a specified mixer device to determine its capabilities.

## Parameters

### `uMxId`

Identifier or handle of an open mixer device.

### `pmxcaps`

Pointer to a [MIXERCAPS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercapsa) structure that receives information about the capabilities of the device.

### `cbmxcaps`

Size, in bytes, of the [MIXERCAPS](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixercapsa) structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_BADDEVICEID** | The specified device identifier is out of range. |
| **MMSYSERR_INVALHANDLE** | The mixer device handle is invalid. |
| **MMSYSERR_INVALPARAM** | One or more parameters are invalid. |

## Remarks

Use the [mixerGetNumDevs](https://learn.microsoft.com/previous-versions/dd757304(v=vs.85)) function to determine the number of mixer devices present in the system. The device identifier specified by *uMxId* varies from zero to one less than the number of mixer devices present.

Only the number of bytes (or less) of information specified in *cbmxcaps* is copied to the location pointed to by *pmxcaps*. If *cbmxcaps* is zero, nothing is copied, and the function returns successfully.

This function also accepts a mixer device handle returned by the [mixerOpen](https://learn.microsoft.com/previous-versions/dd757308(v=vs.85)) function as the *uMxId* parameter. The application should cast the **HMIXER** handle to a **UINT**.

> [!NOTE]
> The mmeapi.h header defines mixerGetDevCaps as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Audio Mixer Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-functions)

[Audio Mixers](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixers)