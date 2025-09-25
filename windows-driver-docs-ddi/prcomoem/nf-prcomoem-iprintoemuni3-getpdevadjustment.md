# IPrintOemUni3::GetPDEVAdjustment

## Description

The `IPrintOemUni3::GetPDEVAdjustment` method enables a plug-in to override specific [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) settings.

## Parameters

### `pdevobj`

Pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `dwAdjustType`

Specifies the type of adjustment asked for. The following flags are currently supported.

| Flag | Meaning |
| --- | --- |
| PDEV_ADJUST_GRAPHICS_RESOLUTION_TYPE | Adjust the graphics resolution setting that is reported in the PDEV structure. For more information, see the [PDEV_ADJUST_GRAPHICS RESOLUTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_pdev_adjust_graphics_resolution) structure. |
| PDEV_IMAGEABLE_ORIGIN_AREA_TYPE | Adjust the imageable origin area that is reported in the PDEV structure. For more information, see the [PDEV_ADJUST_IMAGEABLE_ORIGIN_AREA](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_pdev_adjust_imageable_origin_area) structure. |
| PDEV_ADJUST_PHYSICAL_PAPER_SIZE_TYPE | Adjust the physical paper size that is reported in the PDEV structure. For more information, see the [PDEV_ADJUST_PAPER_PHYSICAL_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_pdev_adjust_physical_paper_size) structure. |

### `pBuf`

Pointer to a structure that contains the planned settings that are used if there is no change. These structures are listed in the preceding table. The plug-in can overwrite the settings in the relevant structure.

### `cbBuffer`

Specifies the size, in bytes, of the structure pointed to by *pBuf*.

### `pbAdjustmentDone` [out]

Pointer to a memory location that the plug-in sets to **TRUE** when it actually changes a value in the buffer. This may be used by the driver for optimizations.

## Return value

The `IPrintOemUni3::GetPDEVAdjustment` method should return S_OK if it recognizes the adjustment type, and S_FALSE if it does not. If the method fails, it should return E_FAIL. The chain of plug-ins is called until either S_OK or a failure code other than E_NOTIMPL is returned. That is, the chain of plug-ins is called until the first plug-in that is capable of handling the adjustment is found.

## Remarks

This function is available in Windows Vista and later.

Currently, the Unidrv driver calls `IPrintOemUni3::GetPDEVAdjustment` to adjust the graphics resolution setting, as reported in the PDEV, to adjust the imageable origin area, or to adjust the physical paper size.

## See also

[IPrintOemUni3](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemuni3)

[PDEV_ADJUST_GRAPHICS RESOLUTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_pdev_adjust_graphics_resolution)

[PDEV_ADJUST_IMAGEABLE_ORIGIN_AREA](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_pdev_adjust_imageable_origin_area)

[PDEV_ADJUST_PAPER_MARGIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_pdev_adjust_paper_margin)

[PDEV_ADJUST_PAPER_PHYSICAL_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_pdev_adjust_physical_paper_size)

[PDEV_HOSTFONT_ENABLED](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_pdev_hostfont_enabled)

[PDEV_USE_TRUE_COLOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_pdev_use_true_color)