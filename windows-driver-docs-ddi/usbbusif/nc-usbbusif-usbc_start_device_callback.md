# USBC_START_DEVICE_CALLBACK callback function

## Description

The **USBC_START_DEVICE_CALLBACK** routine allows a USB client driver to provide a custom definition of the interface collections on a device.

## Parameters

### `DeviceDescriptor` [in]

The device descriptor of the device.

### `ConfigurationDescriptor` [in]

The configuration of the device.

### `FunctionDescriptorBuffer` [out]

Pointer to a buffer that contains an array of function descriptors ([USBC_FUNCTION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usbc_function_descriptor)).

### `FunctionDescriptorBufferLength` [out]

The length in bytes of the buffer that *FunctionDescriptorBuffer* points to.

### `FdoDeviceObject` [in]

The function device object for the device.

### `PdoDeviceObject` [in]

The physical device object for the device.

## Return value

If the operation succeeds, the vendor-supplied callback routine must return STATUS_SUCCESS.

## Remarks

For a general description of the callback routine mechanism, see [Customizing Enumeration of Interface Collections for Composite Devices](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

## See also

[USBC_DEVICE_CONFIGURATION_INTERFACE_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usbc_device_configuration_interface_v1)