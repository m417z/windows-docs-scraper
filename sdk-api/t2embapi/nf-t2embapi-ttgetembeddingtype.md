# TTGetEmbeddingType function

## Description

Obtains the embedding privileges of a font.

## Parameters

### `hDC` [in]

Device context handle.

### `pulEmbedType` [in]

Pointer to flag indicating embedding privileges of the font. This flag can have one of the following values. This function returns the least restrictive license granted.

| Value | Meaning |
| --- | --- |
| **EMBED_PREVIEWPRINT** | Preview and Print Embedding. |
| **EMBED_EDITABLE** | Editable Embedding. |
| **EMBED_INSTALLABLE** | Installable Embedding. |
| **EMBED_NOEMBEDDING** | Restricted License Embedding. |

## Return value

If successful, returns E_NONE.

This function reads the embedding privileges stored in the font and transfers the privileges to *pulPrivStatus*.

Otherwise, returns an error code described in [Embedding-Function Error Messages](https://learn.microsoft.com/windows/desktop/gdi/font-embedding-function-error-messages).

## Remarks

Alternatively, an application can determine embedding privileges by using [TTLoadEmbeddedFont](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttloadembeddedfont) and then checking the value returned in *pulPrivStatus* for success or failure of the function.

## See also

[TTGetEmbeddedFontInfo](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttgetembeddedfontinfo)

[TTGetNewFontName](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttgetnewfontname)

[TTLoadEmbeddedFont](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttloadembeddedfont)