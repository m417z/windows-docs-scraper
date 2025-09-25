# FN_VMB_SERVER_CHANNEL_INIT_SET_SAVE_RESTORE_PACKET_CALLBACKS callback function

## Description

The **VmbServerChannelInitSetSaveRestorePacketCallbacks** function sets the save and restore callback functions that are called for each packet when the
driver calls a save function, such as [VmbChannelSaveBegin](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsavebegin), [VmbChannelSaveContinue](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsavecontinue), and [VmbChannelSaveEnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsaveend), or the [VmbChannelRestoreFromBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelrestorefrombuffer) function.

## Parameters

### `Channel`

A handle for a channel.

### `SavePacketCallback`

A callback function to call during channel save.

### `RestorePacketCallback`

A callback function to call during channel restore.

## Return value

**VmbServerChannelInitSetSaveRestorePacketCallbacks** returns the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER_1** | The *Channel* value was invalid or in an invalid state, such as Disabled. |

## Prototype

```cpp
//Declaration

FN_VMB_SERVER_CHANNEL_INIT_SET_SAVE_RESTORE_PACKET_CALLBACKS FnVmbServerChannelInitSetSaveRestorePacketCallbacks;

// Definition

NTSTATUS FnVmbServerChannelInitSetSaveRestorePacketCallbacks
(
	VMBCHANNEL Channel
	PFN_VMB_CHANNEL_SAVE_PACKET SavePacketCallback
	PFN_VMB_CHANNEL_RESTORE_PACKET RestorePacketCallback
)
{...}

```

## Remarks

> [!IMPORTANT]
> This function is called through the VMBus Kernel Mode Client Library (KMCL) interface, provided by the Vmbkmcl.sys bus driver. This is a server-only function accessed from the [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods) structure.
>
> For more information, see the Remarks section of [**KMCL_SERVER_ONLY_METHODS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/ns-vmbuskernelmodeclientlibapi-_kmcl_server_only_methods).

## See also

[VmbChannelRestoreFromBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelrestorefrombuffer)

[VmbChannelSaveBegin](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsavebegin)

[VmbChannelSaveContinue](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsavecontinue)

[VmbChannelSaveEnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbchannelsaveend)