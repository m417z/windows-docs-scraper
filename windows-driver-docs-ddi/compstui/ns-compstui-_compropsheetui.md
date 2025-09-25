## Description

The **COMPROPSHEETUI** structure is used as an input parameter to CPSUI's [ComPropSheet](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfncompropsheet) function, if the function code is [CPSFUNC_ADD_PCOMPROPSHEETUI](https://learn.microsoft.com/previous-versions/ff546388(v=vs.85)). All structure members must be supplied by the caller of *ComPropSheet*.

## Members

### `cbSize`

Caller-supplied size, in bytes, of the **COMPROPSHEETUI** structure.

### `Flags`

Optional caller-supplied bit flags, as described in the following list:

#### CPSUIF_ABOUT_CALLBACK

If set, the page's callback function (pointed to by the structure's **pfnCallback** member), supports CPSUICB_REASON_ABOUT, so CPSUI will call the callback function if the user clicks on the page's **About** button. (CPSUI supplies an **About** button for each treeview root node.)

#### CPSUIF_ICONID_AS_HICON

If set, the structure's **IconID** member contains an icon handle.

If not set, the **IconID** member contains an icon resource identifier.

#### CPSUIF_UPDATE_PERMISSION

If set, the page's option values can be modified by the user.

### `hInstCaller`

Caller-supplied module instance handle, received by the DLL's entry point function.

### `pCallerName`

Caller-supplied pointer to a NULL-terminated text string representing the application's name. (For a printer interface DLL, this should be the driver's name, such as "PostScript Driver".)

### `UserData`

Optional caller-supplied value, which CPSUI places in a [CPSUICBPARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_cpsuicbparam) structure's **UserData** member when calling the function pointed to by **pfnCallBack**.

### `pHelpFile`

Caller-supplied pointer to a NULL-terminated text string representing a path to a help file. For printer interface DLLs, this is typically the help file path obtained by calling [GetPrinterDriver](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriver).

The help file is indexed by values contained in the **HelpIndex** member of [OPTITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structures.

### `pfnCallBack`

Caller-supplied pointer to a [_CPSUICALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-_cpsuicallback)-typed callback function, which CPSUI calls when a user modifies the page's option values.

Can be used only if **pDlgPage** identifies a CPSUI-supplied [DLGPAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_dlgpage) structure, or if the **DlgProc** member of an application-supplied DLGPAGE structure is **NULL**.

### `pOptItem`

Caller-supplied pointer to an array of [OPTITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structures describing the page's options.

### `pDlgPage`

This member specifies [DLGPAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_dlgpage) structures that describe pages to be added to the property sheet. It can be either of the following:

- A pointer to an array of DLGPAGE structures.

- One of the pointers that is described in the following list. These pointers reference predefined DLGPAGE structures, supplied by CPSUI for use by printer interface DLLs.

  - CPSUI_PDLGPAGE_ADVDOCPROP

 Defines one treeview page whose tab reads **Advanced**. For use only by a [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function.

  - CPSUI_PDLGPAGE_DOCPROP
Defines three pages, whose tabs are **Layout**, **Paper/Quality**, and **Advanced**. The **Advanced** page is a treeview. For use only by a [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function.

  - CPSUI_PDLGPAGE_PRINTERPROP
Defines one treeview page whose tab reads **Device Settings**. For use only by a [DrvDevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdevicepropertysheets) function.

  - CPSUI_PDLGPAGE_TREEVIEWONLY

 Defines one treeview page.

### `cOptItem`

Caller-supplied number of [OPTITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structures pointed to by **pOptItem**.

### `cDlgPage`

Caller-supplied number of [DLGPAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_dlgpage) structures pointed to by **pDlgPage**. Not used if **pDlgPage** specifies a predefined CPSUI_PDLGPAGE-prefixed structure.

### `IconID`

Caller-supplied, can be one of the following:

- An icon resource identifier. This can be application-defined, or it can be one of the CPSUI-supplied, IDI_CPSUI-prefixed icon resource identifiers.

- An icon handle. If a handle is specified, CPSUIF_ICONID_AS_HICON must be set in the **Flags** member.

The specified icon is displayed in the root node of the property sheet page's treeview.

### `pOptItemName`

Caller-supplied pointer to a NULL-terminated string to be displayed in the root node of the property sheet page's treeview. For printer interface DLLs, this string typically represents a printer device type, such as "HP 4si".

### `CallerVersion`

Caller-supplied version number, representing the calling application's current version. The high byte identifies the major version, and the low byte is the minor version. For example, a **CallerVersion** value of 0x310 specifies a caller version number of 3.16. The version number is displayed when a user clicks on a page's **About** button.

### `OptItemVersion`

Caller-supplied version number, representing the root-level option item's current version. For printer interface DLLs, this typically represents a printer device version. The high byte identifies the major version, and the low byte is the minor version. For example, an **OptItemVersion** value of 0x3ff specifies a caller version number of 3.255. The version number is displayed when a user clicks on a page's **About** button.

### `dwReserved`

Reserved. This array must be set to zero.