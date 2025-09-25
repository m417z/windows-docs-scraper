# FN_VMB_CHANNEL_INIT_SET_CLIENT_CONTEXT_SIZE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelInitSetClientContextSize** function sets the size of the optional context area allocated for the client driver
on each incoming packet.

## Parameters

### `Channel`

A handle for a channel.

### `ContextSize`

The size of the context area allocated on each packet object.

## Return value

Returns STATUS_SUCCESS if the operation succeeds, or an appropriate NTSTATUS error code otherwise.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_INIT_SET_CLIENT_CONTEXT_SIZE FnVmbChannelInitSetClientContextSize;

// Definition

NTSTATUS FnVmbChannelInitSetClientContextSize
(
	VMBCHANNEL Channel
	UINT32 ContextSize
)
{...}

```

## Remarks

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also