# IDmaChannelSlave::Start

## Description

The Start method starts a subordinate DMA object.

## Parameters

### `MapSize`

Specifies the number of bytes of the allocated buffer that are to be mapped. The map size must not exceed the size of the buffer allocated in the call to IDmaChannel::AllocateBuffer.

### `WriteToDevice`

Specifies the direction of data movement. If TRUE, the data is to be moved from the buffer to the device. If FALSE, the data is to be moved from the device to the buffer.

## Return value

This method returns NTSTATUS. It returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code. If the caller attempts to start a channel that is already started, the method returns immediately with error code STATUS_UNSUCCESSFUL.

## Remarks

> [!NOTE]
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the [Microsoft style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

The method first sets up map registers to map the first MapSize bytes of the allocated buffer for the adapter object. Next, the method starts a DMA transfer of the number of bytes specified in MapSize.

For more information about this method, see [IDmaChannel::BufferSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idmachannel-buffersize) and [IDmaChannelSlave::ReadCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idmachannelslave-readcounter).

## See also

[IDmaChannelSlave interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannelslave)