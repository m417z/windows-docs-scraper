# _USBD_PIPE_INFORMATION structure

## Description

The **USBD_PIPE_INFORMATION** structure is used by USB client drivers to hold information about a pipe from a specific interface.

## Members

### `MaximumPacketSize`

Specifies the maximum packet size, in bytes, that this pipe handles. This value must be less than or equal to the value of **wMaxPacketSize** in the endpoint descriptor. The USB stack ignores this value if the USBD_PF_CHANGE_MAX_PACKET flag is not set in the **PipeFlags** member.

For high-speed isochronous endpoints, the received **MaximumPacketSize** value includes the number of bytes that can be transferred in additional transactions, if the endpoint supports them. For more information, see Remarks.

### `EndpointAddress`

Specifies the bus address for this pipe.

### `Interval`

Contains the polling interval, indicated by the **bInterval** field in the corresponding endpoint descriptor ([USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor)). This value is only valid for interrupt and isochronous pipes. For other types of pipe, this value should be ignored. It reflects the device's configuration in firmware. Drivers cannot change it.

The polling interval, together with the speed of the device and the type of host controller, determine the frequency with which the driver should initiate a transfer. The value in **Interval** does not represent a fixed amount of time. It is a relative value, and the actual polling frequency will also depend on whether the device and the USB host controller operate at low, full or high speed.

If either the host controller or the device operates at low speed, the period of time between transfers (also known as the "polling period") is measured in units of 1 millisecond frames, and the period is related to the value in **Interval** as indicated the following table:

| Interval | Polling Period (1-millisecond frames) | Interrupt | Isochronous |
| --- | --- | --- | --- |
| 0 to 15 | 8 | Supported. | Not supported. |
| 16 to 35 | 16 | Supported. | Not supported. |
| 36 to 255 | 32 | Supported. | Not supported. |

For devices and host controllers that can operate at full speed, the period is measured in units of 1 millisecond frames. For full-speed isochronous transfers, the **Interval** value and the polling period is always 1. That value indicates that data can be transferred in every frame. For full-speed interrupt transfers, the polling period is derived from the **Interval** value. The following table indicates the supported values for interrupt and isochronous endpoints.

| Interval | Polling Period (1-millisecond frames) | Interrupt | Isochronous |
| --- | --- | --- | --- |
| 1 | 1 | Supported. | Supported. |
| 2 to 3 | 2 | Supported. | Not supported. |
| 4 to 7 | 4 | Supported. | Not supported. |
| 8 to 15 | 8 | Supported. | Not supported. |
| 16 to 31 | 16 | Supported. | Not supported. |
| 32 to 255 | 32 | Supported. | Not supported. |

For devices and host controllers that can operate at high speed, the period is measured in units of microframes. The polling period is derived from the **Interval** value by using the formula `Polling period = 2 ** (Interval - 1)`. The calculated values are indicated in the following table:

| Interval | Polling Period (microframes) | Interrupt | Isochronous |
| --- | --- | --- | --- |
| 1 | 1 | Supported. | Supported. |
| 2 | 2 | Supported. | Supported. |
| 3 | 4 | Supported. | Supported. |
| 4 | 8 | Supported. | Supported. |
| 5 | 16 | Supported. | Not supported. |
| 6 to 255 | 32 | Supported. | Not supported. |

The supported polling periods for high-speed isochronous transfers are 1, 2, 4, and 8. If a client driver submits a URB_FUNCTION_ISOCH_TRANSFER request for a high speed isochronous endpoint with polling period greater than 8, the request fails with status USBD_STATUS_INVALID_PARAMETER. For information about isochronous transfers, see [How to Transfer Data to USB Isochronous Endpoints](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

The mappings in the preceding tables between periods and polling intervals are valid in Microsoft Windows 2000 and later versions of the Windows operating system.

### `PipeType`

Specifies what type of transfers this pipe uses. These values are defined in the [USBD_PIPE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ne-usb-_usbd_pipe_type) enumeration.

### `PipeHandle`

Specifies an opaque handle to the bulk or interrupt pipe. The host controller driver returns this handle when the client driver selects the device configuration with a URB of type URB_FUNCTION_SELECT_CONFIGURATION or when the client driver changes the settings for an interface with a URB of type URB_FUNCTION_SELECT_INTERFACE.

### `MaximumTransferSize`

Specifies the maximum size, in bytes, for a transfer request on this pipe. In Windows Server 2003, Windows XP and later operating systems, this member is not used and does not contain valid data.

For information about the maximum transfer sizes of each type of USB endpoint in different versions of Windows, see [USB Transfer and Packet Sizes](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

**Note** For WinUSB, do not use **MaximumTransferSize** to determine the maximum size of a USB transfer. Instead, use the MAXIMUM_TRANSFER_SIZE value retrieved by [WinUsb_GetPipePolicy](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_getpipepolicy).

### `PipeFlags`

Contains a bitwise-OR of pipe flags that the driver can use to specify certain configurable characteristics of the pipe. The driver specifies these pipe characteristics when it selects the configuration of a USB device with a URB request whose function type is URB_FUNCTION_SELECT_CONFIGURATION.

The following table explains the meaning of each pipe flag:

| Flag name | Meaning |
| --- | --- |
| USBD_PF_CHANGE_MAX_PACKET | Indicates that the driver is overriding the endpoint maximum packet size with the value specified in **MaximumPacketSize**. This value must be less than or equal to the default maximum specified in the pipe's endpoint descriptor. |

## Remarks

This structure contains information for an endpoint, retrieved from the device's interface descriptor. For an explanation of how to obtain the information in **USBD_PIPE_INFORMATION** from the interface descriptor, see [How to Select a Configuration for a USB Device](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

The **MaximumPacketSize** value is derived from the first **11** bits of the **wMaxPacketSize** field of the endpoint descriptor, which indicates the maximum number of bytes that the host controller can send to or receive from the endpoint in a single transaction.

Typically, for high-speed transfers, the host controller sends or receives one transaction per microframe. However, high speed, high bandwidth isochronous or interrupt endpoints support higher data rates through additional transactions. This allows the host controller to transfer up to 3072 bytes in a single microframe. The number of additional transactions supported by that type of endpoint is indicated by bits **12..11** of **wMaxPacketSize** (least significant bit is 0). That number can be 0, 1, or 2. If **12..11** indicate 0, additional transactions per microframe are not supported by the endpoint. If the number is 1, then the host controller can send an additional transaction (total of two transactions per microframe); 2 indicates two additional transactions (total of three transactions per microframe).

The value received in **MaximumPacketSize** for an isochronous endpoint (high-speed and high-bandwidth) indicates the total number of bytes that the host controller can send to or receive from the endpoint in one microframe. The value includes the number of bytes in additional transactions, if the endpoint supports them. For example, consider the following isochronous endpoint characteristics:

* **wMaxPacketSize** is 1,024
* Bits **12..11** indicate 2
* **Interval** is 1.

In the preceding example, the value received in **MaximumPacketSize** is 3,072 bytes (Total transactions * **wMaxPacketSize**). Because **Interval** is 1, the polling period is 1. Thus, the host controller can transfer 3,072 bytes in each microframe of a frame. In a single I/O request (described in one URB), the host controller can transfer no more than 24,576 bytes.

## See also

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor)