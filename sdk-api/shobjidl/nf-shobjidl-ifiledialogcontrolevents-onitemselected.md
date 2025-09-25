# IFileDialogControlEvents::OnItemSelected

## Description

Called when an item is selected in a combo box, when a user clicks an option button (also known as a radio button), or an item is chosen from the **Tools** menu.

## Parameters

### `pfdc` [in]

Type: **[IFileDialogCustomize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialogcustomize)***

A pointer to the interface through which the application added controls to the dialog.

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the control in which the user made a selection.

### `dwIDItem` [in]

Type: **DWORD**

The ID of the selection.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This notification is not sent when the user chooses an item from the drop-down menu attached to the **Open** button, because the action taken in that case is always the same: close the dialog as if the user had simply clicked the **Open** button. For that situation, the application can call [GetSelectedControlItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialogcustomize-getselectedcontrolitem) to obtain the item the user chose from that menu.