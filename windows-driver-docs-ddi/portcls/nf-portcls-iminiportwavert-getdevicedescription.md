# IMiniportWaveRT::GetDeviceDescription

## Description

The `GetDeviceDescription` method returns a pointer to a [DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description) structure describing the device.

## Parameters

### `DeviceDescription` [out]

Pointer to a DEVICE_DESCRIPTION structure to be filled in by the miniport. The caller specifies a valid, non-NULL pointer value for this parameter.

## Return value

`GetDeviceDescription` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error status code.

## Remarks

The *DeviceDescription* parameter contains a pointer to a DEVICE_DESCRIPTION structure that the miniport fills in to describe the device

## See also

[DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description)

[IMiniportWaveRT](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavert)

[IPortWaveRT](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavert)