# CreateIconFromResource function

## Description

Creates an icon or cursor from resource bits describing the icon.

To specify a desired height or width, use the [CreateIconFromResourceEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconfromresourceex) function.

## Parameters

### `presbits` [in]

Type: **PBYTE**

The DWORD-aligned buffer pointer containing the icon or cursor resource bits. These bits are typically loaded by calls to the [LookupIconIdFromDirectory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-lookupiconidfromdirectory), [LookupIconIdFromDirectoryEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-lookupiconidfromdirectoryex), and [LoadResource](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadresource) functions.

See [Cursor and Icon Resources](https://learn.microsoft.com/windows/win32/menurc/resource-file-formats#cursor-and-icon-resources) for more info on icon and cursor resource format.

### `dwResSize` [in]

Type: **DWORD**

The size, in bytes, of the set of bits pointed to by the *presbits* parameter.

### `fIcon` [in]

Type: **BOOL**

Indicates whether an icon or a cursor is to be created. If this parameter is **TRUE**, an icon is to be created. If it is **FALSE**, a cursor is to be created.

The [LOCALHEADER](https://learn.microsoft.com/windows/win32/menurc/localheader) structure defines cursor hotspot and is the first data read from the cursor resource bits.

### `dwVer` [in]

Type: **DWORD**

The version number of the icon or cursor format for the resource bits pointed to by the *presbits* parameter. The value must be greater than or equal to 0x00020000 and less than or equal to 0x00030000. This parameter is generally set to 0x00030000.

## Return value

Type: **HICON**

If the function succeeds, the return value is a handle to the icon or cursor.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **CreateIconFromResource**, [CreateIconFromResourceEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconfromresourceex), [CreateIconIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconindirect), [GetIconInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-geticoninfo), [LookupIconIdFromDirectory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-lookupiconidfromdirectory), and [LookupIconIdFromDirectoryEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-lookupiconidfromdirectoryex) functions allow shell applications and icon browsers to examine and use resources throughout the system.

The **CreateIconFromResource** function calls [CreateIconFromResourceEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconfromresourceex) passing `LR_DEFAULTSIZE|LR_SHARED` as flags.

You should call [DestroyIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroyicon) for icons or [DestroyCursor](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroycursor) for cursors created with **CreateIconFromResource**.

## See also

**Conceptual**

[CreateIconFromResourceEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconfromresourceex)

[CreateIconIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createiconindirect)

[GetIconInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-geticoninfo)

[Icons](https://learn.microsoft.com/windows/desktop/menurc/icons)

[LoadResource](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadresource)

[LookupIconIdFromDirectory](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-lookupiconidfromdirectory)

[LookupIconIdFromDirectoryEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-lookupiconidfromdirectoryex)

**Reference**