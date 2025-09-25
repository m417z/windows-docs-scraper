# PCAM_CONFIGURE_ROUTINE callback function

## Description

[CamConfigure is not supported and may be altered or unavailable in the future. Instead, use [CamConfigureEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_configure_routine_ex).
]

A camera minidriver's **CamConfigure** callback function configures the isochronous streaming interface.

## Parameters

### `BusDeviceObject`

Pointer to the camera minidriver's device object created by the USB hub.

### `DeviceContext`

Pointer to the camera minidriver's device context.

### `Interface`

Pointer to a [USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information) structure initialized with the proper values for a SELECT_INTERFACE URB request. This interface structure corresponds to a single isochronous interface on the device.

### `ConfigurationDescriptor`

Pointer to an initialized [USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor) for this device.

### `DataPipeIndex`

Pointer to a value that indicates the index of the data pipe. The camera minidriver should fill in this value before returning.

### `SyncPipeIndex`

Pointer to a value that indicates the index of the sync pipe, if one is needed. The camera minidriver should fill in this value before returning.

## Return value

**CamConfigure** returns STATUS_SUCCESS or an appropriate error code.

## Remarks

Camera minidrivers that must maintain backward compatibility with the original USBCAMD must use the [USBCAMD_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data) structure and its associated callback functions (that is, callback functions that do not contain the "Ex" suffix).

USBCAMD calls the camera minidriver's **CamConfigure** callback function to configure the isochronous streaming interface. After this function returns, USBCAMD can be notified of which interface and which alternate setting within the USB video streaming interface to use for the idle state.

This function is required.

## See also

[CamConfigureEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_configure_routine_ex)

[USBD_INTERFACE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_interface_information)

[USB_CONFIGURATION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_configuration_descriptor)