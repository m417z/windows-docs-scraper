# IMFMediaEngineSrcElements::GetMedia

## Description

Gets the intended media type of an element in the list.

## Parameters

### `index` [in]

The zero-based index of the source element. To get the number of source elements, call [IMFMediaEngineSrcElements::GetLength](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaenginesrcelements-getlength).

### `pMedia` [out]

Receives a **BSTR** that contains a media-query string. The caller must free the **BSTR** by calling **SysFreeString**. If no media type is set, this parameter receives the value **NULL**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The string returned in *pMedia* should be a media-query string that conforms to the W3C *Media Queries* specification.

## See also

[IMFMediaEngineSrcElements](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaenginesrcelements)