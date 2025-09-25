## Description

The **PDEV_HOSTFONT_ENABLED** structure indicates whether the Hostfont feature is enabled.

## Members

### `bHostfontEnabled`

Specifies whether the Hostfont feature is enabled. If set to **TRUE**, the Hostfont feature is enabled. Otherwise, this feature is disabled.

## Remarks

This structure is available in Windows XP and later.

The *pBuf* parameter of the [IPrintOemPS2::GetPDEVAdjustment](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps2-getpdevadjustment) method can point to a structure of this type.

Hostfont support is designed to improve the performance of a PostScript interpreter running on a host computer system, rather than on a physical printer. When the Hostfont feature is enabled, the Pscript5 driver stops converting and downloading host font data when there is already an identical font resident on the host on which the interpreter is running. This applies only to the following fonts:

- A TrueType Font (TTF) converted to either a PostScript Type 42 or CID2 font

- An OpenType Font (OTF) converted to either a PostScript Type 1 or CID0 font

- A Printer Font Binary (PFB)

## See also

[IPrintOemPS2::GetPDEVAdjustment](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps2-getpdevadjustment)