# GetIconInfo function

## Description

Retrieves information about the specified icon or cursor.

## Parameters

### `hIcon` [in]

Type: **HICON**

A handle to the icon or cursor.

To retrieve information about a standard icon or cursor, specify the [identifier beginning with the IDI\_ prefix](https://learn.microsoft.com/windows/win32/menurc/about-icons) or the [identifier beginning with the IDC\_ prefix](https://learn.microsoft.com/windows/win32/menurc/about-cursors) in this parameter.

### `piconinfo` [out]

Type: **PICONINFO**

A pointer to an [ICONINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-iconinfo) structure. The function fills in the structure's members.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero and the function fills in the members of the specified [ICONINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-iconinfo) structure.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**GetIconInfo** creates bitmaps for the **hbmMask** and **hbmColor** or members of [ICONINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-iconinfo). The calling application must manage these bitmaps and delete them with [DeleteObject](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-deleteobject) call when they are no longer necessary.

### DPI Virtualization

This API does not participate in DPI virtualization. The output returned is not affected by the DPI of the calling thread.

## See also

**Conceptual**

[Bitmaps](https://learn.microsoft.com/windows/win32/gdi/bitmaps)

[Icons](https://learn.microsoft.com/windows/win32/menurc/icons)

[DeleteObject](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-deleteobject)

[GetObject](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-getobject)

[BITMAP](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmap)

[CreateIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-createicon)

[CreateIconFromResource](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-createiconfromresource)

[CreateIconIndirect](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-createiconindirect)

[DestroyIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroyicon)

[DrawIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-drawicon)

[DrawIconEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-drawiconex)

[LoadIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadicona)

[LookupIconIdFromDirectory](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-lookupiconidfromdirectory)

[ICONINFO](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-iconinfo)