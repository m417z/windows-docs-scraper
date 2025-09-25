# FN_VMB_SERVER_CHANNEL_INIT_SET_TARGET_INTERFACE_ID callback function

## Description

The **VmbServerChannelInitSetTargetInterfaceId** function sets the target interface type GUID and instance GUID of the channel offer.

## Parameters

### `Channel`

A handle for a channel.

### `InterfaceType`

A pointer to the interface type GUID.

### `InterfaceInstance`

A pointer to the instance type GUID.

## Return value

Returns STATUS_SUCCESS if the operation is successful. Otherwise, returns an appropriate NTSTATUS error code.

## Prototype

```cpp
//Declaration

FN_VMB_SERVER_CHANNEL_INIT_SET_TARGET_INTERFACE_ID FnVmbServerChannelInitSetTargetInterfaceId;

// Definition

NTSTATUS FnVmbServerChannelInitSetTargetInterfaceId
(
	VMBCHANNEL Channel
	GUID InterfaceType
	GUID InterfaceInstance
)
{...}

```

## Remarks

The *InterfaceType*
GUID identifies the type of channel and, specifically, the protocol that is used with
the channel. If the VMBus in the child partition is creating a Physical Device Object
(PDO) that is associated with this channel, this GUID is the basis of the PDO's hardware
ID reported to the PnP Manager.

The *InterfaceInstance* GUID identifies a specific instance
of the service. For instance, If you have two paravirtual network interfaces, they
have the same interface type, but different interface instance values.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a server-only function accessed from the [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods) structure.
>
> For more information, see the Remarks section of [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods).

## See also