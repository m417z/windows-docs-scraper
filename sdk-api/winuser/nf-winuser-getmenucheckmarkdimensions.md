# GetMenuCheckMarkDimensions function

## Description

Retrieves the dimensions of the default check-mark bitmap. The system displays this bitmap next to selected menu items. Before calling the [SetMenuItemBitmaps](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuitembitmaps) function to replace the default check-mark bitmap for a menu item, an application must determine the correct bitmap size by calling **GetMenuCheckMarkDimensions**.

**Note** The **GetMenuCheckMarkDimensions** function is included only for compatibility with 16-bit versions of Windows. Applications should use the [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) function with the **CXMENUCHECK** and **CYMENUCHECK** values to retrieve the bitmap dimensions.

## Return value

Type: **LONG**

The return value specifies the height and width, in pixels, of the default check-mark bitmap. The high-order word contains the height; the low-order word contains the width.

## See also

**Conceptual**

[Menus](https://learn.microsoft.com/windows/desktop/menurc/menus)

**Reference**

[SetMenuItemBitmaps](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setmenuitembitmaps)