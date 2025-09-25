# MmSizeOfMdl function

## Description

The **MmSizeOfMdl** routine returns the number of bytes to allocate for an MDL describing a given address range.

## Parameters

### `Base` [in]

Pointer to the base virtual address for the range.

### `Length` [in]

Supplies the size, in bytes, of the range.

## Return value

**MmSizeOfMdl** returns the number of bytes required to contain the MDL.

## Remarks

Memory for the MDL itself must be allocated from nonpaged pool.

## See also

[MmCreateMdl](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[MmInitializeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mminitializemdl)