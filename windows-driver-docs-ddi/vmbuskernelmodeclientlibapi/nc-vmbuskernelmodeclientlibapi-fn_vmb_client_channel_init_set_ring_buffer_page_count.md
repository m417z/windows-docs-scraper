# FN_VMB_CLIENT_CHANNEL_INIT_SET_RING_BUFFER_PAGE_COUNT callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbClientChannelInitSetRingBufferPageCount** function sets the number of pages of memory the client allocates for incoming and outgoing ring
buffers.

## Parameters

### `Channel`

A handle for a channel.

### `IncomingPageCount`

Number of pages to allocate for the incoming ring buffer.

### `OutgoingPageCount`

Number of pages to allocate for the outgoing ring buffer.

## Return value

Returns STATUS_SUCCESS if the operation succeeds, or an appropriate NTSTATUS error code otherwise.

## Prototype

```cpp
//Declaration

FN_VMB_CLIENT_CHANNEL_INIT_SET_RING_BUFFER_PAGE_COUNT FnVmbClientChannelInitSetRingBufferPageCount;

// Definition

NTSTATUS FnVmbClientChannelInitSetRingBufferPageCount
(
	VMBCHANNEL Channel
	UINT32 IncomingPageCount
	UINT32 OutgoingPageCount
)
{...}

```

## Remarks

Because the client virtual machine donates the pages for both the incoming and the outgoing ring
buffers, this function can only be invoked on the client endpoint.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also