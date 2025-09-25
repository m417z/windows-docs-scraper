# _URB_ISOCH_TRANSFER structure

## Description

The **_URB_ISOCH_TRANSFER** structure is used by USB client drivers to send data to or retrieve data from an isochronous transfer pipe.

## Members

### `Hdr`

A pointer to a [_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header) structure that specifies the URB header information. **Hdr.Function** must be URB_FUNCTION_ISOCH_TRANSFER, and **Hdr.Length** must be the size of this variable-length data structure.

### `PipeHandle`

Specifies an opaque handle to the isochronous pipe. The host controller driver returns this handle when the client driver selects the device configuration with a URB of type URB_FUNCTION_SELECT_CONFIGURATION or when the client driver changes the settings for an interface with a URB of type URB_FUNCTION_SELECT_INTERFACE.

### `TransferFlags`

Specifies zero, one, or a combination of the following flags:

| Value | Meaning |
| --- | --- |
| **USBD_TRANSFER_DIRECTION_IN** | Is set to request data from a device. To transfer data to a device, this flag must be clear. |
| **USBD_SHORT_TRANSFER_OK** | Is set to direct the host controller not to return an error when it receives a packet from the device that is shorter than the maximum packet size for the endpoint. This flag has no effect on an isochronous pipe, because the bus driver does not return an error when it receives short packets on an isochronous pipe. |
| **USBD_START_ISO_TRANSFER_ASAP** | Causes the transfer to begin on the next frame, if no transfers have been submitted to the pipe since the pipe was opened or last reset. Otherwise, the transfer begins on the first frame that follows all currently queued requests for the pipe. The actual frame that the transfer begins on will be adjusted for bus latency by the host controller driver. |

### `TransferBufferLength`

Specifies the length, in bytes, of the buffer specified in **TransferBuffer** or described in **TransferBufferMDL**. The host controller driver returns the number of bytes that are sent to or read from the pipe in this member.

### `TransferBuffer`

A pointer to a resident buffer for the transfer is **NULL** if an MDL is supplied in **TransferBufferMDL**. The contents of this buffer depend on the value of **TransferFlags**. If USBD_TRANSFER_DIRECTION_IN is specified, this buffer will contain data that is read from the device on return from the host controller driver. Otherwise, this buffer contains driver-supplied data for transfer to the device.

### `TransferBufferMDL`

A pointer to an MDL that describes a resident buffer is **NULL** if a buffer is supplied in **TransferBuffer**. The contents of the buffer depend on the value of **TransferFlags**. If USBD_TRANSFER_DIRECTION_IN is specified, the described buffer will contain data that is read from the device on return from the host controller driver. Otherwise, the buffer contains driver-supplied data for transfer to the device. This MDL must be allocated from nonpaged pool.

### `UrbLink`

Reserved. Do not use.

### `hca`

Reserved. Do not use.

### `StartFrame`

Specifies the frame number that the transfer should begin on. This variable must be within a system-defined range of the current frame. The range is specified by the constant USBD_ISO_START_FRAME_RANGE.

If START_ISO_TRANSFER_ASAP is set in **TransferFlags**, this member contains the frame number that the transfer began on, when the request is returned by the host controller driver. Otherwise, this member must contain the frame number that this transfer begins on.

### `NumberOfPackets`

Specifies the number of packets that are described by the variable-length array member **IsoPacket**.

### `ErrorCount`

Contains the number of packets that completed with an error condition on return from the host controller driver.

### `IsoPacket`

Contains a variable-length array of [USBD_ISO_PACKET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_iso_packet_descriptor) structures that describe the isochronous transfer packets to be transferred on the USB bus. For more information about this member see the Remarks section.

## Remarks

The USB bus driver always returns a value of USBD_STATUS_SUCCESS in **Hdr.Status**, unless every packet in the transfer generated an error or the request was not well-formed and could not be executed at all. The following table includes possible error codes returned in **Hdr.Status**.

| Error value | Meaning |
| --- | --- |
| USBD_STATUS_ISOCH_REQUEST_FAILED | Indicates that every packet of an isochronous request was completed with errors. |
| USBD_STATUS_BAD_START_FRAME | Indicates that the requested start frame is not within USBD_ISO_START_FRAME_RANGE of the current USB frame. |
| USBD_ISO_NOT_ACCESSED_LATE | Indicates that every packet was submitted too late for the packet to be sent, based on the requested start frame. |
| USBD_STATUS_INVALID_PARAMETER | Indicates that one of the URB parameters was incorrect. |

Before the host controller sends an isochronous request to a USB device, it requires information about the device's endpoint to which it must send or receive data. This information is stored in endpoint descriptors ([USB_ENDPOINT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbspec/ns-usbspec-_usb_endpoint_descriptor)) that are retrieved from the selected configuration descriptor.
After the bus driver gets the endpoint descriptor, it creates an isochronous transfer pipe to set up the data transfer. The pipe's attributes are stored in the [USBD_PIPE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_pipe_information) structure. For isochronous transfers, the members are set as follows:

* The **PipeType** member specifies the type of transfer and is set to UsbdPipeTypeIsochronous.
* The **MaximumPacketSize** member specifies the amount of data, in bytes, that constitutes one packet. For isochronous transfers, the packet size is fixed and can be a value from 0-1024. The packet size either equals or is less than the **wMaxPacketSize** value of the endpoint descriptor.
* The **Interval** member is derived from the **bInterval** value of the endpoint descriptor. This value is used to calculate the polling period that indicates the frequency at which data is sent on the bus. For full speed devices, the period is measured in units of 1 millisecond frames; for high speed devices, the period is measured in microframes.

The host controller also determines the amount of data that can be transferred (within a frame or a microframe) depending on the type of device. This information is available in bits **12.. 11** of **wMaxPacketSize** in the endpoint descriptor.

For full-speed devices, only one packet can be transferred within a frame; bits **12.. 11** are reserved and set to zero.

For high speed devices, data can be transferred in a single packet or might span multiple packets, within a microframe.
If bits **12.. 11** are set to *n*, you can transfer `(n+1)*MaximumPacketSize` bytes per microframe. Bits **12.. 11** set to zero indicate that only one packet can be transferred in a microframe. If bits **12.. 11** are set to 1, the host controller can transfer two packets in a microframe.

The **IsoPacket** member of **_URB_ISOCH_TRANSFER** is an array of [USBD_ISO_PACKET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_iso_packet_descriptor) that describes the transfer buffer layout. Each element in the array correlates to data that is transferred in one microframe. If **IsoPacket** has *n* elements, the host controller transfers use *n* frames (for full speed devices) or microframes (for high speed devices) to transfer data. The **IsoPacket[**i**].Offset** member is used to track the amount of data to send or receive. This is done by setting a byte offset from the start of the entire transfer buffer for the request.

For example, there are five microframes available to transfer 1024 byte-sized packets.

If bits **12.. 11** are set to zero (indicating a single packet per microframe transfer), **IsoPacket** contains the following entries:

Microframe 1 `IsoPacket.Element[0].Offset = 0` (start address)

Microframe 2 `IsoPacket.Element[1].Offset = 1024`

Microframe 3 `IsoPacket.Element[2].Offset = 2048`

Microframe 4 `IsoPacket.Element[3].Offset = 3072`

Microframe 5 `IsoPacket.Element[4].Offset = 4096`

If bits **12.. 11** are set to 1 (indicating two packets per microframe), **IsoPacket** contains the following entries:

Microframe 1 `IsoPacket.Element[0].Offset = 0` (start address)

Microframe 2 `IsoPacket.Element[1].Offset = 2048`

Microframe 3 `IsoPacket.Element[2].Offset = 4096`

Microframe 4 `IsoPacket.Element[3].Offset = 6144`

Microframe 5 `IsoPacket.Element[4].Offset = 8192`

**Note** For multiple packets, the offset value indicates sizes for all the packets within the microframe.

The **IsoPacket[**i**].Length** member is updated by the host controller to indicate the actual number of bytes that are received from the device for isochronous IN transfers. **IsoPacket[**i**].Length** is not used for isochronous OUT transfers.

Drivers can use the [GET_ISO_URB_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-get_iso_urb_size) macro to determine the size that is needed to hold the entire URB. If the length is too small to fill the space set aside for this packet, the bus driver leaves a gap from the end of the retrieved data to the offset for the next packet. The bus driver will not adjust the offsets to avoid wasting buffer space.

The **TransferBuffer** or **TransferBufferMDL** members must specify a virtually contiguous buffer.

Treat other members that are part of this structure but not described here as opaque. They are reserved for system use.

## See also

[How to Transfer Data to USB Isochronous Endpoints](https://learn.microsoft.com/windows-hardware/drivers/usbcon/transfer-data-to-isochronous-endpoints)

[URB](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb)

[USB Structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/_usbref/#structures)

[USBD_ISO_PACKET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_iso_packet_descriptor)

[USBD_IsochUrbAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/nf-usbdlib-usbd_isochurballocate)

[_URB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_urb_header)