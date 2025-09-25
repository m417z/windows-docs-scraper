# FN_VMB_CHANNEL_INIT_SET_STATE_CHANGE_CALLBACKS callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelInitSetStateChangeCallbacks** function sets optional callback functions for state changes.

## Parameters

### `Channel`

A handle for a channel.

### `StateChangeCallbacks`

A structure of state change callbacks to set.

## Return value

**VmbChannelInitSetStateChangeCallbacks** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function finished successfully. |
| **STATUS_INVALID_PARAMETER_1** | The *Channel* value was invalid or in an invalid state, such as Disabled. |
| **STATUS_INVALID_PARAMETER_2** | The *StateChangeCallbacks* value is the wrong version or size. |

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_INIT_SET_STATE_CHANGE_CALLBACKS FnVmbChannelInitSetStateChangeCallbacks;

// Definition

NTSTATUS FnVmbChannelInitSetStateChangeCallbacks
(
	VMBCHANNEL Channel
	PVMB_CHANNEL_STATE_CHANGE_CALLBACKS StateChangeCallbacks
)
{...}

```

## Remarks

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also