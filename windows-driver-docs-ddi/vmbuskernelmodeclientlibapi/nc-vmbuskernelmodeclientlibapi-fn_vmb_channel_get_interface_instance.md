# FN_VMB_CHANNEL_GET_INTERFACE_INSTANCE callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelGetInterfaceInstance** function gets the active interface instance, which is a GUID that uniquely identifies a channel.

## Parameters

### `Channel`

The channel for which to get an instance.

### `InterfaceInstance`

A pointer to a GUID, which is the interface instance
of the channel.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_GET_INTERFACE_INSTANCE FnVmbChannelGetInterfaceInstance;

// Definition

VOID FnVmbChannelGetInterfaceInstance
(
	VMBCHANNEL Channel
	LPGUID InterfaceInstance
)
{...}

```

## Remarks

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also