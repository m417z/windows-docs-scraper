# IPersistFolder2::GetCurFolder

## Description

Gets the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) for the folder object.

## Parameters

### `ppidl`

Type: **LPITEMIDLIST***

The address of an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) pointer. This PIDL represents the absolute location of the folder and must be relative to the desktop. This is typically a copy of the PIDL passed to [Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipersistfolder-initialize).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the folder object has not been initialized, this method returns S_FALSE and *ppidl* is set to **NULL**.