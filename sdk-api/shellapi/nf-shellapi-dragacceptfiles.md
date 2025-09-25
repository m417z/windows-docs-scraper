# DragAcceptFiles function

## Description

Registers whether a window accepts dropped files.

## Parameters

### `hWnd`

Type: **HWND**

The identifier of the window that is registering whether it will accept dropped files.

### `fAccept`

Type: **BOOL**

A value that indicates if the window identified by the *hWnd* parameter accepts dropped files. This value is **TRUE** to accept dropped files or **FALSE** to discontinue accepting dropped files.

## Remarks

An application that calls **DragAcceptFiles** with the *fAccept* parameter set to **TRUE** has identified itself as able to process the [WM_DROPFILES](https://learn.microsoft.com/windows/desktop/shell/wm-dropfiles) message from File Manager.