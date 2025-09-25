# IFileDialog2::SetNavigationRoot

## Description

Specifies a top-level location from which to begin browsing a namespace, for instance in the **Save** dialog's **Browse folder** option. Users cannot navigate above this location.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)**

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object that represents the navigation root.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**SetNavigationRoot** can be used by applications that want to restrict navigation to a certain area of the Shell namespace. Items in the navigation pane are replaced with the supplied item, to guide the user from navigating outside of this part of the namespace.

This method cannot be called while the dialog is being displayed.

## See also

[IFileDialog2](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-ifiledialog2)