# IUrlAccessor::GetCLSID

## Description

Gets the [CLSID](https://learn.microsoft.com/windows/desktop/com/clsid) for the document type of the URL item being processed.

## Parameters

### `pClsid` [out]

Type: **CLSID***

Receives a pointer to the [CLSID](https://learn.microsoft.com/windows/desktop/com/clsid) for the document type of the URL item being processed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If this information is not available, you can return E_NOTIMPL or E_FAIL.