# IOleObject::GetClientSite

## Description

Retrieves a pointer to an embedded object's client site.

## Parameters

### `ppClientSite` [out]

Address of [IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite) pointer variable that receives the interface pointer to the object's client site. If an object does not yet know its client site, or if an error has occurred, *ppClientSite* must be set to **NULL**. Each time an object receives a call to **IOleObject::GetClientSite**, it must increase the reference count on *ppClientSite*. It is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when it is done with *ppClientSite*.

## Return value

This method returns S_OK on success.

## Remarks

Link clients most commonly call the **IOleObject::GetClientSite** method in conjunction with the [IOleClientSite::GetContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getcontainer) method to traverse a hierarchy of nested objects. A link client calls **IOleObject::GetClientSite** to get a pointer to the link source's client site. The client then calls **IOleClientSite::GetContainer** to get a pointer to the link source's container. Finally, the client calls [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to get [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject) and **IOleObject::GetClientSite** to get the container's client site within its container. By repeating this sequence of calls, the caller can eventually retrieve a pointer to the master container in which all the other objects are nested.

### Notes to Callers

The returned client-site pointer will be **NULL** if an embedded object has not yet been informed of its client site. This will be the case with a newly loaded or created object when a container has passed a **NULL** client-site pointer to one of the object-creation helper functions but has not yet called [IOleObject::SetClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setclientsite) as part of initializing the object.

## See also

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::SetClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setclientsite)