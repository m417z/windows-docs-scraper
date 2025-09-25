# SetPropA function

## Description

Adds a new entry or changes an existing entry in the property list of the specified window. The function adds a new entry to the list if the specified character string does not exist already in the list. The new entry contains the string and the handle. Otherwise, the function replaces the string's current handle with the specified handle.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window whose property list receives the new entry.

### `lpString` [in]

Type: **LPCTSTR**

A null-terminated string or an atom that identifies a string. If this parameter is an atom, it must be a global atom created by a previous call to the [GlobalAddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaladdatoma) function. The atom must be placed in the low-order word of *lpString*; the high-order word must be zero.

### `hData` [in, optional]

Type: **HANDLE**

A handle to the data to be copied to the property list. The data handle can identify any value useful to the application.

## Return value

Type: **BOOL**

If the data handle and string are added to the property list, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Before a window is destroyed (that is, before it returns from processing the [WM_NCDESTROY](https://learn.microsoft.com/windows/desktop/winmsg/wm-ncdestroy) message), an application must remove all entries it has added to the property list. The application must use the [RemoveProp](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-removepropa) function to remove the entries.

**SetProp** is subject to the restrictions of User Interface Privilege Isolation (UIPI). A process can only call this function on a window belonging to a process of lesser or equal integrity level. When UIPI blocks property changes, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return 5.

#### Examples

For an example, see [Adding a Window Property](https://learn.microsoft.com/windows/desktop/winmsg/using-window-properties).

> [!NOTE]
> The winuser.h header defines SetProp as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GlobalAddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaladdatoma)

**Reference**

[RemoveProp](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-removepropa)

[WM_NCDESTROY](https://learn.microsoft.com/windows/desktop/winmsg/wm-ncdestroy)

[Window Properties](https://learn.microsoft.com/windows/desktop/winmsg/window-properties)

[ITaskbarList2::MarkFullscreenWindow](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-itaskbarlist2-markfullscreenwindow)