# GetFontData function

## Description

The **GetFontData** function retrieves font metric data for a TrueType font.

## Parameters

### `hdc` [in]

A handle to the device context.

### `dwTable` [in]

The name of a font metric table from which the font data is to be retrieved. This parameter can identify one of the metric tables documented in the TrueType Font Files specification published by Microsoft Corporation. If this parameter is zero, the information is retrieved starting at the beginning of the file for TrueType font files or from the beginning of the data for the currently selected font for TrueType Collection files. To retrieve the data from the beginning of the file for TrueType Collection files specify 'ttcf' (0x66637474).

### `dwOffset` [in]

The offset from the beginning of the font metric table to the location where the function should begin retrieving information. If this parameter is zero, the information is retrieved starting at the beginning of the table specified by the *dwTable* parameter. If this value is greater than or equal to the size of the table, an error occurs.

### `pvBuffer` [out]

A pointer to a buffer that receives the font information. If this parameter is **NULL**, the function returns the size of the buffer required for the font data.

### `cjBuffer` [in]

The length, in bytes, of the information to be retrieved. If this parameter is zero, **GetFontData** returns the size of the data specified in the *dwTable* parameter.

## Return value

If the function succeeds, the return value is the number of bytes returned.

If the function fails, the return value is GDI_ERROR.

## Remarks

This function is intended to be used to retrieve TrueType font information directly from the font file by font-manipulation applications. For information about embedding fonts see the [Font Embedding Reference](https://learn.microsoft.com/windows/desktop/gdi/font-embedding-reference).

An application can sometimes use the **GetFontData** function to save a TrueType font with a document. To do this, the application determines whether the font can be embedded by checking the **otmfsType** member of the [OUTLINETEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-outlinetextmetrica) structure. If bit 1 of **otmfsType** is set, embedding is not permitted for the font. If bit 1 is clear, the font can be embedded. If bit 2 is set, the embedding is read-only. If embedding is permitted, the application can retrieve the entire font file, specifying zero for the *dwTable*, *dwOffset*, and *cbData* parameters.

If an application attempts to use this function to retrieve information for a non-TrueType font, an error occurs.

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gettextmetrics)

[OUTLINETEXTMETRIC](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-outlinetextmetrica)