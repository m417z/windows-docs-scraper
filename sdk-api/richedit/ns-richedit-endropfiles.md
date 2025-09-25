# ENDROPFILES structure

## Description

Contains information associated with an [EN_DROPFILES](https://learn.microsoft.com/windows/win32/controls/en-dropfiles) notification code. A rich edit control sends this notification code when it receives a [WM_DROPFILES](https://learn.microsoft.com/windows/desktop/shell/wm-dropfiles) message.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr)**

Notification header.

### `hDrop`

Type: **[HANDLE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the dropped files list (same as with [WM_DROPFILES](https://learn.microsoft.com/windows/desktop/shell/wm-dropfiles) ). This handle is used with the [DragFinish](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-dragfinish), [DragQueryFile](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-dragqueryfilea), and [DragQueryPoint](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-dragquerypoint) functions.

### `cp`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Character position at which the dropped files would be inserted.

### `fProtected`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicates whether the specified character position is protected (**TRUE**) or not protected (**FALSE**).