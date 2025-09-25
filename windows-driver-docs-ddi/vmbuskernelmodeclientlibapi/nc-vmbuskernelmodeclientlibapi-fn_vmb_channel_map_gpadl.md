# FN_VMB_CHANNEL_MAP_GPADL callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelMapGpadl** function maps a client-side buffer into server-side physical address space by using a Guest Physical Address Descriptor List (GPADL) number.

## Parameters

### `Channel`

A handle for a channel.

### `Flags`

Flags. The possible flag values are:

| Value | Meaning |
| --- | --- |
| **VMBUS_CHANNEL_GPADL_FLAG_READ_ONLY** | Map with read-only access. |

If
this flag value is not set, the function tries to map the GPADL for write access. If the GPADL was not
created with write access, this mapping attempt fails. The
caller is not prevented from writing to the buffer if this flag is set. This scheme is used to improve the performance of live migration
and snapshotting.

### `GpadlHandle`

The GPADL handle of the GPADL to map.

### `Mdl:`

 A pointer to a MDL describing the client buffer. This
buffer is only mapped into physical address space. The caller must take
additional steps to map it into virtual address space.

## Return value

Returns STATUS_SUCCESS if the operation succeeds, or an appropriate NTSTATUS error code otherwise.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_MAP_GPADL FnVmbChannelMapGpadl;

// Definition

NTSTATUS FnVmbChannelMapGpadl
(
	VMBCHANNEL Channel
	UINT32 Flags
	UINT32 GpadlHandle
	PMDL *Mdl
)
{...}

```

## Remarks

The GPADL must have been pre-established by the client, for instance, by using the [VmbChannelCreateGpadlFromBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelcreategpadlfrombuffer) function.

Only a single mapping may exist for any given GPADL at a time.

You must pair calls to this
function with calls to the [VmbChannelUnmapGpadl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelunmapgpadl) function.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a server-only function accessed from the [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods) structure.
>
> For more information, see the Remarks section of [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods).

## See also

[VmbChannelCreateGpadlFromBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelcreategpadlfrombuffer)

[VmbChannelUnmapGpadl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelunmapgpadl)