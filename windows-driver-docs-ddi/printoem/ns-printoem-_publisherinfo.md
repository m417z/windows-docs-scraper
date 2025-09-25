## Description

The **PUBLISHERINFO** structure is used as an input parameter to the [IPrintOemPS::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-getinfo) method.

## Members

### `dwMode`

Is a set of bit flags. The only flag defined is **OEM_MODE_PUBLISHER**, which must be set if a rendering plug-in for Pscript5 is using "publishing mode".

### `wMinoutlinePPEM`

Specifies the minimum font size, in pixels, for which the Pscript5 driver will download TrueType fonts as outline (Type 1) fonts. A font smaller than the minimum setting will be downloaded as a bitmap (Type 3) font.

### `wMaxbitmapPPEM`

Specifies the maximum font size, in pixels, for which the Pscript5 driver will download TrueType fonts as bitmap (Type 3) fonts. A font larger than the maximum setting will be downloaded as an outline (Type 1) font.

## See also

[IPrintOemPS::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemps-getinfo)