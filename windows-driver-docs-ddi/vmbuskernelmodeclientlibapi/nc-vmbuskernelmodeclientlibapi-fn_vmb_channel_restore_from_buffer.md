# FN_VMB_CHANNEL_RESTORE_FROM_BUFFER callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelRestoreFromBuffer** function restores the client state from previously saved state.
The driver must check the return value of the function.

## Parameters

### `Channel`

 A handle for a channel.

### `Buffer`

A pointer to a buffer that contains previously saved state.

### `BufferSize`

The size, in bytes, of the buffer.

## Return value

**VmbChannelRestoreFromBuffer** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function finished successfully. |
| **STATUS_MORE_PROCESSING_REQUIRED** | State was restored successfully, but more chunks were saved. |
| **Other status code for which NT_SUCCESS is FALSE** | The function failed. |

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_RESTORE_FROM_BUFFER FnVmbChannelRestoreFromBuffer;

// Definition

NTSTATUS FnVmbChannelRestoreFromBuffer
(
	VMBCHANNEL Channel
	PVOID Buffer
	ULONG BufferSize
)
{...}

```

## Remarks

The caller is expected to call this function with buffers that contain whole
"chunks" of stored data.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a server-only function accessed from the [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods) structure.
>
> For more information, see the Remarks section of [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods).

## See also