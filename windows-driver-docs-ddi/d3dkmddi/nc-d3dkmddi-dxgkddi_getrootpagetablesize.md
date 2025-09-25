# DXGKDDI_GETROOTPAGETABLESIZE callback function

## Description

**DxgkDdiGetRootPageTableSize** returns the minimum root page table size, in bytes, that is needed to hold the given number of page table entries. The actual number of entries in the page table could be greater than the given value.

**DxgkDdiGetRootPageTableSize** is called only when **DXGK_GPUMMUCAPS**::**PageTableLevelCount** is two.

## Parameters

### `hAdapter`

A handle to the display adapter.

### `pArgs`

The [DXGKARG_GETROOTPAGETABLESIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_getrootpagetablesize) structure that describes the operation.

## Return value

The page table size in bytes. The size must be a multiple of the page size of the GPU memory segment where page table is located.