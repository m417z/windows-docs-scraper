# IDmaChannel::FreeBuffer

## Description

The FreeBuffer method frees the buffer that was allocated by the previous call to IDmaChannel::AllocateBuffer.

## Remarks

Because the buffer is automatically freed when the DMA-channel object is deleted, the FreeBuffer method is not typically used.

## See also

[IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel)