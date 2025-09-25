# IAssocHandler::MakeDefault

## Description

Sets an application as the default application for this file type.

## Parameters

### `pszDescription` [in]

Type: **LPCWSTR**

A pointer to a null-terminated, Unicode string that contains the display name of the application.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAssocHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iassochandler)

[IAssocHandler::GetUIName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iassochandler-getuiname)