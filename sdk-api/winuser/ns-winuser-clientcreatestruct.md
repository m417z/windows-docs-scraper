# CLIENTCREATESTRUCT structure

## Description

Contains information about the menu and first multiple-document interface (MDI) child window of an MDI client window. An application passes a pointer to this structure as the
*lpParam* parameter of the [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) function when creating an MDI client window.

## Members

### `hWindowMenu`

Type: **HANDLE**

A handle to the MDI application's window menu. An MDI application can retrieve this handle from the menu of the MDI frame window by using the [GetSubMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsubmenu) function.

### `idFirstChild`

Type: **UINT**

The child window identifier of the first MDI child window created. The system increments the identifier for each additional MDI child window the application creates, and reassigns identifiers when the application destroys a window to keep the range of identifiers contiguous. These identifiers are used in [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) messages sent to the application's MDI frame window when a child window is chosen from the window menu; they should not conflict with any other command identifiers.

## Remarks

When the MDI client window is created by calling [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa), the system sends a [WM_CREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-create) message to the window. The
*lParam* parameter of **WM_CREATE** contains a pointer to a [CREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-createstructa) structure. The
**lpCreateParams** member of this structure contains a pointer to a **CLIENTCREATESTRUCT** structure.

## See also

[About the Multiple Document Interface](https://learn.microsoft.com/windows/desktop/winmsg/about-the-multiple-document-interface)

**Conceptual**

[CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa)

[GetSubMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsubmenu)

[MDICREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-mdicreatestructa)

**Reference**

[WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)