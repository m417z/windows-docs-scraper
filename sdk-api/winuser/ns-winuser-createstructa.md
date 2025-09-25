# CREATESTRUCTA structure

## Description

Defines the initialization parameters passed to the window procedure of an application. These members are identical to the parameters of the [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function.

## Members

### `lpCreateParams`

Type: **LPVOID**

Contains additional data which may be used to create the window. If the window is being created as a result of a call to the [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) or [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function, this member contains the value of the *lpParam* parameter specified in the function call.

If the window being created is a MDI client window, this member contains a pointer to a [CLIENTCREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-clientcreatestruct) structure. If the window being created is a MDI child window, this member contains a pointer to an [MDICREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-mdicreatestructa) structure.

 If the window is being created from a dialog template, this member is the address of a **SHORT** value that specifies the size, in bytes, of the window creation data. The value is immediately followed by the creation data. For more information, see the following Remarks section.

### `hInstance`

Type: **HINSTANCE**

A handle to the module that owns the new window.

### `hMenu`

Type: **HMENU**

A handle to the menu to be used by the new window.

### `hwndParent`

Type: **HWND**

A handle to the parent window, if the window is a child window. If the window is owned, this member identifies the owner window. If the window is not a child or owned window, this member is **NULL**.

### `cy`

Type: **int**

The height of the new window, in pixels.

### `cx`

Type: **int**

The width of the new window, in pixels.

### `y`

Type: **int**

The y-coordinate of the upper left corner of the new window. If the new window is a child window, coordinates are relative to the parent window. Otherwise, the coordinates are relative to the screen origin.

### `x`

Type: **int**

The x-coordinate of the upper left corner of the new window. If the new window is a child window, coordinates are relative to the parent window. Otherwise, the coordinates are relative to the screen origin.

### `style`

Type: **LONG**

The style for the new window. For a list of possible values, see [Window Styles](https://learn.microsoft.com/windows/desktop/winmsg/window-styles).

### `lpszName`

Type: **LPCTSTR**

The name of the new window.

### `lpszClass`

Type: **LPCTSTR**

A pointer to a null-terminated string or an atom that specifies the class name of the new window.

### `dwExStyle`

Type: **DWORD**

The extended window style for the new window. For a list of possible values, see [Extended Window Styles](https://learn.microsoft.com/windows/desktop/winmsg/extended-window-styles).

## Remarks

Because the **lpszClass** member can contain a pointer to a local (and thus inaccessible) atom, do not obtain the class name by using this member. Use the [GetClassName](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclassname) function instead.

 You should access the data represented by the **lpCreateParams** member using a pointer that has been declared using the **UNALIGNED** type, because the pointer may not be **DWORD** aligned. This is demonstrated in the following example:

```
typedef struct tagMyData
{
    // Define creation data here.
} MYDATA;

typedef struct tagMyDlgData
{
    SHORT   cbExtra;
    MYDATA  myData;
} MYDLGDATA, UNALIGNED *PMYDLGDATA;

PMYDLGDATA pMyDlgdata = (PMYDLGDATA) (((LPCREATESTRUCT) lParam)->lpCreateParams);
```

> [!NOTE]
> The winuser.h header defines CREATESTRUCT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[About the Multiple Document Interface](https://learn.microsoft.com/windows/desktop/winmsg/about-the-multiple-document-interface)

**Conceptual**

[CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa)

[CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

[MDICREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-mdicreatestructa)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)