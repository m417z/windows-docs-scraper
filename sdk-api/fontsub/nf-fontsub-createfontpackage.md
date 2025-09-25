# CreateFontPackage function

## Description

The **CreateFontPackage** function creates a subset version of a specified TrueType font, typically in order to pass it to a printer. In order to allow for the fact that pages later in a document may need characters or glyphs that were not used on the first page, this function can create an initial subset font package, then create "Delta" font packages that can be merged with the original subset font package, effectively extending it.

## Parameters

### `puchSrcBuffer` [in]

Points to a buffer containing source TTF or TTC data, describing the font that is to be subsetted.

### `ulSrcBufferSize` [in]

Specifies size of **puchSrcBuffer*, in bytes.

### `ppuchFontPackageBuffer` [out]

Points to a variable of type unsigned char*. The **CreateFontPackage** function will allocate a buffer ***puchFontPackageBuffer*, using *lpfnAllocate* and *lpfnReAllocate*. On successful return, the buffer will contain the subset font or font package. The application is responsible for eventually freeing the buffer.

### `pulFontPackageBufferSize` [out]

Points to an unsigned long, which on successful return will specify the allocated size of buffer ***puchFontPackageBuffer*.

### `pulBytesWritten` [out]

Points to an unsigned long, which on successful return will specify the number of bytes actually used in buffer ***puchFontPackageBuffer*.

### `usFlag` [in]

Specifies whether this font should be subsetted, compressed, or both; whether it is a TTF or TTC; and whether*pusSubsetKeepListrepresents character codes or glyph indices. Any combination of the following flags may be specified:

| Value | Meaning |
| --- | --- |
| **TTFCFP_FLAGS_SUBSET** | If set, requests subsetting. |
| **TTFCFP_FLAGS_COMPRESS** | If set, requests compression. The currently shipping version of this function does not do compression. This flag allows for future implementation of this capability, but is currently ignored. |
| **TTFCFP_FLAGS_TTC** | If set, specifies that the font in *puchSrcBuffer* is a TTC; otherwise, it must be a TTF. |
| **TTFCFP_FLAGS_GLYPHLIST** | If set, specifies that*pusSubsetKeepListis a list of glyph indices; otherwise, it must be a list of character codes. |

### `usTTCIndex` [in]

The zero based TTC Index; only used if TTFCFP_FLAGS_TTC is set in *usFlags*.

### `usSubsetFormat` [in]

The format of the file to create. Select one of these values; they cannot be combined.

| Value | Meaning |
| --- | --- |
| **TTFCFP_SUBSET** | Create a standalone Subset font that cannot be merged with later. |
| **TTFCFP_SUBSET1** | Create a Subset font package that can be merged with later. |
| **TTFCFP_DELTA** | Create a Delta font package that can merge with a previous subset font. |

### `usSubsetLanguage` [in]

The language in the Name table to retain. If Set to 0, all languages will be retained. Used only for initial subsetting: that is, used only if *usSubsetFormat* is either TTFCFP_SUBSET or TTFCFP_SUBSET1, and the TTFCFP_FLAGS_SUBSET flag is set in *usFlags*.

### `usSubsetPlatform` [in]

In conjunction with *usSubsetEncoding*, specifies which CMAP to use. Used only if **pusSubsetKeepList* is a list of characters: that is, used only if TTFCFP_FLAGS_GLYPHLIST is not set in *usFlags*. In that case, by this CMAP subtable is applied to *pusSubsetKeepList* to create a list of glyphs to retain in the output font or font package.

If used, this must take one of the following values; they cannot be combined:

| Value | Meaning |
| --- | --- |
| **TTFCFP_UNICODE_PLATFORMID** |  |
| **TTFCFP_APPLE_PLATFORMID** |  |
| **TTFCFP_ISO_PLATFORMID** |  |
| **TTFCFP_MS_PLATFORMID** |  |

### `usSubsetEncoding` [in]

In conjunction with *usSubsetPlatform*, specifies which CMAP to use. Used only if **pusSubsetKeepList* is a list of characters: that is, used only if TTFCFP_FLAGS_GLYPHLIST is not set in *usFlags*.

If used, this must take one of the following values; they cannot be combined:

| Value | Meaning |
| --- | --- |
| **TTFCFP_STD_MAC_CHAR_SET** | Can be used only if *usSubsetPlatform* == TTFCFP_APPLE_PLATFORMID. |
| **TTFCFP_SYMBOL_CHAR_SET** | Can be used only if *usSubsetPlatform* == TTFSUB_MS_PLATFORMID. |
| **TTFCFP_UNICODE_CHAR_SET** | Can be used only if *usSubsetPlatform* == TTFSUB_MS_PLATFORMID. |
| **TTFCFP_DONT_CARE** |  |

### `pusSubsetKeepList` [in]

Points to an array of integers which comprise a list of character codes or glyph indices that should be retained in the output font or font package. If this list contains character codes (that is, if TTFCFP_FLAGS_GLYPHLIST is not set in *usFlags*), this list may be either Unicode or some other type of encoding, depending on the Platform-Encoding CMAP specified by *usSubsetPlatform* and *usSubsetEncoding*.

### `usSubsetListCount` [in]

The number of elements in the list **pusSubsetKeepList*.

### `lpfnAllocate` [in]

The callback function to allocate initial memory for *puchFontPackageBuffer* and for temporary buffers.

### `lpfnReAllocate` [in]

The callback function to reallocate memory for *puchFontPackageBuffer* and for temporary buffers.

### `lpfnFree` [in]

The callback function to free up memory allocated by *lpfnAllocate* and *lpfnReAllocate*.

### `lpvReserved` [in]

Must be set to **NULL**.

## Return value

If the function is successful, returns zero.

Otherwise, returns a nonzero value. See [Font-Package Function Error Messages](https://learn.microsoft.com/windows/desktop/gdi/font-package-function-error-messages) for possible error returns.

## Remarks

By specifying a value of TTFCFP_SUBSET for *usSubsetFormat*, you can directly create a working font rather than a font package. This does not allow for future merging, but if there is no need for merging, this skips a step in the downstream processing: a font package needs to be converted back to a working font before it can be used.

By specifying a value of TTFCFP_SUBSET1 for *usSubsetFormat*, you can create a font package that allows later merging. For example, consider the case where an application calls this function at the start of a large print job. Part way through the print job, the application discovers that it needs glyphs that are not in the subset it has built. The application can make another call to **CreateFontPackage**, this time specifying a value of TTFCFP_DELTA for *usSubsetFormat*. The printer can use [MergeFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-mergefontpackage) to merge in these additional glyphs.

A CMAP maps from character encodings to glyphs. If **pusSubsetKeepList* is a list of character values, then the application uses parameters *usSubsetPlatform* and *usSubsetEncoding* to specify what type of CMAP is being used, so that character values can be mapped to glyphs.

## See also

[CFP_ALLOCPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_allocproc)

[CFP_FREEPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_freeproc)

[CFP_REALLOCPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_reallocproc)

[MergeFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-mergefontpackage)