# EVT_VMB_CHANNEL_SAVE_PACKET callback function

## Description

[Some information relates to pre-released product which may be substantially modified before it's commercially released. Microsoft makes no warranties, express or implied, with respect to the information provided here.]

The *EvtVmbChannelSavePacket* callback function is invoked when the virtualization service provider (VSP) endpoint must save the state associated with a packet.

## Parameters

### `Channel` [in]

The channel on which the packet arrives.

### `Packet` [in]

The packet for which VSP saves state.

### `SaveBuf` [out]

The buffer into which to save the state.

### `SaveBufSize` [in]

Size of the *SaveBuf* parameter, in bytes.

### `BytesNeeded` [out]

Size necessary to save the state of the transaction, in bytes.

## Return value

*EvtVmbChannelSavePacket* returns a status code.

## Remarks

The [VmbServerChannelInitSetSaveRestorePacketCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbserverchannelinitsetsaverestorepacketcallbacks) function sets a callback function for saving packets for each channel.

The VSP saves the state associated with the transaction that is unique to the VSP. The Kernel Mode Client Library (KMCL)
saves its own state.

This function is invoked for each packet object that is currently in use. The first invocation passes a zero (0) value for the *SaveBufSize* parameter. This call fails if there is any state that needs to be saved, which fills the *BytesNeeded* with the actual size requirement. If this first invocation
returns a failure code, the KMCL calls a second time with a buffer of at least
the length stipulated in the first call.

## See also

[VmbServerChannelInitSetSaveRestorePacketCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/vmbuskernelmodeclientlibapi/nf-vmbuskernelmodeclientlibapi-vmbserverchannelinitsetsaverestorepacketcallbacks)