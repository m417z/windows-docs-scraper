# IFolderFilter::GetEnumFlags

## Description

Allows a client to specify which classes of objects in a Shell folder should be enumerated. When used with [SHBrowseForFolder](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shbrowseforfoldera), specifies the class or classes of items that should be shown in the dialog box tree view and which class or classes should not.

## Parameters

### `psf` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to the folder's [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) interface.

### `pidlFolder` [in]

Type: **PCIDLIST_ABSOLUTE**

The PIDL of the folder.

### `phwnd` [in]

Type: **HWND***

A pointer to the host's window handle.

### `pgrfFlags` [out]

Type: **DWORD***

One or more [SHCONTF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shcontf) values that specify the classes of object to enumerate.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFolderFilter](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderfilter)