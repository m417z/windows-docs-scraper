# FN_VMB_CHANNEL_CREATE_GPADL_FROM_MDL callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelCreateGpadlFromMdl** function creates a Guest Physical Address Descriptor List (GPADL) that describes a client-side buffer. The GPADL can be used
in the server to access the buffer.

## Parameters

### `Channel`

A handle for a channel.

### `Flags`

Flags. The possible values are the following:

| Value | Meaning |
| --- | --- |
| **VMBUS_CHANNEL_GPADL_READ_ONLY** | If you specify this value, the buffer is read-only. Otherwise, the server can write to the buffer. This is not a security measure, but can improve snapshot and live migration performance. |

### `Mdl`

A pointer to a Memory Descriptor List (MDL) chain that describes the buffer. The buffer may
have multiple pieces, which are chained by using the MDL next pointer.

### `StartOffsetWithinMdl`

An offset, in bytes, in the MDL at which to start the mapping.

### `DataLengthWithinMdl`

The length, in bytes, of the buffer chain. If this value is zero (0),
use until the end of the MDL.

### `GpadlHandle`

The GPADL handle of the created MDL. Send this to the server to use with the [VmbChannelMapGpadl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelmapgpadl) function.

## Return value

Returns STATUS_SUCCESS if the operation succeeds, or an appropriate NTSTATUS error code otherwise.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_CREATE_GPADL_FROM_MDL FnVmbChannelCreateGpadlFromMdl;

// Definition

NTSTATUS FnVmbChannelCreateGpadlFromMdl
(
	VMBCHANNEL Channel
	UINT32 Flags
	PMDL Mdl
	UINT32 StartOffsetWithinMdl
	UINT32 DataLengthWithinMdl
	PUINT32 GpadlHandle
)
{...}

```

## Remarks

When this function returns, the server
endpoint can call [VmbChannelMapGpadl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelmapgpadl), because VMBus will already have send
the GPADL description to the opposite endpoint and received confirmation.

 The GPADL must be deleted by using the [VmbChannelDeleteGpadl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchanneldeletegpadl) function.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[VmbChannelDeleteGpadl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchanneldeletegpadl)

[VmbChannelMapGpadl](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelmapgpadl)