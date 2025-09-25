# GetSysColor function

## Description

Retrieves the current color of the specified display element. Display elements are the parts of a window and the display that appear on the system display screen.

## Parameters

### `nIndex` [in]

Type: **int**

The display element whose color is to be retrieved. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **COLOR_3DDKSHADOW**<br><br>21 | Dark shadow for three-dimensional display elements.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_3DFACE**<br><br>15 | Face color for three-dimensional display elements and for dialog box backgrounds. |
| **COLOR_3DHIGHLIGHT**<br><br>20 | Highlight color for three-dimensional display elements (for edges facing the light source.)<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_3DHILIGHT**<br><br>20 | Highlight color for three-dimensional display elements (for edges facing the light source.)<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_3DLIGHT**<br><br>22 | Light color for three-dimensional display elements (for edges facing the light source.)<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_3DSHADOW**<br><br>16 | Shadow color for three-dimensional display elements (for edges facing away from the light source).<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_ACTIVEBORDER**<br><br>10 | Active window border.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_ACTIVECAPTION**<br><br>2 | Active window title bar. <br><br>The associated foreground color is **COLOR_CAPTIONTEXT**.<br><br>Specifies the left side color in the color gradient of an active window's title bar if the gradient effect is enabled.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_APPWORKSPACE**<br><br>12 | Background color of multiple document interface (MDI) applications.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_BACKGROUND**<br><br>1 | Desktop.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_BTNFACE**<br><br>15 | Face color for three-dimensional display elements and for dialog box backgrounds. The associated foreground color is **COLOR_BTNTEXT**.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_BTNHIGHLIGHT**<br><br>20 | Highlight color for three-dimensional display elements (for edges facing the light source.)<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_BTNHILIGHT**<br><br>20 | Highlight color for three-dimensional display elements (for edges facing the light source.)<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_BTNSHADOW**<br><br>16 | Shadow color for three-dimensional display elements (for edges facing away from the light source).<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_BTNTEXT**<br><br>18 | Text on push buttons. The associated background color is COLOR_BTNFACE. |
| **COLOR_CAPTIONTEXT**<br><br>9 | Text in caption, size box, and scroll bar arrow box. The associated background color is COLOR_ACTIVECAPTION.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_DESKTOP**<br><br>1 | Desktop.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_GRADIENTACTIVECAPTION**<br><br>27 | Right side color in the color gradient of an active window's title bar. COLOR_ACTIVECAPTION specifies the left side color. Use SPI_GETGRADIENTCAPTIONS with the [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function to determine whether the gradient effect is enabled.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_GRADIENTINACTIVECAPTION**<br><br>28 | Right side color in the color gradient of an inactive window's title bar. COLOR_INACTIVECAPTION specifies the left side color.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_GRAYTEXT**<br><br>17 | Grayed (disabled) text. This color is set to 0 if the current display driver does not support a solid gray color. |
| **COLOR_HIGHLIGHT**<br><br>13 | Item(s) selected in a control. The associated foreground color is COLOR_HIGHLIGHTTEXT. |
| **COLOR_HIGHLIGHTTEXT**<br><br>14 | Text of item(s) selected in a control. The associated background color is COLOR_HIGHLIGHT. |
| **COLOR_HOTLIGHT**<br><br>26 | Color for a hyperlink or hot-tracked item. The associated background color is COLOR_WINDOW. |
| **COLOR_INACTIVEBORDER**<br><br>11 | Inactive window border.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_INACTIVECAPTION**<br><br>3 | Inactive window caption.<br><br>The associated foreground color is COLOR_INACTIVECAPTIONTEXT.<br><br>Specifies the left side color in the color gradient of an inactive window's title bar if the gradient effect is enabled. <br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_INACTIVECAPTIONTEXT**<br><br>19 | Color of text in an inactive caption. The associated background color is COLOR_INACTIVECAPTION.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_INFOBK**<br><br>24 | Background color for tooltip controls. The associated foreground color is COLOR_INFOTEXT.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_INFOTEXT**<br><br>23 | Text color for tooltip controls. The associated background color is COLOR_INFOBK.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_MENU**<br><br>4 | Menu background. The associated foreground color is COLOR_MENUTEXT.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_MENUHILIGHT**<br><br>29 | The color used to highlight menu items when the menu appears as a flat menu (see [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)). The highlighted menu item is outlined with COLOR_HIGHLIGHT.<br><br>**Windows 2000, Windows 10 or greater:** This value is not supported. |
| **COLOR_MENUBAR**<br><br>30 | The background color for the menu bar when menus appear as flat menus (see [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)). However, COLOR_MENU continues to specify the background color of the menu popup.<br><br>**Windows 2000, Windows 10 or greater:** This value is not supported. |
| **COLOR_MENUTEXT**<br><br>7 | Text in menus. The associated background color is COLOR_MENU.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_SCROLLBAR**<br><br>0 | Scroll bar gray area.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_WINDOW**<br><br>5 | Window background. The associated foreground colors are COLOR_WINDOWTEXT and COLOR_HOTLITE. |
| **COLOR_WINDOWFRAME**<br><br>6 | Window frame.<br><br>**Windows 10 or greater:** This value is not supported. |
| **COLOR_WINDOWTEXT**<br><br>8 | Text in windows. The associated background color is COLOR_WINDOW. |

## Return value

Type: **DWORD**

The function returns the red, green, blue (RGB) color value of the given element.

If the *nIndex* parameter is out of range, the return value is zero. Because zero is also a valid RGB value, you cannot use **GetSysColor** to determine whether a system color is supported by the current platform. Instead, use the [GetSysColorBrush](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolorbrush) function, which returns **NULL** if the color is not supported.

## Remarks

To display the component of the RGB value, use the [GetRValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getrvalue), [GetGValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getgvalue), and [GetBValue](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbvalue) macros.

System colors for monochrome displays are usually interpreted as shades of gray.

To paint with a system color brush, an application should use `GetSysColorBrush(nIndex)`, instead of `CreateSolidBrush(GetSysColor(nIndex))`, because [GetSysColorBrush](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolorbrush) returns a cached brush, instead of allocating a new one.

Color is an important visual element of most user interfaces. For guidelines about using color in your applications, see [Color - Win32](https://learn.microsoft.com/windows/win32/uxguide/vis-color) and [Color in Windows 11](https://learn.microsoft.com/windows/apps/design/signature-experiences/color).

### Windows 10/11 system colors

This table shows the values that are supported in Windows 10 and Windows 11 with color values from the Windows 11 _Aquatic_ contrast theme.

| Color swatch | Description |
|---------|---------|
|:::image type="icon" source="images/sys-color/aquatic-color-window.png":::| **COLOR_WINDOW**Background of pages, panes, popups, and windows.<br><br>Pair with COLOR_WINDOWTEXT |
|:::image type="icon" source="images/sys-color/aquatic-color-windowtext.png"::: | **COLOR_WINDOWTEXT**Headings, body copy, lists, placeholder text, app and window borders, any UI that can't be interacted with.Pair with COLOR_WINDOW |
|:::image type="icon" source="images/sys-color/aquatic-color-hotlight.png":::| **COLOR_HOTLIGHT**Hyperlinks.Pair with COLOR_WINDOW |
|:::image type="icon" source="images/sys-color/aquatic-color-graytext.png":::| **COLOR_GRAYTEXT**Inactive (disabled) UI.Pair with COLOR_WINDOW |
|:::image type="icon" source="images/sys-color/aquatic-color-highlighttext.png":::| **COLOR_HIGHLIGHTTEXT**Foreground color for text or UI that is in selected, interacted with (hover, pressed), or in progress.Pair with COLOR_HIGHLIGHT |
|:::image type="icon" source="images/sys-color/aquatic-color-highlight.png":::| **COLOR_HIGHLIGHT**Background or accent color for UI that is in selected, interacted with (hover, pressed), or in progress.Pair with COLOR_HIGHLIGHTTEXT |
|:::image type="icon" source="images/sys-color/aquatic-color-btntext.png":::| **COLOR_BTNTEXT**Foreground color for buttons and any UI that can be interacted with.Pair with COLOR_3DFACE |
|:::image type="icon" source="images/sys-color/aquatic-color-3dface.png":::| **COLOR_3DFACE**Background color for buttons and any UI that can be interacted with.Pair with COLOR_BTNTEXT |

These images show how the colors appear when used on a background set to **COLOR_WINDOW**.

| Example | Values |
|---------|---------|
|:::image type="content" source="images/sys-color/aquatic-example-windowtext.png" alt-text="A window with text using the window text color." border="false"::: | **COLOR_WINDOWTEXT** |
|:::image type="content" source="images/sys-color/aquatic-example-hotlight.png" alt-text="A window with hyperlink text using the hot light color." border="false":::| **COLOR_HOTLIGHT** |
|:::image type="content" source="images/sys-color/aquatic-example-graytext.png" alt-text="A window with inactive text using the gray text color." border="false":::| **COLOR_GRAYTEXT** |
|:::image type="content" source="images/sys-color/aquatic-example-highlighttext+highlight.png" alt-text="A window with text using the highlight text color on the highlight color." border="false":::|**COLOR_HIGHLIGHTTEXT + HIGHLIGHT** |
|:::image type="content" source="images/sys-color/aquatic-example-btntext+3dface.png" alt-text="A window with a button using the 3d face color and button text using the button text color." border="false":::| **COLOR_BTNTEXT + COLOR_3DFACE**

#### Examples

For an example, see
[SetSysColors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setsyscolors).

## See also

[CreateSolidBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createsolidbrush)

[GetSysColorBrush](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsyscolorbrush)

[SetSysColors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setsyscolors)

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)