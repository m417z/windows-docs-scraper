# FN_VMB_SERVER_CHANNEL_INIT_SET_FLAGS callback function

## Description

The **VmbServerChannelInitSetFlags** function sets flags unique to server channel endpoints.

## Parameters

### `Channel`

A handle for a channel.

### `Flags`

A collection of bit flags to set.

## Return value

**VmbServerChannelInitSetFlags** returns the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER_1** | The *Channel* value was invalid or in an invalid state, such as Disabled. |
| **STATUS_INVALID_PARAMETER_2** | The *Flags* value has invalid bits set. |

## Prototype

```cpp
//Declaration

FN_VMB_SERVER_CHANNEL_INIT_SET_FLAGS FnVmbServerChannelInitSetFlags;

// Definition

NTSTATUS FnVmbServerChannelInitSetFlags
(
	VMBCHANNEL Channel
	UINT32 Flags
)
{...}

```

## Remarks

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a server-only function accessed from the [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods) structure.
>
> For more information, see the Remarks section of [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods).

## See also