# FindResourceExW function

## Description

Determines the location of the resource with the specified type, name, and language in the specified module.

## Parameters

### `hModule` [in, optional]

Type: **HMODULE**

A handle to the module whose portable executable file or an accompanying MUI file contains the resource. If this parameter is **NULL**, the function searches the module used to create the current process.

### `lpType` [in]

Type: **LPCTSTR**

The resource type. Alternately, rather than a pointer, this parameter can be [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcew)(ID), where ID is the integer identifier of the given resource type. For standard resource types, see [Resource Types](https://learn.microsoft.com/windows/desktop/menurc/resource-types). For more information, see the Remarks section below.

### `lpName` [in]

Type: **LPCTSTR**

The name of the resource. Alternately, rather than a pointer, this parameter can be [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcew)(ID), where ID is the integer identifier of the resource. For more information, see the Remarks section below.

### `wLanguage` [in]

Type: **WORD**

The language of the resource. If this parameter is `MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL)`, the current language associated with the calling thread is used.

To specify a language other than the current language, use the [MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid) macro to create this parameter. For more information, see **MAKELANGID**.

## Return value

Type: **HRSRC**

If the function succeeds, the return value is a handle to the specified resource's information block. To obtain a handle to the resource, pass this handle to the [LoadResource](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadresource) function.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If [IS_INTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-is_intresource) is **TRUE** for x = *lpType* or *lpName*, x specifies the integer identifier of the type or name of the given resource. Otherwise, those parameters are long pointers to null-terminated strings. If the first character of the string is a pound sign (#), the remaining characters represent a decimal number that specifies the integer identifier of the resource's name or type. For example, the string "#258" represents the integer identifier 258.

To reduce the amount of memory required for a resource, an application should refer to it by integer identifier instead of by name.

An application can use **FindResourceEx** to find any type of resource, but this function should be used only if the application must access the binary resource data by making subsequent calls to [LoadResource](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadresource) and then to [LockResource](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-lockresource).

To use a resource immediately, an application should use one of the following resource-specific functions to find the resource and convert the data into a more usable form.

| Function | Action |
| --- | --- |
| [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) | Loads and formats a message-table entry. |
| [LoadAccelerators](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadacceleratorsw) | Loads an accelerator table. |
| [LoadBitmap](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadbitmapw) | Loads a bitmap resource. |
| [LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursorw) | Loads a cursor resource. |
| [LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadiconw) | Loads an icon resource. |
| [LoadMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadmenuw) | Loads a menu resource. |
| [LoadString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadstringw) | Loads a string-table entry. |

For example, an application can use the [LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadiconw) function to load an icon for display on the screen. However, the application should use **FindResourceEx** and [LoadResource](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadresource) if it is loading the icon to copy its data to another application.

String resources are stored in sections of up to 16 strings per section. The strings in each section are stored as a sequence of counted (not necessarily null-terminated) Unicode strings. The [LoadString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadstringw) function will extract the string resource from its corresponding section.

## See also

[FindResource](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-findresourcew)
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)
[IS_INTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-is_intresource)
[LoadAccelerators](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadacceleratorsw)
[LoadBitmap](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadbitmapw)
[LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursorw)
[LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadiconw)
[LoadMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadmenuw)
[LoadResource](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadresource)
[LoadString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadstringw)
[MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid)

**Other Resources**

**Reference**
[Resources](https://learn.microsoft.com/windows/desktop/menurc/resources)