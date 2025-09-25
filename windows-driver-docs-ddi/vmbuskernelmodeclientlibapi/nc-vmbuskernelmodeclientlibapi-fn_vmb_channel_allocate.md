# FN_VMB_CHANNEL_ALLOCATE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelAllocate** function allocates a new VMBus channel that has default parameters and callbacks.

## Parameters

### `ParentDeviceObject`

A pointer to the parent device.

### `IsServer`

Whether the new channel is a server endpoint.

### `Channel`

A pointer to an allocated channel.

## Return value

Returns STATUS_SUCCESS if the operation succeeds, or an appropriate NTSTATUS error code otherwise.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_ALLOCATE FnVmbChannelAllocate;

// Definition

NTSTATUS FnVmbChannelAllocate
(
	PDEVICE_OBJECT ParentDeviceObject
	BOOLEAN IsServer
	VMBCHANNEL * Channel
)
{...}

```

## Remarks

The
channel may be further initialized using the VMBus channel initialization routines before
it is enabled by using the [VmbChannelEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelenable) function. The channel must be freed by using the [VmbChannelCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelcleanup) function.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[VmbChannelCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelcleanup)

[VmbChannelEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelenable)