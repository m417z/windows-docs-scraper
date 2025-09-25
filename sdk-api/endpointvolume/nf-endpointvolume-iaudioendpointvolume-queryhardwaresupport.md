# IAudioEndpointVolume::QueryHardwareSupport

## Description

The *QueryHardwareSupport* method queries the audio endpoint device for its hardware-supported functions.

## Parameters

### `pdwHardwareSupportMask` [out]

Pointer to a **DWORD** variable into which the method writes a hardware support mask that indicates the hardware capabilities of the audio endpoint device. The method can set the mask to 0 or to the bitwise-OR combination of one or more [ENDPOINT_HARDWARE_SUPPORT_XXX](https://learn.microsoft.com/windows/desktop/CoreAudio/endpoint-hardware-support-xxx-constants) constants.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pdwHardwareSupportMask* is **NULL**. |

## Remarks

This method indicates whether the audio endpoint device implements the following functions in hardware:

* Volume control
* Mute control
* Peak meter

The system automatically substitutes a software implementation for any function in the preceding list that the endpoint device does not implement in hardware.

## See also

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)