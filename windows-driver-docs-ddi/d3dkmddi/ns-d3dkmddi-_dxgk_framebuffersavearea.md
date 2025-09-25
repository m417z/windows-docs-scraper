# DXGK_FRAMEBUFFERSAVEAREA structure

## Description

The **DXGK_FRAMEBUFFERSAVEAREA** structure specifies the size required by the driver to save the frame buffer reserve area during power transitions.

## Members

### `MaximumSize`

The maximum size required by the driver to save the frame buffer reserve area during power transitions. This value must be a multiple of PAGE_SIZE.

## Remarks

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKDDI_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)

[**DXGKQAITYPE_FRAMEBUFFERSAVESIZE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype)