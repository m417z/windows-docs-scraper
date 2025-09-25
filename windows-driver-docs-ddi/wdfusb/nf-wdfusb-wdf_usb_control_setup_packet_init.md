# WDF_USB_CONTROL_SETUP_PACKET_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_CONTROL_SETUP_PACKET_INIT** function initializes a [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure for a standard USB control transfer.

## Parameters

### `Packet` [out]

A pointer to a [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

### `Direction` [in]

A [WDF_USB_BMREQUEST_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_bmrequest_direction)-typed value that is stored in the **Packet.bm.Request.Dir** member of the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

### `Recipient` [in]

A [WDF_USB_BMREQUEST_RECIPIENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_bmrequest_recipient)-typed value that is stored in the **Packet.bm.Request.Recipient** member of the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

### `Request` [in]

A request type constant that is stored in the **Packet.bRequest** member of the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

### `Value` [in]

A request-specific value that is stored in the **Packet.wValue.Value** member of the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

### `Index` [in]

A request-specific index value that is stored in the **Packet.wIndex.Value** member of the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

## Remarks

The **WDF_USB_CONTROL_SETUP_PACKET_INIT** function does the following:

1. Zeros the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.
2. Sets the **Packet.bm.Request.Type** member to **BmRequestStandard**.
3. Sets other structure members by using the **WDF_USB_CONTROL_SETUP_PACKET_INIT** function's input arguments.

To initialize a [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure, the driver should call one of the following functions:

* **WDF_USB_CONTROL_SETUP_PACKET_INIT**
* [WDF_USB_CONTROL_SETUP_PACKET_INIT_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_class)
* [WDF_USB_CONTROL_SETUP_PACKET_INIT_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_feature)
* [WDF_USB_CONTROL_SETUP_PACKET_INIT_GET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_get_status)
* [WDF_USB_CONTROL_SETUP_PACKET_INIT_VENDOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_vendor)

#### Examples

The following code example initializes a [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

```cpp
WDF_USB_CONTROL_SETUP_PACKET  packet;

WDF_USB_CONTROL_SETUP_PACKET_INIT(
                                  &packet,
                                  BMREQUEST_HOST_TO_DEVICE,
                                  BMREQUEST_TO_DEVICE,
                                  0,
                                  0,
                                  0
                                  );
```

## See also

[WDF_USB_BMREQUEST_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_bmrequest_direction)

[WDF_USB_BMREQUEST_RECIPIENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_bmrequest_recipient)

[WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet)

[WDF_USB_CONTROL_SETUP_PACKET_INIT_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_class)

[WDF_USB_CONTROL_SETUP_PACKET_INIT_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_feature)

[WDF_USB_CONTROL_SETUP_PACKET_INIT_GET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_get_status)

[WDF_USB_CONTROL_SETUP_PACKET_INIT_VENDOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_vendor)