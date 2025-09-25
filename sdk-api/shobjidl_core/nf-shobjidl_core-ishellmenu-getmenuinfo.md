# IShellMenu::GetMenuInfo

## Description

Gets information from the [IShellMenu::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellmenu-initialize) method.

## Parameters

### `ppsmc` [out, optional]

Type: **[IShellMenuCallback](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellmenucallback)****

When this method returns, contains the address of a pointer to the [IShellMenuCallback](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellmenucallback) interface that you specified when you called [IShellMenu::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellmenu-initialize). This pointer can be **NULL**.

### `puId` [out, optional]

Type: **UINT***

When this method returns, contains a pointer to a **UINT** value that receives the *uID* value that you specified when you called [IShellMenu::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellmenu-initialize). This pointer can be **NULL**.

### `puIdAncestor` [out, optional]

Type: **UINT***

When this method returns, contains a pointer to a **UINT** value that receives the *uIdAncestor* value that you specified when you called [IShellMenu::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellmenu-initialize). This pointer can be **NULL**.

### `pdwFlags` [out]

Type: **DWORD***

When this method returns, contains a pointer to a **DWORD** value that receives the *dwFlags* value that you specified when you called [IShellMenu::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellmenu-initialize). This pointer can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.