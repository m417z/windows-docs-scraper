# DragFinish function

## Description

Releases memory that the system allocated for use in transferring file names to the application.

## Parameters

### `hDrop`

Type: **HDROP**

Identifier of the structure that describes dropped files. This handle is retrieved from the *wParam* parameter of the [WM_DROPFILES](https://learn.microsoft.com/windows/desktop/shell/wm-dropfiles) message.