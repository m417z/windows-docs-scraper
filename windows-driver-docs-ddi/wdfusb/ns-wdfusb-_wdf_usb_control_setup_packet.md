# _WDF_USB_CONTROL_SETUP_PACKET structure

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_CONTROL_SETUP_PACKET** structure describes a setup packet for a USB control transfer.

## Members

### `Packet`

### `Packet.bm`

### `Packet.bm.Request`

### `Packet.bm.Request.Recipient`

A bit field that is specified by a [WDF_USB_BMREQUEST_RECIPIENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_bmrequest_recipient)-typed value.

### `Packet.bm.Request.Reserved`

A reserved bit field. Do not use this member.

### `Packet.bm.Request.Type`

A bit field that is specified by a [WDF_USB_BMREQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_bmrequest_type)-typed value.

### `Packet.bm.Request.Dir`

A bit field that is specified by a [WDF_USB_BMREQUEST_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_bmrequest_direction)-typed value.

### `Packet.bm.Byte`

A byte-sized bitmap that contains the **Request.Recipient**, **Request.Reserved**, **Request.Type**, and **Request.Dir** bit fields. Use this member as an alternative to specifying the individual bit fields.

### `Packet.bRequest`

A request type. Request type constants are defined in *Usb100.h*. For more information about request types, see the USB specification.

### `Packet.wValue`

### `Packet.wValue.Bytes`

### `Packet.wValue.Bytes.LowByte`

The low byte of a 2-byte, request-specific value. For more information about specifying **wValue**, see the USB specification.

### `Packet.wValue.Bytes.HiByte`

The high byte of a 2-byte, request-specific value.

### `Packet.wValue.Value`

A 2-byte value that contains the **Bytes.LowByte** and **Bytes.HiByte** values. Use this member as an alternative to specifying individual low-byte and high-byte values.

### `Packet.wIndex`

### `Packet.wIndex.Bytes`

### `Packet.wIndex.Bytes.LowByte`

The low byte of a 2-byte, request-specific value. For more information about specifying **wValue**, see the USB specification.

### `Packet.wIndex.Bytes.HiByte`

The high byte of a 2-byte, request-specific value.

### `Packet.wIndex.Value`

A 2-byte value that contains the **Bytes.LowByte** and **Bytes.HiByte** values. Use this member as an alternative to specifying individual low-byte and high-byte values.

### `Packet.wLength`

The number of bytes to transfer, if applicable. For more information about this value, see the USB specification. The framework sets this value.

### `Generic`

### `Generic.Bytes`

An 8-byte value that represents the entire setup packet. You can use this member as an alternative to specifying individual structure members.

## Remarks

The **WDF_USB_CONTROL_SETUP_PACKET** structure is used as input to the [WdfUsbTargetDeviceSendControlTransferSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicesendcontroltransfersynchronously) and [WdfUsbTargetDeviceFormatRequestForControlTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforcontroltransfer) methods.

To initialize a **WDF_USB_CONTROL_SETUP_PACKET** structure, the driver should call one of the following functions:

* [WDF_USB_CONTROL_SETUP_PACKET_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init)
* [WDF_USB_CONTROL_SETUP_PACKET_INIT_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_class)
* [WDF_USB_CONTROL_SETUP_PACKET_INIT_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_feature)
* [WDF_USB_CONTROL_SETUP_PACKET_INIT_GET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_get_status)
* [WDF_USB_CONTROL_SETUP_PACKET_INIT_VENDOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_vendor)

## See also

[WDF_USB_BMREQUEST_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_bmrequest_direction)

[WDF_USB_BMREQUEST_RECIPIENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_bmrequest_recipient)

[WDF_USB_BMREQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_bmrequest_type)

[WdfUsbTargetDeviceFormatRequestForControlTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdeviceformatrequestforcontroltransfer)

[WdfUsbTargetDeviceSendControlTransferSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdfusbtargetdevicesendcontroltransfersynchronously)