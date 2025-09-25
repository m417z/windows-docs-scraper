# IViewObject::Unfreeze

## Description

Releases a drawing that was previously frozen using [IViewObject::Freeze](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-freeze). The most common use of this method is for banded printing.

## Parameters

### `dwFreeze` [in]

Contains a key previously returned from [IViewObject::Freeze](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-freeze) that determines which view object to unfreeze.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_NOCONNECTION** | Error in the unfreezing process or the object is currently not frozen. |

## See also

[IViewObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject)

[IViewObject::Freeze](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-freeze)