# IOleClientSite::ShowObject

## Description

Asks a container to display its object to the user. This method ensures that the container itself is visible and not minimized.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_NOT_SUPPORTED** | Client site is in an OLE 1 container. |

## Remarks

After a link client binds to a link source, it commonly calls [IOleObject::DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb) on the link source, usually requesting the source to perform some action requiring that it display itself to the user. As part of its implementation of **IOleObject::DoVerb**, the link source can call **ShowObject**, which forces the client to show the link source as best it can. If the link source's container is itself an embedded object, it will recursively invoke **ShowObject** on its own container.

Having called the **ShowObject** method, a link source has no guarantee of being appropriately displayed because its container may not be able to do so at the time of the call. The **ShowObject** method does not guarantee visibility, only that the container will do the best it can.

## See also

[IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite)

[IOleObject::DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb)