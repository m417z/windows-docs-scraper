# IShellFolderBand::InitializeSFB

## Description

Initializes an [IShellFolderBand](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-ishellfolderband) object.

## Parameters

### `psf`

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to an [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) object.

### `pidl`

Type: **PCIDLIST_ABSOLUTE**

A PIDL.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)

[IShellFolderBand](https://learn.microsoft.com/windows/desktop/api/shlobj/nn-shlobj-ishellfolderband)