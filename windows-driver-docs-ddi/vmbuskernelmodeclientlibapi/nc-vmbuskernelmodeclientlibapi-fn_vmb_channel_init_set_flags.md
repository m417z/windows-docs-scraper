# FN_VMB_CHANNEL_INIT_SET_FLAGS callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelInitSetFlags** function sets flags common to server or client channel endpoints.

## Parameters

### `Channel`

A handle for the channel.

### `Flags`

A collection of bit flags to set.

## Return value

**VmbChannelInitSetFlags** can return one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER_1** | The *Channel* value was invalid or in an invalid state, such as Disabled. |
| **STATUS_INVALID_PARAMETER_2** | The value in *Flags* has invalid bits. |

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_INIT_SET_FLAGS FnVmbChannelInitSetFlags;

// Definition

NTSTATUS FnVmbChannelInitSetFlags
(
	VMBCHANNEL Channel
	UINT32 Flags
)
{...}

```

## Remarks

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also