# FN_VMB_CHANNEL_SET_INTERRUPT_LATENCY callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

Guest VM updates to the outgoing monitor latency for MNF interrupts.

## Parameters

### `Channel`

A handle for the channel. Allocated by [**VmbChannelAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_allocate).

### `Latency`

The desired monitor latency in 100ns units.

### `OriginalLatency`

On success, set to the previous latency value.

## Return value

Returns STATUS_SUCCESS if the operation succeeds, or an appropriate NTSTATUS error code otherwise.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_SET_INTERRUPT_LATENCY FnVmbChannelSetInterruptLatency;

// Definition

NTSTATUS FnVmbChannelSetInterruptLatency
(
	VMBCHANNEL Channel
	UINT16 Latency
	PUINT16 OriginalLatency
)
{...}

```

## Remarks

This call is valid for opened channels, that is between the calls to [*EvtChannelOpened*](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_opened) and [*EvtChannelClosed*](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_closed), inclusive.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also