# MDICREATESTRUCTW structure

## Description

Contains information about the class, title, owner, location, and size of a multiple-document interface (MDI) child window.

## Members

### `szClass`

Type: **LPCTSTR**

The name of the window class of the MDI child window. The class name must have been registered by a previous call to the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassw) function.

### `szTitle`

Type: **LPCTSTR**

The title of the MDI child window. The system displays the title in the child window's title bar.

### `hOwner`

Type: **HANDLE**

A handle to the instance of the application creating the MDI client window.

### `x`

Type: **int**

The initial horizontal position, in client coordinates, of the MDI child window. If this member is **CW_USEDEFAULT**, the MDI child window is assigned the default horizontal position.

### `y`

Type: **int**

The initial vertical position, in client coordinates, of the MDI child window. If this member is **CW_USEDEFAULT**, the MDI child window is assigned the default vertical position.

### `cx`

Type: **int**

The initial width, in device units, of the MDI child window. If this member is **CW_USEDEFAULT**, the MDI child window is assigned the default width.

### `cy`

Type: **int**

The initial height, in device units, of the MDI child window. If this member is set to **CW_USEDEFAULT**, the MDI child window is assigned the default height.

### `style`

Type: **DWORD**

The style of the MDI child window. If the MDI client window was created with the **MDIS_ALLCHILDSTYLES** window style, this member can be any combination of the window styles listed in the [Window Styles](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) page. Otherwise, this member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **WS_MINIMIZE**<br><br>0x20000000L | Creates an MDI child window that is initially minimized. |
| **WS_MAXIMIZE**<br><br>0x01000000L | Creates an MDI child window that is initially maximized. |
| **WS_HSCROLL**<br><br>0x00100000L | Creates an MDI child window that has a horizontal scroll bar. |
| **WS_VSCROLL**<br><br>0x00200000L | Creates an MDI child window that has a vertical scroll bar. |

### `lParam`

Type: **LPARAM**

An application-defined value.

## Remarks

When the MDI client window creates an MDI child window
by calling [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa), the system sends a [WM_CREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-create) message to the created window. The *lParam* member of the **WM_CREATE** message contains a pointer to a [CREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-createstructw) structure. The
**lpCreateParams** member of this structure contains a pointer to the **MDICREATESTRUCT** structure passed with the [WM_MDICREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-mdicreate) message that created the MDI child window.

> [!NOTE]
> The winuser.h header defines MDICREATESTRUCT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CLIENTCREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-clientcreatestruct)

[CREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-createstructw)

**Conceptual**

[Multiple Document Interface](https://learn.microsoft.com/windows/desktop/winmsg/multiple-document-interface)

**Reference**

[WM_CREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-create)