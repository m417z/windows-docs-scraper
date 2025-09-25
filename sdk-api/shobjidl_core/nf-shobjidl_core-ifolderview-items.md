# IFolderView::Items

## Description

Gets the address of an enumeration object based on the collection of items in the folder view.

## Parameters

### `uFlags` [in]

Type: **UINT**

[_SVGIO](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_svgio) values that limit the enumeration to certain types of items.

### `riid` [in]

Type: **REFIID**

Reference to the desired IID to represent the folder.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This is typically an [IEnumIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumidlist), [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject), or [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray). If an error occurs, this value is **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IFolderView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifolderview)

[IFolderView::Item](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifolderview-item)