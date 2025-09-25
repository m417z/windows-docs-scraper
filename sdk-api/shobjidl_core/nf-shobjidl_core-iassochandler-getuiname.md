# IAssocHandler::GetUIName

## Description

Retrieves the display name of an application.

## Parameters

### `ppsz` [out]

Type: **LPWSTR***

When this method returns, contains the address of a pointer to a null-terminated, Unicode string that contains the display name of the application.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAssocHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iassochandler)

[IAssocHandler::GetName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iassochandler-getname)