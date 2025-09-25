# FN_VMB_CHANNEL_SAVE_CONTINUE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelSaveContinue** function saves the channel state to a buffer. Run the [VmbChannelSaveBegin](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsavebegin) before you run this function. The driver must check the return value of the function.

## Parameters

### `Channel`

A handle for a channel to save.

### `SaveBuffer`

A pointer to the buffer into which to save state information.

### `SaveBufferSize`

The size, in bytes, of the save buffer.

### `BytesFilled`

A pointer to a variable that receives the number of bytes
that were copied to the save buffer.

### `BytesRequired`

A pointer to a variable that receives the number of
bytes that are needed for this function to make progress on the next
call.

## Return value

**VmbChannelSaveContinue** returns the following values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The state was saved. |
| **STATUS_BUFFER_TOO_SMALL** | The save buffer was too small. The *BytesNeeded* parameter contains the number of bytes that are required to make any progress. |
| **STATUS_STATUS_BUFFER_OVERFLOW** | Some data was written to the save buffer, but there is more data to be saved. |

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_SAVE_CONTINUE FnVmbChannelSaveContinue;

// Definition

NTSTATUS FnVmbChannelSaveContinue
(
	VMBCHANNEL Channel
	PVOID SaveBuffer
	ULONG SaveBufferSize
	PULONG BytesFilled
	PULONG BytesRequired
)
{...}

```

## Remarks

The save process saves
the data in "chunks" and can continue from the point it stopped.

If the caller did not allocate enough space in advance, multiple calls may be needed.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a server-only function accessed from the [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods) structure.
>
> For more information, see the Remarks section of [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods).

## See also

[VmbChannelSaveBegin](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsavebegin)