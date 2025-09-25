# FN_VMB_PACKET_INITIALIZE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbPacketInitialize** function initializes a buffer to contain a VMBus packet.

## Parameters

### `Channel`

A handle for a channel.

### `VmbPacket`

The buffer to use to store the VMBus packet.

### `ByteCount`

The size of *Buffer*, in bytes.

## Return value

**VmbPacketInitialize** returns the following status codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function finished successfully. |
| **STATUS_INVALID_PARAMETER_3** | The value of *ByteCount* is not valid. It needs to be greater than the maximum packet size plus the size of a void pointer. |

## Prototype

```cpp
//Declaration

FN_VMB_PACKET_INITIALIZE FnVmbPacketInitialize;

// Definition

NTSTATUS FnVmbPacketInitialize
(
	VMBCHANNEL Channel
	VMBPACKET VmbPacket
	UINT32 ByteCount
)
{...}

```

## Remarks

The size of the buffer must be at
least the size calculated by using the [VmbChannelSizeofPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsizeofpacket) function.

**VmbPacketInitialize** is an alternative
to the [VmbPacketAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketallocate) function. Use the current function if the caller supplies the
memory for the packet object.

The packet's initial completion routine is invalid and must be set before
sending the packet.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also

[VmbChannelSizeofPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsizeofpacket)

[VmbPacketAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbpacketallocate)