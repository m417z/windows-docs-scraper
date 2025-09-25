# _MDL structure

## Description

An **MDL** structure is a partially opaque structure that represents a memory descriptor list (MDL).

## Members

### `Next`

Pointer to the next MDL in an MDL chain. For more information about MDL chains, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

### `Size`

### `MdlFlags`

### `Process`

### `MappedSystemVa`

### `StartVa`

### `ByteCount`

### `ByteOffset`

## Remarks

An MDL describes the layout of a virtual memory buffer in physical memory. For more information, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

## See also

- [IoAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocatemdl)
- [MmGetMdlByteCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlbytecount)
- [MmGetMdlByteOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlbyteoffset)
- [MmGetMdlPfnArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlpfnarray)
- [MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress)
- [MmInitializeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mminitializemdl)