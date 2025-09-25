# FN_VMB_CHANNEL_DELETE_GPADL callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelDeleteGpadl** function deletes a Guest Physical Address Descriptor List (GPADL) mapped by the [VmbChannelCreateGpadlFromMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelcreategpadlfrommdl) or
[VmbChannelCreateGpadlFromBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelcreategpadlfrombuffer) functions. If the GPADL is currently mapped to the server, this function is blocked until the GPADL is unmapped.

## Parameters

### `Channel`

A handle for a channel.

### `GpadlHandle`

The GPADL handle of the GPADL to delete.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_DELETE_GPADL FnVmbChannelDeleteGpadl;

// Definition

VOID FnVmbChannelDeleteGpadl
(
	VMBCHANNEL Channel
	UINT32 GpadlHandle
)
{...}

```

## Remarks

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[VmbChannelCreateGpadlFromBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelcreategpadlfrombuffer)

[VmbChannelCreateGpadlFromMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelcreategpadlfrommdl)