# IFileDialogControlEvents::OnButtonClicked

## Description

Called when the user clicks a command button.

## Parameters

### `pfdc` [in]

Type: **[IFileDialogCustomize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialogcustomize)***

A pointer to the interface through which the application added controls to the dialog.

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the button that the user clicked.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.