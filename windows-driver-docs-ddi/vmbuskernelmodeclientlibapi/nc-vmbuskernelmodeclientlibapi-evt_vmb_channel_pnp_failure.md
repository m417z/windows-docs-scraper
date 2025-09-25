# EVT_VMB_CHANNEL_PNP_FAILURE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The *EvtChannelPnpFailure* callback function is invoked if the client endpoint in the
guest virtual machine asynchronously fails to connect even though a
PnP device was located.

## Parameters

### `Channel` [in]

The channel of the client endpoint.

### `FailureStatus` [in]

A failure code.

## Remarks

The [VmbClientChannelInitSetTargetPnp](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbclientchannelinitsettargetpnp) function registers *EvtChannelPnpFailure* code to run in the event of this kind of failure.

## See also

[VmbClientChannelInitSetTargetPnp](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbclientchannelinitsettargetpnp)