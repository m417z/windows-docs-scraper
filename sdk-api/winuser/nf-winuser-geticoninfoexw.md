# GetIconInfoExW function

## Description

Retrieves information about the specified icon or cursor. **GetIconInfoEx** extends [GetIconInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-geticoninfo) by using the newer [ICONINFOEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-iconinfoexa) structure.

## Parameters

### `hicon` [in]

Type: **HICON**

A handle to the icon or cursor.

To retrieve information about a standard icon or cursor, specify the [identifier beginning with the IDI\_ prefix](https://learn.microsoft.com/windows/win32/menurc/about-icons) or the [identifier beginning with the IDC\_ prefix](https://learn.microsoft.com/windows/win32/menurc/about-cursors) in this parameter.

### `piconinfo` [in, out]

Type: **PICONINFOEX**

When this method returns, contains a pointer to an [ICONINFOEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-iconinfoexa) structure. The function fills in the structure's members.

## Return value

Type: **BOOL**

**TRUE** indicates success, **FALSE** indicates failure.

## Remarks

**GetIconInfoEx** creates bitmaps for the **hbmMask** and **hbmColor** or members of [ICONINFOEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-iconinfoexw). The calling application must manage these bitmaps and delete them with [DeleteObject](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-deleteobject) call when they are no longer necessary.

### DPI Virtualization

This API does not participate in DPI virtualization. The output returned is not affected by the DPI of the calling thread.

> [!NOTE]
> The winuser.h header defines GetIconInfoEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

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