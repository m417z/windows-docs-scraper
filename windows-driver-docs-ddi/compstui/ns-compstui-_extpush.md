## Description

The **EXTPUSH** structure is used by CPSUI applications (including printer interface DLLs) for specifying an extended push button, which can be added to a property sheet page option. When the button is pushed, a new dialog can be displayed.

## Members

### `cbSize`

Size, in bytes, of the **EXTPUSH** structure.

### `Flags`

Bit flags, which can be one of the following:

| Flag | Description |
|---|---|
| EPF_ICONID_AS_HICON | If set, the **IconID** member contains an icon handle. If not set, the **IconID** member contains an icon resource identifier. |
| EPF_INCLUDE_SETUP_TITLE | If set, CPSUI appends "Setup" to the string pointed to by **pTitle**. |
| EPF_NO_DOT_DOT_DOT | If set, CPSUI does not append "..." to the string pointed to by **pTitle**. |
| EPF_OVERLAY_NO_ICON | If set, CPSUI overlays its IDI_CPSUI_NO icon onto the icon identified by the **IconID** member. |
| EPF_OVERLAY_STOP_ICON | If set, CPSUI overlays the IDI_CPSUI_STOP icon onto the icon identified by the **IconID** member. |
| EPF_OVERLAY_WARNING_ICON | If set, CPSUI overlays its IDI_CPSUI_WARNING icon onto the icon identified by the **IconID** member. |
| EPF_PUSH_TYPE_DLGPROC | If set, the **DlgProc** and **DlgTemplateID/hDlgTemplate** members are valid. If not set, the **pfnCallBack** member is valid. |
| EPF_USE_HDLGTEMPLATE | If set, **hDlgTemplate** contains a template handle. If not set, **DlgTemplateID** contains a template resource identifier. |

### `pTitle`

String identifier, representing the push button title. This can be a 32-bit pointer to a NULL-terminated string, or it can be a 16-bit string resource identifier with HIWORD set to zero.

### `DUMMYUNIONNAME`

Defines the **DUMMYUNIONNAME** union.

### `DUMMYUNIONNAME.DlgProc`

DLGPROC-typed pointer to a dialog box procedure to process messages for the push button's dialog box. For more information on using [*DialogProc*](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-dlgproc), see the **Remarks** section below.

If this pointer is supplied, EPF_PUSH_TYPE_DLGPROC must be set in **Flags**.

### `DUMMYUNIONNAME.pfnCallBack`

Pointer to a [_CPSUICALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-_cpsuicallback)-typed callback function to handle the CPSUICB_REASON_PUSHBUTTON reason. For more information, see the following Remarks section.

If this pointer is supplied, EPF_PUSH_TYPE_DLGPROC must be cleared in **Flags**.

### `IconID`

One of the following icon identifiers:

- An icon resource identifier. This can be application-defined, or it can be one of the CPSUI-supplied, IDI_CPSUI-prefixed icon resource identifiers.

- An icon handle. If a handle is specified, EPF_ICONID_AS_HICON must be set in the **Flags** member.

- CPSUI displays the icon next to the push button. If this value is zero, an icon is not displayed.

### `DUMMYUNIONNAME2`

Defines the **DUMMYUNIONNAME2** union.

### `DUMMYUNIONNAME2.DlgTemplateID`

Specifies the resource ID for the dialog box.

If **DlgTemplateID** = 0 then common UI will call *DlgProc* with following parameter:

```cpp
DlgProc(hDlg, WM_USER, NULL, (LPARAM)pCPSUICBParam);
```

### `DUMMYUNIONNAME2.hDlgTemplate`

Handle to the **DLGTEMPLATE** which will be used for a pop up dialog box.

### `dwReserved`

Reserved, must be initialized to zero.

## Remarks

An extended push button is a CPSUI-defined type of push button that can be associated with an [**OPTITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structure. An **OPTITEM** structure can have one extended push button or one extended check box associated with it.

When you use the **EXTPUSH** structure to create a push button, you can optionally create an additional dialog box that opens when the user clicks on the button. To create this dialog box, you should specify a pointer to a dialog box procedure in the **DlgProc** member, and include a dialog template specification in either the **DlgTemplateID** or the **hDlgTemplate** member.

If EPF_USE_HDLGTEMPLATE is set in **Flags**, CPSUI creates the dialog box by calling [*DialogBoxIndirectParam*](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-dialogboxindirectparama), passing the contents of the **DlgProc** and **hDlgTemplate** members.

If EPF_USE_HDLGTEMPLATE is not set in **Flags**, CPSUI creates the dialog box by calling [*DialogBoxParam*](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-dialogboxparama), passing the contents of the **DlgProc** and **DlgTemplateID** members.

When the dialog box procedure is called with a *uMsg* value of WM_INITDIALOG, the *lParam* value is the address of a [**CPSUICBPARAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_cpsuicbparam) structure, with the **Reason** member set to CPSUICB_REASON_EXTPUSH. For more information about the *uMsg* and *lParam* parameters, see [*DialogProc*](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-dlgproc).

If you do not need CPSUI to display a dialog box when the user clicks on the button, you can specify the address of a [_CPSUICALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-_cpsuicallback)-typed callback function in the **pfnCallBack** member. When a user clicks on the button, CPSUI calls the callback function. The accompanying CPSUICBPARAM structure's **Reason** member will be set to CPSUICB_REASON_EXTPUSH.

## See also

[**EXTCHKBOX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_extchkbox)