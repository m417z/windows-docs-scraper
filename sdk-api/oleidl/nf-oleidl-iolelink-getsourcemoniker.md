# IOleLink::GetSourceMoniker

## Description

Retrieves the moniker identifying the link source of a linked object.

## Parameters

### `ppmk` [out]

Address of an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) pointer variable that receives the interface pointer to an absolute moniker that identifies the link source. When successful, the implementation must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on *ppmk*; it is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs the implementation must set *ppmk* to **NULL**.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **MK_E_UNAVAILABLE** | No moniker is available. |

## Remarks

### Notes to Callers

Your container application can call **IOleLink::GetSourceMoniker** to display the current source of a link in the **Links** dialog box. Note that this requires your container to use the [IMoniker::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-getdisplayname) method to get the display name of the moniker. If you would rather get the display name directly, your container can call [IOleLink::GetSourceDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-getsourcedisplayname) instead of **IOleLink::GetSourceMoniker**.

If you use the [OleUIEditLinks](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuieditlinksa) function to display the **Links** dialog box, you must implement the [IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera) interface. The dialog box calls your implementations of [IOleUILinkContainer::GetLinkSource](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-getlinksource) to get the string it should display. Your implementation of that method can call **IOleLink::GetSourceMoniker**.

### Notes to Implementers

The linked object stores both an absolute and a relative moniker for the link source. If the relative moniker is non-**NULL** and a moniker is available for the compound document, **IOleLink::GetSourceMoniker** returns the moniker created by composing the relative moniker onto the end of the compound document's moniker. Otherwise, it returns the absolute moniker or, if an error occurs, **NULL**.

The container specifies the absolute moniker when it calls one of the [OleCreateLink](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatelink) functions to create a link. The application can call **IOleLink::GetSourceMoniker** or [IOleLink::GetSourceDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-getsourcedisplayname) to change the absolute moniker. In addition, the linked object automatically updates the monikers whenever it successfully binds to the link source, or when it is bound to the link source and it receives a rename notification through the [IAdviseSink::OnRename](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onrename) method.

## See also

[IOleLink](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolelink)

[IOleLink::GetSourceDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-getsourcedisplayname)

[IOleLink::GetSourceMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-getsourcemoniker)