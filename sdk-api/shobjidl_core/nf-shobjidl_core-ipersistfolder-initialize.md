# IPersistFolder::Initialize

## Description

Instructs a Shell folder object to initialize itself based on the information passed.

## Parameters

### `pidl`

Type: **LPCITEMIDLIST**

The address of the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) (item identifier list) structure that specifies the absolute location of the folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

All objects that implement the [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) interface for use in the Shell's namespace must implement this method. When a folder's location in the namespace is not a relevant consideration, this method can simply return S_OK. When the location is relevant to the folder, you should store the fully qualified IDLIST passed in for later reference.

For example, if the folder implementation needs to construct a fully qualified pointer to an item identifier list (PIDL) to elements that it contains, the PIDL passed to this method should be used to construct the fully qualified PIDLs.