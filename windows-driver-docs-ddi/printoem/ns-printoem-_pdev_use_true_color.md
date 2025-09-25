## Description

The **PDEV_USE_TRUE_COLOR** structure indicates whether the output color space should be color or grayscale.

## Members

### `bUseTrueColor`

Specifies whether the PostScript output should be in color mode or in monochrome/grayscale mode. If **TRUE**, output is in color. If **FALSE**, output is monochrome/grayscale.

## Remarks

This structure is available in Windows XP and later.

The *pBuf* parameter of the [IPrintOemPS2::GetPDEVAdjustment](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps2-getpdevadjustment) method can point to a structure of this type.

A plug-in can use this flag to turn color output on or off for Pscript5 printer output data. If the plug-in chooses to not change the current setting, it can simply return **S_FALSE**.

## See also

[IPrintOemPS2::GetPDEVAdjustment](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps2-getpdevadjustment)