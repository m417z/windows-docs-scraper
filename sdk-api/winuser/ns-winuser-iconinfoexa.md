# ICONINFOEXA structure

## Description

Contains information about an icon or a cursor. Extends [ICONINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-iconinfo). Used by [GetIconInfoEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-geticoninfoexa).

## Members

### `cbSize`

Type: **DWORD**

The size, in bytes, of this structure.

### `fIcon`

Type: **BOOL**

Specifies whether this structure defines an icon or a cursor. A value of **TRUE** specifies an icon; **FALSE** specifies a cursor.

### `xHotspot`

Type: **DWORD**

The x-coordinate of a cursor's hot spot. If this structure defines an icon, the hot spot is always in the center of the icon, and this member is ignored.

### `yHotspot`

Type: **DWORD**

The y-coordinate of the cursor's hot spot. If this structure defines an icon, the hot spot is always in the center of the icon, and this member is ignored.

### `hbmMask`

Type: **HBITMAP**

A handle to the icon monochrome mask [bitmap](https://learn.microsoft.com/windows/win32/gdi/bitmaps).

### `hbmColor`

Type: **HBITMAP**

A handle to the icon color [bitmap](https://learn.microsoft.com/windows/win32/gdi/bitmaps).

### `wResID`

Type: **WORD**

Resource identifier of the resource in **szModName** module. If the icon or cursor was loaded by name, then **wResID** is zero and **szResName** contains the resource name.

You can use [MAKEINTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-makeintresourcea)(wResID) macro to convert resource identifier to a resource name type compatible with the [resource-management functions](https://learn.microsoft.com/windows/win32/menurc/resources-functions).

### `szModName`

Type: **TCHAR[MAX_PATH]**

Name of the module from which an icon or a cursor was loaded.

You can use [GetModuleHandle](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlea) function to convert it to the module handle compatible with the [resource-management functions](https://learn.microsoft.com/windows/win32/menurc/resources-functions).

### `szResName`

Type: **TCHAR[MAX_PATH]**

Resource name of the resource in **szModName** module.

## Remarks

For monochrome icons, the **hbmMask** is twice the height of the icon (with the AND mask on top and the XOR mask on the bottom), and **hbmColor** is **NULL**. Also, in this case the height should be an even multiple of two.

For color icons, the **hbmMask** and **hbmColor** bitmaps are the same size, each of which is the size of the icon.

You can use a [GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject) function to get contents of **hbmMask** and **hbmColor** in the [BITMAP](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmap) structure. The bitmap bits can be obtained with call to [GetDIBits](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-getdibits) on the bitmaps in this structure.

**ICONINFOEX** is an extended version of **ICONINFO** structure with additional **szModName**/**szResName**/**wResID** members that can be used to query an icon or cursor resource bits. These bits are typically loaded by calls to the [FindResource](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-findresourcew), [LoadResource](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadresource), [LockResource](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-lockresource) and [LookupIconIdFromDirectoryEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-lookupiconidfromdirectoryex) functions.

> [!NOTE]
> The winuser.h header defines ICONINFOEX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[CreateIconIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconindirect)

[GetIconInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-geticoninfo)

[Icons](https://learn.microsoft.com/windows/desktop/menurc/icons)

[Bitmaps](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject)

[BITMAP](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmap)

[GetDIBits](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-getdibits)

**Reference**