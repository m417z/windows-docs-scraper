# PROPENUMPROCA callback function

## Description

An application-defined callback function used with the [EnumProps](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumpropsa) function. The function receives property entries from a window's property list. The **PROPENUMPROC** type defines a pointer to this callback function. _PropEnumProc_ is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

Type: **HWND**

A handle to the window whose property list is being enumerated. This parameter is typically named _hWnd_.

### `unnamedParam2`

Type: **LPCTSTR**

The string component of a property list entry. This is the string that was specified, along with a data handle, when the property was added to the window's property list via a call to the [SetProp](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setpropa) function. This parameter is typically named _lpString_.

### `unnamedParam3`

Type: **HANDLE**

A handle to the data. This handle is the data component of a property list entry. This parameter is typically named _hData_.

## Return value

Type: **BOOL**

Return **TRUE** to continue the property list enumeration.

Return **FALSE** to stop the property list enumeration.

## Remarks

> [!NOTE]
> The parameters are defined in the header with no names: `typedef BOOL (CALLBACK* PROPENUMPROCA)(HWND, LPCSTR, HANDLE);`. Therefore, the syntax block lists them as `unnamedParam1` - `unnamedParam3`. You can name these parameters anything in your app. However, they are usually named as shown in the parameter descriptions.

The following restrictions apply to this callback function:

- The callback function can call the [RemoveProp](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-removepropa) function. However, **RemoveProp** can remove only the property passed to the callback function through the callback function's parameters.
- The callback function should not attempt to add properties.

> [!NOTE]
> The winuser.h header defines PROPENUMPROC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[Window Properties](https://learn.microsoft.com/windows/desktop/winmsg/window-properties)

**Reference**

[EnumProps](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumpropsa)

[RemoveProp](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-removepropa)

[SetProp](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setpropa)