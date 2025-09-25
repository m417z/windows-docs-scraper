# _WDF_COMMON_BUFFER_CONFIG structure

## Description

[Applies to KMDF only]

The **WDF_COMMON_BUFFER_CONFIG** structure contains configuration information for a common buffer.

## Members

### `Size`

The size, in bytes, of this structure.

### `AlignmentRequirement`

The alignment requirement for a common buffer. This value must be one less than the alignment boundary. For example, you can specify 15 for a 16-byte alignment boundary and 31 for a 32-byte alignment boundary. You can also use one of the FILE_*Xxxx*_ALIGNMENT constants that are defined in *Wdm.h*.

## Remarks

The **WDF_COMMON_BUFFER_CONFIG** structure is used as input to the [WdfCommonBufferCreateWithConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffercreatewithconfig) method.

If your driver specifies an alignment requirement that is greater that the computer's page size (PAGE_SIZE), the logical addresses that the [WdfCommonBufferGetAlignedLogicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedlogicaladdress) method returns are always aligned to the specified alignment requirement, but the virtual addresses that the [WdfCommonBufferGetAlignedVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedvirtualaddress) method returns might not be aligned to the alignment requirement.

If your driver specifies an alignment requirement that is less than the computer's page size, all logical and virtual addresses are aligned to the specified alignment requirement.

For more information about specifying alignment requirements, see [Enabling DMA Transactions](https://learn.microsoft.com/windows-hardware/drivers/wdf/enabling-dma-transactions) and [Using Common Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-common-buffers).

## See also

[WdfCommonBufferCreateWithConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffercreatewithconfig)

[WdfCommonBufferGetAlignedLogicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedlogicaladdress)

[WdfCommonBufferGetAlignedVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcommonbuffer/nf-wdfcommonbuffer-wdfcommonbuffergetalignedvirtualaddress)