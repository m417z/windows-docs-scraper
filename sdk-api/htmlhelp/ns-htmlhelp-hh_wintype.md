# HH_WINTYPE structure

## Description

Use this structure to specify or modify the attributes of a [window type](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms644703(v=vs.85)).

## Members

### `cbStruct`

Specifies the size of the structure. This value must always be filled in before passing the structure to HtmlHelp().

### `fUniCodeStrings`

Specifies whether the strings used in this structure are UNICODE.

### `pszType`

A null-terminated string that specifies the name of the window type.

### `fsValidMembers`

Specifies which members in the structure are valid.

### `fsWinProperties`

Specifies the properties of the window, such as whether it is the standard HTML Help Viewer or whether it includes a Search tab.

### `pszCaption`

A null-terminated string that specifies the caption to display in the title bar of the window.

### `dwStyles`

Specifies the styles used to create the window. These styles can be ignored, combined with extended styles, or used exclusively depending on the value of the *fsValidMembers* and *fsWinProperties* parameters.

### `dwExStyles`

Specifies the extended styles used to create the window. These styles can be ignored, combined with default styles, or used exclusively depending on the value of the *fsValidMembers* and *fsWinProperties* parameters.

### `rcWindowPos`

Specifies the coordinates of the window in pixels. The values are read in the following order:

*rcWindowPos* = {left, top, right, bottom};

### `nShowState`

Specifies the initial display state of the window. Valid values are the same as those for the Win32 API **ShowWindow** function.

### `hwndHelp`

Specifies the handle of the window if the window has been created.

### `hwndCaller`

Specifies the window that will receive HTML Help notification messages. [Notification messages](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/about-notification-messages) are sent via Windows **WM_NOTIFY** messages.

### `paInfoTypes`

Pointer to an array of Information Types.

### `hwndToolBar`

Specifies the handle of the toolbar.

### `hwndNavigation`

Specifies the handle of the Navigation pane.

### `hwndHTML`

Specifies the handle of the Topic pane, which hosts Shdocvw.dll.

### `iNavWidth`

Specifies the width of the Navigation pane when the Help Viewer is expanded.

### `rcHTML`

Specifies the coordinates of the Topic pane.

### `pszToc`

Specifies the contents (.hhc) file to display in the Navigation pane.

### `pszIndex`

Specifies the index (.hhk) file to display in the Navigation pane.

### `pszFile`

Specifies the default HTML file to display in the Topic pane.

### `pszHome`

Specifies the file or URL to display in the Topic pane when the Home button is clicked.

Specifies which buttons to include on the toolbar.

### `fsToolBarFlags`

Specifies which buttons to include on the Toolbar pane of a three-pane Help Viewer.

### `fNotExpanded`

Specifies that the Help Viewer open with the Navigation pane closed.

### `curNavType`

Specifies the default tab to display on the Navigation pane.

### `tabpos`

Specifies where to place the tabs on the Navigation pane of the HTML Help Viewer.

### `idNotify`

Specifies a non-zero ID for enabling HTML Help notification messages. This ID is passed as the wParam value of Windows **WM_NOTIFY** messages.

### `tabOrder`

Tab order: Contents, Index, Search, History, Favorites, Reserved 1-5, Custom tabs

### `cHistory`

Number of history items to keep. (Default: 30)

### `pszJump1`

Specifies the text to display underneath the Jump1 button.

### `pszJump2`

Specifies the text to display underneath the Jump2 button.

### `pszUrlJump1`

Specifies the URL to jump to when the Jump1 button is clicked.

### `pszUrlJump2`

Specifies the URL to jump to when the Jump2 button is clicked.

### `rcMinSize`

Minimum size for window (ignored in version 1).

### `cbInfoTypes`

Size of *paInfoTypes*

### `pszCustomTabs`

Series of zero-terminated strings to be used as tab labels.

## Remarks

Window types can be defined by an author in a project (.hhp) file, or they can be defined programmatically using the HTML Help API.

When a **HH_WINTYPE** structure is passed to **HtmlHelp()** using the **HH_SET_WIN_TYPE** command, the HTML Help API makes a private copy of the contents of the structure. The help developer is therefore responsible for freeing memory used by the **HH_WINTYPE** structure or character arrays within it. The help developer can free memory after calling **HH_SET_WIN_TYPE**.

### Used by

* [HH_SET_WIN_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/hh-set-win-type-command)
* [HH_GET_WIN_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/hh-get-win-type-command)

## See also

[About Structures](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/about-structures)