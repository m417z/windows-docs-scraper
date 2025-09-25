# OLEVERBATTRIB enumeration

## Description

Describes the attributes of a specified verb for an object.

## Constants

### `OLEVERBATTRIB_NEVERDIRTIES:1`

Executing this verb will not cause the object to become dirty and is therefore in need of saving to persistent storage.

### `OLEVERBATTRIB_ONCONTAINERMENU:2`

Indicates a verb that should appear in the container's menu of verbs for this object. OLEIVERB_HIDE, OLEIVERB_SHOW, and OLEIVERB_OPEN never have this value set.

## Remarks

Values are used in the enumerator (which supports the [IEnumOLEVERB](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ienumoleverb) interface) that is created by a call to [IOleObject::EnumVerbs](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumverbs).

## See also

[IEnumOLEVERB](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ienumoleverb)

[IOleObject::EnumVerbs](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumverbs)

[OLEVERB](https://learn.microsoft.com/windows/desktop/api/oleidl/ns-oleidl-oleverb)