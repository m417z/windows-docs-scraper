# CreateIconFromResourceEx function

## Description

Creates an icon or cursor from resource bits describing the icon.

## Parameters

### `presbits` [in]

Type: **PBYTE**

The DWORD-aligned buffer pointer containing the icon (**RT_ICON**) or cursor (**RT_CURSOR**) resource bits. These bits are typically loaded by calls to the [LookupIconIdFromDirectoryEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-lookupiconidfromdirectoryex) and [LoadResource](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadresource) functions.

See [Cursor and Icon Resources](https://learn.microsoft.com/windows/win32/menurc/resource-file-formats#cursor-and-icon-resources) for more info on icon and cursor resource format.

### `dwResSize` [in]

Type: **DWORD**

The size, in bytes, of the set of bits pointed to by the *pbIconBits* parameter.

### `fIcon` [in]

Type: **BOOL**

Indicates whether an icon or a cursor is to be created. If this parameter is **TRUE**, an icon is to be created. If it is **FALSE**, a cursor is to be created.

The [LOCALHEADER](https://learn.microsoft.com/windows/win32/menurc/localheader) structure defines cursor hotspot and is the first data read from the cursor resource bits.

### `dwVer` [in]

Type: **DWORD**

The version number of the icon or cursor format for the resource bits pointed to by the *presbits* parameter. The value must be greater than or equal to 0x00020000 and less than or equal to 0x00030000. This parameter is generally set to 0x00030000.

### `cxDesired` [in]

Type: **int**

The width, in pixels, of the icon or cursor. If this parameter is zero and the *Flags* parameter is **LR_DEFAULTSIZE**, the function uses the **SM_CXICON** or **SM_CXCURSOR** system metric value to set the width. If this parameter is zero and **LR_DEFAULTSIZE** is not used, the function uses the actual resource width.

### `cyDesired` [in]

Type: **int**

The height, in pixels, of the icon or cursor. If this parameter is zero and the *Flags* parameter is **LR_DEFAULTSIZE**, the function uses the **SM_CYICON** or **SM_CYCURSOR** system metric value to set the height. If this parameter is zero and **LR_DEFAULTSIZE** is not used, the function uses the actual resource height.

### `Flags` [in]

Type: **UINT**

A combination of the following values.

| Value | Meaning |
| --- | --- |
| **LR_DEFAULTCOLOR**<br><br>0x00000000 | Uses the default color format. |
| **LR_DEFAULTSIZE**<br><br>0x00000040 | Uses the width or height specified by the system metric values for cursors or icons, if the *cxDesired* or *cyDesired* values are set to zero. If this flag is not specified and *cxDesired* and *cyDesired* are set to zero, the function uses the actual resource size. |
| **LR_MONOCHROME**<br><br>0x00000001 | Creates a monochrome icon or cursor. |
| **LR_SHARED**<br><br>0x00008000 | Shares the icon or cursor handle if the icon or cursor is created multiple times. If **LR_SHARED** is not set, a second call to **CreateIconFromResourceEx** for the same resource will create the icon or cursor again and return a different handle.<br><br>When you use this flag, the system will destroy the resource when it is no longer needed. <br><br>Do not use **LR_SHARED** for icons or cursors that have non-standard sizes, that may change after loading, or that are loaded from a file. |

## Return value

Type: **HICON**

If the function succeeds, the return value is a handle to the icon or cursor.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The [CreateIconFromResource](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconfromresource), **CreateIconFromResourceEx**, [CreateIconIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconindirect), [GetIconInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-geticoninfo), and [LookupIconIdFromDirectoryEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-lookupiconidfromdirectoryex) functions allow shell applications and icon browsers to examine and use resources throughout the system.

You should call [DestroyIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroyicon) for icons or [DestroyCursor](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroycursor) for cursors created with **CreateIconFromResourceEx**.

#### Examples

For an example, see [Sharing Icon Resources](https://learn.microsoft.com/windows/desktop/menurc/using-icons#sharing-icon-resources).

## See also

[BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader)

**Conceptual**

[CreateIconFromResource](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconfromresource)

[CreateIconIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconindirect)

[DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon)

[GetIconInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-geticoninfo)

[Icons](https://learn.microsoft.com/windows/desktop/menurc/icons)

[LoadResource](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadresource)

[LookupIconIdFromDirectoryEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-lookupiconidfromdirectoryex)

**Other Resources**

**Reference**