# FN_VMB_CHANNEL_SET_INCOMING_PROCESSING_AT_PASSIVE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelSetIncomingProcessingAtPassive** function sets the required IRQL for incoming parsing routines for a channel to
PASSIVE_LEVEL.

## Parameters

### `Channel`

A handle for a channel.

### `RequirePassive`

If true, the channel requires PASSIVE_LEVEL. If false, packets may arrive at either DISPATCH_LEVEL or PASSIVE_LEVEL.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_SET_INCOMING_PROCESSING_AT_PASSIVE FnVmbChannelSetIncomingProcessingAtPassive;

// Definition

VOID FnVmbChannelSetIncomingProcessingAtPassive
(
	VMBCHANNEL Channel
	BOOLEAN RequirePassive
)
{...}

```

## Remarks

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also