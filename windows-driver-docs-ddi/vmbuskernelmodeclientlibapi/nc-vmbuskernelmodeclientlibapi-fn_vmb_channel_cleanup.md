# FN_VMB_CHANNEL_CLEANUP callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelCleanup** function disposes of a channel that was allocated by using the [VmbChannelAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelallocate) function or initialized by using a VMBus channel initialization function.

## Parameters

### `Channel`

The channel to clean up.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_CLEANUP FnVmbChannelCleanup;

// Definition

VOID FnVmbChannelCleanup
(
	__drv_freesMem(Mem)VMBCHANNEL Channel
)
{...}

```

## Remarks

If the channel was allocated by [VmbChannelAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelallocate), **VmbChannelCleanup** also releases the channel.

Before you call this function, the channel must be disabled.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[VmbChannelAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelallocate)