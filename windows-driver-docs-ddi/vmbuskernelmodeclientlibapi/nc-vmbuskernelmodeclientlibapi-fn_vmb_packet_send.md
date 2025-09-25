# FN_VMB_PACKET_SEND callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbPacketSend** function sends the data in a packet buffer or external data Memory Descriptor List (MDL). The function associates that data with the VMBus packet object, which represents the packet
throughout the lifetime of the transaction.

## Parameters

### `PacketObject`

A handle to the VMBus packet object.

### `Buffer`

A buffer that contains the command packet that is sent
through the VMBus ring buffer.

### `BufferLength`

The length, in bytes, of the buffer in the *Buffer* parameter.

### `ExternalDataMdl`

An MDL that describes a data buffer associated with the packet.

### `Flags`

Flags. The following are pertinent flags:

| Value | Meaning |
| --- | --- |
| **VMBUS_CHANNEL_FORMAT_FLAG_WAIT_FOR_COMPLETION** | This packet cannot be considered complete and its resources cannot be released until a completion packet comes back from the opposite endpoint. |
| **VMBUS_CHANNEL_FORMAT_FLAG_PAGED_BUFFER** | The inline buffer is paged and must be treated accordingly, which means it must be copied before entering DPC level. Probing user-mode buffers or handling access violations is the responsibility of the caller. |

## Return value

Returns STATUS_SUCCESS if the operation succeeds, or an appropriate NTSTATUS error code otherwise.

## Prototype

```cpp
//Declaration

FN_VMB_PACKET_SEND FnVmbPacketSend;

// Definition

NTSTATUS FnVmbPacketSend
(
	__drv_aliasesMem VMBPACKET PacketObject
	PVOID Buffer
	UINT32 BufferLength
	PMDL ExternalDataMdl
	UINT32 Flags
)
{...}

```

## Remarks

For information on other ways to send packets, see the [VmbPacketSendWithExternalMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsendwithexternalmdl), [VmbChannelSendSynchronousRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsendsynchronousrequest), and [VmbPacketSendWithExternalPfns](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsendwithexternalpfns) functions.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[VmbChannelSendSynchronousRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsendsynchronousrequest)

[VmbPacketSendWithExternalMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsendwithexternalmdl)

[VmbPacketSendWithExternalPfns](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsendwithexternalpfns)