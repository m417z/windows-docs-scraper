# IDmaChannel::AllocateBuffer

## Description

The AllocateBuffer method allocates a common buffer that can be accessed by the port driver and DMA hardware.

## Parameters

### `BufferSize`

Specifies the size in bytes of the buffer to be allocated.

### `PhysicalAddressConstraint`

Specifies an optional constraint to place on the physical address of the buffer. If this parameter is non-NULL, only the bits that are set in the constraint address will vary from the beginning to the end of the buffer. For example, to request a buffer that does not cross a 64-kilobyte boundary, specify the physical address constraint 0x000000000000FFFF.

## Return value

This method returns NTSTATUS. AllocateBuffer returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

This method must be called only once following the creation of the DMA-channel object unless the previously allocated buffer is first freed by calling FreeBuffer.

## See also

[IDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-idmachannel)