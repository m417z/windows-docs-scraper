## Description

The **PROPSHEETUI_INFO** structure is used as an input parameter to [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui)-typed functions.

## Members

### `cbSize`

CPSUI-supplied size, in bytes, of the **PROPSHEETUI_INFO** structure.

### `Version`

CPSUI-supplied version number of the **PROPSHEETUI_INFO** structure. The current version number is defined by PROPSHEETUI_INFO_VERSION in compstui.h.

### `Flags`

CPSUI-supplied bit flags. The following flag is defined:

| Flag | Description |
|---|---|
| PSUIINFO_UNICODE | If set, the calling application uses Unicode characters. |

### `Reason`

CPSUI-supplied constant specifying the action to be performed on the property sheet by the [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui)-typed function to which the PROPSHEETUI_INFO structure was passed. One of the following constants will be supplied:

- PROPSHEETUI_REASON_DESTROY

- PROPSHEETUI_REASON_GET_ICON

- PROPSHEETUI_REASON_GET_INFO_HEADER

- PROPSHEETUI_REASON_INIT

- PROPSHEETUI_REASON_SET_RESULT

For information about the meaning of each constant, see the Remarks section of the [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui) description.

### `hComPropSheet`

CPSUI-supplied handle to a property sheet [group parent](https://learn.microsoft.com/windows-hardware/drivers/print/group-parent). This handle can be passed to CPSUI's [ComPropSheet](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfncompropsheet) function.

### `pfnComPropSheet`

Address of CPSUI's [ComPropSheet](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfncompropsheet) function.

### `lParamInit`

Value received as the *lParam* parameter for the associated PFNPROPSHEETUI-typed function, when the function was first called with a **Reason** of PROPSHEETUI_REASON_INIT. For information about what this value can be, see the description of [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui).

This value is supplied by CPSUI, and is valid for all **Reason** values.

### `UserData`

Optional, private value or pointer supplied by the associated [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui)-typed function, initially set to zero by CPSUI. If the function stores a value in **UserData**, then for subsequent calls to the function, the stored value or pointer is unchanged unless changed by the function.

### `Result`

Result value supplied by the associated [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui)-typed function, initially set to zero by CPSUI. If the function stores a result value in **Result**, then for subsequent calls to the function, the stored value is unchanged unless changed by the function.

If the PFNPROPSHEETUI-typed function's address was specified as an argument to [CommonPropertySheetUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nf-compstui-commonpropertysheetuia), the last value stored in **Result** is returned to **CommonPropertySheetUI** in the location pointed to by its *pResult* argument.