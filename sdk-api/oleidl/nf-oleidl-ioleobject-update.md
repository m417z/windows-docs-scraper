# IOleObject::Update

## Description

Updates an object handler's or link object's data or view caches.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |
| **OLE_E_CANT_BINDTOSOURCE** | Cannot run object to get updated data. The object is for some reason unavailable to the caller. |
| **CACHE_E_NOCACHE_UPDATED** | No caches were updated. |
| **CACHE_S_SOMECACHES_NOTUPDATED** | Some caches were not updated. |

## Remarks

The **Update** method provides a way for containers to keep data updated in their linked and embedded objects. A link object can become out-of-date if the link source has been updated. An embedded object that contains links to other objects can also become out of date. An embedded object that does not contain links cannot become out of date because its data is not linked to another source.

### Notes to Implementers

When a container calls a link object's **IOleObject::Update** method, the link object finds the link source and gets a new presentation from it. This process may also involve running one or more object applications, which could be time-consuming.

When a container calls an embedded object's **IOleObject::Update** method, it is requesting the object to update all link objects it may contain. In response, the object handler recursively calls **IOleObject::Update** for each of its own linked objects, running each one as needed.

## See also

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::IsUpToDate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-isuptodate)