# FN_VMB_PACKET_GET_POINTER callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbPacketGetPointer** function retrieves a pointer that was previously
saved by using the [VmbPacketSetPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsetpointer) function.

## Parameters

### `PacketObject`

The handle of a packet object.

## Return value

**VmbPacketGetPointer** returns the value previously saved by using [VmbPacketSetPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsetpointer).

## Prototype

```cpp
//Declaration

FN_VMB_PACKET_GET_POINTER FnVmbPacketGetPointer;

// Definition

PVOID FnVmbPacketGetPointer
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

[VmbPacketSetPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsetpointer)