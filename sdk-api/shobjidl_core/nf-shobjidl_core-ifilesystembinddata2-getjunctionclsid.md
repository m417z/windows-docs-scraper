# IFileSystemBindData2::GetJunctionCLSID

## Description

Gets the class identifier (CLSID) of the object that implements [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) for the item, if the item is a junction point.

## Parameters

### `pclsid` [out]

Type: **CLSID***

When this method returns successfully, receives a pointer to the CLSID of the object that implements [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) for the current item, if the item is a junction point.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.