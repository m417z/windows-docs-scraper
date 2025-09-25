# FN_VMB_CHANNEL_INIT_SET_FRIENDLY_NAME callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The **VmbChannelInitSetFriendlyName** function sets the friendly name of the Kernel Mode Client Library (KMCL) channel. The friendly name is used for debugging and
performance counter instance naming.

## Parameters

### `Channel`

A handle for the channel to name.

### `Name:`

The new friendly name of the channel.

## Return value

Returns STATUS_SUCCESS if the operation succeeds, or an appropriate NTSTATUS error code otherwise.

## Prototype

```cpp
//Declaration

FN_VMB_CHANNEL_INIT_SET_FRIENDLY_NAME FnVmbChannelInitSetFriendlyName;

// Definition

NTSTATUS FnVmbChannelInitSetFriendlyName
(
	VMBCHANNEL Channel
	PCUNICODE_STRING Name
)
{...}

```

## Remarks

Channel names should be descriptive, yet
relatively short and easy to understand, for example, Network, SCSI, IDE, or SynthVideo.

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a client function accessed from the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1) structure.
>
> For more information, see the Remarks section of the [**KMCL_CLIENT_INTERFACE_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_client_interface_v1).

## See also