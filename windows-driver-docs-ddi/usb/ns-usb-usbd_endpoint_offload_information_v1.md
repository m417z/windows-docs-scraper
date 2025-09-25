## Description

Stores xHCI-specific V1 information that is used by client drivers to transfer data to and from the offloaded endpoints.

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

## see-also

- **[USBD_ENDPOINT_OFFLOAD_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_endpoint_offload_information)**