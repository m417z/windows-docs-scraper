# IEnumIDList::Clone

## Description

Creates a new item enumeration object with the same contents and state as the current one.

## Parameters

### `ppenum`

Type: **[IEnumIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumidlist)****

The address of a pointer to the new enumeration object. The calling application must eventually free the new object by calling its [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) member function.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error value otherwise.

## Remarks

This method makes it possible to record a particular point in the enumeration sequence and then return to that point at a later time.

## See also

[IEnumIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumidlist)