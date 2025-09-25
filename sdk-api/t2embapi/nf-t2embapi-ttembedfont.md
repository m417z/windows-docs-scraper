# TTEmbedFont function

## Description

Creates a font structure containing the subsetted wide-character (16-bit) font. The current font of the device context (hDC) provides the font information.

This function passes the data to a client-defined callback routine for insertion into the document stream.

## Parameters

### `hDC` [in]

Device context handle.

### `ulFlags` [in]

Flag specifying the embedding request. This flag can have zero or more of the following values.

| Value | Meaning |
| --- | --- |
| **TTEMBED_EMBEDEUDC** | Include the associated EUDC font file data with the font structure. |
| **TTEMBED_RAW** | Return a font structure containing the full character set, non-compressed. This is the default behavior of the function. |
| **TTEMBED_SUBSET** | Return a subsetted font containing only the glyphs indicated by the *pusCharCodeSet* or *pulCharCodeSet* parameter. These character codes must be denoted as 16-bit or UCS-4 characters, as appropriate for the parameter. |
| **TTEMBED_TTCOMPRESSED** | Return a compressed font structure. |

### `ulCharSet` [in]

Flag specifying the character set of the font to be embedded. This flag can have one of the following values.

| Value | Meaning |
| --- | --- |
| **CHARSET_UNICODE** | Unicode character set, requiring 16-bit character encoding. |
| **CHARSET_SYMBOL** | Symbol character set, requiring 16-bit character encoding. |

### `pulPrivStatus` [out]

Pointer to flag indicating embedding privileges of the font. This flag can have one of the following values. This function returns the least restrictive license granted.

| Value | Meaning |
| --- | --- |
| **EMBED_PREVIEWPRINT** | Preview and Print Embedding. |
| **EMBED_EDITABLE** | Editable Embedding. |
| **EMBED_INSTALLABLE** | Installable Embedding. |
| **EMBED_NOEMBEDDING** | Restricted License Embedding. |

### `pulStatus` [out]

Pointer to a bitfield containing status information about the embedding request. This field is filled upon completion of this function. No bits are currently defined for this parameter.

### `lpfnWriteToStream`

Pointer to the client-defined callback function, which writes the font structure to the document stream. See [WRITEEMBEDPROC](https://learn.microsoft.com/previous-versions/dd145225(v=vs.85)).

### `lpvWriteStream` [in]

A token to represent the output stream.

### `pusCharCodeSet` [in]

Pointer to the buffer containing the optional Unicode character codes for subsetting. This field is only used for subsetting a font and is ignored if the *ulFlags* field does not specify TTEMBED_SUBSET.

### `usCharCodeCount` [in]

The number of characters in the list of characters indicated by *pusCharCodeSet*. This field is only used for subsetting a font and is ignored if the *ulFlags* field does not specify TTEMBED_SUBSET.

### `usLanguage` [in]

Specifies which language in the name table to keep when subsetting. Set to 0 to keep all languages. This field is only used for subsetting a font and is ignored if the *ulFlags* field does not specify TTEMBED_SUBSET.

### `pTTEmbedInfo` [in, optional]

Pointer to a [TTEMBEDINFO](https://learn.microsoft.com/windows/desktop/api/t2embapi/ns-t2embapi-ttembedinfo) structure containing the URLs from which the embedded font object may be legitimately referenced. If *pTTEmbedInfo* is **NULL**, no URLs will be added to the embedded font object and no URL checking will occur when the client calls [TTLoadEmbeddedFont](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttloadembeddedfont).

## Return value

If the embedding is successful, returns E_NONE.

The font structure is incorporated into the document stream by the client. *pulPrivStatus* is set, indicating the embedding privileges of the font; and *pulStatus* is set to provide results of the embedding operation.

Otherwise, returns an error code described in [Embedding-Function Error Messages](https://learn.microsoft.com/windows/desktop/gdi/font-embedding-function-error-messages).

## Remarks

Clients are responsible for determining and indicating the character set of the font.

For information about embedding UCS-4 characters, see [TTEmbedFontEx](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttembedfontex). For information about embedding font characters from a file, see [TTEmbedFontFromFileA](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttembedfontfromfilea).

## See also

[TTEMBEDINFO](https://learn.microsoft.com/windows/desktop/api/t2embapi/ns-t2embapi-ttembedinfo)

[TTEmbedFontEx](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttembedfontex)

[TTEmbedFontFromFileA](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttembedfontfromfilea)

[TTLoadEmbeddedFont](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttloadembeddedfont)