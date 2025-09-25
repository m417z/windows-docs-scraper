# SHMapPIDLToSystemImageListIndex function

## Description

[**SHMapPIDLToSystemImageListIndex** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Retrieves the icon index from the system image list that is associated with a folder item.

## Parameters

### `pshf` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

An [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) interface pointer for the folder that contains the item.

### `pidl` [in]

Type: **PCUITEMID_CHILD**

A pointer to the item's [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure.

### `piIndexSel` [out, optional]

Type: **int***

A pointer to an **int** that, when this function returns successfully, receives the index of the item's **open** icon in the system image list. If the item does not have a special **open** icon then the index of its normal icon is returned. If the **open** icon exists and cannot be obtained, then the value pointed to by *piIndex* is set to -1. This parameter can be **NULL** if the calling application is not interested in the **open** icon.

## Return value

Type: **int**

Returns the index of the item's normal icon in the system image list if successful, or -1 otherwise.