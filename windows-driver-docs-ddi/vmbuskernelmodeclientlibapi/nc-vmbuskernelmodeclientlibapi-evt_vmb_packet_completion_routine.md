# EVT_VMB_PACKET_COMPLETION_ROUTINE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The *EvtVmbPacketCompletionRoutine* callback function is invoked when the transaction associated with a sent packet
is complete.

## Parameters

### `Packet` [in]

The packet that is completed.

### `Status` [in]

A status code.

### `Buffer` [in]

A buffer that contains the completion response from the opposite endpoint, if any.

### `BufferLength` [in]

Length of the *Buffer* parameter, in bytes.

## Remarks

After allocating a packet object by using the [VmbPacketAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketallocate) function, the client drive can set a completion callback by using the [VmbPacketSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsetcompletionroutine) function.

If the sender used the VMBUS_CHANNEL_FORMAT_FLAG_WAIT_FOR_COMPLETION
flag, invocation of this callback means that the opposite endpoint received the packet and completed it.
If not, the outgoing packet was successfully placed into the ring buffer.

## See also

[VmbPacketAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketallocate)

[VmbPacketSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsetcompletionroutine)