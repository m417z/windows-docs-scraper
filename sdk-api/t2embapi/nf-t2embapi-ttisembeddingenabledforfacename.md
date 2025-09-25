# TTIsEmbeddingEnabledForFacename function

## Description

Determines whether embedding is enabled for a specified font.

## Parameters

### `lpszFacename` [in]

Pointer to the facename of the font, such as Arial Bold.

### `pbEnabled` [out]

Pointer to a boolean, set upon completion of the function. A nonzero value indicates the font is not in the typeface exclusion list, and, therefore, can be embedded without conflict.

## Return value

If successful, returns E_NONE.

*pbEnabled* is filled with a boolean that indicates whether embedding is currently enabled within a device context for the specified font.

Otherwise, returns an error code described in [Embedding-Function Error Messages](https://learn.microsoft.com/windows/desktop/gdi/font-embedding-function-error-messages).

## Remarks

If successful, the client may embed the font.

For additional information on the exclusion list, see the Remarks section of [TTEnableEmbeddingForFacename](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttenableembeddingforfacename).

## See also

[TTEnableEmbeddingForFacename](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttenableembeddingforfacename)

[TTGetEmbeddedFontInfo](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttgetembeddedfontinfo)

[TTGetEmbeddingType](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttgetembeddingtype)

[TTIsEmbeddingEnabled](https://learn.microsoft.com/windows/desktop/api/t2embapi/nf-t2embapi-ttisembeddingenabled)