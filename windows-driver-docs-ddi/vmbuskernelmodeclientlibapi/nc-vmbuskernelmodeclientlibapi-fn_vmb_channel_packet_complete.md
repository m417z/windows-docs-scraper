# FN_VMB_CHANNEL_PACKET_COMPLETE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelPacketComplete** function cleans up any
outstanding memory mappings, releases any buffers in use, and, if the opposite endpoint requested a completion packet, sends a
completion packet.

## Parameters

### `PacketCompletionContext`

A handle that identifies the incoming packet and is used to refer to the packet
once processing is finished.

### `PacketCompletionBuffer`

A buffer of completion data to be sent back to the originating endpoint. Although this usually contains just a status value, the contents are up to the client driver.

### `BufSize`

The size, in bytes, of the completion buffer.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_PACKET_COMPLETE FnVmbChannelPacketComplete;

// Definition

VOID FnVmbChannelPacketComplete
(
	VMBPACKETCOMPLETION PacketCompletionContext
	PVOID PacketCompletionBuffer
	UINT32 BufSize
)
{...}

```

## Remarks

This function is called when the client driver is finished
processing a packet. This function may be called directly from the packet parsing function
or it may be called later.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also