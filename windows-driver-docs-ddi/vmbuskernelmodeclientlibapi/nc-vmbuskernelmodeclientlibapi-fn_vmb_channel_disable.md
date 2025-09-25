# FN_VMB_CHANNEL_DISABLE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelDisable** function disables a channel, which closes it for client channels and revokes the channel offer for server channels. This function waits until the channel is completely torn down
before it returns.

## Parameters

### `Channel`

The handle of a channel to disable.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_DISABLE FnVmbChannelDisable;

// Definition

VOID FnVmbChannelDisable
(
	VMBCHANNEL Channel
)
{...}

```

## Remarks

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also