## Description

The **DXGKARGCB_PINFRAMEBUFFERFORSAVE2** structure contains the information used by the [**DXGKCB_PINFRAMEBUFFERFORSAVE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave2) callback function to pin an entire frame buffer at once.

## Members

### `PhysicalAdapterIndex` [in]

The index of the physical adapter.

### `CommitSize` [in]

The size, in bytes, that the driver requires to pin. This size must be a multiple of PAGE_SIZE and must be less than or equal to the maximum size specified by the driver in the [**DXGK_FRAMEBUFFERSAVEAREA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_framebuffersavearea) structure when the driver's [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) callback is called with **DXGKQAITYPE_FRAMEBUFFERSAVESIZE** during driver initialization.

### `Flags`

### `Flags.PreferContiguous`

Indicates that the driver can use a contiguous address descriptor list (ADL) in this path and is preferable to a page array. When logical remapping is enabled, this may save a large amount of memory when allocating the ADL based on CommitSize. This flag behaves identically to the same-named flag in [**DXGKARGCB_ALLOCATE_ADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_allocate_adl) when [allocating an ADL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocateadl).

### `Flags.Reserved`

Reserved; must be set to zero.

### `Flags.Value`

An alternative way to access the **Flags** bits.

### `pAdl` [out]

On a successful call to [**DXGKCB_PINFRAMEBUFFERFORSAVE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave2), points to the [**DXGK_ADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_adl) structure with a list of pages of the frame buffer save area. These pages are guaranteed to be mapped to the IoMmu.

## Remarks

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

## See also

[**DXGK_ADL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_adl)

[**DXGK_FRAMEBUFFERSAVEAREA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_framebuffersavearea)

[**DXGKCB_PINFRAMEBUFFERFORSAVE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave2)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)