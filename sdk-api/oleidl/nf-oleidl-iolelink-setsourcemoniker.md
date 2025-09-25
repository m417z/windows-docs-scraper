# IOleLink::SetSourceMoniker

## Description

Sets the moniker for the link source.

## Parameters

### `pmk` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on a moniker that identifies the new link source of the linked object. A value of **NULL** breaks the link.

### `rclsid` [in]

The CLSID of the link source that the linked object should use to access information about the linked object when it is not bound.

## Return value

This method returns S_OK on success.

## Remarks

### Notes to Callers

Your container application can call **IOleLink::SetSourceMoniker** when the end user changes the source of a link or breaks a link. Note that this requires your container to use the [MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname) function to create a moniker out of the display name that the end user enters. If you'd rather have the linked object perform the parsing, your container can call [IOleLink::SetSourceDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-setsourcedisplayname) instead of **IOleLink::SetSourceMoniker**.

The end user changes the source of a link or breaks a link using the **Links** dialog box. If you use the [OleUIEditLinks](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuieditlinksa) function to display the **Links** dialog box, you must implement the [IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera) interface. The dialog box calls your implementations of [IOleUILinkContainer::SetLinkSource](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-setlinksource) and [IOleUILinkContainer::CancelLink](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-cancellink); your implementation of these methods can call **IOleLink::SetSourceMoniker**.

If the linked object is currently bound to its link source, the linked object's implementation of **IOleLink::SetSourceMoniker** closes the link before changing the moniker.

### Notes to Implementers

The [IOleLink](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolelink) contract does not specify how the linked object stores or uses the link source moniker. The provided implementation stores the absolute moniker specified when the link is created or when the moniker is changed; it then computes and stores a relative moniker. Future implementations might manage monikers differently to provide better moniker tracking. The absolute moniker provides the complete path to the link source. The linked object uses this absolute moniker and the moniker of the compound document to compute a relative moniker that identifies the link source relative to the compound document that contains the link.

pmkCompoundDoc->RelativePathTo(pmkAbsolute, ppmkRelative)

When binding to the link source, the linked object first tries to bind using the relative moniker. If that fails, it tries to bind the absolute moniker.

When the linked object successfully binds using either the relative or the absolute moniker, it automatically updates the other moniker. The linked object also updates both monikers when it is bound to the link source and it receives a rename notification through the [IAdviseSink::OnRename](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onrename) method. A container application can also use the [IOleLink::SetSourceDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-setsourcedisplayname) method to change a link's moniker.

The linked object's implementation of [IPersistStorage::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-save) saves both the relative and the absolute moniker.

## See also

[IOleLink](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolelink)

[IOleLink::GetSourceMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-getsourcemoniker)

[IOleLink::SetSourceDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-setsourcedisplayname)

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)

[OleUIEditLinks](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuieditlinksa)