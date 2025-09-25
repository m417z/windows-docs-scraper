# _GET_LOCAL_HOST_INFO2 structure

## Description

The GET_LOCAL_HOST_INFO2 structure contains the data returned by a [REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) request using **u.GetLocalHostInformation.nLevel** GET_HOST_CAPABILITIES.

## Members

### `HostCapabilities`

Indicates the host capabilities. The following table lists the values that can be assigned to th is member:

| Flag | Description |
| --- | --- |
| HOST_INFO_PACKET_BASED | The host controller supports packet-based isochronous transactions. |
| HOST_INFO_STREAM_BASED | The host controller supports stream-based isochronous transactions. |
| HOST_INFO_SUPPORTS_ISOCH_STRIPPING | The host controller supports configurable stripping of header information. |
| HOST_INFO_SUPPORTS_START_ON_CYCLE | The host controller supports synchronizing start on specific isochronous cycle times. |
| HOST_INFO_SUPPORTS_RETURNING_ISO_HDR | The host controller does not automatically strip off the isochronous packet header. |
| HOST_INFO_SUPPORTS_ISO_HDR_INSERTION | The host controller supports the DESCRIPTOR_HEADER_SCATTER_GATHER flag in ISOCH_DESCRIPTOR. |
| HOST_INFO_SUPPORTS_ISO_DUAL_BUFFER_RX | The host controller supports the RESOURCE_VARIABLE_ISOCH_PAYLOAD flag in ISOCH_DESCRIPTOR. |
| HOST_INFO_DMA_DOUBLE_BUFFERING_ENABLED DMA | transfers that are made to/from the host controller will be double-buffered by using system map registers. System map registers limit the size of a single transfer. Check the MaxDmaBufferSize value that is returned in the GET_LOCAL_HOST_INFO7 structure by a REQUEST_GET_LOCAL_HOST_INFO request and limit the transfer size accordingly. |

### `MaxAsyncReadRequest`

The bus driver fills in this member with the maximum size asynchronous read request that the host controller supports.

### `MaxAsyncWriteRequest`

The bus driver fills in this member with the maximum size asynchronous write request that the host controller supports.

## Remarks

Port drivers that return the HOST_INFO_PACKET_BASED flag support the IsochAllocateResources request's RESOURCE_USE_PACKET_BASED flag. Port drivers that return the HOST_STREAM_PACKET_BASED flag support stream-based I/O. If the host controller does not support stream-based I/O, the driver must use packet-based I/O, and set the RESOURCE_USE_PACKET_BASED flag when issuing the [REQUEST_ISOCH_ALLOCATE_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class).

Some host controllers automatically strip the packet header off an isochronous packet. If a host controller does not automatically strip the header, the port driver returns the HOST_INFO_SUPPORTS_ISO_HDR flag. Some host controllers allow a driver to configure the host controller to strip off a given number of quadlets; for such controllers the port driver returns the HOST_INFO_SUPPORTS_ISOCH_STRIPPING flag. The driver should check this flag before calling [REQUEST_ISOCH_ALLOCATE_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) with the RESOURCE_STRIP_ADDITIONAL_QUADLETS flag.

If a host controller supports synchronizing [REQUEST_ISOCH_LISTEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) and [REQUEST_ISOCH_TALK](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) requests to the isochronous cycle time, the port driver returns the HOST_INFO_SUPPORTS_START_ON_CYCLE. Drivers should check this flag before attempting to issue an REQUEST_ISOCH_ALLOCATE_RESOURCES request using the RESOURCE_SYNCH_ON_TIME flag, or before attaching a buffer whose [ISOCH_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_isoch_descriptor) has the DESCRIPTOR_SYNCH_ON_TIME flag set.

## See also

[GET_LOCAL_HOST_INFO7](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_get_local_host_info7_w2k)

[ISOCH_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_isoch_descriptor)

[REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)

[REQUEST_ISOCH_ALLOCATE_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)