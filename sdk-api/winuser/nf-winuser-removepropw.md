# RemovePropW function

## Description

Removes an entry from the property list of the specified window. The specified character string identifies the entry to be removed.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window whose property list is to be changed.

### `lpString` [in]

Type: **LPCTSTR**

A null-terminated character string or an atom that identifies a string. If this parameter is an atom, it must have been created using the [GlobalAddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-globaladdatoma) function. The atom, a 16-bit value, must be placed in the low-order word of *lpString*; the high-order word must be zero.

## Return value

Type: **HANDLE**

The return value identifies the specified data. If the data cannot be found in the specified property list, the return value is **NULL**.

## Remarks

The return value is the *hData* value that was passed to [SetProp](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setpropa); it is an application-defined value. Note, this function only destroys the association between the data and the window. If appropriate, the application must free the data handles associated with entries removed from a property list. The application can remove only those properties it has added. It must not remove properties added by other applications or by the system itself.

The **RemoveProp** function returns the data handle associated with the string so that the application can free the data associated with the handle.

Starting with Windows Vista, **RemoveProp** is subject to the restrictions of User Interface Privilege Isolation (UIPI). A process can only call this function on a window belonging to a process of lesser or equal integrity level. When UIPI blocks property changes, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return **5**.

#### Examples

For an example, see [Deleting a Window Property](https://learn.microsoft.com/windows/desktop/winmsg/using-window-properties).

> [!NOTE]
> The winuser.h header defines RemoveProp as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AddAtom](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-addatomw)

**Conceptual**

[GetProp](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpropa)

**Reference**

[SetProp](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setpropa)

[Window Properties](https://learn.microsoft.com/windows/desktop/winmsg/window-properties)