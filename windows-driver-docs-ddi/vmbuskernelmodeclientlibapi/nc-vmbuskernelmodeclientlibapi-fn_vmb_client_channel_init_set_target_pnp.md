# FN_VMB_CLIENT_CHANNEL_INIT_SET_TARGET_PNP callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbClientChannelInitSetTargetPnp** function sets a client channel's target by interface type and instance IDs. If this
function is called, Kernel Mode Client Library (KMCL) uses PnP to find the VMBus Physical Device Object (PDO) that corresponds to the
provided interface.

## Parameters

### `Channel`

A pointer to a channel.

### `InterfaceType`

A pointer to the interface type GUID.
This GUID identifies the
type of channel and the protocol that is used with the channel.

### `InterfaceInstance`

A pointer to the instance type GUID. This is a
specific instance of the service. If not
provided, any instance with the provided type is accepted.

### `PnpFailureCallback`

A pointer to an event callback to call if the
device asynchronously fails to connect even though the PnP device was
located.

## Return value

**VmbClientChannelInitSetTargetPnp** returns the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER_1** | The *Channel* value was invalid or in an invalid state, such as Disabled. |

## Prototype

```cpp
//Declaration

FN_VMB_CLIENT_CHANNEL_INIT_SET_TARGET_PNP FnVmbClientChannelInitSetTargetPnp;

// Definition

NTSTATUS FnVmbClientChannelInitSetTargetPnp
(
	VMBCHANNEL Channel
	LPCGUID InterfaceType
	LPCGUID InterfaceInstance
	PFN_VMB_CHANNEL_PNP_FAILURE PnpFailureCallback
)
{...}

```

## Remarks

If you
have two paravirtual network interfaces, they will have the
same *InterfaceType* but different *InterfaceInstance* values.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also