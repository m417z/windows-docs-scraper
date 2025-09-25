# FN_VMB_CHANNEL_PACKET_FAIL callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelPacketFail** function fails a packet during packet processing due to an unrecoverable error. This function stops the queue.

## Parameters

### `PacketCompletionContext`

A handle that identifies the incoming packet and is used to refer to the packet
once processing is finished.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_PACKET_FAIL FnVmbChannelPacketFail;

// Definition

VOID FnVmbChannelPacketFail
(
	VMBPACKETCOMPLETION PacketCompletionContext
)
{...}

```

## Remarks

Call this function for packets presented to the server endpoint which seem malformed, to
the extent that channel processing should cease.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also