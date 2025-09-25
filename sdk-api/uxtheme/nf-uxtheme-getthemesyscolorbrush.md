# GetThemeSysColorBrush function

## Description

Retrieves a system color brush.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to theme data.

### `iColorId` [in]

Type: **int**

Value of type **int** that specifies the number of the desired system color. May be one of the following values.

| Value | Meaning |
| --- | --- |
| **TMT_SCROLLBAR** | The color of scroll bars. |
| **TMT_BACKGROUND** | The color of the background. |
| **TMT_ACTIVECAPTION** | The color of the caption area on an active window. |
| **TMT_INACTIVECAPTION** | The color of the caption area on an inactive window. |
| **TMT_WINDOW** | The color of a window. |
| **TMT_WINDOWFRAME** | The color of the frame around a window. |
| **TMT_MENUTEXT** | The color of text drawn on a menu. |
| **TMT_WINDOWTEXT** | The color of text drawn in a window. |
| **TMT_CAPTIONTEXT** | The color of text drawn in the caption area of an active window. |
| **TMT_ACTIVEBORDER** | The color of the border around an active window. |
| **TMT_INACTIVEBORDER** | The color of the border around an inactive window. |
| **TMT_APPWORKSPACE** | The color of the application workspace. |
| **TMT_HIGHLIGHT** | The color of a highlight. |
| **TMT_HIGHLIGHTTEXT** | The color of highlighted text. |
| **TMT_BTNFACE** | The color of a button face. |
| **TMT_BTNSHADOW** | The color of the shadow underneath a button. |
| **TMT_GRAYTEXT** | The color of dimmed text. |
| **TMT_BTNTEXT** | The color of text contained within a button. |
| **TMT_INACTIVECAPTIONTEXT** | The color of the text in the caption area of an inactive window. |
| **TMT_BTNHIGHLIGHT** | The color of the highlight around a button. |
| **TMT_DKSHADOW3D** | The color of three-dimensional dark shadows. |
| **TMT_LIGHT3D** | The color of three-dimensional light areas. |
| **TMT_INFOTEXT** | The color of informational text. |
| **TMT_INFOBK** | The color of the background behind informational text. |
| **TMT_BUTTONALTERNATEFACE** | The color of the alternate face of a button. |
| **TMT_HOTTRACKING** | The color of highlight applied when a user moves the mouse over a control. |
| **TMT_GRADIENTACTIVECAPTION** | The gradient color applied to the caption area of an active window. |
| **TMT_GRADIENTINACTIVECAPTION** | The gradient color applied to the caption area of an inactive window. |
| **TMT_MENUHILIGHT** | The color of highlight drawn on a menu item when the user moves the mouse over it. |
| **TMT_MENUBAR** | The color of the menu bar. |

## Return value

Type: **[HBRUSH](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to brush data.

## Remarks

If the theme data handle is not a **NULL** handle, **GetThemeSysColorBrush** returns the brush that matches the specified color from the SysMetrics section of the visual style. If the theme data handle is **NULL**, the function returns the brush matching the global system color.

The brush handle that is returned by this function should be released when it is no longer needed using [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject).