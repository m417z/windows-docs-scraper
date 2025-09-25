# IShellMenu::GetShellFolder

## Description

Gets the folder that the menu band is set to browse.

## Parameters

### `pdwFlags` [out]

Type: **DWORD***

When this method returns successfully, contains a pointer to a set of flag values that specify how the menu band operates.

Can return any of the following flags.

| Value | Meaning |
| --- | --- |
| **SMINIT_DEFAULT** | No options. |
| **SMINIT_RESTRICT_DRAGDROP** | Do not allow drag-and-drop. |
| **SMINIT_TOPLEVEL** | This is the top band. |
| **SMINIT_CACHED** | Do not destroy the band when the window is closed. |

Always returns one of the following flags.

| Value | Meaning |
| --- | --- |
| **SMINIT_VERTICAL** | Specifies a vertical band. |
| **SMINIT_HORIZONTAL** | Specifies a horizontal band. |

### `ppidl` [out]

Type: **PCIDLIST_ABSOLUTE***

When this method returns, contains the address of the folder's fully qualified [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist).

### `riid` [in]

Type: **REFIID**

The REFIID for the target folder.

### `ppv` [out]

Type: **void****

When this method returns successfully, contains the address of a pointer to the Shell folder object referenced by the *riid*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.