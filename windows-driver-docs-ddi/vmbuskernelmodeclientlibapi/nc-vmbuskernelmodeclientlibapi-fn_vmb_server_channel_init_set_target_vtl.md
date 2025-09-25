# FN_VMB_SERVER_CHANNEL_INIT_SET_TARGET_VTL callback function

## Description

The **VmbServerChannelInitSetTargetVtl** function sets the target VTL for this channel. The channel will be offered to clients running in the specified VTL and no others.

## Parameters

### `Channel`

A handle for the channel. Allocated by [**VmbChannelAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_allocate).

### `TargetVtl`

The VTL level where this channel will be offered.

## Return value

**VmbServerChannelInitSetTargetVtl** returns the following status values:

| Return code | Description |
| --- | --- |
| STATUS_INVALID_PARAMETER_1 | The **Channel** parameter was invalid or in an invalid state (Disabled).
| STATUS_INVALID_PARAMETER_2 | **TargetVtl** is invalid. |

## Prototype

```cpp
//Declaration

FN_VMB_SERVER_CHANNEL_INIT_SET_TARGET_VTL FnVmbServerChannelInitSetTargetVtl;

// Definition

NTSTATUS FnVmbServerChannelInitSetTargetVtl
(
	VMBCHANNEL Channel
	UINT8 TargetVtl
)
{...}

```

## Remarks

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a server-only function accessed from the [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods) structure.
>
> For more information, see the Remarks section of [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods).

## See also

[**VmbChannelAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nc-vmbuskernelmodeclientlibapi-fn_vmb_channel_allocate)