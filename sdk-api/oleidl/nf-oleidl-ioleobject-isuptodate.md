# IOleObject::IsUpToDate

## Description

Checks whether an object is up to date.

## Return value

This method returns S_OK if the object is up to date; otherwise, S_FALSE. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_UNAVAILABLE** | The status of object cannot be determined in a timely manner. |

## Remarks

The **IOleObject::IsUpToDate** method provides a way for containers to check recursively whether all objects are up to date. That is, when the container calls this method on the first object, the object in turn calls it for all its own objects, and they in turn for all of theirs, until all objects have been checked.

### Notes to Implementers

Because of the recursive nature of **IOleObject::IsUpToDate**, determining whether an object is out-of-date, particularly one containing one or more other objects, can be as time-consuming as simply updating the object in the first place. If you would rather avoid lengthy queries of this type, make sure that **IOleObject::IsUpToDate** returns OLE_E_UNAVAILABLE. In cases where the object to be queried is small and contains no objects itself, thereby making an efficient query possible, this method can return either S_OK or S_FALSE.

## See also

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::Update](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-update)