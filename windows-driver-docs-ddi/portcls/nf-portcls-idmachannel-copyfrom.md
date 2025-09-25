# IDmaChannel::CopyFrom

## Description

The CopyFrom method copies sample data from the DMA channel's common buffer to the specified destination buffer.

## Parameters

### `Destination`

Pointer to the destination buffer

### `Source`

Pointer to the source buffer, which is located in the DMA channel's common buffer.

### `ByteCount`

Specifies the number of bytes to be copied.

## Remarks

The Source and Destination pointers are both kernel-mode virtual addresses. The IDmaChannel::SystemAddress call returns the virtual address of a DMA channel's common buffer.

The Source parameter points to the beginning of the source buffer, which occupies ByteCount contiguous bytes in the DMA channel's common buffer.

## See also

[IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel)