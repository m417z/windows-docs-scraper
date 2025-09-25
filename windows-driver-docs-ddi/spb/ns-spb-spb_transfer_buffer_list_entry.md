# SPB_TRANSFER_BUFFER_LIST_ENTRY structure

## Description

The **SPB_TRANSFER_BUFFER_LIST_ENTRY** structure describes either a simple transfer buffer, or an element in an array of one or more transfer buffers.

## Members

### `Buffer`

The virtual address of the transfer buffer. For a transfer that is requested by a client of the SPB controller driver that runs in user mode, this buffer must reside entirely in user-mode memory.

### `BufferCb`

The size, in bytes, of the transfer buffer that *Buffer* points to.

## Remarks

To request an [I/O transfer sequence](https://learn.microsoft.com/windows-hardware/drivers/spb/i-o-transfer-sequences) for a target device on the bus, a client (peripheral driver) of the SPB controller driver sends an [IOCTL_SPB_EXECUTE_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_execute_sequence) request that describes the sequence. The transfers in the sequence are described by an [SPB_TRANSFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list) structure that is followed by an array of one or more [SPB_TRANSFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list_entry) structures. Each element in this array describes an individual transfer in the sequence, and each element contains an [SPB_TRANSFER_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer) structure that describes the buffer to use for the transfer.

If the buffer format is **SpbTransferBufferFormatSimple**, an **SPB_TRANSFER_BUFFER** structure contains a single **SPB_TRANSFER_BUFFER_LIST_ENTRY** structure that describes a simple buffer that is specified by an address and a length. If the buffer format is **SpbTransferBufferFormatList**, the buffer is a scatter-gather list, and the **SPB_TRANSFER_BUFFER** structure contains a pointer to an **SPB_TRANSFER_BUFFER_LIST_ENTRY** array that describes the list.

## See also

* [IOCTL_SPB_EXECUTE_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/spb/spb-ioctls#ioctl_spb_execute_sequence)
* [SPB_TRANSFER_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer)
* [SPB_TRANSFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list)
* [SPB_TRANSFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list_entry)