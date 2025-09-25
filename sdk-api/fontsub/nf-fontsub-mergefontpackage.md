# MergeFontPackage function

## Description

The **MergeFontPackage** function manipulates fonts created by [CreateFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-createfontpackage). It is slightly more flexible than its name might suggest: it can appropriately handle all of the subset fonts and font packages created by **CreateFontPackage**. It can turn a font package into a working font, and it can merge a Delta font package into an appropriately prepared working font.

Typically, [CreateFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-createfontpackage) creates subset fonts and font packages to pass to a printer or print server; **MergeFontPackage** runs on that printer or print server.

## Parameters

### `puchMergeFontBuffer` [in]

A pointer to a buffer containing a font to merge with. This is used only when *usMode* is TTFMFP_DELTA.

### `ulMergeFontBufferSize` [in]

Specifies size of **puchMergeFontBuffer*, in bytes.

### `puchFontPackageBuffer` [in]

A pointer to a to buffer containing a font package.

### `ulFontPackageBufferSize` [in]

Specifies size of **puchMergeFontBuffer*, in bytes.

### `ppuchDestBuffer` [out]

A pointer to a variable of type unsigned char*. The **MergeFontPackage** function will allocate a buffer ***ppuchDestBuffer*, using *lpfnAllocate* and *lpfnReAllocate*. On successful return, that buffer will contain the resulting merged or expanded font. The application is responsible for eventually freeing that buffer.

### `pulDestBufferSize` [out]

Points to an unsigned long, which on successful return will specify the allocated size of buffer ***ppuchDestBuffer*.

### `pulBytesWritten` [out]

Points to an unsigned long, which on successful return will specify the number of bytes actually used in buffer ***ppuchDestBuffer*.

### `usMode` [in]

Specifies what kind of process to perform. Select one of these values; they cannot be combined.

| Value | Meaning |
| --- | --- |
| **TTFMFP_SUBSET** | Copies a simple working font; see remarks below.<br><br>*puchMergeFontBuffer* will be ignored; *puchFontPackageBuffer* should contain a working font created by [CreateFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-createfontpackage) with *usSubsetFormat* set to TTFCFP_SUBSET; this working font will simply be copied to *ppuchDestBuffer*. |
| **TTFMFP_SUBSET1** | Turns a font package into a mergeable working font; see remarks below.<br><br>*puchMergeFontBuffer* will be ignored; *puchFontPackageBuffer* should contain a mergeable working font created by [CreateFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-createfontpackage) with *usSubsetFormat* set to TTFCFP_SUBSET1. The result in ***ppuchDestBuffer* will be a working font that may be merged with later. |
| **TTFMFP_DELTA** | Merges a Delta font package into a mergeable working font; see remarks below.<br><br>**puchFontPackageBuffer* should contain a font package created by [CreateFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-createfontpackage) with *usSubsetFormat* set to TTFCFP_DELTA and *puchMergeFontBuffer* should contain a font package created by a prior call to **MergeFontPackage** with *usMode* set to TTFMFP_SUBSET1 or TTFMFP_DELTA. The resulting merged font in ***ppuchDestBuffer* will be a working font that may be merged with later. |

### `lpfnAllocate` [in]

The callback function to allocate initial memory for *ppuchDestBuffer* and for temporary buffers.

### `lpfnReAllocate` [in]

The callback function to reallocate memory for *ppuchDestBuffer* and for temporary buffers.

### `lpfnFree` [in]

The callback function to free up memory allocated by *lpfnAllocate* and *lpfnReAllocate*.

### `lpvReserved` [in]

Must be set to **NULL**.

## Return value

If the function is successful, returns zero.

Otherwise, returns a nonzero value. See [Font-Package Function Error Messages](https://learn.microsoft.com/windows/desktop/gdi/font-package-function-error-messages) for possible error returns.

## Remarks

This function handles four distinct, related entities, each representing a subset font:

| Entity | Produced by | Directly usable as a font |
| --- | --- | --- |
| Simple working font | [CreateFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-createfontpackage) with *usSubsetFormat* set to TFCFP_SUBSET. | Yes |
| Font package | [CreateFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-createfontpackage) with *usSubsetFormat* set to TTFCFP_SUBSET1. | No |
| Delta font package | [CreateFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-createfontpackage) with *usSubsetFormat* set to TTFCFP_DELTA. | No |
| Mergeable working font | **MergeFontPackage** with *usMode* set to TTFMFP_SUBSET1 or TTFMFP_DELTA. | Yes |

## See also

[CFP_ALLOCPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_allocproc)

[CFP_FREEPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_freeproc)

[CFP_REALLOCPROC](https://learn.microsoft.com/windows/desktop/api/fontsub/nc-fontsub-cfp_reallocproc)

[CreateFontPackage](https://learn.microsoft.com/windows/desktop/api/fontsub/nf-fontsub-createfontpackage)