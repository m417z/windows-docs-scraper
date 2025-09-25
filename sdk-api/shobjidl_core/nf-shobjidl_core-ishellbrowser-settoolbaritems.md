# IShellBrowser::SetToolbarItems

## Description

[This method has no effect on Windows Vista or later operating systems.]

Adds toolbar items to Windows Explorer's toolbar.

## Parameters

### `lpButtons`

Type: **LPTBBUTTONSB**

The address of an array of [TBBUTTON](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tbbutton) structures.

### `nButtons`

Type: **UINT**

The number of [TBBUTTON](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tbbutton) structures in the *lpButtons* array.

### `uFlags`

Type: **UINT**

Flags specifying where the toolbar buttons should go. This parameter can be one or more of the following values.

#### FCT_ADDTOEND

Add at the right side of the toolbar.

#### FCT_CONFIGABLE

Not implemented.

#### FCT_MERGE

Merge the toolbar items instead of replacing all of the buttons with those provided by the view. This is the recommended choice.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error value otherwise.

## See also

[IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser)