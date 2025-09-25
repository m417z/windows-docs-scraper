# _IRB structure

## Description

Drivers use this structure to pass most requests to IEEE 1394 bus driver.

## Members

### `FunctionNumber`

Determines the type of request. Each request type is documented under the value of **FunctionNumber** in [IEEE 1394 Bus I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

### `Flags`

Reserved. Drivers must set this member to zero with one exception. When making a [REQUEST_ISOCH_ALLOCATE_BANDWIDTH](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) request, the caller can set the IRB_FLAG_ALLOW_REMOTE_FREE flag in **Flags** to indicate that the system should free the bandwidth handle memory pointed to be **IsochAllocateBandwidth.hBandwidth**. If caller does not set this flag, then caller will have to free the bandwidth handle.

### `BusReserved`

Reserved.

### `PortReserved`

Reserved.

### `u`

Specifies a union of structures, one for each value of **FunctionNumber**. The applicable submembers of **u** for each request are described with each request type in [IEEE 1394 Bus I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

| FunctionNumber | Associated Member |
| --- | --- |
| [REQUEST_ALLOCATE_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | AllocateAddressRange |
| [REQUEST_ASYNC_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | AsyncLock |
| [REQUEST_ASYNC_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | AsyncRead |
| [REQUEST_ASYNC_STREAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | AsyncStream |
| [REQUEST_ASYNC_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | AsyncWrite |
| [REQUEST_ISOCH_ALLOCATE_BANDWIDTH](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | IsochAllocateBandwidth |
| [REQUEST_ISOCH_DETACH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | IsochDetachBuffers |
| [REQUEST_ISOCH_LISTEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | IsochListen |
| [REQUEST_ISOCH_MODIFY_STREAM_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | IsochModifyStreamProperties |
| [REQUEST_ISOCH_QUERY_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | IsochQueryResources |
| [REQUEST_ISOCH_SET_CHANNEL_BANDWIDTH](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | IsochSetChannelBandwidth |
| [REQUEST_FREE_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | FreeAddressRange |
| [REQUEST_GET_CONFIG_ROM](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | GetConfigRom |
| [REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | GetLocalHostInformation |
| [REQUEST_GET_SPEED_BETWEEN_DEVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | GetMaxSpeedBetweenDevices |
| [REQUEST_GET_SPEED_TOPOLOGY_MAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | GetSpeedTopologyMaps |
| [REQUEST_SEND_PHY_CONFIG_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | SendPhyConfigurationPacket |
| [REQUEST_SEND_PHY_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | SendPhyPacket |
| [REQUEST_SET_LOCAL_HOST_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | SetLocalHostProperties |
| [REQUEST_SET_DEVICE_XMIT_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) | SetDeviceXmitProperties |
| [REQUEST_RECEIVE_PHY_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) | ReceivePhyPackets |

### `u.AsyncRead`

### `u.AsyncWrite`

### `u.AsyncLock`

### `u.IsochAllocateBandwidth`

### `u.IsochAllocateChannel`

### `u.IsochAllocateResources`

### `u.IsochAttachBuffers`

### `u.IsochDetachBuffers`

### `u.IsochFreeBandwidth`

### `u.IsochFreeChannel`

### `u.IsochFreeResources`

### `u.IsochListen`

### `u.IsochQueryCurrentCycleTime`

### `u.IsochQueryResources`

### `u.IsochSetChannelBandwidth`

### `u.IsochStop`

### `u.IsochTalk`

### `u.IsochModifyStreamProperties`

### `u.AllocateAddressRange`

### `u.FreeAddressRange`

### `u.GetLocalHostInformation`

### `u.Get1394AddressFromDeviceObject`

### `u.Control`

### `u.GetMaxSpeedBetweenDevices`

### `u.SetDeviceXmitProperties`

### `u.SetLocalHostProperties`

### `u.GetConfigurationInformation`

### `u.GetConfigRom`

### `u.BusReset`

### `u.GetGenerationCount`

### `u.SendPhyConfigurationPacket`

### `u.SendPhyPacket`

### `u.ReceivePhyPackets`

### `u.GetSpeedTopologyMaps`

### `u.BusResetNotification`

### `u.AsyncStream`

## Remarks

The **Parameters->Others.Arguments1** member of an [IOCTL_1394_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) IRP points to an IRB structure. The bus driver uses the IRB to determine the type of request made by the device driver, and also to return the results of the operation. See [IEEE 1394 Bus I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/ddi/) for a description of the behavior of each request.

## See also

[IOCTL_1394_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)