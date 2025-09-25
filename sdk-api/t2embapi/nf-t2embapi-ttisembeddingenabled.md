# TTIsEmbeddingEnabled function

## Description

Determines whether the typeface exclusion list contains a specified font.

## Parameters

### `hDC` [in]

Device context handle.

### `pbEnabled` [out]

Pointer to a boolean, set upon completion of the function. A nonzero value indicates the font is not in the typeface exclusion list and, therefore, can be embedded without conflict.

## Return value

If successful, returns E_NONE.

The parameter *pbEnabled* is filled with a boolean that indicates whether embedding is currently enabled within a device context.

Otherwise, returns an error code described in [Embedding-Function Error Messages](https://learn.microsoft.com/windows/desktop/gdi/font-embedding-function-error-messages).

## Remarks

If the specified font is listed, the client should not embed the font.

For additional information on the exclusion list, see the Remarks section of [TTEnableEmbeddingForFacename](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttenableembeddingforfacename).

## See also

[TTEnableEmbeddingForFacename](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttenableembeddingforfacename)

[TTGetEmbeddedFontInfo](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttgetembeddedfontinfo)

[TTGetEmbeddingType](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttgetembeddingtype)

[TTIsEmbeddingEnabledForFacename](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttisembeddingenabledforfacename)