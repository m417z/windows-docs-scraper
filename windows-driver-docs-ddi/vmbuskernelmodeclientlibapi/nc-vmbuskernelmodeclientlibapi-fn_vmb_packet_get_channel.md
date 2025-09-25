# FN_VMB_PACKET_GET_CHANNEL callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbPacketGetChannel** function returns the VMBus channel with which a VMBus packet is associated.

## Parameters

### `PacketObject`

The packet object.

## Return value

**VmbPacketGetChannel** returns a handle of the associated channel.

## Prototype

```cpp
//Declaration

FN_VMB_PACKET_GET_CHANNEL FnVmbPacketGetChannel;

// Definition

VMBCHANNEL FnVmbPacketGetChannel
(
	VMBPACKET PacketObject
)
{...}

```

## Remarks

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also