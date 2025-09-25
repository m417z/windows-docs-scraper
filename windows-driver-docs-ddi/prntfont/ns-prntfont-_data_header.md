## Description

The **DATA_HEADER** structure is used to specify a data section within a Unidrv font format file (.uff file).

## Members

### `dwSignature`

Specifies the signature value identifying the type of data in the data section. Valid signature values are listed in the following table.

| Signature | Definition |
|---|---|
| DATA_CTT_SIG | This data section contains [CTT](https://learn.microsoft.com/windows-hardware/drivers/)-formatted glyph set information. |
| DATA_GTT_SIG | This data section contains [GTT](https://learn.microsoft.com/windows-hardware/drivers/)-formatted glyph set information. |
| DATA_IFI_SIG | This data section contains IFI-formatted font metrics. |
| DATA_UFM_SIG | This data section contains [UFM](https://learn.microsoft.com/windows-hardware/drivers/)-formatted font metrics. |
| DATA_VAR_SIG | This data section contains data to be downloaded to the printer. See the following Remarks section. |

### `wSize`

Specifies the size, in bytes, of the DATA_HEADER structure.

### `wDataID`

If the data section contains font metrics data, this value must be a unique font identifier. For fonts that are permanently downloaded by the font installer, this value should be the downloaded font's identifier.

If the data section contains glyph data, this value must be a glyph set identifier.

If the data section contains variable data, this value must be zero.

### `dwDataSize`

Specifies the size, in bytes, of all the information represented by this DATA_HEADER structure. For example, if **dwSignature** is DATA_UFM_SIG, this value represents the size, in bytes, of the font's [**UNIFM_HDR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_unifm_hdr) structure and all associated structures. The size value does not include any byte padding required to align the next DATA_HEADER structure to a DWORD.

### `dwReserved`

Not used. Must be set to zero.

## Remarks

If **dwSignature** is DATA_VAR_SIG, the data section contains variable data that Unidrv sends to the printer the first time the font is selected. Typically, this data consists of a font header and corresponding font identifier, along with downloadable glyph information for all the glyphs supported by the font. [PCL](https://learn.microsoft.com/windows-hardware/drivers/) soft font information includes printer control language commands for loading the font header and glyph definitions for all supported glyphs. Unidrv does not validate variable data. Data validation should be performed by the font installer.

Each DATA_HEADER structure must be DWORD-aligned.

## See also

[**UNIFM_HDR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_unifm_hdr)