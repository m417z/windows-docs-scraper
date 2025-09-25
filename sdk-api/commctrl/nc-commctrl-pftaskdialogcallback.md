## Description

The *TaskDialogCallbackProc* function is an application-defined function used with the [TaskDialogIndirect](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-taskdialogindirect) function. It receives messages from the task dialog when various events occur.

The **PFTASKDIALOGCALLBACK** type defines a pointer to this callback function. *TaskDialogCallbackProc* is a placeholder for the application defined function name.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the TaskDialog window. Do not continue sending messages to hwnd after the callback procedure returns from having been called with [TDN_DESTROYED](https://learn.microsoft.com/windows/desktop/Controls/tdn-destroyed).

### `msg` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One of the following notifications.

| Notification | Usage |
| --- | --- |
| [TDN_BUTTON_CLICKED](https://learn.microsoft.com/windows/desktop/Controls/tdn-button-clicked) | Indicates that a button has been selected. The command ID of the button is specified by *wParam*. |
| [TDN_CREATED](https://learn.microsoft.com/windows/desktop/Controls/tdn-created) | Indicates that the Task Dialog has been created. |
| [TDN_DESTROYED](https://learn.microsoft.com/windows/desktop/Controls/tdn-destroyed) | Indicates that the Task Dialog has been destroyed. |
| [TDN_DIALOG_CONSTRUCTED](https://learn.microsoft.com/windows/desktop/Controls/tdn-dialog-constructed) | Indicates that the Task Dialog has been created but has not been displayed yet. |
| [TDN_EXPANDO_BUTTON_CLICKED](https://learn.microsoft.com/windows/desktop/Controls/tdn-expando-button-clicked) | Indicates that the expando button has been selected. |
| [TDN_HELP](https://learn.microsoft.com/windows/desktop/Controls/tdn-help) | Indicates that the F1 key has been pressed while the Task Dialog has focus. |
| [TDN_HYPERLINK_CLICKED](https://learn.microsoft.com/windows/desktop/Controls/tdn-hyperlink-clicked) | Indicates that a hyperlink has been selected. A pointer to the link text is specified by *lParam*. |
| [TDN_NAVIGATED](https://learn.microsoft.com/windows/desktop/Controls/tdn-navigated) | Indicates that navigation has occurred. |
| [TDN_RADIO_BUTTON_CLICKED](https://learn.microsoft.com/windows/desktop/Controls/tdn-radio-button-clicked) | Indicates that a radio button has been selected. The command ID of the radio button is specified by *wParam*. |
| [TDN_TIMER](https://learn.microsoft.com/windows/desktop/Controls/tdn-timer) | Indicates that the Task Dialog timer has fired. The total elapsed time is specified by *wParam*. You can update the progress bar by sending a [TDM_SET_PROGRESS_BAR_POS](https://learn.microsoft.com/windows/desktop/Controls/tdm-set-progress-bar-pos) message to the window specified by the *hwnd* parameter. |
| [TDN_VERIFICATION_CLICKED](https://learn.microsoft.com/windows/desktop/Controls/tdn-verification-clicked) | Indicates that the Task Dialog verification check box has been selected. |

### `wParam` [in]

Type: **[WPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies additional notification information. The contents of this parameter depend on the value of the *uNotification* parameter.

### `lParam` [in]

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies additional notification information. The contents of this parameter depend on the value of the *uNotification* parameter.

### `lpRefData`

Type: **[LONG_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to application specific data. This is the data pointed to by the **lpCallbackData** member of structure [TASKDIALOGCONFIG](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-taskdialogconfig) used to create the task dialog.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The return value is specific to the notification being processed. When responding to a button click, your implementation should return S_FALSE if the Task Dialog is not to close. Otherwise return S_OK.

## Remarks

An application must register this callback function by passing its address in the **pfCallback** member of the [TASKDIALOGCONFIG](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-taskdialogconfig) structure that is passed via pointer through [TaskDialogIndirect](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-taskdialogindirect).