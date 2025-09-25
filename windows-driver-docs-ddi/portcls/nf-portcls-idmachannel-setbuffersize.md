# IDmaChannel::SetBufferSize

## Description

The SetBufferSize method sets the DMA channel's current buffer size.

## Parameters

### `BufferSize`

Specifies the buffer's current size in bytes.

## Remarks

The SetBufferSize method is used to change the size of a buffer that was previously allocated by the IDmaChannel::AllocateBuffer method. After the call to AllocateBuffer and before SetBufferSize is called, the IDmaChannel::BufferSize returns the actual size of the allocated buffer. After SetBufferSize is called, BufferSize returns the size specified in the SetBufferSize call. The DMA-channel object does not actually use this value internally. The current buffer size is maintained by the object to allow its various clients to communicate the intended size of the buffer.

## See also

[IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel)