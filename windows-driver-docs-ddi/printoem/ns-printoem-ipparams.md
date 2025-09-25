## Description

The **IPPARAMS** structure is used as an input parameter to a rendering plug-in **IPrintOemUn::ImageProcessing** method.

## Members

### `dwSize`

Specifies the size, in bytes of the IPPARAMS structure. Supplied by Unidrv.

### `ptOffset`

Pointer to a [**POINT**](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure containing the banded image's offset from the upper left corner of the drawing area. Supplied by Unidrv.

### `pHalftoneOption`

Pointer to a string containing the name of the currently selected halftoning option. Supplied by Unidrv.

### `bBanding`

Specifies whether image banding is active. If **TRUE**, image banding is active. If **FALSE**, image banding is not active. Supplied by Unidrv.

### `bBlankBand`

Specifies whether a blank band was drawn in the source bitmap supplied to **IPrintOemUni::ImageProcessing**. A value of **TRUE** indicates that nothing was drawn in the source bitmap supplied to **IPrintOemUni::ImageProcessing**. A **TRUE** value also indicates that data in the source bitmap is invalid and should not be processed. Supplied by Unidrv.

## See also

[IPrintOemUn::ImageProcessing](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-imageprocessing)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)