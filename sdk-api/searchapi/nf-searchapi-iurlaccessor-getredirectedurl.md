# IUrlAccessor::GetRedirectedURL

## Description

Gets the redirected URL for the current item.

## Parameters

### `wszRedirectedURL` [out]

Type: **WCHAR[]**

Receives the redirected URL as a Unicode string, not including the terminating **NULL**.

### `dwSize` [in]

Type: **DWORD**

Size in **TCHAR****s** of *wszRedirectedURL*, not including the terminating **NULL**.

### `pdwLength` [out]

Type: **DWORD***

Receives a pointer to the number of
**TCHAR****s**
written to *wszRedirectedURL*,
not including the terminating **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

File URLs are not redirected. This method applies only to a content source of HTTP.

If this method is implemented, the URL that is passed to [ISearchProtocol::CreateAccessor](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchprotocol-createaccessor) will be redirected to the value returned by this method. All subsequent relative URL links will be processed based on the redirected URL.