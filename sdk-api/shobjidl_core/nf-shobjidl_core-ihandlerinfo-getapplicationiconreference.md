# IHandlerInfo::GetApplicationIconReference

## Description

Retrieves the icon of the application that implemented the handler.

## Parameters

### `value` [out]

Type: **LPWSTR***

A pointer to a string that, when this method returns successfully, receives the path of the icon.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IHandlerInfo](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ihandlerinfo)