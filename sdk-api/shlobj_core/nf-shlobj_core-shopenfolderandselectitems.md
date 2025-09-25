# SHOpenFolderAndSelectItems function

## Description

Opens a Windows Explorer window with specified items in a particular folder selected.

## Parameters

### `pidlFolder` [in]

Type: **PCIDLIST_ABSOLUTE**

A pointer to a fully qualified item ID list that specifies the folder.

### `cidl`

Type: **UINT**

A count of items in the selection array, *apidl*. If *cidl* is zero, then *pidlFolder* must point to a fully specified [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) describing a single item to select. This function opens the parent folder and selects that item.

### `apidl` [in, optional]

Type: **PCUITEMID_CHILD_ARRAY**

A pointer to an array of PIDL structures, each of which is an item to select in the target folder referenced by *pidlFolder*.

### `dwFlags`

Type: **DWORD**

The optional flags. Under Windows XP this parameter is ignored. In Windows Vista, the following flags are defined.

#### OFASI_EDIT (0x0001)

Select an item and put its name in edit mode. This flag can only be used when a single item is being selected. For multiple item selections, it is ignored.

#### OFASI_OPENDESKTOP (0x0002)

Select the item or items on the desktop rather than in a Windows Explorer window. Note that if the desktop is obscured behind open windows, it will not be made visible.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) must be called before using **SHOpenFolderAndSelectItems**. Not doing so causes **SHOpenFolderAndSelectItems** to fail.