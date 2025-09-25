# FN_VMB_CHANNEL_SEND_SYNCHRONOUS_REQUEST callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelSendSynchronousRequest** function sends a packet to the opposite endpoint and waits for a response.

## Parameters

### `Channel`

A handle for the channel.

### `Buffer`

Data to send.

### `BufferSize`

The size, in bytes, of the data to send.

### `ExternalDataMdl`

A Memory Descriptor List (MDL) that describes an additional buffer to send.

### `Flags`

Standard flags.

### `CompletionBuffer`

Buffer in which to store completion packet results.

### `CompletionBufferSize`

The size, in bytes, of the *CompletionBuffer* value. This value must be rounded up to nearest 8 bytes, or else the function fails. On success,
returns the number of bytes written into *CompletionBuffer*.

### `Timeout`

A timeout in the style of the [KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject) routing.
After this time elapses, the packet is cancelled. For a timeout of zero (0), if a packet does not fir in the ring buffer, it is not queued.

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The functions finished successfully. |
| **STATUS_BUFFER_OVERFLOW** | The packet did not fit in the buffer and was not queued. |
| **STATUS_CANCELLED** | The packet was canceled. |
| **STATUS_DEVICE_REMOVED** | The channel is being shut down. |

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_SEND_SYNCHRONOUS_REQUEST FnVmbChannelSendSynchronousRequest;

// Definition

NTSTATUS FnVmbChannelSendSynchronousRequest
(
	VMBCHANNEL Channel
	PVOID Buffer
	UINT32 BufferSize
	PMDL ExternalDataMdl
	UINT32 Flags
	PVOID CompletionBuffer
	PUINT32 CompletionBufferSize
	PLARGE_INTEGER Timeout
)
{...}

```

## Remarks

Clients can run this function with any combination of parameters.

The root may only call
this if `*Timeout == 0` and the **VMBUS_CHANNEL_FORMAT_FLAG_WAIT_FOR_COMPLETION** flag is not set.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)