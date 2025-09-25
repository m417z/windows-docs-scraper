# GetThemeSysColor function

## Description

Retrieves the value of a system color.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to theme data.

### `iColorId` [in]

Type: **int**

Value of type **int** that specifies the color number. May be one of the values listed in [GetSysColor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolor) for the *nIndex* parameter.

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The value of the specified system color.

## Remarks

If the theme data handle is not a **NULL** handle, this function returns the color from the SysMetrics section of the current visual style. If the theme data handle is **NULL**, this function returns the color matching the global system color.