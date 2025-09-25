# IShellMenu::GetMenu

## Description

Gets the menu information set by calling [IShellMenu::SetMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellmenu-setmenu).

## Parameters

### `phmenu` [out]

Type: **HMENU***

When this method returns, contains a pointer to an **HMENU** value that receives the *hmenu* value that you specified when you called [IShellMenu::SetMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellmenu-setmenu). This value can be **NULL**.

### `phwnd` [out]

Type: **HWND***

When this method returns, contains a pointer to an **HWND** value that receives the *hwnd* value that you specified when you called [IShellMenu::SetMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellmenu-setmenu). This value can be **NULL**.

### `pdwFlags` [out]

Type: **DWORD***

When this method returns, contains a pointer to a **DWORD** value that receives the *dwFlags* value that you specified when you called [IShellMenu::SetMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellmenu-setmenu). This value can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.