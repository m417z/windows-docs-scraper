# IMFMediaEngineSrcElements::AddElement

## Description

Adds a source element to the end of the list.

## Parameters

### `pURL` [in]

The URL of the source element, or **NULL**.

### `pType` [in]

The MIME type of the source element, or **NULL**.

### `pMedia` [in]

A media-query string that specifies the intended media type, or **NULL**. If specified, the string should conform to the W3C *Media Queries* specification.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Any of the parameters to this method can be **NULL**.

This method allocates copies of the **BSTR**s that are passed in.

## See also

[IMFMediaEngineSrcElements](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaenginesrcelements)