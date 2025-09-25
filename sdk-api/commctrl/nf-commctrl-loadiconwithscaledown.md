# LoadIconWithScaleDown function

## Description

Loads an icon. If the icon is not a standard size, this function scales down a larger image instead of scaling up a smaller image.

## Parameters

### `hinst` [in]

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the module of either a DLL or executable (.exe) file that contains the icon to be loaded. For more information, see [GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea).

To load a predefined system icon or a standalone icon file, set this parameter to **NULL**.

### `pszName` [in]

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a null-terminated, Unicode buffer that contains location information about the icon to load.

If *hinst* is non-**NULL**, *pszName* specifies the icon resource either by name or ordinal. This ordinal must be packaged by using the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcew) macro.

If *hinst* is **NULL**, *pszName* specifies the [identifier (beginning with the IDI\_ prefix)](https://learn.microsoft.com/windows/win32/menurc/about-icons) of a predefined system icon to load.

### `cx` [in]

Type: **int**

The desired width, in pixels, of the icon.

### `cy` [in]

Type: **int**

The desired height, in pixels, of the icon.

### `phico` [out]

Type: **[HICON](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

When this function returns, contains a pointer to the handle of the loaded icon.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The contents of the buffer pointed to by *pszName* do not fit any of the expected interpretations. |

## Remarks

This function will first search the icon file for an icon having exactly the same size. If a match is not found, then unless both *cx* and *cy* match one of the standard icon sizes—16, 32, 48, or 256 pixels— the next largest icon is selected and then scaled down to the desired size. For example, if an icon with an x dimension of 40 pixels is requested by the callign application, the 48-pixel icon is used and scaled down to 40 pixels. In contrast, the [LoadImage](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_loadimagea) function selects the 32-pixel icon and scales it up to 40 pixels.

If the function is unable to locate a larger icon, it defaults to the standard behavior of finding the next smallest icon and scaling it up to the desired size.