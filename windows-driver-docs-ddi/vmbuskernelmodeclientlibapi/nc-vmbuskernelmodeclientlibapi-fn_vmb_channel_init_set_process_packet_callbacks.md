# FN_VMB_CHANNEL_INIT_SET_PROCESS_PACKET_CALLBACKS callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelInitSetProcessPacketCallbacks** function sets callback functions for packet processing.

## Parameters

### `Channel`

A handle for the channel.

### `ProcessPacketCallback`

A callback function to call when a packet is ready for processing.

### `ProcessingCompleteCallback`

A callback function to call when processing of a batch of packets has been completed.

## Return value

**VmbChannelInitSetProcessPacketCallbacks** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function finished successfully. |
| **STATUS_INVALID_PARAMETER_1** | The *Channel* value was invalid or in an invalid state, such as Disabled. |

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_INIT_SET_PROCESS_PACKET_CALLBACKS FnVmbChannelInitSetProcessPacketCallbacks;

// Definition

NTSTATUS FnVmbChannelInitSetProcessPacketCallbacks
(
	VMBCHANNEL Channel
	PFN_VMB_CHANNEL_PROCESS_PACKET ProcessPacketCallback
	PFN_VMB_CHANNEL_PROCESSING_COMPLETE ProcessingCompleteCallback
)
{...}

```

## Remarks

This function is only meaningful if Kernel Mode Client Library (KMCL) queue
management is not suppressed.

**ProcessPacketCallback** is invoked for every packet that
is received. [EvtVmbChannelProcessingComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_processing_complete) will be invoked every time the ring buffer that contains incoming packets transitions from non-empty to empty. This happens
after the last invocation of **ProcessPacketCallback** in a single batch.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[EvtVmbChannelProcessingComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-evt_vmb_channel_processing_complete)

[ProcessPacketCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelinitsetprocesspacketcallbacks)