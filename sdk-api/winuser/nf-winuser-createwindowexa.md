# CreateWindowExA function

## Description

Creates an overlapped, pop-up, or child window with an extended window style; otherwise, this function is identical to the [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) function. For more information about creating a window and for full descriptions of the other parameters of **CreateWindowEx**, see **CreateWindow**.

## Parameters

### `dwExStyle` [in]

Type: **DWORD**

The extended window style of the window being created. For a list of possible values, see [Extended Window Styles](https://learn.microsoft.com/windows/desktop/winmsg/extended-window-styles).

### `lpClassName` [in, optional]

Type: **LPCTSTR**

A **null**-terminated string or a class atom.

If a **null**-terminated string, it specifies the window class name. The class name can be any name registered with the [RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclasswa) or [RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa) function, provided that the module that registers the class is also the module that creates the window. The class name can also be any of the predefined [system class](https://learn.microsoft.com/windows/desktop/winmsg/about-window-classes) names.

If a class atom created by a previous call to **RegisterClass** or **RegisterClassEx**, it must be converted using the macro [MAKEINTATOM](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-makeintatom). (The atom must be in the low-order word of *lpClassName*; the high-order word must be zero.)

### `lpWindowName` [in, optional]

Type: **LPCTSTR**

The window name. If the window style specifies a title bar, the window title pointed to by *lpWindowName* is displayed in the title bar. When using [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) to create controls, such as buttons, check boxes, and static controls, use *lpWindowName* to specify the text of the control. When creating a static control with the **SS_ICON** style, use *lpWindowName* to specify the icon name or identifier. To specify an identifier, use the syntax "#*num*".

### `dwStyle` [in]

Type: **DWORD**

The style of the window being created. This parameter can be a combination of the [window style values](https://learn.microsoft.com/windows/desktop/winmsg/window-styles), plus the control styles indicated in the Remarks section.

### `X` [in]

Type: **int**

The initial horizontal position of the window. For an overlapped or pop-up window, the *x* parameter is the initial x-coordinate of the window's upper-left corner, in screen coordinates. For a child window, *x* is the x-coordinate of the upper-left corner of the window relative to the upper-left corner of the parent window's client area. If *x* is set to **CW_USEDEFAULT**, the system selects the default position for the window's upper-left corner and ignores the *y* parameter. **CW_USEDEFAULT** is valid only for overlapped windows; if it is specified for a pop-up or child window, the *x* and *y* parameters are set to zero.

### `Y` [in]

Type: **int**

The initial vertical position of the window. For an overlapped or pop-up window, the *y* parameter is the initial y-coordinate of the window's upper-left corner, in screen coordinates. For a child window, *y* is the initial y-coordinate of the upper-left corner of the child window relative to the upper-left corner of the parent window's client area. For a list box *y* is the initial y-coordinate of the upper-left corner of the list box's client area relative to the upper-left corner of the parent window's client area.

If an overlapped window is created with the **WS_VISIBLE** style bit set and the *x* parameter is set to **CW_USEDEFAULT**, then the *y* parameter determines how the window is shown. If the *y* parameter is **CW_USEDEFAULT**, then the window manager calls [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) with the **SW_SHOW** flag after the window has been created. If the *y* parameter is some other value, then the window manager calls **ShowWindow** with that value as the *nCmdShow* parameter.

### `nWidth` [in]

Type: **int**

The width, in device units, of the window. For overlapped windows, *nWidth* is the window's width, in screen coordinates, or **CW_USEDEFAULT**. If *nWidth* is **CW_USEDEFAULT**, the system selects a default width and height for the window; the default width extends from the initial x-coordinates to the right edge of the screen; the default height extends from the initial y-coordinate to the top of the icon area. **CW_USEDEFAULT** is valid only for overlapped windows; if **CW_USEDEFAULT** is specified for a pop-up or child window, the *nWidth* and *nHeight* parameter are set to zero.

### `nHeight` [in]

Type: **int**

The height, in device units, of the window. For overlapped windows, *nHeight* is the window's height, in screen coordinates. If the *nWidth* parameter is set to **CW_USEDEFAULT**, the system ignores *nHeight*.

### `hWndParent` [in, optional]

Type: **HWND**

A handle to the parent or owner window of the window being created. To create a child window or an owned window, supply a valid window handle. This parameter is optional for pop-up windows.

 To create a [message-only window](https://learn.microsoft.com/windows/desktop/winmsg/window-features), supply **HWND_MESSAGE** or a handle to an existing message-only window.

### `hMenu` [in, optional]

Type: **HMENU**

A handle to a menu, or specifies a child-window identifier, depending on the window style. For an overlapped or pop-up window, *hMenu* identifies the menu to be used with the window; it can be **NULL** if the class menu is to be used. For a child window, *hMenu* specifies the child-window identifier, an integer value used by a dialog box control to notify its parent about events. The application determines the child-window identifier; it must be unique for all child windows with the same parent window.

### `hInstance` [in, optional]

Type: **HINSTANCE**

A handle to the instance of the module to be associated with the window.

### `lpParam` [in, optional]

Type: **LPVOID**

Pointer to a value to be passed to the window through the [CREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-createstructa) structure (**lpCreateParams** member) pointed to by the *lParam* param of the **WM_CREATE** message. This message is sent to the created window by this function before it returns.

If an application calls [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) to create a MDI client window, *lpParam* should point to a [CLIENTCREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-clientcreatestruct) structure. If an MDI client window calls **CreateWindow** to create an MDI child window, *lpParam* should point to a [MDICREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-mdicreatestructa) structure. *lpParam* may be **NULL** if no additional data is needed.

## Return value

Type: **HWND**

If the function succeeds, the return value is a handle to the new window.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

This function typically fails for one of the following reasons:

* an invalid parameter value
* the system class was registered by a different module
* The **WH_CBT** hook is installed and returns a failure code
* if one of the controls in the dialog template is not registered, or its window window procedure fails [WM_CREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-create) or [WM_NCCREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccreate)

## Remarks

The **CreateWindowEx** function sends [WM_NCCREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccreate), [WM_NCCALCSIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccalcsize), and [WM_CREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-create) messages to the window being created.

If the created window is a child window, its default position is at the bottom of the Z-order. If the created window is a top-level window, its default position is at the top of the Z-order (but beneath all topmost windows unless the created window is itself topmost).

For information on controlling whether the Taskbar displays a button for the created window, see [Managing Taskbar Buttons](https://learn.microsoft.com/windows/desktop/shell/taskbar).

For information on removing a window, see the [DestroyWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroywindow) function.

The following predefined control classes can be specified in the *lpClassName* parameter. Note the corresponding control styles you can use in the *dwStyle* parameter.

| Class | Meaning |
| --- | --- |
| **BUTTON** | Designates a small rectangular child window that represents a button the user can click to turn it on or off. Button controls can be used alone or in groups, and they can either be labeled or appear without text. Button controls typically change appearance when the user clicks them. For more information, see [Buttons](https://learn.microsoft.com/windows/desktop/Controls/buttons).<br><br>For a table of the button styles you can specify in the *dwStyle* parameter, see [Button Styles](https://learn.microsoft.com/windows/desktop/Controls/button-styles). |
| **COMBOBOX** | Designates a control consisting of a list box and a selection field similar to an edit control. When using this style, an application should either display the list box at all times or enable a drop-down list box. If the list box is visible, typing characters into the selection field highlights the first list box entry that matches the characters typed. Conversely, selecting an item in the list box displays the selected text in the selection field. For more information, see [Combo Boxes](https://learn.microsoft.com/windows/desktop/Controls/combo-boxes).<br><br>For a table of the combo box styles you can specify in the *dwStyle* parameter, see [Combo Box Styles](https://learn.microsoft.com/windows/desktop/Controls/combo-box-styles). |
| **EDIT** | Designates a rectangular child window into which the user can type text from the keyboard. The user selects the control and gives it the keyboard focus by clicking it or moving to it by pressing the TAB key. The user can type text when the edit control displays a flashing caret; use the mouse to move the cursor, select characters to be replaced, or position the cursor for inserting characters; or use the key to delete characters. For more information, see [Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/edit-controls).<br><br>For a table of the edit control styles you can specify in the *dwStyle* parameter, see [Edit Control Styles](https://learn.microsoft.com/windows/desktop/Controls/edit-control-styles). |
| **LISTBOX** | Designates a list of character strings. Specify this control whenever an application must present a list of names, such as filenames, from which the user can choose. The user can select a string by clicking it. A selected string is highlighted, and a notification message is passed to the parent window. For more information, see [List Boxes](https://learn.microsoft.com/windows/desktop/uxguide/ctrl-list-boxes).<br><br>For a table of the list box styles you can specify in the *dwStyle* parameter, see [List Box Styles](https://learn.microsoft.com/windows/desktop/Controls/list-box-styles). |
| **MDICLIENT** | Designates an MDI client window. This window receives messages that control the MDI application's child windows. The recommended style bits are **WS_CLIPCHILDREN** and **WS_CHILD**. Specify the **WS_HSCROLL** and **WS_VSCROLL** styles to create an MDI client window that allows the user to scroll MDI child windows into view. For more information, see [Multiple Document Interface](https://learn.microsoft.com/windows/desktop/winmsg/multiple-document-interface). |
| **RichEdit** | Designates a Microsoft Rich Edit 1.0 control. This window lets the user view and edit text with character and paragraph formatting, and can include embedded Component Object Model (COM) objects. For more information, see [Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/rich-edit-controls).<br><br>For a table of the rich edit control styles you can specify in the *dwStyle* parameter, see [Rich Edit Control Styles](https://learn.microsoft.com/windows/desktop/Controls/rich-edit-control-styles). |
| **RICHEDIT_CLASS** | Designates a Microsoft Rich Edit 2.0 control. This controls let the user view and edit text with character and paragraph formatting, and can include embedded COM objects. For more information, see [Rich Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/rich-edit-controls).<br><br>For a table of the rich edit control styles you can specify in the *dwStyle* parameter, see [Rich Edit Control Styles](https://learn.microsoft.com/windows/desktop/Controls/rich-edit-control-styles). |
| **SCROLLBAR** | Designates a rectangle that contains a scroll box and has direction arrows at both ends. The scroll bar sends a notification message to its parent window whenever the user clicks the control. The parent window is responsible for updating the position of the scroll box, if necessary. For more information, see [Scroll Bars](https://learn.microsoft.com/windows/desktop/Controls/scroll-bars).<br><br>For a table of the scroll bar control styles you can specify in the *dwStyle* parameter, see [Scroll Bar Control Styles](https://learn.microsoft.com/windows/desktop/Controls/scroll-bar-control-styles). |
| **STATIC** | Designates a simple text field, box, or rectangle used to label, box, or separate other controls. Static controls take no input and provide no output. For more information, see [Static Controls](https://learn.microsoft.com/windows/desktop/Controls/static-controls). <br><br>For a table of the static control styles you can specify in the *dwStyle* parameter, see [Static Control Styles](https://learn.microsoft.com/windows/desktop/Controls/static-control-styles). |

The **WS_EX_NOACTIVATE** value for *dwExStyle* prevents foreground activation by the system. To prevent queue activation when the user clicks on the window, you must process the [WM_MOUSEACTIVATE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mouseactivate) message appropriately. To bring the window to the foreground or to activate it programmatically, use [SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow) or [SetActiveWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setactivewindow). Returning **FALSE** to [WM_NCACTIVATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-ncactivate) prevents the window from losing queue activation. However, the return value is ignored at activation time.

 With **WS_EX_COMPOSITED** set, all descendants of a window get bottom-to-top painting order using double-buffering. Bottom-to-top painting order allows a descendent window to have translucency (alpha) and transparency (color-key) effects, but only if the descendent window also has the **WS_EX_TRANSPARENT** bit set. Double-buffering allows the window and its descendents to be painted without flicker.

## Example

The following sample code illustrates the use of **CreateWindowExA**.

```cpp
BOOL Create(
        PCWSTR lpWindowName,
        DWORD dwStyle,
        DWORD dwExStyle = 0,
        int x = CW_USEDEFAULT,
        int y = CW_USEDEFAULT,
        int nWidth = CW_USEDEFAULT,
        int nHeight = CW_USEDEFAULT,
        HWND hWndParent = 0,
        HMENU hMenu = 0
        )
    {
        WNDCLASS wc = {0};

        wc.lpfnWndProc   = DERIVED_TYPE::WindowProc;
        wc.hInstance     = GetModuleHandle(NULL);
        wc.lpszClassName = ClassName();

        RegisterClass(&wc);

        m_hwnd = CreateWindowEx(
            dwExStyle, ClassName(), lpWindowName, dwStyle, x, y,
            nWidth, nHeight, hWndParent, hMenu, GetModuleHandle(NULL), this
            );

        return (m_hwnd ? TRUE : FALSE);
    }
```

> [!NOTE]
> The winuser.h header defines CreateWindowEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[About the Multiple Document Interface](https://learn.microsoft.com/windows/desktop/winmsg/about-the-multiple-document-interface)

[CLIENTCREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-clientcreatestruct)

[CREATESTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-createstructa)

**Conceptual**

[CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa)

[DestroyWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-destroywindow)

[EnableWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enablewindow)

**Other Resources**

**Reference**

[RegisterClass](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassa)

[RegisterClassEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclassexa)

[SetActiveWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setactivewindow)

[SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow)

[SetWindowLong](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowlonga)

[SetWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowpos)

[ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow)

[WM_CREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-create)

[WM_NCCALCSIZE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccalcsize)

[WM_NCCREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccreate)

[WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint)

[WM_PARENTNOTIFY](https://learn.microsoft.com/windows/win32/inputmsg/wm-parentnotify)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)