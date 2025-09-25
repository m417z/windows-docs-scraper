# IFileDialogCustomize::EnableOpenDropDown

## Description

Enables a drop-down list on the **Open** or **Save** button in the dialog.

## Parameters

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the drop-down list.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The Open or Save button label takes on the text of the first item in the drop-down. This overrides any label set by [IFileDialog::SetOkButtonLabel](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-setokbuttonlabel).

 Use [IFileDialogCustomize::AddControlItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialogcustomize-addcontrolitem) to add items to the drop-down.