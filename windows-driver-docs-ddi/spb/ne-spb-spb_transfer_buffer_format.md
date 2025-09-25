# SPB_TRANSFER_BUFFER_FORMAT enumeration

## Description

The **SPB_TRANSFER_BUFFER_FORMAT** enumeration specifies the format of the buffer that is described by an [SPB_TRANSFER_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer) structure.

## Constants

### `SpbTransferBufferFormatInvalid`

Reserved for use by the operating system.

### `SpbTransferBufferFormatSimple`

The transfer buffer is described by a simple user-mode or kernel-mode pointer and a length.

### `SpbTransferBufferFormatList`

The transfer buffer is described by a pointer to a list of buffers and a count of the number of buffers in the list.

### `SpbTransferBufferFormatSimpleNonPaged`

The transfer buffer is described by a simple user-mode or kernel-mode pointer and a length. The buffer resides in non-paged memory. This format value is valid only if the client that originates the I/O request is a kernel-mode driver.

### `SpbTransferBufferFormatMdl`

The transfer buffer is described by a pointer to an MDL. This format value is valid only if the client that originates the I/O request is a kernel-mode driver.

### `SpbTransferBufferFormatMax`

Reserved for use by the operating system.

## Remarks

The **Format** member of the [SPB_TRANSFER_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer) structure is an **SPB_TRANSFER_BUFFER_FORMAT** enumeration value.

## See also

- [SPB_TRANSFER_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer)