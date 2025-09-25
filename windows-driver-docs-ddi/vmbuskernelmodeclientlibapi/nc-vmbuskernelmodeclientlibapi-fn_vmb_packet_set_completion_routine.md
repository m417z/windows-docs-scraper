# FN_VMB_PACKET_SET_COMPLETION_ROUTINE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbPacketSetCompletionRoutine** function sets the completion routine for a packet object.

## Parameters

### `PacketObject`

The packet for which to specify a completion routine.

### `CompletionRoutine`

Function to call when the packet is completed.

## Prototype

```cpp
//Declaration

FN_VMB_PACKET_SET_COMPLETION_ROUTINE FnVmbPacketSetCompletionRoutine;

// Definition

VOID FnVmbPacketSetCompletionRoutine
(
	VMBPACKET PacketObject
	PFN_VMB_PACKET_COMPLETION_ROUTINE CompletionRoutine
)
{...}

```

## Remarks

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[EvtVmbPacketCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_packet_completion_routine)

[VmbPacketSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsend)

[VmbPacketSendWithExternalMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsendwithexternalmdl)

[VmbPacketSendWithExternalPfns](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsendwithexternalpfns)