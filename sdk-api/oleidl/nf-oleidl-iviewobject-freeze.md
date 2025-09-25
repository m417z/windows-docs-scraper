# IViewObject::Freeze

## Description

Freezes the drawn representation of an object so that it will not change until the [IViewObject::Unfreeze](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-unfreeze) method is called. The most common use of this method is for banded printing.

## Parameters

### `dwDrawAspect` [in]

Specifies how the object is to be represented. Representations include content, an icon, a thumbnail, or a printed document. Valid values are taken from the enumeration [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect). See the **DVASPECT** enumeration for more information.

### `lindex` [in]

Portion of the object that is of interest for the draw operation. Its interpretation varies with dwAspect. See the [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) enumeration for more information.

### `pvAspect` [in]

Pointer to additional information about the view of the object specified in *dwAspect*. Since none of the current aspects support additional information, *pvAspect* must always be **NULL**.

### `pdwFreeze` [out]

Pointer to where an identifying DWORD key is returned. This unique key is later used to cancel the freeze by calling [IViewObject::Unfreeze](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-unfreeze). This key is an index that the default cache uses to keep track of which object is frozen.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **VIEW_S_ALREADY_FROZEN** | Presentation has already been frozen. The value of *pdwFreeze* is the identifying key of the already frozen object. |
| **OLE_E_BLANK** | Presentation not in cache. |
| **DV_E_LINDEX** | Invalid value for *lindex*; currently; only -1 is supported. |
| **DV_E_DVASPECT** | Invalid value for *dwAspect*. |

## Remarks

The **IViewObject::Freeze** method causes the view object to freeze its drawn representation until a subsequent call to [IViewObject::Unfreeze](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-unfreeze) releases it. After calling **IViewObject::Freeze**, successive calls to [IViewObject::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw) with the same parameters produce the same picture until **IViewObject::Unfreeze** is called.

**IViewObject::Freeze** is not part of the persistent state of the object and does not continue across unloads and reloads of the object.

The most common use of this method is for banded printing.

While in a frozen state, view notifications are not sent. Pending view notifications are deferred to the subsequent call to [IViewObject::Unfreeze](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-unfreeze).

## See also

[DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect)

[IViewObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject)

[IViewObject::Unfreeze](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-unfreeze)