# EVT_VMB_CHANNEL_RESTORE_PACKET callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The *EvtVmbChannelRestorePacket* callback function is invoked when the virtualization service provider (VSP) server
endpoint must restore the state associated with a packet object.

## Parameters

### `Channel` [in]

The channel on which the packet arrives.

### `LibBuf` [in]

Pointer to packet object state internal to the Kernel Mode Client Library (KMCL).

### `LibBufSize` [in]

Size of the *LibBuf* parameter, in bytes.

### `SaveBuf` [in]

Pointer to transaction state specific to the VSP.

### `SaveBufSize` [in]

Size of the *SaveBuf* parameter, in bytes.

## Return value

*EvtVmbChannelRestorePacket* returns a status code.

## Remarks

The [VmbServerChannelInitSetSaveRestorePacketCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbserverchannelinitsetsaverestorepacketcallbacks) function sets a callback function for restoring packets for each channel.

In order
to restore an in-flight packet object, the VSP must allocate a new packet
by using the [VmbPacketAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketallocate) function. The VSP restores the packet to the previous state by passing *LibBuf* and *LibBufSize* to the [VmbPacketRestore](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketrestore) function.
If the VSP provided any internal state for the transaction in the *EvtVmbChannelSavePacket*
callback function, then this is provided in *SaveBuf*, and restored by the VSP.

## See also

[EvtVmbChannelSavePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_restore_packet)

[VmbPacketAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketallocate)

[VmbPacketRestore](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketrestore)

[VmbServerChannelInitSetSaveRestorePacketCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbserverchannelinitsetsaverestorepacketcallbacks)