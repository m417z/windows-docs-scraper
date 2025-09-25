# GetThemeSysBool function

## Description

Retrieves the Boolean value of a system metric.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to theme data.

### `iBoolId` [in]

Type: **int**

Value of type **int** that specifies the system Boolean metric desired. May be the following value.

| Value | Meaning |
| --- | --- |
| **TMT_FLATMENUS** | Describes how menus are drawn. If **TRUE**, menus are drawn without shadows. If **FALSE**, menus have shadows underneath them. |

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value of desired system metric.

## Remarks

If the theme data handle is not a **NULL** handle, this function returns the desired **BOOL** from the SysMetrics section of the visual style. If the theme data handle is **NULL**, this function returns the value of the specified system Boolean.