# IOleUILinkContainerW::OpenLinkSource

## Description

Opens the link's source.

## Parameters

### `dwLink` [in]

Container-defined unique identifier for a single link. Containers can use the pointer to the link's container site for this value.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Insufficient access permissions. |
| **E_FAIL** | The operation failed. |
| **E_INVALIDARG** | The specified identifier is invalid. |
| **E_OUTOFMEMORY** | There is insufficient memory available for this operation. |

## Remarks

### Notes to Callers

The **IOleUILinkContainer::OpenLinkSource** method is called when the **Open Source** button is selected from the **Links** dialog box. For OLE links, call [IOleObject::DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb), specifying OLEIVERB_SHOW for *iVerb*.

## See also

[IOleObject::DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb)

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)

[OLEVERB](https://learn.microsoft.com/windows/desktop/api/oleidl/ns-oleidl-oleverb)