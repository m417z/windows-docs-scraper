# DefWindowProcA function

## Description

Calls the default window procedure to provide default processing for any window messages that an application does not process. This function ensures that every message is processed. **DefWindowProc** is called with the same parameters received by the window procedure.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window procedure that received the message.

### `Msg` [in]

Type: **UINT**

The message.

### `wParam` [in]

Type: **WPARAM**

Additional message information. The content of this parameter depends on the value of the *Msg* parameter.

### `lParam` [in]

Type: **LPARAM**

Additional message information. The content of this parameter depends on the value of the *Msg* parameter.

## Return value

Type: **LRESULT**

The return value is the result of the message processing and depends on the message.

## Syntax

```cpp
LRESULT DefWindowProcA(
  [in] HWND   hWnd,
  [in] UINT   Msg,
  [in] WPARAM wParam,
  [in] LPARAM lParam
);
```

## See also

[CallWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-callwindowproca)

**Conceptual**

[DefDlgProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defdlgprocw)

**Reference**

[Window Procedures](https://learn.microsoft.com/windows/desktop/winmsg/window-procedures)

[WindowProc](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-wndproc)

## Remarks

> [!NOTE]
> The winuser.h header defines DefWindowProc as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).