# NWMF enumeration

## Description

Flags used by [INewWindowManager::EvaluateNewWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inewwindowmanager-evaluatenewwindow). These values are factors in the decision of whether to display a pop-up window.

## Constants

### `NWMF_UNLOADING:0x1`

The page is unloading. This flag is set in response to the [onbeforeunload](https://learn.microsoft.com/previous-versions/aa741480(v=vs.85)) and [onunload](https://learn.microsoft.com/previous-versions/aa741488(v=vs.85)) events. Some pages load pop-up windows when you leave them, not when you enter. This flag is used to identify those situations.

### `NWMF_USERINITED:0x2`

The call to [INewWindowManager::EvaluateNewWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inewwindowmanager-evaluatenewwindow) is the result of a user-initiated action (a mouse click or key press). Use this flag in conjunction with the [NWMF_FIRST_USERINITED](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-nwmf) flag to determine whether the call is a direct or indirect result of the user-initiated action.

### `NWMF_FIRST:0x4`

When [NWMF_USERINITED](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-nwmf) is present, this flag indicates that the call to [INewWindowManager::EvaluateNewWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inewwindowmanager-evaluatenewwindow) is the first query that results from this user-initiated action. Always use this flag in conjunction with [NWMF_USERINITED](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-nwmf).

### `NWMF_OVERRIDEKEY:0x8`

The override key (ALT) was pressed. The override key is used to bypass the pop-up manager—allowing all pop-up windows to display—and must be held down at the time that [INewWindowManager::EvaluateNewWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inewwindowmanager-evaluatenewwindow) is called.

**Note** When [INewWindowManager::EvaluateNewWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inewwindowmanager-evaluatenewwindow) is implemented for a [WebBrowser](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa752040(v=vs.85)) control host, the implementer can choose to ignore the override key.

### `NWMF_SHOWHELP:0x10`

The new window attempting to load is the result of a call to the [showHelp](https://developer.mozilla.org/en-US/docs/Web/API/Window) method. Help is sometimes displayed in a separate window, and this flag is valuable in those cases.

### `NWMF_HTMLDIALOG:0x20`

The new window is a dialog box that displays HTML content.

### `NWMF_FROMDIALOGCHILD:0x40`

The [EvaluateNewWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inewwindowmanager-evaluatenewwindow) method is being called from an HTML dialog. The new window should not show the UI in the parent window.

### `NWMF_USERREQUESTED:0x80`

The new windows was definitely requested by the user, either by selecting Open in New Window from a context menu or pressing Shift and clicking a link.

### `NWMF_USERALLOWED:0x100`

The call to the [EvaluateNewWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inewwindowmanager-evaluatenewwindow) method is the result of the user requesting a replay that resulted in a refresh.

### `NWMF_FORCEWINDOW:0x10000`

The new window should be forced to open in a new window rather than a tab.

### `NWMF_FORCETAB:0x20000`

The new window should be forced to open in a new tab.

### `NWMF_SUGGESTWINDOW:0x40000`

The new window should open in a new tab unless [NWMF_FORCEtab](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-nwmf) is also present, indicating that user wants the window to open as a window.

### `NWMF_SUGGESTTAB:0x80000`

The new window should open in a new tab unless [NWMF_FORCEWINDOW](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-nwmf) is also present, indicating that user wants the window to open as a window.

### `NWMF_INACTIVETAB:0x100000`

The [EvaluateNewWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-inewwindowmanager-evaluatenewwindow) method is being called from an inactive tab.