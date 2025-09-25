# IOleUILinkContainerA::GetNextLink

## Description

Enumerates the links in a container.

## Parameters

### `dwLink` [in]

Container-defined unique identifier for a single link. This value is only passed to other methods on this interface, so it can be any value that uniquely identifies a link to the container. Containers frequently use the pointer to the link's container site object for this value.

## Return value

Returns a container's link identifiers in sequence; **NULL** if it has returned the last link.

## Remarks

### Notes to Callers

Call this method to enumerate the links in a container. If the value passed in *dwLink* is **NULL**, then the container should return the first link's identifier. If *dwLink* identifies the last link in the container, then the container should return **NULL**.

## See also

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)

[IOleUILinkContainer::GetLinkUpdateOptions](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-getlinkupdateoptions)

[IOleUILinkContainer::SetLinkUpdateOptions](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-setlinkupdateoptions)