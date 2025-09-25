# WDF_USB_CONTROL_SETUP_PACKET_INIT_FEATURE function

## Description

[Applies to KMDF and UMDF]

The **WDF_USB_CONTROL_SETUP_PACKET_INIT_FEATURE** function initializes a [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure for a USB control transfer that sets or clears a device feature.

## Parameters

### `Packet` [out]

A pointer to a [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

### `BmRequestRecipient` [in]

A [WDF_USB_BMREQUEST_RECIPIENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_bmrequest_recipient)-typed value that is stored in the **Packet.bm.Request.Recipient** member of the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

### `FeatureSelector` [in]

A feature-specific value that is stored in the **Packet.wValue.Value** member of the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

### `Index` [in]

A feature-specific index value that is stored in the **Packet.wIndex.Value** member of the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

### `SetFeature` [in]

A Boolean value that, if **TRUE**, indicates that the specified feature will be set. If **FALSE**, the specified feature will be cleared.

## Remarks

The **WDF_USB_CONTROL_SETUP_PACKET_INIT_FEATURE** function does the following:

1. Zeros the [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.
2. Sets the **Packet.bm.Request.Type** member to **BmRequestStandard**.
3. Sets the **Packet.bm.Request.Dir** member to **BmRequestDeviceToDevice**.
4. Sets the **Packet.bRequest** member to either a "set feature" or a "clear feature" request value, based on the *SetFeature* argument.
5. Sets other structure members by using the **WDF_USB_CONTROL_SETUP_PACKET_INIT_FEATURE** function's input arguments.

To initialize a [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure, the driver should call one of the following functions:

* [WDF_USB_CONTROL_SETUP_PACKET_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init)
* [WDF_USB_CONTROL_SETUP_PACKET_INIT_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_class)
* **WDF_USB_CONTROL_SETUP_PACKET_INIT_FEATURE**
* [WDF_USB_CONTROL_SETUP_PACKET_INIT_GET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_get_status)
* [WDF_USB_CONTROL_SETUP_PACKET_INIT_VENDOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_vendor)

#### Examples

The following code example initializes a [WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet) structure.

```cpp
WDF_USB_CONTROL_SETUP_PACKET packet;

WDF_USB_CONTROL_SETUP_PACKET_INIT_FEATURE(
                                          &packet,
                                          BMREQUEST_TO_DEVICE,
                                          USB_DEVICE_DESCRIPTOR_TYPE,
                                          0,
                                          FALSE
                                          );
```

## See also

[WDF_USB_BMREQUEST_RECIPIENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_bmrequest_recipient)

[WDF_USB_CONTROL_SETUP_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ns-wdfusb-_wdf_usb_control_setup_packet)

[WDF_USB_CONTROL_SETUP_PACKET_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init)

[WDF_USB_CONTROL_SETUP_PACKET_INIT_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_class)

[WDF_USB_CONTROL_SETUP_PACKET_INIT_GET_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_get_status)

[WDF_USB_CONTROL_SETUP_PACKET_INIT_VENDOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/nf-wdfusb-wdf_usb_control_setup_packet_init_vendor)