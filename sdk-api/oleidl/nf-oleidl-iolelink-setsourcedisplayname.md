# IOleLink::SetSourceDisplayName

## Description

Sets the display name for the link source.

## Parameters

### `pszStatusText` [in]

A pointer to the display name of the new link source. This parameter cannot be **NULL**.

## Return value

This method returns S_OK on success.

Values from [MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname) may also be returned here.

## Remarks

### Notes to Callers

Your container application can call **IOleLink::SetSourceDisplayName** when the end user changes the source of a link or breaks a link. Note that this requires the linked object to create a moniker out of the display name. If you'd rather parse the display name into a moniker yourself, your container can call [IOleLink::SetSourceMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-setsourcemoniker) instead of **IOleLink::SetSourceDisplayName**.

If you use the [OleUIEditLinks](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuieditlinksa) function to display the **Links** dialog box, you must implement the [IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera) interface. The dialog box calls your implementations of [IOleUILinkContainer::SetLinkSource](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-setlinksource) and [IOleUILinkContainer::CancelLink](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-cancellink). Your implementation of these methods can call **IOleLink::SetSourceDisplayName**.

If your container application is immediately going to bind to a newly specified link source, you should call [MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname) and [IOleLink::SetSourceMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-setsourcemoniker) instead, and then call [IOleLink::BindToSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-bindtosource) using the bind context from the parsing operation. By reusing the bind context, you can avoid redundant loading of objects that might otherwise occur.

### Notes to Implementers

The contract for **IOleLink::SetSourceDisplayName** does not specify when the linked object will parse the display name into a moniker. The parsing can occur before **IOleLink::SetSourceDisplayName** returns, or the linked object can store the display name and parse it only when it needs to bind to the link source. Note that parsing the display name is potentially an expensive operation because it might require binding to the link source. The provided implementation of **IOleLink::SetSourceDisplayName** parses the display name and then releases the bind context used in the parse operation. This can result in running and then stopping the link source server.

If the linked object is bound to the current link source, the implementation of **IOleLink::SetSourceDisplayName** breaks the connection.

For more information on how the linked object stores and uses the moniker to the link source, see [IOleLink::SetSourceMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-setsourcemoniker).

## See also

[IOleLink](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolelink)

[IOleLink::SetSourceMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-setsourcemoniker)

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)

[MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname)

[OleUIEditLinks](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuieditlinksa)