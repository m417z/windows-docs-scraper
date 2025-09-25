# IFileDialogControlEvents::OnControlActivating

## Description

Called when an **Open** button drop-down list customized through [EnableOpenDropDown](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialogcustomize-enableopendropdown) or a **Tools** menu is about to display its contents.

## Parameters

### `pfdc` [in]

Type: **[IFileDialogCustomize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialogcustomize)***

A pointer to an [IFileDialogCustomize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialogcustomize) object through which the application adds controls to the dialog.

### `dwIDCtl` [in]

Type: **DWORD**

The ID of the list or menu about to display.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In response to this notification, an application can update the contents of the menu or list about to be displayed, based on the current state of the dialog.