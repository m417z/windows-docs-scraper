# FN_VMB_CHANNEL_PAUSE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelPause** function moves a channel into the paused state, which prevents new I/O.

## Parameters

### `Channel`

A handle for the channel to pause.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_PAUSE FnVmbChannelPause;

// Definition

VOID FnVmbChannelPause
(
	VMBCHANNEL Channel
)
{...}

```

## Remarks

This function waits until the channel is in the paused state before it returns. This ensures that all packets that are waiting for completion have completed.

 If the channel is disabled, this function sets the channel to automatically
pause when it is enabled.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also