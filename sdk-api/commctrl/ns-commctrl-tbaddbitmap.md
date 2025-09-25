# TBADDBITMAP structure

## Description

Adds a bitmap that contains button images to a toolbar.

## Members

### `hInst`

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the module instance with the executable file that contains a bitmap resource. To use bitmap handles instead of resource IDs, set this member to **NULL**.

You can add the system-defined button bitmaps to the list by specifying HINST_COMMCTRL as the **hInst** member and one of the following values as the **nID** member.

| Value | Meaning |
| --- | --- |
| **IDB_STD_LARGE_COLOR** | Large, color standard bitmaps. |
| **IDB_STD_SMALL_COLOR** | Small, color standard bitmaps. |
| **IDB_VIEW_LARGE_COLOR** | Small large, color view bitmaps. |
| **IDB_VIEW_SMALL_COLOR** | Small, color view bitmaps. |
| **IDB_HIST_NORMAL** | Windows Explorer travel buttons and favorites bitmaps in normal state. |
| **IDB_HIST_HOT** | Windows Explorer travel buttons and favorites bitmaps in hot state. |
| **IDB_HIST_DISABLED** | Windows Explorer travel buttons and favorites bitmaps in disabled state. |
| **IDB_HIST_PRESSED** | Windows Explorer travel buttons and favorites bitmaps in pressed state. |

### `nID`

Type: **[UINT_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If
**hInst** is **NULL**, set this member to the bitmap handle of the bitmap with the button images. Otherwise, set it to the resource identifier of the bitmap with the button images.

## Remarks

If
**nID** holds a bitmap handle, rather than a resource ID, do not destroy the bitmap until it has been replaced with [TB_REPLACEBITMAP](https://learn.microsoft.com/windows/desktop/Controls/tb-replacebitmap). Otherwise, the toolbar is destroyed.

Defined values can be used as indexes to the standard bitmaps. For more information, see [Toolbar Standard Button Image Index Values](https://learn.microsoft.com/windows/desktop/Controls/toolbar-standard-button-image-index-values).

The **TBADDBITMAP** structure is used with the [TB_ADDBITMAP](https://learn.microsoft.com/windows/desktop/Controls/tb-addbitmap) message.