# FN_VMB_PACKET_RESTORE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbPacketRestore** function restores packet from a buffer that contains saved packet
context.

## Parameters

### `PacketObject`

This is a handle of a VMBus packet.

### `Buffer`

Pointer to buffer that contains previously saved context.

### `BufferSize`

The size, in bytes, of buffer.

## Return value

Returns STATUS_SUCCESS if the operation succeeds, or an appropriate NTSTATUS error code otherwise.

## Prototype

```cpp
//Declaration

FN_VMB_PACKET_RESTORE FnVmbPacketRestore;

// Definition

NTSTATUS FnVmbPacketRestore
(
	__drv_aliasesMem VMBPACKET PacketObject
	PVOID Buffer
	ULONG BufferSize
)
{...}

```

## Remarks

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a server-only function accessed from the [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods) structure.
>
> For more information, see the Remarks section of [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods).

## See also