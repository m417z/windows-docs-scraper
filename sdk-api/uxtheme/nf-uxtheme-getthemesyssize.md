# GetThemeSysSize function

## Description

Retrieves the value of a system size metric from theme data.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to theme data.

### `iSizeId` [in]

Type: **int**

Value of type **int** that specifies the system size metric desired. The following values are valid:

| Value | Meaning |
| --- | --- |
| **SM_CXBORDER** | Specifies the width of a border. |
| **SM_CXVSCROLL** | Specifies the width of a scroll bar. |
| **SM_CXHSCROLL** | Specifies the height of a scroll bar. |
| **SM_CXSIZE** | Specifies the width of a caption. |
| **SM_CYSIZE** | Specifies the height of a caption. |
| **SM_CXSMSIZE** | Specifies the width of a small caption. |
| **SM_CYSMSIZE** | Specifies the height of a small caption. |
| **SM_CXMENUSIZE** | Specifies the width of a menu bar. |
| **SM_CYMENUSIZE** | Specifies the height of a menu bar. |
| **SM_CXPADDEDBORDER** | Specifies the amount of border padding for captioned windows. |

## Return value

Type: **int**

Returns the size in pixels.

## Remarks

 If *hTheme* is  **not**  **NULL**, this function returns the size stored in the current visual style (SysMetrics section of the visual style) scaled to the current screen dpi. If *hTheme* is **NULL**, this function returns the global system metric in pixels that is scaled to the current dpi only if the application is marked as dpi-aware; otherwise, the pixels returned are unscaled.