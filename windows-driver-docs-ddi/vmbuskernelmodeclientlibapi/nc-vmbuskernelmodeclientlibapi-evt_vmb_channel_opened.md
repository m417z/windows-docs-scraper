# EVT_VMB_CHANNEL_OPENED callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The *EvtVmbChannelOpened* callback function is invoked when the client endpoint in the guest virtual machine opens a
channel which has been offered to it.

## Parameters

### `Channel` [in]

The channel that the guest virtual machine opens.

## Return value

EvtVmbChannelClosed returns a status code.

## Remarks

After a channel is created, a client driver can specify callback functions for state changes, including *EvtVmbChannelOpened*, by using the [VMB_CHANNEL_STATE_CHANGE_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmb_channel_state_change_callbacks_init) function.

After a channel has been
configured, the Kernel Mode Client Library (KMCL) client calls the [VmbChannelEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelenable) function. On the host, this
function offers a channel to the guest. On the guest, this function
accepts an existing offer or waits for such an offer to arrive. When a channel is opened, KMCL invokes the *EvtVmbChannelOpened* callback function.
After this callback finishes, the channel
is in the open state.

 Before this callback function is invoked, packets can
be queued, but they cannot be sent.

If the client driver returns a failure status code, the channel
rolls back to a state where no traffic flows.

## See also

[VMB_CHANNEL_STATE_CHANGE_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmb_channel_state_change_callbacks_init)

[VmbChannelEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelenable)