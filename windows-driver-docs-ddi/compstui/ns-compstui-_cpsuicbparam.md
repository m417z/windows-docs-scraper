## Description

The CPSUICBPARAM structure is used as the input parameter to [_CPSUICALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-_cpsuicallback)-typed callback functions.

## Members

### `cbSize`

CPSUI-supplied size, in bytes, of the CPSUICBPARAM structure.

### `Reason`

CPSUI-supplied value indicating the reason it is calling the callback function. This can be one of the following values:

#### CPSUICB_REASON_ABOUT

The user has clicked on the page's **About** button, and the application previously set the CPSUIF_ABOUT_CALLBACK flag in a [**COMPROPSHEETUI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_compropsheetui) structure. CPSUI sets *pCurItem* to the value contained in **pOptItem**, and sets **pOldSel** to point to the **COMPROPSHEETUI** structure.

#### CPSUICB_REASON_APPLYNOW

The user has clicked on the page's **Apply** or **OK** button, and CPSUI has received a [PSN_APPLY](https://learn.microsoft.com/windows/win32/controls/psm-apply) notification message. CPSUI sets **pCurItem** to point to the option to which **pOptItem** points. It also sets **OldSel** to minus one to indicate that all valid changed option values should be applied now.

#### CPSUICB_REASON_DLGPROC

The option identified by **pCurItem** is a push button ([TVOT_PUSHBUTTON](https://learn.microsoft.com/windows-hardware/drivers/print/tvot-pushbutton) option type), and the user has clicked on the button.

The push button option's OPTPARAM **Style** field is set to PUSHBUTTON_TYPE_DLGPROC.

#### CPSUICB_REASON_ECB_CHANGED

The option identified by **pCurItem** is an extended check box, and the user has changed the box's state.

#### CPSUICB_REASON_EXTPUSH

The option identified by **pCurItem** is an extended push button, and the user has clicked on the button.

#### CPSUICB_REASON_ITEMS_REVERTED

The user clicked on the page's **Undo** button, and CPSUI has reverted all selections to their original values.

#### CPSUICB_REASON_KILLACTIVE

The property sheet page is about to lose activation, and CPSUI has received a [PSN_KILLACTIVE](https://learn.microsoft.com/windows/win32/controls/psn-killactive) notification message. CPSUI sets **pCurItem** to the value contained in **pOptItem**, and sets **pOldSel** to point to the [**COMPROPSHEETUI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_compropsheetui) structure.

#### CPSUICB_REASON_OPTITEM_SETFOCUS

The option identified by **pCurItem** has received input focus.

#### CPSUICB_REASON_PUSHBUTTON

The option identified by **pCurItem** is a push button ([TVOT_PUSHBUTTON](https://learn.microsoft.com/windows-hardware/drivers/print/tvot-pushbutton) option type), and the user has clicked on the button.

The push button item's [**OPTPARAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optparam) **Style** field is set to PUSHBUTTON_TYPE_CALLBACK.

#### CPSUICB_REASON_SEL_CHANGED

The user has changed the selected value for the option pointed to by **pCurItem**.

#### CPSUICB_REASON_SETACTIVE

The property sheet page is about to become active, and CPSUI has received a [PSN_SETACTIVE](https://learn.microsoft.com/windows/win32/controls/psn-setactive) notification message. CPSUI sets **pCurItem** to the value contained in **pOptItem**, and sets **pOldSel** to point to the [**COMPROPSHEETUI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_compropsheetui) structure.

### `hDlg`

CPSUI-supplied handle to the currently active dialog box.

### `pOptItem`

CPSUI-supplied pointer to an array of [**OPTITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structures. This is the same pointer that the application previously supplied in a [**COMPROPSHEETUI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_compropsheetui) structure.

### `cOptItem`

CPSUI-supplied number of OPTITEM structures in the array pointed to by **pOptItem**. This is the same number that the application previously supplied in a [**COMPROPSHEETUI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_compropsheetui) structure.

### `Flags`

CPSUI-supplied flags. This is the same set of flags that the application previously supplied in a [**COMPROPSHEETUI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_compropsheetui) structure.

### `pCurItem`

CPSUI-supplied pointer to a member of the OPTITEM array pointed to by **pOptItem**. This array member represents the "current" option, which is the one for which the callback function was called.

### `DUMMYUNIONNAME`

Defines the **DUMMYUNIONNAME** union.

### `DUMMYUNIONNAME.OldSel`

If the **Reason** member contains CPSUICB_REASON_SEL_CHANGED, CPSUI sets this union to the previous contents of the **OldSel**/**pOldSel** member of the [**OPTITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structure pointed to by **pCurItem**.

For all other **Reason** values, the contents of this union should be ignored.

### `DUMMYUNIONNAME.pOldSel`

If the **Reason** member contains CPSUICB_REASON_SEL_CHANGED, CPSUI sets this union to the previous contents of the **OldSel**/**pOldSel** member of the [**OPTITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structure pointed to by **pCurItem**.

For all other **Reason** values, the contents of this union should be ignored.

### `UserData`

CPSUI-supplied user data. This is the same value that the application previously supplied in a [**COMPROPSHEETUI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_compropsheetui) structure.

### `Result`

Result value supplied by the [_CPSUICALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-_cpsuicallback)-typed callback function. By default, CPSUI sets this value to CPSUI_OK. After the callback function returns, CPSUI calls its [ComPropSheet](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfncompropsheet) function with a function code of [CPSFUNC_SET_RESULT](https://learn.microsoft.com/previous-versions/ff547087(v=vs.85)), supplying the **Reason** member contents as the result value.

This member is used only if the **Reason** member is CPSUICB_REASON_APPLYNOW and the callback function does not return CPSUI_ACTION_NO_APPLY_EXIT.