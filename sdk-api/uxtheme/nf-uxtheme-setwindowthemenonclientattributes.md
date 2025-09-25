# SetWindowThemeNonClientAttributes function

## Description

Sets non-client attributes to control how visual styles are applied to a specified window.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window in which to apply changes.

### `dwMask` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A bitmask that describes which values are to be modified. Can be a combination of the [WTNCA](https://learn.microsoft.com/windows/desktop/Controls/wtnca) constants.

### `dwAttributes` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of flags that modify window visual style attributes based on *dwMask*. Can be a combination of the [WTNCA](https://learn.microsoft.com/windows/desktop/Controls/wtnca) constants.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.