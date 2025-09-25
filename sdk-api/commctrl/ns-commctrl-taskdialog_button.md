# TASKDIALOG_BUTTON structure

## Description

The **TASKDIALOG_BUTTON** structure contains information used to display a button in a task dialog. The [TASKDIALOGCONFIG](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-taskdialogconfig) structure uses this structure.

## Members

### `nButtonID`

Type: **int**

Indicates the value to be returned when this button is selected.

### `pszButtonText`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer that references the string to be used to label the button. This parameter can be either a null-terminated string or an integer resource identifier passed to the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. When using Command Links, you delineate the command from the note by placing a new line character in the string.