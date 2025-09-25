# EVT_VMB_CHANNEL_STARTED callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The *EvtVmbChannelStarted* callback function is invoked at either endpoint when a channel is
fully configured but before any packets have been delivered. This occurs when the opposite endpoint opened the channel or reopened it after closing it.

## Parameters

### `Channel` [in]

The channel which is started.

## Remarks

After a channel is created, a client driver can specify callback functions for state changes, including *EvtVmbChannelStarted*, by using the [VMB_CHANNEL_STATE_CHANGE_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmb_channel_state_change_callbacks_init) function.

If a paused channel is opened or an opened channel is started, Kernel Mode Client Library (KMCL) calls *EvtVmbChannelStarted* after it calls the [EvtVmbChannelOpened](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_opened) callback. *EvtVmbChannelStarted* can call the [VmbPacketSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsend), [VmbPacketSendWithExternalMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsendwithexternalmdl), and [VmbPacketSendWithExternalPfns](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsendwithexternalpfns) functions
to queue up outgoing packets. Because the incoming queue is not running at this point, this callback must not block on incoming packets or
completions.

Most drivers using KMCL do not implement
this callback. An alternative is the [EvtVmbChannelPostStarted](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_post_started) callback function.

Waiting for a sent packet to complete, such as by the [VmbChannelSendSynchronousRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsendsynchronousrequest) function, never returns because packets are not flowing when this callback is invoked.

## See also

[EvtVmbChannelOpened](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_opened)

[EvtVmbChannelPostStarted](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_post_started)

[VMB_CHANNEL_STATE_CHANGE_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmb_channel_state_change_callbacks_init)

[VmbChannelSendSynchronousRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsendsynchronousrequest)

[VmbPacketSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsend)

[VmbPacketSendWithExternalMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsendwithexternalmdl)

[VmbPacketSendWithExternalPfns](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketsendwithexternalpfns)