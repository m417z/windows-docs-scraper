# EVT_VMB_CHANNEL_POST_STARTED callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The *EvtVmbChannelPostStarted* callback function is invoked at either endpoint after packets can be received from
the opposite endpoint.

## Parameters

### `Channel` [in]

The channel for these endpoints.

## Remarks

After a channel is created, a client driver can specify callback functions for state changes, including *EvtVmbChannelPostStarted*, by using the [VMB_CHANNEL_STATE_CHANGE_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmb_channel_state_change_callbacks_init) function.

After a channel has been
configured, the Kernel Mode Client Library (KMCL) client calls the [VmbChannelEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelenable) function to open the channel. When a channel is opened, KMCL invokes the [EvtVmbChannelOpened](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_opened) callback function. After the channel endpoints can receive packets but before packets are processed, KMCL invokes the *EvtVmbChannelPostStarted* callback.

You can wait for sent packets to complete in this function, such as by using the [VmbChannelSendSynchronousRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsendsynchronousrequest) function.

## See also

[EvtVmbChannelOpened](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_opened)

[EvtVmbChannelPostStarted](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_post_started)

[VMB_CHANNEL_STATE_CHANGE_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmb_channel_state_change_callbacks_init)

[VmbChannelEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelenable)

[VmbChannelSendSynchronousRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsendsynchronousrequest)