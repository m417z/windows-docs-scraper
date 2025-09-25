# FN_VMB_PACKET_ALLOCATE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbPacketAllocate** function allocates a packet from the channel's lookaside list.

## Parameters

### `Channel`

A handle for a channel.

## Return value

**VmbPacketAllocate** returns a pointer to an allocated VMBus packet object or null.

## Prototype

```cpp
//Declaration

FN_VMB_PACKET_ALLOCATE FnVmbPacketAllocate;

// Definition

VMBPACKET FnVmbPacketAllocate
(
	VMBCHANNEL Channel
)
{...}

```

## Remarks

The default completion routine of a packet automatically releases the packet.
If the packet is not sent or if the completion routine is changed, the
client should call the [VmbPacketFree](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketfree) function to release the packet.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[VmbPacketFree](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketfree)