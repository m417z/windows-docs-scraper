# FN_VMB_PACKET_SEND_WITH_EXTERNAL_PFNS callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbPacketSendWithExternalPfns** function sends the data in a packet buffer or external data as an array of Page Frame Numbers (PFNs). The function associates that data with the VMBus packet object, which represents the packet
throughout the lifetime of the transaction.

## Parameters

### `PacketObject`

A handle to the VMBus packet object.

### `Buffer`

A buffer that contains the command packet that is sent
through the VMBus ring buffer.

### `BufferLength`

The length, in bytes, of the buffer in the *Buffer* parameter.

### `ExternalDataPfns`

An array of Page Frame
Numbers that describe a data buffer associated with
the packet.

### `PfnLength`

The number of PFNs to send from
*ExternalDataPfns*. The final referenced array index is `ExternalDataPfns[PfnOffset+PfnLength-1]` inclusive.

### `Flags`

Flags. The following are pertinent flags:

| Value | Meaning |
| --- | --- |
| **VMBUS_CHANNEL_FORMAT_FLAG_WAIT_FOR_COMPLETION** | This packet cannot be considered complete and its resources cannot be released until a completion packet comes back from the opposite endpoint. This flag must be set. |
| **VMBUS_CHANNEL_FORMAT_FLAG_PAGED_BUFFER** | The inline buffer is paged and must be treated accordingly, which means it must be copied before entering DPC level. Probing user-mode buffers or handling access violations is the responsibility of the caller. |

## Return value

Returns STATUS_SUCCESS if the operation succeeds, or an appropriate NTSTATUS error code otherwise.

## Prototype

```cpp
//Declaration

FN_VMB_PACKET_SEND_WITH_EXTERNAL_PFNS FnVmbPacketSendWithExternalPfns;

// Definition

NTSTATUS FnVmbPacketSendWithExternalPfns
(
	__drv_aliasesMem VMBPACKET PacketObject
	PVOID Buffer
	UINT32 BufferLength
	PPFN_NUMBER ExternalDataPfns
	UINT32 PfnLength
	UINT32 Flags
)
{...}

```

## Remarks

This function differs from the [VmbPacketSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsend) function in that it allows passing an array of PFNs, effectively physical addresses.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[VmbPacketSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsend)