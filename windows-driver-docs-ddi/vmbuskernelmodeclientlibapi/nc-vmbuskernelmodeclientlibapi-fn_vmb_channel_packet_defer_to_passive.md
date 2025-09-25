# FN_VMB_CHANNEL_PACKET_DEFER_TO_PASSIVE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelPacketDeferToPassive** function is called by the client driver to defer a packet
passed to it by the [EvtVmbChannelProcessPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_process_packet) callback function.

## Parameters

### `PacketCompletionContext`

A handle that identifies the incoming packet and is used to refer to the packet
once processing is finished.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_PACKET_DEFER_TO_PASSIVE FnVmbChannelPacketDeferToPassive;

// Definition

VOID FnVmbChannelPacketDeferToPassive
(
	VMBPACKETCOMPLETION PacketCompletionContext
)
{...}

```

## Remarks

A deferred packet goes back onto the parsing queue. It is guaranteed to be
parsed again at PASSIVE_LEVEL.

This routine is designed to only be called in-line from [EvtVmbChannelProcessPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_process_packet).

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[EvtVmbChannelProcessPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_process_packet)