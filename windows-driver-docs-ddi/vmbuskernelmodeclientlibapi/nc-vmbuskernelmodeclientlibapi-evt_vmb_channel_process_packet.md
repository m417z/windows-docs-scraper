# EVT_VMB_CHANNEL_PROCESS_PACKET callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The *EvtVmbChannelProcessPacket* callback function is invoked when a packet arrives in the incoming ring buffer.

## Parameters

### `Channel` [in]

The channel on which the packet arrives.

### `Packet` [in]

The completion context, which identifies this packet to Kernel Mode Client Library (KMCL) when the transaction can be retired.

### `Buffer` [in]

The packet which was sent by the opposite endpoint. This value does not contain the VMBus and KMCL headers.

### `BufferLength` [in]

The length of the *Buffer* parameter, in bytes.

### `Flags` [in]

Flags. Possible values include the following:

| Value | Meaning |
| --- | --- |
| **VMBUS_CHANNEL_PROCESS_PACKET_FLAGS**<br><br>0x1 | The packet references external data. This data can be retrieved by using the [VmbChannelPacketGetExternalData](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelpacketgetexternaldata) function. |

## Remarks

The client driver registers its implementation of this callback function by using the [VmbChannelInitSetProcessPacketCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelinitsetprocesspacketcallbacks) function.

Every time you invoke this function, you must eventually call
the [VmbChannelPacketComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelpacketcomplete) function.

This callback function can be invoked at DISPATCH_LEVEL or lower, unless the channel
has been configured to defer packet processing to a worker thread.

## See also

[VmbChannelInitSetProcessPacketCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelinitsetprocesspacketcallbacks)

[VmbChannelPacketComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelpacketcomplete)

[VmbChannelPacketGetExternalData](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelpacketgetexternaldata)