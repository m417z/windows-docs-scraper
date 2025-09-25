# IBrowserService::GetBrowserByIndex

## Description

Deprecated. Retrieves the browser with the given index.

## Parameters

### `dwID` [in]

Type: **DWORD**

A value of type **DWORD** that indicates the index of the browser.

### `ppunk` [out]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

The address of a pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) that indicates the browser with the given index. The calling application must release this resource when it is no longer needed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.