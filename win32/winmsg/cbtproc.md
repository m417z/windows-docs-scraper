# CBTProc callback function

An application-defined or library-defined callback function used with the [**SetWindowsHookExA**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexa)/[**SetWindowsHookExW**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexw) function. The system calls this function before activating, creating, destroying, minimizing, maximizing, moving, or sizing a window; before completing a system command; before removing a mouse or keyboard event from the system message queue; before setting the keyboard focus; or before synchronizing with the system message queue. A computer-based training (CBT) application uses this hook procedure to receive useful notifications from the system.

## Parameters

  - *nCode* \[in\]
Type: **int**
The code that the hook procedure uses to determine how to process the message. If *nCode* is less than zero, the hook procedure must pass the message to the [**CallNextHookEx**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex) function without further processing and should return the value returned by **CallNextHookEx**. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **HCBT_ACTIVATE** 5 | The system is about to activate a window. |
| **HCBT_CLICKSKIPPED** 6 | The system has removed a mouse message from the system message queue. Upon receiving this hook code, a CBT application must install a [**WH_JOURNALPLAYBACK**](https://learn.microsoft.com/windows/win32/winmsg/about-hooks) hook procedure in response to the mouse message. |
| **HCBT_CREATEWND** 3 | A window is about to be created. The system calls the hook procedure before sending the [**WM_CREATE**](https://learn.microsoft.com/windows/win32/winmsg/wm-create) or [**WM_NCCREATE**](https://learn.microsoft.com/windows/win32/winmsg/wm-nccreate) message to the window. If the hook procedure returns a nonzero value, the system destroys the window; the [**CreateWindow**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-createwindowa) function returns **NULL**, but the [**WM_DESTROY**](https://learn.microsoft.com/windows/win32/winmsg/wm-destroy) message is not sent to the window. If the hook procedure returns zero, the window is created normally.<br><br>At the time of the **HCBT_CREATEWND** notification, the window has been created, but its final size and position may not have been determined and its parent window may not have been established. It is possible to send messages to the newly created window, although it has not yet received [**WM_NCCREATE**](https://learn.microsoft.com/windows/win32/winmsg/wm-nccreate) or [**WM_CREATE**](https://learn.microsoft.com/windows/win32/winmsg/wm-create) messages. It is also possible to change the position in the z-order of the newly created window by modifying the **hwndInsertAfter** member of the [**CBT_CREATEWND**](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-cbt_createwnda) structure. |
| **HCBT_DESTROYWND** 4 | A window is about to be destroyed. |
| **HCBT_KEYSKIPPED** 7 | The system has removed a keyboard message from the system message queue. Upon receiving this hook code, a CBT application must install a [**WH_JOURNALPLAYBACK**](https://learn.microsoft.com/windows/win32/winmsg/about-hooks) hook procedure in response to the keyboard message. |
| **HCBT_MINMAX** 1 | A window is about to be minimized or maximized. |
| **HCBT_MOVESIZE** 0 | A window is about to be moved or sized. |
| **HCBT_QS** 2 | The system has retrieved a [**WM_QUEUESYNC**](https://learn.microsoft.com/windows/win32/winmsg/wm-queuesync) message from the system message queue. |
| **HCBT_SETFOCUS** 9 | A window is about to receive the keyboard focus. |
| **HCBT_SYSCOMMAND** 8 | A system command is about to be carried out. This allows a CBT application to prevent task switching by means of hot keys. |

  - *wParam* \[in\]
Type: **WPARAM**
Depends on the *nCode* parameter. For details, see the following Remarks section.

  - *lParam* \[in\]
Type: **LPARAM**
Depends on the *nCode* parameter. For details, see the following Remarks section.

## Return value

Type: LRESULT

The value returned by the hook procedure determines whether the system allows or prevents one of these operations. For operations corresponding to the following CBT hook codes, the return value must be 0 to allow the operation, or 1 to prevent it.

  - **HCBT\_ACTIVATE**
  - **HCBT\_CREATEWND**
  - **HCBT\_DESTROYWND**
  - **HCBT\_MINMAX**
  - **HCBT\_MOVESIZE**
  - **HCBT\_SETFOCUS**
  - **HCBT\_SYSCOMMAND**

For operations corresponding to the following CBT hook codes, the return value is ignored.

  - **HCBT\_CLICKSKIPPED**
  - **HCBT\_KEYSKIPPED**
  - **HCBT\_QS**

## Remarks

The **HOOKPROC** type defines a pointer to this callback function. *CBTProc* is a placeholder for the application-defined or library-defined function name.

The hook procedure should not install a [**WH_JOURNALPLAYBACK**](https://learn.microsoft.com/windows/win32/winmsg/about-hooks) hook procedure except in the situations described in the preceding list of hook codes.

An application installs the hook procedure by specifying the [**WH\_CBT**](https://learn.microsoft.com/windows/win32/winmsg/about-hooks) hook type and a pointer to the hook procedure in a call to the [**SetWindowsHookExA**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexa)/[**SetWindowsHookExW**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexw) function.

The following table describes the *wParam* and *lParam* parameters for each **HCBT\_** hook code.

| Value | wParam | lParam |
| --- | --- | --- |
| **HCBT_ACTIVATE** | Specifies the handle to the window about to be activated. | Specifies a long pointer to a [**CBTACTIVATESTRUCT**](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-cbtactivatestruct) structure containing the handle to the active window and specifies whether the activation is changing because of a mouse click. |
| **HCBT_CLICKSKIPPED** | Specifies the mouse message removed from the system message queue. | Specifies a long pointer to a [**MOUSEHOOKSTRUCT**](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-mousehookstruct) structure containing the hit-test code and the handle to the window for which the mouse message is intended.<br><br>The **HCBT_CLICKSKIPPED** value is sent to a *CBTProc* hook procedure only if a [**WH_MOUSE**](https://learn.microsoft.com/windows/win32/winmsg/about-hooks) hook is installed. For a list of hit-test codes, see [**WM_NCHITTEST**](https://learn.microsoft.com/windows/win32/inputdev/wm-nchittest). |
| **HCBT_CREATEWND** | Specifies the handle to the new window. | Specifies a long pointer to a [**CBT_CREATEWND**](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-cbt_createwnda) structure containing initialization parameters for the window. The parameters include the coordinates and dimensions of the window. By changing these parameters, a *CBTProc* hook procedure can set the initial size and position of the window. |
| **HCBT_DESTROYWND** | Specifies the handle to the window about to be destroyed. | Is undefined and must be set to zero. |
| **HCBT_KEYSKIPPED** | Specifies the virtual-key code. | Specifies the repeat count, scan code, key-transition code, previous key state, and context code. The **HCBT_KEYSKIPPED** value is sent to a *CBTProc* hook procedure only if a [**WH_KEYBOARD**](https://learn.microsoft.com/windows/win32/winmsg/about-hooks) hook is installed. For more information, see [**WM_KEYUP**](https://learn.microsoft.com/windows/win32/inputdev/wm-keyup) or [**WM_KEYDOWN**](https://learn.microsoft.com/windows/win32/inputdev/wm-keydown). |
| **HCBT_MINMAX** | Specifies the handle to the window being minimized or maximized. | Specifies, in the low-order word, a show-window value (**SW_**) specifying the operation. For a list of show-window values, see the [**ShowWindow**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-showwindow). The high-order word is undefined. |
| **HCBT_MOVESIZE** | Specifies the handle to the window to be moved or sized. | Specifies a long pointer to a [**RECT**](https://learn.microsoft.com/previous-versions//dd162897(v=vs.85)) structure containing the coordinates of the window. By changing the values in the structure, a *CBTProc* hook procedure can set the final coordinates of the window. |
| **HCBT_QS** | Is undefined and must be zero. | Is undefined and must be zero. |
| **HCBT_SETFOCUS** | Specifies the handle to the window gaining the keyboard focus. | Specifies the handle to the window losing the keyboard focus. |
| **HCBT_SYSCOMMAND** | Specifies a system-command value (**SC_**) specifying the system command. For more information about system-command values, see [**WM_SYSCOMMAND**](https://learn.microsoft.com/windows/win32/menurc/wm-syscommand). | Contains the same data as the *lParam* value of a [**WM_SYSCOMMAND**](https://learn.microsoft.com/windows/win32/menurc/wm-syscommand) message: If a system menu command is chosen with the mouse, the low-order word contains the x-coordinate of the cursor, in screen coordinates, and the high-order word contains the y-coordinate; otherwise, the parameter is not used. |

For more details, see [Windows Events](https://learn.microsoft.com/windows/win32/Events/windows-events).

## Requirements

|  |  |
| --- | --- |
| Minimum supported client | Windows 2000 Professional [desktop apps only] |
| Minimum supported server | Windows 2000 Server [desktop apps only] |
| Header | Winuser.h (include Windows.h) |

## See also

[**CallNextHookEx**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex)

[CreateWindowA](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-createwindowa)/[CreateWindowW](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-createwindoww)

[**SetWindowsHookExA**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexa)/[**SetWindowsHookExW**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexw)

[WM_SYSCOMMAND message](https://learn.microsoft.com/windows/win32/menurc/wm-syscommand)

[Hooks](https://learn.microsoft.com/windows/win32/winmsg/hooks)