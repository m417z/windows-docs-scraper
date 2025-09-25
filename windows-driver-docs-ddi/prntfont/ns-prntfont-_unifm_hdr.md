# _UNIFM_HDR structure

## Description

The UNIFM_HDR structure is used to define the contents of [Unidrv font metrics files](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management) (.ufm files).

## Members

### `dwSize`

Specifies the total size, in bytes, of the .ufm file. Note that this is the total size of all structures used to define the file. This value is not the size of the UNIFM_HDR structure.

### `dwVersion`

Specifies the file version number, as defined in prntfont.h by a constant with a name format of UNIFM_VERSION_*x*_*x*.

### `ulDefaultCodepage`

Specifies the code page identifier for the font's default code page. For more information, see the following Remarks section.

### `lGlyphSetDataRCID`

Specifies an RC_GTT resource identifier that identifies a .gtt (Glyph Translation Table) file, or one of the CC_-prefixed code conversion identifiers defined in prntfont.h. For more information, see the following Remarks section.

### `loUnidrvInfo`

Specifies the byte offset from the beginning of the .ufm (Unidrv Font Metrics) file to the location of the file's [UNIDRVINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_unidrvinfo) structure.

### `loIFIMetrics`

Specifies the byte offset from the beginning of the .ufm file to the location of the file's [PRINTIFI32](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_printifi32) structure.

### `loExtTextMetric`

Specifies the byte offset from the beginning of the .ufm file to the location of the file's [EXTTEXTMETRIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_exttextmetric) structure.

### `loWidthTable`

Specifies the byte offset from the beginning of the .ufm file to the location of the file's [WIDTHTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_widthtable) structure.

### `loKernPair`

Specifies the byte offset from the beginning of the .ufm file to the location of the file's [KERNDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_kerndata) structure.

### `dwReserved`

Not used.

## Remarks

A UNIFM_HDR structure must be the first structure contained in a .ufm file.

If **lGlyphSetDataRCID** is not CC_DEFAULT, then the following rules apply:

- If **lGlyphSetDataRCID** contains an RC_GTT resource identifier, the code page number specified for **ulDefaultCodepage** must be the same code page number that is contained in the .gtt (Glyph Translation Table) file's first [UNI_CODEPAGEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uni_codepageinfo) structure.

- If **lGlyphSetDataRCID** contains one of the CC_-prefixed code conversion identifiers (other than CC_DEFAULT), the code page number specified for **ulDefaultCodepage** must be the code page number that is associated with the CC_-prefixed identifier. (These code page numbers are listed in Prntfont.h, next to each CC_-prefixed identifier.)

 The character conversion codes predefined by the system, listed in Prntfont.h, are as follows:

```cpp
    //
    // System predefined character conversion
    //
    // UNIDRV is going to support  following system predefined character conversion.
    // By specifying these number in UNIFM.dwGlyphSetDataRCID;
    //

    #define CC_NOPRECNV 0x0000FFFF // Not use predefined

    //
    // ANSI
    //
    #define CC_DEFAULT  0 // Default Character Conversion
    #define CC_CP437   -1 // Unicode to IBM Codepage 437
    #define CC_CP850   -2 // Unicode to IBM Codepage 850
    #define CC_CP863   -3 // Unicode to IBM Codepage 863

    //
    // East Asia
    //

    #define CC_BIG5     -10 // Unicode to Chinese Big 5. Codepage 950.
    #define CC_ISC      -11 // Unicode to Korean Industrial Standard. Codepage 949.
    #define CC_JIS      -12 // Unicode to JIS X0208. Codepage 932.
    #define CC_JIS_ANK  -13 // Unicode to JIS X0208 except ANK. Codepage 932.
    #define CC_NS86     -14 // Big-5 to National Standard conversion. Codepage 950
    #define CC_TCA      -15 // Big-5 to Taipei Computer Association. Codepage 950.
    #define CC_GB2312   -16 // Unicode to GB2312. Codepage 936
    #define CC_SJIS     -17 // Unicode to Shift-JIS. Codepage 932.
    #define CC_WANSUNG  -18 // Unicode to Extended Wansung. Codepage 949.
    ```

If **lGlyphSetDataRCID** is CC_DEFAULT, there are no restrictions on the value specified for **ulDefaultCodepage**, but a default code page must be specified.

## See also

[EXTTEXTMETRIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_exttextmetric)

[KERNDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_kerndata)

[PRINTIFI32](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_printifi32)

[UNIDRVINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_unidrvinfo)

[UNI_CODEPAGEINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_uni_codepageinfo)

[WIDTHTABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_widthtable)