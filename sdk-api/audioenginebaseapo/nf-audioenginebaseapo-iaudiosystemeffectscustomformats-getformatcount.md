# IAudioSystemEffectsCustomFormats::GetFormatCount

## Description

The `GetFormatCount` method retrieves the number of custom formats supported by the system effects audio processing object (sAPO).

## Parameters

### `pcFormats` [out]

Specifies a pointer to an unsigned integer. The unsigned integer represents the number of formats supported by the sAPO.

## Return value

The `GetFormatCount` method returns S_OK when the call is successful. Otherwise, it returns E_POINTER to indicate that an invalid pointer was passed to the function.

## Remarks

For more information about sAPOs, see [System Effects Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/target-device-id).

## See also

[System Effects Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/system-effects-audio-processing-objects)