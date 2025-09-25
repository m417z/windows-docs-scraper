## Description

The **PDEV_ADJUST_PAPER_MARGIN** structure specifies the imageable printing area.

## Members

### `rcImageableArea`

Is a [RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl) structure that specifies the rectangular region that can be printed in. This region is specified in units of 0.001 mm.

## Remarks

This structure is available in Windows XP and later.

The *pBuf* parameter of the [IPrintOemPS2::GetPDEVAdjustment](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps2-getpdevadjustment) method can point to a structure of this type.

## See also

[IPrintOemPS2::GetPDEVAdjustment](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps2-getpdevadjustment)

[RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl)