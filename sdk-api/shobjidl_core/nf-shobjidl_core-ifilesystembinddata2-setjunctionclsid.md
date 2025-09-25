# IFileSystemBindData2::SetJunctionCLSID

## Description

Sets the class identifier (CLSID) of the object that implements [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder), if the current item is a junction point.

## Parameters

### `clsid` [in]

Type: **REFCLSID**

The CLSID for the object that implements [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) with a junction point as its current item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.