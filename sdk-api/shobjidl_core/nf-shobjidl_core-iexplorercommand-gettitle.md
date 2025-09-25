# IExplorerCommand::GetTitle

## Description

Gets the title text of the button or menu item that launches a specified Windows Explorer command item.

## Parameters

### `psiItemArray` [in]

Type: **[IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)***

A pointer to an [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray).

### `ppszName` [out]

Type: **LPWSTR***

Pointer to a buffer that, when this method returns successfully, receives the title string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.