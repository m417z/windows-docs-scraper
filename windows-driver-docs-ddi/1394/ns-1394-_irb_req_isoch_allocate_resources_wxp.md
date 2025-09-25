# _IRB_REQ_ISOCH_ALLOCATE_RESOURCES_WXP structure

## Description

This structure contains the fields necessary for the 1394 bus driver to carry out a IsochAllocateResources request.

## Members

### `fulSpeed`

Specifies the connection speed to use for communication on the channel. The possible speed values are SPEED_FLAGS_xxx, where xxx is the (approximate) transfer rate in megabits per second. Existing hardware supports transfer rates of 100, 200, and 400 Mb/sec.

| Transfer Rate | Description |
| --- | --- |
| SPEED_FLAGS_100 | 100 Mb/s |
| SPEED_FLAGS_200 | 200 Mb/s |
| SPEED_FLAGS_400 | 400 Mb/s |

**Note** In Windows 7 and later versions of Windows, you can specify new values higher speed and greater sized payloads. For more information, see [New Flags for Speed and Payload Size](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) and [IEEE 1394 IOCTL Changes](https://learn.microsoft.com/windows-hardware/drivers/ieee/device-driver-interface--ddi--changes-in-windows-7) in Device Driver Interface (DDI) Changes in Windows 7.

### `fulFlags`

Specifies how the bus driver should use any buffers attached to the resource handle. Many of the flags specify how the bus driver should configure the IEEE host controller for DMA from or to attached buffers.

| Flag | Description |
| --- | --- |
| RESOURCE_USED_IN_LISTENING | Attached buffers are used to read data from an isochronous channel. Set this if the resource handle will be used in a REQUEST_ISOCH_LISTEN request. |
| RESOURCE_USED_IN_TALKING | Attached buffers are used to write data to an isochronous channel. Set this if the resource handle will be used in a REQUEST_ISOCH_TALK request. |
| RESOURCE_STRIP_ADDITIONAL_QUADLETS | The bus driver configures the host controller to strip additional quadlets from incoming isochronous packets. The number of quadlets to be stripped is specified in **nQuadletsToStrip**. |
| RESOURCE_SYNCH_ON_TIME | The bus driver configures the host controller to synchronize the beginning of the isochronous transaction to the CYCLE_TIME specified in the StartTime member of the request's IRB. See REQUEST_ISOCH_LISTEN or REQUEST_ISOCH_TALK. |
| RESOURCE_USE_PACKET_BASED | Used to switch to packet-based transfer, rather than the default. The default is stream-based transfer, unless the host controller only supports packet-based DMA. |
| RESOURCE_USE_MULTICHANNEL | The driver owning this resource listens on multiple channels. |
| RESOURCE_VARIABLE_ISOCH_PAYLOAD | The driver owning this resource transfers frames of variable size. |

### `nChannel`

Specifies the isochronous channel for all transactions involving the resource handle allocated by this request.

### `nMaxBytesPerFrame`

Specifies the expected maximum isochronous frame size while transmitting and receiving on the channel.

### `nNumberOfBuffers`

Specifies one more than the maximum expected number of buffers that are attached to the resource handle at any given time.

### `nMaxBufferSize`

Specifies the maximum size of the buffers that are attached to the resource handle.

### `nQuadletsToStrip`

Specifies the number of quadlets to strip from the beginning of every packet in an incoming isochronous stream. This parameter is ignored unless the device driver sets the RESOURCE_STRIP_ADDITIONAL_QUADLETS flag in **u.IsochAllocateResources.fulFlags**.

### `hResource`

Specifies a handle to the resource.

### `ChannelMask`

Specifies a set of isochronous channels, if RESOURCE_USE_MULTICHANNEL is set, that are used for all transactions involving the resource handle allocated by this request.