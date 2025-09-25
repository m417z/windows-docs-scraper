# SetWindowTheme function

## Description

Causes a window to use a different set of visual style information than its class normally uses.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the window whose visual style information is to be changed.

### `pszSubAppName` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string that contains the application name to use in place of the calling application's name. If this parameter is **NULL**, the calling application's name is used.

### `pszSubIdList` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string that contains a semicolon-separated list of CLSID names to use in place of the actual list passed by the window's class. If this parameter is **NULL**, the ID list from the calling class is used.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The theme manager retains the *pszSubAppName* and the *pszSubIdList* associations through the lifetime of the window, even if visual styles subsequently change. The window is sent a [WM_THEMECHANGED](https://learn.microsoft.com/windows/desktop/winmsg/wm-themechanged) message at the end of a **SetWindowTheme** call, so that the new visual style can be found and applied.

When *pszSubAppName* and *pszSubIdList* are **NULL**, the theme manager removes the previously applied associations. You can prevent visual styles from being applied to a specified window by specifying an empty string, (L""), which does not match any section entries.

#### Examples

The following example code gives a list-view control the appearance of a Windows Explorer list:

```cpp
SetWindowTheme(hwndList, L"Explorer", NULL);

```