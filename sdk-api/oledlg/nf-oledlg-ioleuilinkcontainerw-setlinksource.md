# IOleUILinkContainerW::SetLinkSource

## Description

Changes the source of a link.

## Parameters

### `dwLink` [in]

Container-defined unique identifier for a single link. See [IOleUILinkContainer::GetNextLink](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-getnextlink).

### `lpszDisplayName` [in]

Pointer to new source string to be parsed.

### `lenFileName` [in]

Length of the leading file name portion of the *lpszDisplayName* string. If the link source is not stored in a file, then *lenFileName* should be 0. For OLE links, call [IOleLink::GetSourceDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-getsourcedisplayname).

### `pchEaten` [out]

Pointer to the number of characters successfully parsed in *lpszDisplayName*.

### `fValidateSource` [in]

**TRUE** if the moniker should be validated; for OLE links, [MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname) should be called. **FALSE** if the moniker should not be validated. If possible, the link should accept the unvalidated source, and mark itself as unavailable.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Insufficient access permissions. |
| **E_FAIL** | The operation failed. |
| **E_INVALIDARG** | The supplied identifier is invalid. |
| **E_OUTOFMEMORY** | Insufficient memory available for this operation. |

## Remarks

### Notes to Callers

Call this method from the **Change Source** dialog box, with *fValidateSource* initially set to **TRUE**. **Change Source** can be called directly or from the **Links** dialog box. If this call to **IOleUILinkContainer::SetLinkSource** returns an error (e.g., [MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname) failed because the source was unavailable), then you should display an **Invalid Link Source** message, and the user should be allowed to decide whether to fix the source. If the user chooses to fix the source, then the user should be returned to the **Change Source** dialog box with the invalid portion of the input string highlighted. If the user chooses not to fix the source, then **IOleUILinkContainer::SetLinkSource** should be called a second time with *fValidateSource* set to **FALSE**, and the user should be returned to the **Links** dialog box with the link marked **Unavailable**.

## See also

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)

[MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname)