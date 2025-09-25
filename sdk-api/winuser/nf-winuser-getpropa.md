# GetPropA function

## Description

Retrieves a data handle from the property list of the specified window. The character string identifies the handle to be retrieved. The string and handle must have been added to the property list by a previous call to the [SetProp](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setpropa) function.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window whose property list is to be searched.

### `lpString` [in]

Type: **LPCTSTR**

An atom that identifies a string. If this parameter is an atom, it must have been created by using the [GlobalAddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaladdatoma) function. The atom, a 16-bit value, must be placed in the low-order word of the *lpString* parameter; the high-order word must be zero.

## Return value

Type: **HANDLE**

If the property list contains the string, the return value is the associated data handle. Otherwise, the return value is **NULL**.

## See also

**Conceptual**

[GlobalAddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaladdatoma)

**Reference**

[SetProp](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setpropa)

[Window Properties](https://learn.microsoft.com/windows/desktop/winmsg/window-properties)

[ITaskbarList2::MarkFullscreenWindow](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nf-shobjidl_core-itaskbarlist2-markfullscreenwindow)

## Remarks

> [!NOTE]
> The winuser.h header defines GetProp as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).