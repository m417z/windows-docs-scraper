# IShellMenu::Initialize

## Description

Initializes a menu band.

## Parameters

### `psmc` [in, optional]

Type: **[IShellMenuCallback](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellmenucallback)***

A pointer to an [IShellMenuCallback](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellmenucallback) interface. This interface receives notifications from the menu. This value can be **NULL**.

### `uId` [in]

Type: **UINT**

The identifier of the selected menu item. Set this parameter to -1 for the menu itself.

### `uIdAncestor` [in]

Type: **UINT**

### `dwFlags` [in]

Type: **DWORD**

Flags that control how the menu operates.

A combination of the following option values:

| Value | Meaning |
| --- | --- |
| **SMINIT_DEFAULT** | No options. |
| **SMINIT_RESTRICT_DRAGDROP** | Do not allow drag-and-drop. |
| **SMINIT_TOPLEVEL** | This is the top band. |
| **SMINIT_CACHED** | Do not destroy the band when the window is closed. |

In addition to the values above, one of the following layout options:

| Value | Meaning |
| --- | --- |
| **SMINIT_VERTICAL** | Specifies a vertical band. |
| **SMINIT_HORIZONTAL** | Specifies a horizontal band. |

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.