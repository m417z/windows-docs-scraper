# CreateIconIndirect function

## Description

Creates an icon or cursor from an [ICONINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-iconinfo) structure.

## Parameters

### `piconinfo` [in]

Type: **PICONINFO**

A pointer to an [ICONINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-iconinfo) structure the function uses to create the icon or cursor.

## Return value

Type: **HICON**

If the function succeeds, the return value is a handle to the icon or cursor that is created.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The system copies the bitmaps in the [ICONINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-iconinfo) structure before creating the icon or cursor. Because the system may temporarily select the bitmaps in a device context, the **hbmMask** and **hbmColor** members of the **ICONINFO** structure should not already be selected into a device context. The application must continue to manage the original bitmaps and delete them when they are no longer necessary.

When you are finished using the icon, destroy it using the [DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon) function.

#### Examples

For an example, see [Creating a Cursor](https://learn.microsoft.com/windows/win32/menurc/using-cursors#creating-a-cursor).

## See also

**Conceptual**

[DestroyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroyicon)

[ICONINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-iconinfo)

[Icons](https://learn.microsoft.com/windows/desktop/menurc/icons)