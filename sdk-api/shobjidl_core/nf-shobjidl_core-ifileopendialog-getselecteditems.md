# IFileOpenDialog::GetSelectedItems

## Description

Gets the currently selected items in the dialog. These items may be items selected in the view, or text selected in the file name edit box.

## Parameters

### `ppsai` [out]

Type: **[IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)****

The address of a pointer to an [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray) through which the selected items can be accessed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method can be used for single item or multiple item selections. If the user has entered new text in the file name field, this can be a time-consuming operation. When the application calls this method, the application parses the text in the `filename` field. For example, if this is a network share, the operation could take some time. However, this operation will not block the UI, since the user should able to stop the operation, which will result in **IFileOpenDialog::GetSelectedItems** returning a failure code).