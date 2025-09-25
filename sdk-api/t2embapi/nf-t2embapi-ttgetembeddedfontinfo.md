# TTGetEmbeddedFontInfo function

## Description

Retrieves information about an embedded font, such as embedding permissions. **TTGetEmbeddedFontInfo** performs the same task as [TTLoadEmbeddedFont](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttloadembeddedfont) but does not allocate internal data structures for the embedded font.

## Parameters

### `ulFlags` [in]

Flags specifying the request. This flag can have zero or more of the following values.

| Value | Meaning |
| --- | --- |
| **TTEMBED_EMBEDEUDC** | Include the associated EUDC font file data with the font structure. |
| **TTEMBED_RAW** | Return a font structure containing the full character set, non-compressed. This is the default behavior of the function. |
| **TTEMBED_SUBSET** | Return a subsetted font containing only the glyphs indicated by the *pusCharCodeSet* or *pulCharCodeSet* parameter. These character codes must be denoted as 16-bit or UCS-4 characters, as appropriate for the parameter. |
| **TTEMBED_TTCOMPRESSED** | Return a compressed font structure. |

### `pulPrivStatus` [out]

On completion, indicates embedding privileges of the font. A list of possible values follows:

| Value | Meaning |
| --- | --- |
| **EMBED_PREVIEWPRINT** | Preview and Print Embedding. |
| **EMBED_EDITABLE** | Editable Embedding. |
| **EMBED_INSTALLABLE** | Installable Embedding. |
| **EMBED_NOEMBEDDING** | Restricted License Embedding. |

### `ulPrivs` [in]

Flag indicating a further restriction of embedding privileges, imposed by the client. See [TTLoadEmbeddedFont](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttloadembeddedfont) for additional information.

This flag must have one of the following values.

| Value | Meaning |
| --- | --- |
| **LICENSE_PREVIEWPRINT** | Preview and Print Embedding. |
| **LICENSE_EDITABLE** | Editable Embedding. |
| **LICENSE_INSTALLABLE** | Installable Embedding. |
| **LICENSE_NOEMBEDDING** | Restricted License Embedding. |
| **LICENSE_DEFAULT** | Use default embedding level. |

### `pulStatus` [out]

Pointer to a bitfield containing status information, and is filled upon completion of this function. The status can be zero or the following value:

| Value | Meaning |
| --- | --- |
| **TTLOAD_FONT_SUBSETTED** | The font loaded is a subset of the original font. |

### `lpfnReadFromStream`

[callback] Pointer to the client-defined callback function that reads the font structure from the document stream.

### `lpvReadStream` [in]

Currently undefined. Reserved for a pointer to the stream (font structure).

### `pTTLoadInfo` [in]

Pointer to a [TTLOADINFO](https://learn.microsoft.com/windows/desktop/api/t2embapi/ns-t2embapi-ttloadinfo) structure containing the URL from which the embedded font object has been obtained.

## Return value

If successful, returns E_NONE.

The location referenced by **pulPrivStatus* identifies embedding privileges of the font. The location referenced by **pulStatus* identifies whether a subset of the font is embedded.

Otherwise, returns an error code described in [Embedding-Function Error Messages](https://learn.microsoft.com/windows/desktop/gdi/font-embedding-function-error-messages).

## See also

[TTGetEmbeddingType](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttgetembeddingtype)

[TTGetNewFontName](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttgetnewfontname)

[TTLOADINFO](https://learn.microsoft.com/windows/desktop/api/t2embapi/ns-t2embapi-ttloadinfo)

[TTLoadEmbeddedFont](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttloadembeddedfont)