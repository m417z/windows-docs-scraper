# TaskDialogIndirect function

## Description

The **TaskDialogIndirect** function creates, displays, and operates a task dialog. The task dialog contains application-defined icons, messages, title, verification check box, command links, push buttons, and radio buttons. This function can register a callback function to receive notification messages.

## Parameters

### `pTaskConfig` [in]

Type: **const [TASKDIALOGCONFIG](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-taskdialogconfig)***

Pointer to a [TASKDIALOGCONFIG](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-taskdialogconfig) structure that contains information used to display the task dialog.

### `pnButton` [out, optional]

Type: **int***

Address of a variable that receives either:

* one of the button IDs specified in the **pButtons** member of the *pTaskConfig* parameter
* one of the following values:

| Value | Description |
| --- | --- |
| 0 | Function call failed. Refer to return value for more information. |
| **IDCANCEL** | **Cancel** button was selected, Alt-F4 was pressed, Escape was pressed or the user clicked on the **close window** button. |
| **IDNO** | **No** button was selected. |
| **IDOK** | **OK** button was selected. |
| **IDRETRY** | **Retry** button was selected. |
| **IDYES** | **Yes** button was selected. |

If this parameter is **NULL**, no value is returned.

### `pnRadioButton` [out, optional]

Type: **int***

Address of a variable that receives one of the button IDs specified in the **pRadioButtons** member of the *pTaskConfig* parameter. If this parameter is **NULL**, no value is returned.

### `pfVerificationFlagChecked` [out, optional]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Address of a variable that receives one of the following values.

| Value | Description |
| --- | --- |
| **TRUE** | The verification checkbox was checked when the dialog was dismissed. |
| **FALSE** | The verification checkbox was not checked when the dialog was dismissed. |

If this parameter is **NULL**, the verification checkbox is disabled.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **E_OUTOFMEMORY** | There is insufficient memory to complete the operation. |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **E_FAIL** | The operation failed. |

## Remarks

When you use a task dialog box to indicate that the system is low on memory, the strings pointed to by the various string and icon members in the [TASKDIALOGCONFIG](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-taskdialogconfig) structure should not be taken from a resource file since an attempt to load the resource may fail.

 If you create a task dialog while a dialog box is present, use a handle to the dialog box as the *hWndParent* parameter. The *hWndParent* parameter should not identify a child window, such as a control in a dialog box.

The parent window should not be hidden or disabled when this function is called.

```

int nButtonPressed                  = 0;
TASKDIALOGCONFIG config             = {0};
const TASKDIALOG_BUTTON buttons[]   = {
                                        { IDOK, L"Change password" }
                                      };
config.cbSize                       = sizeof(config);
config.hInstance                    = hInst;
config.dwCommonButtons              = TDCBF_CANCEL_BUTTON;
config.pszMainIcon                  = TD_WARNING_ICON;
config.pszMainInstruction           = L"Change Password";
config.pszContent                   = L"Remember your changed password.";
config.pButtons                     = buttons;
config.cButtons                     = ARRAYSIZE(buttons);

TaskDialogIndirect(&config, &nButtonPressed, NULL, NULL);
switch (nButtonPressed)
{
    case IDOK:
        break; // the user pressed button 0 (change password).
    case IDCANCEL:
        break; // user canceled the dialog
    default:
        break; // should never happen
}
```

## See also

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)