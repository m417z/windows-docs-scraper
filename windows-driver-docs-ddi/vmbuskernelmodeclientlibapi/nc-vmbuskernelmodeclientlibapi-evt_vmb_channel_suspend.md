# EVT_VMB_CHANNEL_SUSPEND callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The *EvtVmbChannelSuspend* callback function is invoked at the server endpoint when the channel is being
closed or deleted by the client endpoint, which moves the server into the Stopped
state.

## Parameters

### `Channel` [in]

The channel which is suspended.

## Remarks

After a channel is created, a client driver can specify callback functions for state changes, including *EvtVmbChannelSuspend*, by using the [VMB_CHANNEL_STATE_CHANGE_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmb_channel_state_change_callbacks_init) function.

If a running channel is suspended by using the [VmbChannelPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelpause) function or closed by using the [VmbChannelDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchanneldisable) function or by the opposite endpoint, Kernel Mode Client Library (KMCL) calls *EvtVmbChannelSuspend*. This callback guarantees that no more
[EvtVmbChannelProcessPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_process_packet) callbacks are running or will be queued.

*EvtVmbChannelSuspend* is also a
notification that the KMCL client must eventually complete all outstanding
packets indicated by using [EvtVmbChannelProcessPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_process_packet) These packets do
not have to be completed synchronously. KMCL blocks until they have
been completed.

The KMCL client must also stop sending packets by using the [VmbPacketSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsend), [VmbPacketSendWithExternalMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsendwithexternalmdl), or [VmbPacketSendWithExternalPfns](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsendwithexternalpfns) functions.

A call to [VmbChannelPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelpause) on an active channel blocks until
*EvtVmbChannelSuspend* is called and no more outstanding incoming packets exist.
A call to [VmbChannelDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchanneldisable) block until the channel is paused and closed.

This function does guarantee completion of outstanding transactions. The client may be buggy, malicious,
or the guest virtual machine may have crashed. The server must retire any outstanding transactions, probably by cancelling them.

## See also

[EvtVmbChannelProcessPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_process_packet)

[VMB_CHANNEL_STATE_CHANGE_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmb_channel_state_change_callbacks_init)

[VmbChannelDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchanneldisable)

[VmbChannelPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelpause)

[VmbPacketSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsend)

[VmbPacketSendWithExternalMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsendwithexternalmdl)

[VmbPacketSendWithExternalPfns](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsendwithexternalpfns)