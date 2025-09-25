# IOleUILinkContainerA::GetLinkUpdateOptions

## Description

Determines the current update options for a link.

## Parameters

### `dwLink` [in]

Container-defined unique identifier for a single link. See [IOleUILinkContainer::GetNextLink](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-getnextlink).

### `lpdwUpdateOpt` [out]

A pointer to the location that the current update options will be written.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Insufficient access permissions. |
| **E_FAIL** | The operation failed. |
| **E_INVALIDARG** | The specified identifier is invalid. |
| **E_OUTOFMEMORY** | There is insufficient memory available for this operation. |

## Remarks

### Notes to Implementers

Containers can implement this method for OLE links simply by calling [IOleLink::SetUpdateOptions](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-setupdateoptions) on the link object.

## See also

[IOleLink::SetUpdateOptions](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-setupdateoptions)

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)

[IOleUILinkContainer::GetNextLink](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-getnextlink)

[IOleUILinkContainer::SetLinkUpdateOptions](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-setlinkupdateoptions)