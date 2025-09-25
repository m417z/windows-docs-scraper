# IMFMediaEngineSrcElements::GetURL

## Description

Gets the URL of an element in the list.

## Parameters

### `index` [in]

The zero-based index of the source element. To get the number of source elements, call [IMFMediaEngineSrcElements::GetLength](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaenginesrcelements-getlength).

### `pURL` [out]

Receives a **BSTR** that contains the URL of the source element. The caller must free the **BSTR** by calling **SysFreeString**. If no URL is set, this parameter receives the value **NULL**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineSrcElements](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaenginesrcelements)