# ACMFILTERCHOOSE structure

## Description

The **ACMFILTERCHOOSE** structure contains information the ACM uses to initialize the system-defined waveform-audio filter selection dialog box. After the user closes the dialog box, the system returns information about the user's selection in this structure.

## Members

### `cbStruct`

Size, in bytes, of the **ACMFILTERCHOOSE** structure. This member must be initialized before an application calls the [acmFilterChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterchoose) function. The size specified in this member must be large enough to contain the base **ACMFILTERCHOOSE** structure.

### `fdwStyle`

Optional style flags for the [acmFilterChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterchoose) function. This member must be initialized to a valid combination of the following flags before an application calls the **acmFilterChoose** function. The following values are defined:

| Name | Description |
| --- | --- |
| **ACMFILTERCHOOSE_STYLEF_CONTEXTHELP** | Context-sensitive help will be available in the dialog box. To use this feature, an application must register the ACMHELPMSGCONTEXTMENU and ACMHELPMSGCONTEXTHELP constants, using the [RegisterWindowMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerwindowmessagea) function. When the user invokes help, the registered message will be posted to the owning window. The message will contain the *wParam* and *lParam* parameters from the original WM_CONTEXTMENU or WM_CONTEXTHELP message. |
| **ACMFILTERCHOOSE_STYLEF_ENABLEHOOK** | Enables the hook function specified in the **pfnHook** member. An application can use hook functions for a variety of customizations, including answering the [MM_ACM_FILTERCHOOSE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-acm-filterchoose) message. |
| **ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATE** | Causes the ACM to create the dialog box template identified by the **hInstance** and **pszTemplateName** members. |
| **ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATEHANDLE** | The **hInstance** member identifies a data block that contains a preloaded dialog box template. If this flag is specified, the ACM ignores the **pszTemplateName** member. |
| **ACMFILTERCHOOSE_STYLEF_INITTOFILTERSTRUCT** | The buffer pointed to by **pwfltr** contains a valid [WAVEFILTER](https://learn.microsoft.com/windows/desktop/api/mmreg/ns-mmreg-wavefilter) structure that the dialog box will use as the initial selection. |
| **ACMFILTERCHOOSE_STYLEF_SHOWHELP** | A help button will appear in the dialog box. To use a custom Help file, an application must register the ACMHELPMSGSTRING value with the [RegisterWindowMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerwindowmessagea) function. When the user presses the help button, the registered message is posted to the owner. |

### `hwndOwner`

Handle to the window that owns the dialog box. This member can be any valid window handle or **NULL** if the dialog box has no owner. This member must be initialized before calling the [acmFilterChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterchoose) function.

### `pwfltr`

Pointer to a [WAVEFILTER](https://learn.microsoft.com/windows/desktop/api/mmreg/ns-mmreg-wavefilter) structure. If the ACMFILTERCHOOSE_STYLEF_INITTOFILTERSTRUCT flag is specified in the **fdwStyle** member, this structure must be initialized to a valid filter. When the [acmFilterChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterchoose) function returns, this buffer contains the selected filter. If the user cancels the dialog box, no changes will be made to this buffer.

### `cbwfltr`

Size, in bytes, of the buffer pointed to by the **pwfltr** member. The [acmFilterChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterchoose) function returns ACMERR_NOTPOSSIBLE if the buffer is too small to contain the filter information; the ACM also copies the required size into this member. An application can use the [acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics) and [acmFilterTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfiltertagdetails) functions to determine the largest size required for this buffer.

### `pszTitle`

Pointer to a string to be placed in the title bar of the dialog box. If this member is **NULL**, the ACM uses the default title (that is, "Filter Selection").

### `szFilterTag`

Buffer containing a null-terminated string describing the filter tag of the filter selection when the [ACMFILTERTAGDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmfiltertagdetails) structure returned by [acmFilterTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfiltertagdetails). If the user cancels the dialog box, this member will contain a null-terminated string.

### `szFilter`

Buffer containing a null-terminated string describing the filter attributes of the filter selection when the [ACMFILTERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmfilterdetails) structure returned by [acmFilterDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterdetails). If the user cancels the dialog box, this member will contain a null-terminated string.

### `pszName`

Pointer to a string for a user-defined filter name. If this is a non-null-terminated string, the ACM attempts to match the name with a previously saved user-defined filter name. If a match is found, the dialog box is initialized to that filter. If a match is not found or this member is a null-terminated string, this member is ignored for input. When the [acmFilterChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterchoose) function returns, this buffer contains a null-terminated string describing the user-defined filter. If the filter name is untitled (that is, the user has not given a name for the filter), this member will be a null-terminated string on return. If the user cancels the dialog box, no changes will be made to this buffer.

If the ACMFILTERCHOOSE_STYLEF_INITTOFILTERSTRUCT flag is specified by the **fdwStyle** member, the **pszName** member is ignored as an input member.

### `cchName`

Size, in characters, of the buffer identified by the **pszName** member. This buffer should be at least 128 characters long. If **pszName** is **NULL**, this member is ignored.

### `fdwEnum`

Optional flags for restricting the type of filters listed in the dialog box. These flags are identical to the *fdwEnum* flags for the [acmFilterEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterenum) function. If **pwfltrEnum** is **NULL**, this member should be zero.

| Name | Description |
| --- | --- |
| **ACM_FILTERENUMF_DWFILTERTAG** | The **dwFilterTag** member of the [WAVEFILTER](https://learn.microsoft.com/windows/desktop/api/mmreg/ns-mmreg-wavefilter) structure pointed to by the **pwfltrEnum** member is valid. The enumerator will only enumerate a filter that conforms to this attribute. |

### `pwfltrEnum`

Pointer to a [WAVEFILTER](https://learn.microsoft.com/windows/desktop/api/mmreg/ns-mmreg-wavefilter) structure that will be used to restrict the filters listed in the dialog box. The **fdwEnum** member defines which members of this structure should be used for the enumeration restrictions. The **cbStruct** member of this **WAVEFILTER** structure must be initialized to the size of the **WAVEFILTER** structure. If no special restrictions are desired, this member can be **NULL**.

### `hInstance`

Handle to a data block that contains a dialog box template specified by the **pszTemplateName** member. This member is used only if the **fdwStyle** member specifies the ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATE or ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATEHANDLE flag; otherwise, this member should be **NULL** on input.

### `pszTemplateName`

Pointer to a null-terminated string that specifies the name of the resource file for the dialog box template that is to be substituted for the dialog box template in the ACM. An application can use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-makeintresourcea) macro for numbered dialog box resources. This member is used only if the **fdwStyle** member specifies the ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATE flag; otherwise, this member should be **NULL** on input.

### `lCustData`

Application-defined data that the ACM passes to the hook function identified by the **pfnHook** member. The system passes the data in the *lParam* parameter of the [WM_INITDIALOG](https://learn.microsoft.com/windows/win32/dlgbox/wm-initdialog) message.

### `pfnHook`

Pointer to a callback function that processes messages intended for the dialog box. An application must specify the ACMFILTERCHOOSE_STYLEF_ENABLEHOOK flag in the **fdwStyle** member to enable the hook; otherwise, this member should be **NULL**. The hook function should return **FALSE** to pass a message to the standard dialog box procedure or **TRUE** to discard the message. The callback function type is [acmFilterChooseHookProc](https://learn.microsoft.com/windows/desktop/api/msacm/nc-msacm-acmfilterchoosehookproc).

## See also

[ACMFILTERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmfilterdetails)

[ACMFILTERTAGDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmfiltertagdetails)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)

[Audio Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-structures)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-makeintresourcea)

[MM_ACM_FILTERCHOOSE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-acm-filterchoose)

[RegisterWindowMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerwindowmessagea)

[WAVEFILTER](https://learn.microsoft.com/windows/desktop/api/mmreg/ns-mmreg-wavefilter)

[WM_INITDIALOG](https://learn.microsoft.com/windows/win32/dlgbox/wm-initdialog)

[acmFilterChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterchoose)

[acmFilterDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterdetails)

[acmFilterEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterenum)

[acmFilterTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfiltertagdetails)

[acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics)