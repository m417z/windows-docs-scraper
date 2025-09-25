# _MM_PHYSICAL_ADDRESS_LIST structure

## Description

The **MM_PHYSICAL_ADDRESS_LIST** structure specifies a range of physical addresses.

## Members

### `PhysicalAddress`

The starting physical address of the range. This address must be aligned to a page boundary in physical memory.

### `NumberOfBytes`

The number of bytes in the range. This member must be nonzero and an integer multiple of the memory page size.

## Remarks

The first parameter to the [MmAllocateMdlForIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemdlforiospace) routine is a pointer to an array of **MM_PHYSICAL_ADDRESS_LIST** structures.

## See also

[MmAllocateMdlForIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmallocatemdlforiospace)