# ACMFORMATCHOOSE structure

## Description

The **ACMFORMATCHOOSE** structure contains information the ACM uses to initialize the system-defined waveform-audio format selection dialog box. After the user closes the dialog box, the system returns information about the user's selection in this structure.

## Members

### `cbStruct`

Size, in bytes, of the **ACMFORMATCHOOSE** structure. This member must be initialized before an application calls the [acmFormatChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatchoose) function. The size specified in this member must be large enough to contain the base **ACMFORMATCHOOSE** structure.

### `fdwStyle`

Optional style flags for the [acmFormatChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatchoose) function. This member must be initialized to a valid combination of the following flags before an application calls the **acmFormatChoose** function:

| Name | Description |
| --- | --- |
| **ACMFORMATCHOOSE_STYLEF_CONTEXTHELP** | Context-sensitive help will be available in the dialog box. To use this feature, an application must register the ACMHELPMSGCONTEXTMENU and ACMHELPMSGCONTEXTHELP constants, using the [RegisterWindowMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerwindowmessagea) function. When the user invokes help, the registered message will be posted to the owning window. The message will contain the *wParam* and *lParam* parameters from the original WM_CONTEXTMENU or WM_CONTEXTHELP message. |
| **ACMFORMATCHOOSE_STYLEF_ENABLEHOOK** | Enables the hook function pointed to by the **pfnHook** member. An application can use hook functions for a variety of customizations, including answering the [MM_ACM_FORMATCHOOSE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-acm-formatchoose) message. |
| **ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATE** | Causes the ACM to create the dialog box template identified by **hInstance** and **pszTemplateName**. |
| **ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATEHANDLE** | The **hInstance** member identifies a data block that contains a preloaded dialog box template. If this flag is specified, the ACM ignores the **pszTemplateName** member. |
| **ACMFORMATCHOOSE_STYLEF_INITTOWFXSTRUCT** | The buffer pointed to by **pwfx** contains a valid [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure that the dialog box will use as the initial selection. |
| **ACMFORMATCHOOSE_STYLEF_SHOWHELP** | A help button will appear in the dialog box. To use a custom Help file, an application must register the ACMHELPMSGSTRING constant with the [RegisterWindowMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerwindowmessagea) function. When the user presses the help button, the registered message will be posted to the owner. |

### `hwndOwner`

Handle to the window that owns the dialog box. This member can be any valid window handle, or **NULL** if the dialog box has no owner. This member must be initialized before calling the [acmFormatChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatchoose) function.

### `pwfx`

Pointer to a [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure. If the ACMFORMATCHOOSE_STYLEF_INITTOWFXSTRUCT flag is specified in the **fdwStyle** member, this structure must be initialized to a valid format. When the [acmFormatChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatchoose) function returns, this buffer contains the selected format. If the user cancels the dialog box, no changes will be made to this buffer.

### `cbwfx`

Size, in bytes, of the buffer pointed to by **pwfx**. If the buffer is too small to contain the format information, the [acmFormatChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatchoose) function returns ACMERR_NOTPOSSIBLE. Also, the ACM copies the required size into this member. An application can use the [acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics) and [acmFormatTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformattagdetails) functions to determine the largest size required for this buffer.

### `pszTitle`

Pointer to a string to be placed in the title bar of the dialog box. If this member is **NULL**, the ACM uses the default title (that is, "Sound Selection").

### `szFormatTag`

Buffer containing a null-terminated string describing the format tag of the format selection when the [ACMFORMATTAGDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmformattagdetails) structure returned by the [acmFormatTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformattagdetails) function. If the user cancels the dialog box, this member will contain a null-terminated string.

### `szFormat`

Buffer containing a null-terminated string describing the format attributes of the format selection when the [ACMFORMATDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmformatdetails) structure returned by the [acmFormatDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatdetails) function. If the user cancels the dialog box, this member will contain a null-terminated string.

### `pszName`

Pointer to a string for a user-defined format name. If this is a non-null-terminated string, the ACM will attempt to match the name with a previously saved user-defined format name. If a match is found, the dialog box is initialized to that format. If a match is not found or this member is a null-terminated string, this member is ignored on input. When the [acmFormatChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatchoose) function returns, this buffer contains a null-terminated string describing the user-defined format. If the format name is untitled (that is, the user has not given a name for the format), this member will be a null-terminated string on return. If the user cancels the dialog box, no changes will be made to this buffer.

### `cchName`

Size, in characters, of the buffer identified by the **pszName** member. This buffer should be at least 128 characters long. If the **pszName** member is **NULL**, this member is ignored.

### `fdwEnum`

Optional flags for restricting the type of formats listed in the dialog box. These flags are identical to the *fdwEnum* flags for the [acmFormatEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatenum) function. If **pwfxEnum** is **NULL**, this member should be zero. The following values are defined:

| Name | Description |
| --- | --- |
| **ACM_FORMATENUMF_CONVERT** | The [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure pointed to by the **pwfxEnum** member is valid. The enumerator will enumerate only destination formats that can be converted from the given **pwfxEnum** format. |
| **ACM_FORMATENUMF_HARDWARE** | The enumerator should enumerate only formats that are supported in hardware by one or more of the installed waveform-audio devices. This flag provides a way for an application to choose only formats native to an installed waveform-audio device. |
| **ACM_FORMATENUMF_INPUT** | The enumerator should enumerate only formats that are supported for input (recording). |
| **ACM_FORMATENUMF_NCHANNELS** | The **nChannels** member of the [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure pointed to by the **pwfxEnum** member is valid. The enumerator will enumerate only a format that conforms to this attribute. |
| **ACM_FORMATENUMF_NSAMPLESPERSEC** | The **nSamplesPerSec** member of the [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure pointed to by the **pwfxEnum** member is valid. The enumerator will enumerate only a format that conforms to this attribute. |
| **ACM_FORMATENUMF_OUTPUT** | The enumerator should enumerate only formats that are supported for output (playback). |
| **ACM_FORMATENUMF_SUGGEST** | The [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure pointed to by the **pwfxEnum** member is valid. The enumerator will enumerate all suggested destination formats for the given **pwfxEnum** format. |
| **ACM_FORMATENUMF_WBITSPERSAMPLE** | The **wBitsPerSample** member of the [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure pointed to by the **pwfxEnum** member is valid. The enumerator will enumerate only a format that conforms to this attribute. |
| **ACM_FORMATENUMF_WFORMATTAG** | The **wFormatTag** member of the [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure pointed to by the **pwfxEnum** member is valid. The enumerator will enumerate only a format that conforms to this attribute. |

### `pwfxEnum`

Pointer to a **WAVEFORMATEX** structure that will be used to restrict the formats listed in the dialog box. The **fdwEnum** member defines the members of the structure pointed to by **pwfxEnum** that should be used for the enumeration restrictions. If no special restrictions are desired, this member can be **NULL**. For other requirements associated with the **pwfxEnum** member, see the description for the [acmFormatEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatenum) function.

### `hInstance`

Handle to a data block that contains a dialog box template specified by the **pszTemplateName** member. This member is used only if the **fdwStyle** member specifies the ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATE or ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATEHANDLE flag; otherwise, this member should be **NULL** on input.

### `pszTemplateName`

Pointer to a null-terminated string that specifies the name of the resource file for the dialog box template that is to be substituted for the dialog box template in the ACM. An application can use the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-makeintresourcea) macro for numbered dialog box resources. This member is used only if the **fdwStyle** member specifies the ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATE flag; otherwise, this member should be **NULL** on input.

### `lCustData`

Application-defined data that the ACM passes to the hook function identified by the **pfnHook** member. The system passes the data in the *lParam* parameter of the [WM_INITDIALOG](https://learn.microsoft.com/windows/win32/dlgbox/wm-initdialog) message.

### `pfnHook`

Pointer to a callback function that processes messages intended for the dialog box. An application must specify the ACMFORMATCHOOSE_STYLEF_ENABLEHOOK flag in the **fdwStyle** member to enable the hook; otherwise, this member should be **NULL**. The hook function should return **FALSE** to pass a message to the standard dialog box procedure or **TRUE** to discard the message. The callback function type is [acmFormatChooseHookProc](https://learn.microsoft.com/windows/desktop/api/msacm/nc-msacm-acmformatchoosehookproc).

## See also

[ACMFORMATDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmformatdetails)

[ACMFORMATTAGDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmformattagdetails)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)

[Audio Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-structures)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-makeintresourcea)

[MM_ACM_FORMATCHOOSE](https://learn.microsoft.com/windows/desktop/Multimedia/mm-acm-formatchoose)

[RegisterWindowMessage](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerwindowmessagea)

[WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85))

[WM_INITDIALOG](https://learn.microsoft.com/windows/win32/dlgbox/wm-initdialog)

[acmFormatChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatchoose)

[acmFormatDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatdetails)

[acmFormatEnum](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatenum)

[acmFormatTagDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformattagdetails)

[acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics)