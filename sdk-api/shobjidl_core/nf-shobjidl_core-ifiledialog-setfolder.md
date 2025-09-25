# IFileDialog::SetFolder

## Description

Sets a folder that is always selected when the dialog is opened, regardless of previous user action.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the interface that represents the folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This folder overrides any "most recently used" folder. If this method is called while the dialog is displayed, it causes the dialog to navigate to the specified folder.

In general, we do not recommended the use of this method. If you call **SetFolder** before you display the dialog box, the most recent location that the user saved to or opened from is not shown. Unless there is a very specific reason for this behavior, it is not a good or expected user experience and should therefore be avoided. In almost all instances, [IFileDialog::SetDefaultFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-setdefaultfolder) is the better method.

As of Windows 7, if the path of the folder specified through *psi* is the default path of a [known folder](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776911(v=vs.85)), the known folder's current path is used in the dialog. That path might not be the same as the path specified in *psi*; for instance, if the known folder has been redirected. If the known folder is a library (virtual folders Documents, Music, Pictures, and Videos), the library's path is used in the dialog. If the specified library is hidden (as they are by default as of Windows 8.1), the library's default save location is used in the dialog, such as the Microsoft OneDrive Documents folder for the Documents library. Because of these mappings, the folder location used in the dialog might not be exactly as you specified when you called this method.