# TASKDIALOGCONFIG structure

## Description

The **TASKDIALOGCONFIG** structure contains information used to display a task dialog. The [TaskDialogIndirect](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-taskdialogindirect) function uses this structure.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the structure size, in bytes.

### `hwndParent`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the parent window. This member can be **NULL**.

### `hInstance`

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the module that contains the icon resource identified by the **pszMainIcon** or **pszFooterIcon** members, and the string resources identified by the **pszWindowTitle**, **pszMainInstruction**, **pszContent**, **pszVerificationText**, **pszExpandedInformation**, **pszExpandedControlText**, **pszCollapsedControlText** or **pszFooter** members.

### `dwFlags`

Type: **TASKDIALOG_FLAGS**

Specifies the behavior of the task dialog. This parameter can be a combination of flags from the following group:

| Value | Meaning |
| --- | --- |
| **TDF_ENABLE_HYPERLINKS** | Enables hyperlink processing for the strings specified in the **pszContent**, **pszExpandedInformation** and **pszFooter** members. When enabled, these members may point to strings that contain hyperlinks in the following form:<br><br>``` <A HREF="executablestring">Hyperlink Text</A> ```<br><br>**Warning: Enabling hyperlinks when using content from an unsafe source may cause security vulnerabilities.**<br><br>**Note** Task Dialogs will not actually execute any hyperlinks. Hyperlink execution must be handled in the callback function specified by **pfCallback**. For more details, see [TaskDialogCallbackProc](https://learn.microsoft.com/windows/desktop/api/commctrl/nc-commctrl-pftaskdialogcallback). |
| **TDF_USE_HICON_MAIN** | Indicates that the dialog should use the icon referenced by the handle in the **hMainIcon** member as the primary icon in the task dialog. If this flag is specified, the **pszMainIcon** member is ignored. |
| **TDF_USE_HICON_FOOTER** | Indicates that the dialog should use the icon referenced by the handle in the **hFooterIcon** member as the footer icon in the task dialog. If this flag is specified, the **pszFooterIcon** member is ignored. |
| **TDF_ALLOW_DIALOG_CANCELLATION** | Indicates that the dialog should be able to be closed using Alt-F4, Escape, and the title bar's close button even if no cancel button is specified in either the **dwCommonButtons** or **pButtons** members. |
| **TDF_USE_COMMAND_LINKS** | Indicates that the buttons specified in the **pButtons** member are to be displayed as command links (using a standard task dialog glyph) instead of push buttons. When using command links, all characters up to the first new line character in the **pszButtonText** member will be treated as the command link's main text, and the remainder will be treated as the command link's note. This flag is ignored if the **cButtons** member is zero. |
| **TDF_USE_COMMAND_LINKS_NO_ICON** | Indicates that the buttons specified in the **pButtons** member are to be displayed as command links (without a glyph) instead of push buttons. When using command links, all characters up to the first new line character in the **pszButtonText** member will be treated as the command link's main text, and the remainder will be treated as the command link's note. This flag is ignored if the **cButtons** member is zero. |
| **TDF_EXPAND_FOOTER_AREA** | Indicates that the string specified by the **pszExpandedInformation** member is displayed at the bottom of the dialog's footer area instead of immediately after the dialog's content. This flag is ignored if the **pszExpandedInformation** member is **NULL**. |
| **TDF_EXPANDED_BY_DEFAULT** | Indicates that the string specified by the **pszExpandedInformation** member is displayed when the dialog is initially displayed. This flag is ignored if the **pszExpandedInformation** member is **NULL**. |
| **TDF_VERIFICATION_FLAG_CHECKED** | Indicates that the verification checkbox in the dialog is checked when the dialog is initially displayed. This flag is ignored if the **pszVerificationText** parameter is **NULL**. |
| **TDF_SHOW_PROGRESS_BAR** | Indicates that a Progress Bar is to be displayed. |
| **TDF_SHOW_MARQUEE_PROGRESS_BAR** | Indicates that an Marquee Progress Bar is to be displayed. |
| **TDF_CALLBACK_TIMER** | Indicates that the task dialog's callback is to be called approximately every 200 milliseconds. |
| **TDF_POSITION_RELATIVE_TO_WINDOW** | Indicates that the task dialog is positioned (centered) relative to the window specified by **hwndParent**. If the flag is not supplied (or no **hwndParent** member is specified), the task dialog is positioned (centered) relative to the monitor. |
| **TDF_RTL_LAYOUT** | Indicates that text is displayed reading right to left. |
| **TDF_NO_DEFAULT_RADIO_BUTTON** | Indicates that no default item will be selected. |
| **TDF_CAN_BE_MINIMIZED** | Indicates that the task dialog can be minimized. |
| **TDIF_SIZE_TO_CONTENT** | This flag is deprecated. Use **TDF_SIZE_TO_CONTENT** instead. |
| **TDF_SIZE_TO_CONTENT** | Indicates that the width of the task dialog is determined by the width of its content area. This flag is ignored if **cxWidth** is not set to 0. |

### `dwCommonButtons`

Type: **TASKDIALOG_COMMON_BUTTON_FLAGS**

Specifies the push buttons displayed in the task dialog. If no common buttons are specified and no custom buttons are specified using the **cButtons** and **pButtons** members, the task dialog will contain the **OK** button by default. This parameter may be a combination of flags from the following group:

| Value | Meaning |
| --- | --- |
| **TDCBF_OK_BUTTON** | The task dialog contains the push button: **OK**. |
| **TDCBF_YES_BUTTON** | The task dialog contains the push button: **Yes**. |
| **TDCBF_NO_BUTTON** | The task dialog contains the push button: **No**. |
| **TDCBF_CANCEL_BUTTON** | The task dialog contains the push button: **Cancel**. If this button is specified, the task dialog will respond to typical cancel actions (Alt-F4 and Escape). |
| **TDCBF_RETRY_BUTTON** | The task dialog contains the push button: **Retry**. |
| **TDCBF_CLOSE_BUTTON** | The task dialog contains the push button: **Close**. |

### `pszWindowTitle`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer that references the string to be used for the task dialog title. This parameter can be either a null-terminated string or an integer resource identifier passed to the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. If this parameter is **NULL**, the filename of the executable program is used.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.hMainIcon`

Type: **[HICON](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to an Icon that is to be displayed in the task dialog. This member is ignored unless the TDF_USE_HICON_MAIN flag is specified. If this member is **NULL** and the TDF_USE_HICON_MAIN is specified, no icon will be displayed.

### `DUMMYUNIONNAME.pszMainIcon`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer that references the icon to be displayed in the task dialog. This parameter is ignored if the USE_HICON_MAIN flag is specified. Otherwise, if this parameter is **NULL** or the **hInstance** parameter is **NULL**, no icon will be displayed. This parameter must be an integer resource identifier passed to the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro or one of the following predefined values:

| Value | Meaning |
| --- | --- |
| **TD_ERROR_ICON** | A stop-sign icon appears in the task dialog. |
| **TD_WARNING_ICON** | An exclamation-point icon appears in the task dialog. |
| **TD_INFORMATION_ICON** | An icon consisting of a lowercase letter i in a circle appears in the task dialog. |
| **TD_SHIELD_ICON** | A shield icon appears in the task dialog. |

### `pszMainInstruction`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer that references the string to be used for the main instruction. This parameter can be either a null-terminated string or an integer resource identifier passed to the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro.

### `pszContent`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer that references the string to be used for the dialog's primary content. This parameter can be either a null-terminated string or an integer resource identifier passed to the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. If the ENABLE_HYPERLINKS flag is specified for the **dwFlags** member, then this string may contain hyperlinks in the form: \<A HREF="executablestring">Hyperlink Text\</A>. **WARNING: Enabling hyperlinks when using content from an unsafe source may cause security vulnerabilities.**

### `cButtons`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of entries in the **pButtons** array that is used to create buttons or command links in the task dialog. If this member is zero and no common buttons have been specified using the **dwCommonButtons** member, then the task dialog will have a single **OK** button displayed.

### `pButtons`

Type: **const [TASKDIALOG_BUTTON](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-taskdialog_button)***

Pointer to an array of [TASKDIALOG_BUTTON](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-taskdialog_button) structures containing the definition of the custom buttons that are to be displayed in the task dialog. This array must contain at least the number of entries that are specified by the **cButtons** member.

### `nDefaultButton`

Type: **int**

The default button for the task dialog. This may be any of the values specified in **nButtonID** members of one of the [TASKDIALOG_BUTTON](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-taskdialog_button) structures in the **pButtons** array, or one of the IDs corresponding to the buttons specified in the **dwCommonButtons** member:

|  |  |
| --- | --- |
| IDCANCEL | Make the **Cancel** button the default. |
| IDNO | Make the **No** button the default. |
| IDOK | Make the **OK** button the default. |
| IDRETRY | Make the **Retry** button the default. |
| IDYES | Make the **Yes** button the default. |
| IDCLOSE | Make the **Close** button the default. |

If this member is zero or its value does not correspond to any button ID in the dialog, then the first button in the dialog will be the default.

### `cRadioButtons`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of entries in the **pRadioButtons** array that is used to create radio buttons in the task dialog.

### `pRadioButtons`

Type: **const [TASKDIALOG_BUTTON](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-taskdialog_button)***

Pointer to an array of [TASKDIALOG_BUTTON](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-taskdialog_button) structures containing the definition of the radio buttons that are to be displayed in the task dialog. This array must contain at least the number of entries that are specified by the **cRadioButtons** member. This parameter can be **NULL**.

### `nDefaultRadioButton`

Type: **int**

The button ID of the radio button that is selected by default. If this value does not correspond to a button ID, the first button in the array is selected by default.

### `pszVerificationText`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer that references the string to be used to label the verification checkbox. This parameter can be either a null-terminated string or an integer resource identifier passed to the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. If this parameter is **NULL**, the verification checkbox is not displayed in the task dialog. If the *pfVerificationFlagChecked* parameter of [TaskDialogIndirect](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-taskdialogindirect) is **NULL**, the checkbox is not enabled.

### `pszExpandedInformation`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer that references the string to be used for displaying additional information. This parameter can be either a null-terminated string or an integer resource identifier passed to the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. The additional information is displayed either immediately below the content or below the footer text depending on whether the TDF_EXPAND_FOOTER_AREA flag is specified. If the TDF_ENABLE_HYPERLINKS flag is specified for the **dwFlags** member, then this string may contain hyperlinks in the form: \<A HREF="executablestring">Hyperlink Text\</A>. **WARNING: Enabling hyperlinks when using content from an unsafe source may cause security vulnerabilities.**

### `pszExpandedControlText`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer that references the string to be used to label the button for collapsing the expandable information. This parameter can be either a null-terminated string or an integer resource identifier passed to the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. This member is ignored when the **pszExpandedInformation** member is **NULL**. If this member is **NULL** and the **pszCollapsedControlText** is specified, then the **pszCollapsedControlText** value will be used for this member as well.

### `pszCollapsedControlText`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer that references the string to be used to label the button for expanding the expandable information. This parameter can be either a null-terminated string or an integer resource identifier passed to the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. This member is ignored when the **pszExpandedInformation** member is **NULL**. If this member is **NULL** and the **pszCollapsedControlText** is specified, then the **pszCollapsedControlText** value will be used for this member as well.

### `DUMMYUNIONNAME2`

### `DUMMYUNIONNAME2.hFooterIcon`

Type: **[HICON](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to an Icon that is to be displayed in the footer of the task dialog. This member is ignored unless the TDF_USE_HICON_FOOTER flag is specified and the **pszFooterIcon** is not. If this member is **NULL** and the TDF_USE_HICON_FOOTER is specified, no icon is displayed.

### `DUMMYUNIONNAME2.pszFooterIcon`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer that references the icon to be displayed in the footer area of the task dialog. This parameter is ignored if the TDF_USE_HICON_FOOTER flag is specified, or if **pszFooter** is **NULL**. Otherwise, if this parameter is **NULL** or the **hInstance** parameter is **NULL**, no icon is displayed. This parameter must be an integer resource identifier passed to the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro or one of the predefined values listed for **pszMainIcon**.

### `pszFooter`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to the string to be used in the footer area of the task dialog. This parameter can be either a null-terminated string or an integer resource identifier passed to the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. If the TDF_ENABLE_HYPERLINKS flag is specified for the **dwFlags** member, then this string may contain hyperlinks in this form.

```
<A HREF="executablestring">Hyperlink Text</A>
```

**Warning** Enabling hyperlinks when using content from an unsafe source may cause security vulnerabilities.

### `pfCallback`

Type: **PFTASKDIALOGCALLBACK**

Pointer to an application-defined callback function. For more information see [TaskDialogCallbackProc](https://learn.microsoft.com/windows/desktop/api/commctrl/nc-commctrl-pftaskdialogcallback).

### `lpCallbackData`

Type: **[LONG_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to application-defined reference data. This value is defined by the caller.

### `cxWidth`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The width of the task dialog's client area, in dialog units. If 0, the task dialog manager will calculate the ideal width.