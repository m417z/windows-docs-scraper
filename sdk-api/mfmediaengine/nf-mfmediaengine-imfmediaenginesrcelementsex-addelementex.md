# IMFMediaEngineSrcElementsEx::AddElementEx

## Description

Provides an enhanced version of [IMFMediaEngineSrcElements::AddElement](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaenginesrcelements-addelement) to add the key system intended to be used with content to an element.

## Parameters

### `pURL`

The URL of the source element, or **NULL**.

### `pType`

The MIME type of the source element, or **NULL**.

### `pMedia`

A media-query string that specifies the intended media type, or **NULL**. If specified, the string should conform to the W3C *Media Queries* specification.

### `keySystem`

The media key session.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineSrcElementsEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaenginesrcelementsex)