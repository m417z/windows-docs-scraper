# SPB_TRANSFER_BUFFER structure

## Description

The **SPB_TRANSFER_BUFFER** structure describes the data buffer for an individual transfer in an [I/O transfer sequence](https://learn.microsoft.com/windows-hardware/drivers/spb/i-o-transfer-sequences).

## Members

### `Format`

The buffer format. This member is set to one of the following [SPB_TRANSFER_BUFFER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_transfer_buffer_format) enumeration values:

- **SpbTransferBufferFormatSimple**
- **SpbTransferBufferFormatList**
- **SpbTransferBufferFormatSimpleNonPaged**
- **SpbTransferBufferFormatMdl**

**SpbTransferBufferFormatMdl** is a valid value only for I/O transfer sequences that are requested by clients of the SPB controller driver that are kernel-mode components.

### `Simple`

A SPB_TRANSFER_BUFFER_LIST_ENTRY structure that specifies the base address and the length of a simple transfer buffer. Use this member of the union if **Format** is **SpbTransferBufferFormatSimple** or **SpbTransferBufferFormatSimpleNonPaged**. The **SpbTransferBufferFormatSimpleNonPaged** format is used only by kernel-mode clients.

### `BufferList`

A scatter-gather list that consists of an array of buffer descriptors. Use this member of the union if **Format** is **SpbTransferBufferFormatList**.

### `BufferList.List`

A pointer to an array of **SPB_TRANSFER_BUFFER_LIST_ENTRY** structures that describe the buffers in the scatter-gather list.

### `BufferList.ListCe`

The number of elements in the **List** array.

### `Mdl`

A pointer to an MDL that describes the buffer. This member is used only by kernel-mode clients. Use this member of the union if **Format** is **SpbTransferBufferFormatMdl**. For more information, see Remarks.

## Remarks

This structure is used by an [SPB_TRANSFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list_entry) structure to describe a transfer buffer.

The **Mdl** member of this structure can be used only by clients of the SPB controller driver that are kernel-mode components. User-mode clients must not use this member. For more information about MDLs, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

## See also

- [SPB_TRANSFER_BUFFER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_transfer_buffer_format)
- [SPB_TRANSFER_BUFFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer_list_entry)
- [SPB_TRANSFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list_entry)