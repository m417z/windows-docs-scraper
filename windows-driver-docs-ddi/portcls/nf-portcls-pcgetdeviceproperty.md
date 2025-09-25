# PcGetDeviceProperty function

## Description

The **PcGetDeviceProperty** function returns the requested device property from the registry.

## Parameters

### `DeviceObject` [in]

Pointer to the device object for the device. This parameter points to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) system structure but is cast to type PVOID.

### `DeviceProperty` [in]

A [DEVICE_REGISTRY_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-device_registry_property)-typed enumerator that identifies the device property to be retrieved.

### `BufferLength` [in]

Specifies the length in bytes of the buffer that is to receive the requested property data.

### `PropertyBuffer` [out]

Pointer to a caller-allocated buffer into which the method is to write the requested property data. The buffer must be large enough to contain the number of bytes specified in *BufferLength*.

### `ResultLength` [out]

Pointer to a caller-allocated variable into which the method outputs a count specifying the number of bytes actually written to the buffer. If the buffer size specified in *BufferLength* is too small to hold the property data, the method instead outputs the number of bytes required for the property data and returns STATUS_BUFFER_TOO_SMALL.

## Return value

**PcGetDeviceProperty** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code. The routine returns STATUS_BUFFER_TOO_SMALL if the buffer size specified in *BufferLength* was not large enough to contain the requested property data.

## Remarks

Two calls to **PcGetDeviceProperty** might be necessary to determine the required *BufferLength*. In the first call, *BufferLength* can either be zero or a best-guess estimate of the required buffer size. If the return status is STATUS_BUFFER_TOO_SMALL, this means that the caller should allocate a buffer of the size that was output through *ResultLength* and call **PcGetDeviceProperty** again.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IoGetDeviceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceproperty)