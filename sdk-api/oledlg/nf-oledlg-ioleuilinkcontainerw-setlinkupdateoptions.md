# IOleUILinkContainerW::SetLinkUpdateOptions

## Description

Sets a link's update options to automatic or manual.

## Parameters

### `dwLink` [in]

Container-defined unique identifier for a single link. See [IOleUILinkContainer::GetNextLink](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-getnextlink).

### `dwUpdateOpt` [in]

Update options, which can be automatic (OLEUPDATE_ALWAYS) or manual (OLEUPDATE_ONCALL).

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

Containers can implement this method for OLE links by simply calling [IOleLink::SetUpdateOptions](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-setupdateoptions) on the link object.

## See also

**IOleLink::SetUpdateOptions**

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)

[IOleUILinkContainer::GetNextLink](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-getnextlink)