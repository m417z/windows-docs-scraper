# EVT_VMB_CHANNEL_CLOSED callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The *EvtVmbChannelClosed* callback function is invoked when the client endpoint in the guest virtual machine closes a
channel by using the [VmbChannelDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchanneldisable) function, or the opposite endpoint rescinds or closes the
channel.

## Parameters

### `Channel` [in]

The channel that the guest virtual machine closes.

## Remarks

After a channel is created, a client driver can specify callback functions for state changes, including *EvtVmbChannelClosed*, by using the [VMB_CHANNEL_STATE_CHANGE_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmb_channel_state_change_callbacks_init) function.

After this callback function finishes on the host, the channel
is either closed or disabled, depending on whether the guest closed
the channel or the Kernel Mode Client Library (KMCL) client called [VmbChannelDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchanneldisable),
respectively.

On the guest, the channel always becomes disabled. It
must be restarted by using the [VmbChannelEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelenable) function.

After this is function invoked, packets can be queued, but they cannot be sent.

## See also

[VMB_CHANNEL_STATE_CHANGE_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmb_channel_state_change_callbacks_init)

[VmbChannelDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchanneldisable)

[VmbChannelEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelenable)