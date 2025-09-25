# SetWindowThemeAttribute function

## Description

Sets attributes to control how visual styles are applied to a specified window.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a window to apply changes to.

### `eAttribute` [in]

Type: **enum WINDOWTHEMEATTRIBUTETYPE**

Value of type [WINDOWTHEMEATTRIBUTETYPE](https://learn.microsoft.com/windows/desktop/api/uxtheme/ne-uxtheme-windowthemeattributetype) that specifies the type of attribute to set. The value of this parameter determines the type of data that should be passed in the *pvAttribute* parameter. Can be the following value.

| Value | Meaning |
| --- | --- |
| **WTA_NONCLIENT** | Specifies non-client related attributes. *pvAttribute* must be a pointer of type [WTA_OPTIONS](https://learn.microsoft.com/windows/desktop/api/uxtheme/ns-uxtheme-wta_options). |

### `pvAttribute` [in]

Type: **[PVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer that specifies attributes to set. Type is determined by the value of the *eAttribute* value.

### `cbAttribute` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the size, in bytes, of the data pointed to by *pvAttribute*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[WINDOWTHEMEATTRIBUTETYPE](https://learn.microsoft.com/windows/desktop/api/uxtheme/ne-uxtheme-windowthemeattributetype)