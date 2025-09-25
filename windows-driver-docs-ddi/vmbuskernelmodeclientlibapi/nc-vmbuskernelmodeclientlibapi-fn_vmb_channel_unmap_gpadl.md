# FN_VMB_CHANNEL_UNMAP_GPADL callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelUnmapGpadl** function unmaps a Guest Physical Address Descriptor List (GPADL) mapped using by the [VmbChannelMapGpadl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelmapgpadl) function. The buffer must no longer be in
use by the server before this function is called.

## Parameters

### `Channel`

A handle for a channel.

### `GpadlHandle`

The handle of the GPADL to unmap.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_UNMAP_GPADL FnVmbChannelUnmapGpadl;

// Definition

VOID FnVmbChannelUnmapGpadl
(
	VMBCHANNEL Channel
	UINT32 GpadlHandle
)
{...}

```

## Remarks

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a server-only function accessed from the [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods) structure.
>
> For more information, see the Remarks section of [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods).

## See also

[VmbChannelMapGpadl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelmapgpadl)