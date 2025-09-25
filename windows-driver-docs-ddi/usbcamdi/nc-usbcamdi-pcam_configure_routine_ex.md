# PCAM_CONFIGURE_ROUTINE_EX callback function

## Description

A camera minidriver's **CamConfigureEx** callback function configures the isochronous streaming interface.

## Parameters

### `BusDeviceObject`

Pointer to the camera minidriver's device object created by the USB hub.

### `DeviceContext`

Pointer to the camera minidriver's device context.

### `Interface`

Pointer to the [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) structure initialized with the proper values for a SELECT_INTERFACE URB request. This interface structure corresponds to a single isochronous interface on the device.

### `ConfigurationDescriptor`

Pointer to the [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor) for this device.

### `PipeConfigListSize`

Specifies the number of elements in the *PipeConfig* array.

### `PipeConfig`

Pointer to a [USBCAMD_Pipe_Config_Descriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_pipe_config_descriptor) array describing the association between pipes and streams.

### `DeviceDescriptor`

Pointer to the [USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor) for this device.

## Return value

**CamConfigureEx** returns STATUS_SUCCESS or an appropriate error code.

## Remarks

Camera minidrivers use **CamConfigureEx** to inform USBCAMD about the relationship between discovered pipes and streams.

USBCAMD calls the **CamConfigureEx** callback function to configure the isochronous streaming interface. After this function returns, USBCAMD can be notified of which interface and which alternate setting within the USB video streaming interface to use for the idle state.

USBCAMD requires that the camera must have a single USB configuration description, and all alternate settings within the USB video streaming interface must have the same number and type of pipes.

The original USBCAMD does not call **CamConfigureEx**.

This function is required.

## See also

[USBCAMD_DEVICE_DATA2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data2)

[USBCAMD_Pipe_Config_Descriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_pipe_config_descriptor)

[USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information)

[USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor)

[USB_DEVICE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_device_descriptor)