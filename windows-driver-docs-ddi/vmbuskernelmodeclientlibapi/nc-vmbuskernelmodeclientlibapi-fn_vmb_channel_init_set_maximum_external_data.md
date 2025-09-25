# FN_VMB_CHANNEL_INIT_SET_MAXIMUM_EXTERNAL_DATA callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelInitSetMaximumExternalData** function sets the maximum size and chain length of data that is described by a
packet, but not directly sent in the packet. That is, the maximum size of the
buffer described by an **ExternalDataMdl**.

## Parameters

### `Channel`

A pointer to a Kernel Mode Client Library (KMCL) channel.

### `DataSize`

The maximum size of external data.

### `ChainLength`

The maximum number of Memory Descriptor Lists (MDLs) in an incoming MDL chain.

## Return value

**VmbChannelInitSetMaximumExternalData** can return one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function finished successfully. |
| **STATUS_INVALID_PARAMETER_1** | The *Channel* value was invalid or in an invalid state, such as Disabled. |
| **STATUS_INVALID_PARAMETER_2** | The *DataSize* value is invalid. Zero (0) is invalid. |
| **STATUS_INVALID_PARAMETER_3** | The *ChainLength* value is invalid. Zero (0) is invalid. |

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_INIT_SET_MAXIMUM_EXTERNAL_DATA FnVmbChannelInitSetMaximumExternalData;

// Definition

NTSTATUS FnVmbChannelInitSetMaximumExternalData
(
	VMBCHANNEL Channel
	UINT32 DataSize
	UINT32 ChainLength
)
{...}

```

## Remarks

The KMCL ensures that your ring buffers are large enough to send packets that contain buffers in the specified limits.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also