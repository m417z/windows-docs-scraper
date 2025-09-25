# CallWindowProcW function

## Description

Passes message information to the specified window procedure.

## Parameters

### `lpPrevWndFunc` [in]

Type: **WNDPROC**

The previous window procedure. If this value is obtained by calling the [GetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowlonga) function with the *nIndex* parameter set to **GWL_WNDPROC** or **DWL_DLGPROC**, it is actually either the address of a window or dialog box procedure, or a special internal value meaningful only to **CallWindowProc**.

### `hWnd` [in]

Type: **HWND**

A handle to the window procedure to receive the message.

### `Msg` [in]

Type: **UINT**

The message.

### `wParam` [in]

Type: **WPARAM**

Additional message-specific information. The contents of this parameter depend on the value of the *Msg* parameter.

### `lParam` [in]

Type: **LPARAM**

Additional message-specific information. The contents of this parameter depend on the value of the *Msg* parameter.

## Return value

Type: **LRESULT**

The return value specifies the result of the message processing and depends on the message sent.

## Remarks

Use the **CallWindowProc** function for window subclassing. Usually, all windows with the same class share one window procedure. A subclass is a window or set of windows with the same class whose messages are intercepted and processed by another window procedure (or procedures) before being passed to the window procedure of the class.

The [SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga) function creates the subclass by changing the window procedure associated with a particular window, causing the system to call the new window procedure instead of the previous one. An application must pass any messages not processed by the new window procedure to the previous window procedure by calling **CallWindowProc**. This allows the application to create a chain of window procedures.

If **STRICT** is defined, the *lpPrevWndFunc* parameter has the data type **WNDPROC**. The **WNDPROC** type is declared as follows:

``` syntax
LRESULT (CALLBACK* WNDPROC) (HWND, UINT, WPARAM, LPARAM);
```

If **STRICT** is not defined, the *lpPrevWndFunc* parameter has the data type **FARPROC**. The **FARPROC** type is declared as follows:

``` syntax
int (FAR WINAPI * FARPROC) ()
```

In C, the **FARPROC** declaration indicates a callback function that has an unspecified parameter list. In C++, however, the empty parameter list in the declaration indicates that a function has no parameters. This subtle distinction can break careless code. Following is one way to handle this situation:

``` syntax
#ifdef STRICT
  WNDPROC MyWindowProcedure
#else
  FARPROC MyWindowProcedure
#endif
...
  lResult = CallWindowProc(MyWindowProcedure, ...) ;
```

For further information about functions declared with empty argument lists, refer to
*The C++ Programming Language, Second Edition,* by Bjarne Stroustrup.

The **CallWindowProc** function handles Unicode-to-ANSI conversion. You cannot take advantage of this conversion if you call the window procedure directly.

#### Examples

For an example, see [Subclassing a Window](https://learn.microsoft.com/windows/desktop/winmsg/using-window-procedures)

> [!NOTE]
> The winuser.h header defines CallWindowProc as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowlonga)

**Reference**

[SetClassLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclasslonga)

[SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga)

[Window Procedures](https://learn.microsoft.com/windows/desktop/winmsg/window-procedures)