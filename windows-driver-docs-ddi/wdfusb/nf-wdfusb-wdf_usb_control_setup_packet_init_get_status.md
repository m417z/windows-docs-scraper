# WDF_USB_CONTROL_SETUP_PACKET_INIT_GET_STATUS function

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_CONTROL_SETUP_PACKET_INIT_GET_STATUS** function initializes a [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure for a USB control transfer that obtains device status.

## Parameters

### `Packet` [out]

A pointer to a [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

### `BmRequestRecipient` [in]

A [WDF_USB_BMREQUEST_RECIPIENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_bmrequest_recipient)-typed value that is stored in the **Packet.bm.Request.Recipient** member of the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

### `Index` [in]

A status index value that is stored in the **Packet.wIndex.Value** member of the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

## Remarks

The **WDF_USB_CONTROL_SETUP_PACKET_INIT_GET_STATUS** function does the following:

1. Zeros the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.
2. Sets the **Packet.bm.Request.Type** member to **BmRequestStandard**.
3. Sets the **Packet.bm.Request.Dir** member to **BmRequestDeviceToHost**.
4. Sets the **Packet.bRequest** member to a "get status" request value.
5. Sets the **Packet.wValue.Value** member to zero.
6. Sets the **Packet->Packet.wIndex.Value** member to the *Index* argument.

To initialize a [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure, the driver should call one of the following functions:

* [WDF_USB_CONTROL_SETUP_PACKET_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init)
* [WDF_USB_CONTROL_SETUP_PACKET_INIT_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_class)
* [WDF_USB_CONTROL_SETUP_PACKET_INIT_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_feature)
* **WDF_USB_CONTROL_SETUP_PACKET_INIT_GET_STATUS**
* [WDF_USB_CONTROL_SETUP_PACKET_INIT_VENDOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_vendor)

#### Examples

The following code example initializes a [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

```cpp
WDF_USB_CONTROL_SETUP_PACKET  packet;

WDF_USB_CONTROL_SETUP_PACKET_INIT_GET_STATUS(
                                             &packet,
                                             BmRequestToDevice,
                                             0
                                             );
```

## See also

[WDF_USB_BMREQUEST_RECIPIENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_bmrequest_recipient)

[WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet)

[WDF_USB_CONTROL_SETUP_PACKET_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init)

[WDF_USB_CONTROL_SETUP_PACKET_INIT_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_class)

[WDF_USB_CONTROL_SETUP_PACKET_INIT_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_feature)

[WDF_USB_CONTROL_SETUP_PACKET_INIT_VENDOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_vendor)