# IDmaChannel::BufferSize

## Description

The BufferSize method returns the size in bytes of the DMA channel's data buffer.

## Return value

This method returns ULONG which is the size in bytes of the buffer.

## Remarks

The BufferSize method returns the buffer size that was set by the previous call to IDmaChannel::SetBufferSize. If SetBufferSize has not been called since the IDmaChannel::AllocateBuffer call, BufferSize returns the allocated buffer size. The DMA-channel object does not actually use this value internally. This value is maintained by the object to allow its various clients to communicate the intended size of the buffer. This call is often used to obtain the map-size parameter to the IDmaChannelSlave::Start method.

> [!NOTE]
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the [Microsoft style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

## See also

[IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel)