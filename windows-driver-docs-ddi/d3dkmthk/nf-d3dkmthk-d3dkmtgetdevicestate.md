# D3DKMTGetDeviceState function

## Description

The **D3DKMTGetDeviceState** function retrieves the state of a device.

## Parameters

### `unnamedParam1` [in/out]

*pData* [in, out]

A pointer to a [D3DKMT_GETDEVICESTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getdevicestate) structure that describes parameters for retrieving the state of a device.

## Return value

**D3DKMTGetDeviceState** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The state of the device was successfully retrieved.|
|STATUS_DEVICE_REMOVED|The graphics adapter was stopped or the display device was reset.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_GETDEVICESTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getdevicestate)