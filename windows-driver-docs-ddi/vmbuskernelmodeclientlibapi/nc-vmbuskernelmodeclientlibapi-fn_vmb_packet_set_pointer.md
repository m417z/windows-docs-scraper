# FN_VMB_PACKET_SET_POINTER callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbPacketSetPointer** function saves an arbitrary pointer in the packet
context.

## Parameters

### `PacketObject`

A handle for a VMBus packet.

### `Pointer`

 An arbitrary pointer to save in the context of the packet.

## Prototype

```cpp
//Declaration

FN_VMB_PACKET_SET_POINTER FnVmbPacketSetPointer;

// Definition

VOID FnVmbPacketSetPointer
(
	VMBPACKET PacketObject
	PVOID Pointer
)
{...}

```

## Remarks

This function is intended to offer a more efficient way to retrieve the context of a client driver.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also