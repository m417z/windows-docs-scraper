# FN_VMB_CHANNEL_INIT_SET_MAXIMUM_PACKET_SIZE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelInitSetMaximumPacketSize** function sets the maximum packet size that can be delivered through a channel, which is the maximum size that will ever be specified by the [VmbPacketSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsend) function.

## Parameters

### `Channel`

A handle for the channel.

### `PacketSize`

Maximum size, in bytes, of a packet.

## Return value

**VmbChannelInitSetMaximumPacketSize** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function finished successfully. |
| **STATUS_INVALID_PARAMETER_1** | The *Channel* value was invalid or in an invalid state, such as Disabled. |
| **STATUS_INVALID_PARAMETER_2** | The *PacketSize* value is invalid. Zero (0) is invalid. |

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_INIT_SET_MAXIMUM_PACKET_SIZE FnVmbChannelInitSetMaximumPacketSize;

// Definition

NTSTATUS FnVmbChannelInitSetMaximumPacketSize
(
	VMBCHANNEL Channel
	UINT32 PacketSize
)
{...}

```

## Remarks

This function can only be called during channel initialization.

The size of the ring buffers is, in part, based on this maximum packet size.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[VmbPacketSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsend)