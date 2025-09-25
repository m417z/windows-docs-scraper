# IOleItemContainer::IsRunning

## Description

Determines whether the specified object is running.

## Parameters

### `pszItem` [in]

The container's name for the object.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The object is running. |
| **S_FALSE** | The object is not running. |
| **MK_E_NOOBJECT** | The parameter does not identify an object in this container. |

## Remarks

The item moniker implementation of [IMoniker::IsRunning](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-isrunning) calls this method.

### Notes to Implementers

Your implementation of **IOleItemContainer::IsRunning** should first determine whether *pszItem* identifies one of the container's objects. If it does not, your implementation should return MK_E_NOOBJECT. If the object is not loaded, your implementation should return S_FALSE. If it is loaded, your implementation can call the [OleIsRunning](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleisrunning) function to determine whether it is running.

If *pszItem* names a pseudo-object, your implementation can simply return S_OK because a pseudo-object is running whenever its container is running.

## See also

[IOleItemContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleitemcontainer)