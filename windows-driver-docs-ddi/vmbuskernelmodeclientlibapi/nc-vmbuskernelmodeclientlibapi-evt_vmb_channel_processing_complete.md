# EVT_VMB_CHANNEL_PROCESSING_COMPLETE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The *EvtVmbChannelProcessingComplete* callback function is invoked when a group of packets has been delivered by
the [EvtVmbChannelProcessPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_process_packet) function, if there is a pause before delivering subsequent packets.

## Parameters

### `Channel` [in]

The channel one which the packets are delivered.

### `PacketsProcessed` [in]

The number of packets which were delivered in this batch.

## Remarks

The client driver registers its implementation of this callback function by using the [VmbChannelInitSetProcessPacketCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelinitsetprocesspacketcallbacks) function.

A pause in packet processing might occur because the
incoming ring buffer was empty.

This callback function can be invoked at DISPATCH_LEVEL or lower, unless the channel
has been configured to defer packet processing to a worker thread.

## See also

[EvtVmbChannelProcessPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_process_packet)

[VmbChannelInitSetProcessPacketCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelinitsetprocesspacketcallbacks)