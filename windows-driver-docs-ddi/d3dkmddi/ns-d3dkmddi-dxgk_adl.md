## Description

The **DXGK_ADL** structure is an address descriptor list (ADL), which used to describe an array of pages that can be either physical or logical.

## Members

### `PageCount`

The number of pages that the ADL represents.

### `Flags`

A [**DXGK_ADL_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_adl_flags) structure that specifies flags for the ADL.

### `BasePageNumber`

Used for contiguous ADLs. When **Flags.Contiguous** is set, **BasePageNumber** is the initial page number of a contiguous range of memory and **PageCount** is the number of pages that it represents. For example, if **PageCount**=3 and **BasePageNumber**=100, then **DXGK_ADL** represents the pages 100, 101, and 102 (address range 0x100000-0x102000).

### `Pages`

Used for non-contiguous ADLs. When **Flags.Contiguous** is not set, **Pages** points to an array of exactly **PageCount** pages. The pages in the array are not guaranteed to be contiguous.

**Pages** is of type **DXGK_PAGE_NUMBER**, which is guaranteed to be the same size as a [**PFN_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#mmgetmdlpfnarray). This array can be substituted in place of an MDL's PFN array when programming the hardware.

## Remarks

*Dxgkernel* provides ADLs in order to support both physical and logical access modes, and be able to switch between the two modes seamlessly at runtime. An ADL is very similar to an MDL, but describes an array of pages that can be either physical or logical. Because these pages can be logical pages, the addresses described by an ADL cannot be mapped to a virtual address for direct CPU access.

For more information, see [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping).

## See also

[**DXGK_ADL_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_adl_flags)