# IOleClientSite::GetContainer

## Description

Retrieves a pointer to the object's container.

## Parameters

### `ppContainer` [out]

Address of [IOleContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecontainer) pointer variable that receives the interface pointer to the container object. If an error occurs, the implementation must set *ppContainer* to **NULL**.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_NOT_SUPPORTED** | The client site is in an OLE 1 container. |
| **E_NOINTERFACE** | The container does not implement the [IOleContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecontainer) interface. |

## Remarks

If a container supports links to its embedded objects, implementing **GetContainer** enables link clients to enumerate the container's objects and recursively traverse a containment hierarchy. This method is optional but recommended for all containers that expect to support links to their embedded objects.

Link clients can traverse a hierarchy of compound-document objects by recursively calling **GetContainer** to get a pointer to the link source's container; followed by [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to get a pointer to the container's [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject) interface and, finally, [IOleObject::GetClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getclientsite) to get the container's client site in its container.

Simple containers that do not support links to their embedded objects probably do not need to implement this method. Instead, they can return E_NOINTERFACE and set *ppContainer* to **NULL**.

## See also

[IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite)