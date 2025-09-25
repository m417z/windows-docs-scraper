# IFolderView::GetFolder

## Description

Gets the folder object.

## Parameters

### `riid` [in]

Type: **REFIID**

Reference to the desired IID to represent the folder.

### `ppv` [out]

Type: **VOID****

When this method returns, contains the interface pointer requested in *riid*. This is typically [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) or a related interface. This can also be an [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray) with a single element.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.