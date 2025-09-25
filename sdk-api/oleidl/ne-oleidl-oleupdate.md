# OLEUPDATE enumeration

## Description

Indicates whether the linked object updates the cached data for the linked object automatically or only when the container calls either the [IOleObject::Update](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-update) or [IOleLink::Update](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-update) methods. The constants are used in the [IOleLink](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolelink) interface.

## Constants

### `OLEUPDATE_ALWAYS:1`

Update the link object whenever possible, this option corresponds to the **Automatic update** option in the **Links** dialog box.

### `OLEUPDATE_ONCALL:3`

Update the link object only when [IOleObject::Update](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-update) or [IOleLink::Update](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-update) is called, this option corresponds to the **Manual update** option in the **Links** dialog box.

## See also

[IOleLink::GetUpdateOptions](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-getupdateoptions)

[IOleLink::SetUpdateOptions](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-setupdateoptions)