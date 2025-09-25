# IDmaChannel::CopyTo

## Description

The CopyTo method copies sample data to the DMA channel's common buffer from the specified source buffer.

## Parameters

### `Destination`

Pointer to the destination buffer, which is located in the DMA channel's common buffer.

### `Source`

Pointer to the source buffer

### `ByteCount`

Specifies the number of bytes to be copied.

## Remarks

The Source and Destination pointers are both kernel-mode virtual addresses. The IDmaChannel::SystemAddress call returns the virtual address of a DMA channel's common buffer.

The Destination parameter points to the beginning of the destination buffer, which occupies ByteCount contiguous bytes in the DMA channel's common buffer.

## See also

[IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel)