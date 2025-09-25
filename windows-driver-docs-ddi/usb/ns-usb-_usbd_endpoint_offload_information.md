# _USBD_ENDPOINT_OFFLOAD_INFORMATION structure

## Description

Stores xHCI-specific V2 information that is used by client drivers to transfer data to and from the offloaded endpoints.

## Members

### `Size`

The size of this structure.

### `EndpointAddress`

Specifies the USB-defined endpoint address.

### `ResourceId`

The resource identifier.

### `Mode`

A **[USBD_ENDPOINT_OFFLOAD_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ne-usb-_usbd_endpoint_offload_mode)** value that indicates whether endpoint offloading is handled in software or the USB device or host controller.

### `RootHubPortNumber`

The port number of the root hub to which the device is connected.

### `RouteString`

The route string describing the path from the root hub to the device.

### `Speed`

The speed of the USB device.

### `UsbDeviceAddress`

The USB address of the device.

### `SlotId`

The slot ID of the device.

### `MultiTT`

Indicates if the device is connected to a hub with transaction translators.

### `LSOrFSDeviceConnectedToTTHub`

Indicates if the device is a low-speed or full-speed device connected to a hub with transaction translators.

### `Reserved0`

Reserved.

### `TransferSegmentLA`

The physical address of the transfer ring segment.

### `TransferSegmentVA`

The virtual address of the transfer ring segment.

### `TransferRingSize`

The size of the transfer ring.

### `TransferRingInitialCycleBit`

The initial cycle bit of the transfer ring.

### `MessageNumber`

The message number for the secondary event ring.

### `EventRingSegmentLA`

The physical address of the event ring segment.

### `EventRingSegmentVA`

The virtual address of the event ring segment.

### `EventRingSize`

The size of the event ring, in bytes.

### `EventRingInitialCycleBit`

The initial cycle bit of the event ring.

### `ClientTransferRingSegmentPAIn`

The physical address of the client-provided transfer ring segment.

### `ClientTransferRingSizeIn`

The size of the client-provided transfer ring segment.

### `ClientDataBufferPAIn`

The physical address of the client-provided data buffer.

### `ClientDataBufferSizeIn`

The size of the client-provided data buffer.

### `ClientDataBufferLAOut`

The physical address of the mapped data buffer.

### `ClientDataBufferVAOut`

The virtual address of the mapped data buffer.

## remarks

This structure duplicates and extends **[USBD_ENDPOINT_OFFLOAD_INFORMATION_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-usbd_endpoint_offload_information_v1)**.

This structure supports two versions, indicated by `USBD_ENDPOINT_OFFLOAD_INFORMATION` and `USBD_ENDPOINT_OFFLOAD_INFORMATION_V2`, with the latter possibly including additional fields beyond what is documented here. The structure facilitates detailed configuration and management of USB endpoint offload.

## see-also

- **[USBD_ENDPOINT_OFFLOAD_INFORMATION_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-usbd_endpoint_offload_information_v1)**