# IOCTL_USB_USER_REQUEST IOCTL

## Description

The **IOCTL_USB_USER_REQUEST** I/O control request is available to both user-mode applications and kernel-mode drivers.

**IOCTL_USB_USER_REQUEST** is a user-mode I/O control request. This request targets the USB host controller (GUID_DEVINTERFACE_USB_HOST_CONTROLLER).

Callers can specify any of the following request codes:

USBUSER_CLEAR_ROOTPORT_FEATURE

Do not use this request.

USBUSER_GET_CONTROLLER_DRIVER_KEY

Reports the host controller driver key in a [USB_UNICODE_NAME](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_unicode_name)-typed Unicode string. This request is always enabled.

USBUSER_GET_CONTROLLER_INFO_0

Retrieves a [USB_CONTROLLER_INFO_0](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_controller_info_0) structure that describes the host controller. This request is always enabled.

USBUSER_GET_ROOTPORT_STATUS

Do not use this request.

USBUSER_GET_ROOTHUB_SYMBOLIC_NAME

Reports the root hub symbolic name in a [USB_UNICODE_NAME](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_unicode_name)-typed Unicode string. This request is always enabled.

USBUSER_INVALID_REQUEST

Do not use this request.

USBUSER_OP_CLOSE_RAW_DEVICE

Do not use this request.

USBUSER_OP_OPEN_RAW_DEVICE

Do not use this request.

USBUSER_OP_MASK_DEVONLY_API

Do not use this request.

USBUSER_OP_MASK_HCTEST_API

Do not use this request.

USBUSER_OP_RAW_RESET_PORT

Do not use this request.

USBUSER_OP_SEND_ONE_PACKET

Do not use this request.

USBUSER_OP_SEND_RAW_COMMAND

Do not use this request.

USBUSER_SET_ROOTPORT_FEATURE

Do not use this request.

USBUSER_PASS_THRU

Sends a vendor specific command that is defined by the [USB_PASS_THRU_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_pass_thru_parameters) structure to the host controller miniport driver. This request is always enabled.

USBUSER_GET_BANDWIDTH_INFORMATION

Retrieves a [USB_BANDWIDTH_INFO](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_bandwidth_info) structure that contains information about the allocated bandwidth. This request is always enabled.

USBUSER_GET_POWER_STATE_MAP

Retrieves a [USB_POWER_INFO](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_power_info) structure that contains information about the power state of the host controller and root hubs. This request is always enabled.

USBUSER_GET_BUS_STATISTICS_0

Retrieves a [USB_BUS_STATISTICS_0](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_bus_statistics_0) structure that contains bus statistics. This request is always enabled.

USBUSER_GET_BUS_STATISTICS_0_AND_RESET

Do not use this request.

USBUSER_GET_USB_DRIVER_INFORMATION

Retrieves a [USB_DRIVER_VERSION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_driver_version_parameters) structure that indicates the version of the driver, USB stack, and associated interfaces. This request is always enabled.

USBUSER_GET_USB2_HW_VERSION

Do not use this request.

## Parameters

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a user request header structure ([USBUSER_REQUEST_HEADER](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usbuser_request_header)) that defines the request. Following the header structure is a structure that holds the parameters of the request. For more information about the parameter structures that correspond to each request, see the description of each request.

### Input buffer length

The size of a [USBUSER_REQUEST_HEADER](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usbuser_request_header) structure.

### Output buffer

A parameter structure immediately follows the [USBUSER_REQUEST_HEADER](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usbuser_request_header) structure at **Irp->AssociatedIrp.SystemBuffer**. For some user requests, the parameter structure will contain output data when the request completes.

### Output buffer length

The length of the parameter structure.

### Input/output buffer

### Input/output buffer length

### Status block

The USB stack sets **Irp->IoStatus.Status** to STATUS_SUCCESS if the request is successful. Otherwise, the USB stack sets **Status** to the appropriate error condition, such as STATUS_INVALID_PARAMETER or STATUS_INSUFFICIENT_RESOURCES.

## See also

[USBUSER_REQUEST_HEADER](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usbuser_request_header)

[USB_BANDWIDTH_INFO](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_bandwidth_info)

[USB_CONTROLLER_INFO_0](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_controller_info_0)

[USB_DRIVER_VERSION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_driver_version_parameters)

[USB_PASS_THRU_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_pass_thru_parameters)

[USB_POWER_INFO](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_power_info)

[USB_UNICODE_NAME](https://learn.microsoft.com/windows/desktop/api/usbuser/ns-usbuser-usb_unicode_name)