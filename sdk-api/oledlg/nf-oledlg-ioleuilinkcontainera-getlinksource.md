# IOleUILinkContainerA::GetLinkSource

## Description

Retrieves information about a link that can be displayed in the **Links** dialog box.

## Parameters

### `dwLink` [in]

Container-defined unique identifier for a single link. See [IOleUILinkContainer::GetNextLink](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-ioleuilinkcontainera-getnextlink).

### `lplpszDisplayName` [out, optional]

Address of a pointer variable that receives a pointer to the full display name string for the link source. The **Links** dialog box will free this string.

### `lplenFileName` [out]

Pointer to the length of the leading file name portion of the *lplpszDisplayName* string. If the link source is not stored in a file, then *lplenFileName* should be 0. For OLE links, call [IOleLink::GetSourceDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-getsourcedisplayname).

### `lplpszFullLinkType` [out, optional]

Address of a pointer variable that receives a pointer to the full link type string that is displayed at the bottom of the **Links** dialog box. The caller allocates this string. The **Links** dialog box will free this string. For OLE links, this should be the full User Type name. Use [IOleObject::GetUserType](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getusertype), specifying USERCLASSTYPE_FULL for *dwFormOfType*.

### `lplpszShortLinkType` [out, optional]

Address of a pointer variable that receives a pointer to the short link type string that is displayed in the listbox of the **Links** dialog box. The caller allocates this string. The **Links** dialog box will free this string. For OLE links, this should be the short user type name. Use [IOleObject::GetUserType](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getusertype), specifying USERCLASSTYPE_SHORT for *dwFormOfType*.

### `lpfSourceAvailable` [out]

Pointer that returns **FALSE** if it is known that a link is unavailable since the link is to some known but unavailable document. Certain options, such as **Update Now**, are disabled (grayed in the user interface) for such cases.

### `lpfIsSelected` [out]

Pointer to a variable that tells the **Edit Links** dialog box that this link's entry should be selected in the dialog's multi-selection listbox. [OleUIEditLinks](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuieditlinksa) calls this method at least once for each item to be placed in the links list. If none of them return **TRUE**, then none of them will be selected when the dialog box is first displayed. If all of them return **TRUE**, then all will be displayed. That is, it returns **TRUE** if this link is currently part of the selection in the underlying document, **FALSE** if not. Any links that are selected in the underlying document are selected in the dialog box; this way, the user can select a set of links and use the dialog box to update them or change their source(s) simultaneously.

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

Call this method during dialog box initialization, after returning from the **Change Source** dialog box.

## See also

[IOleLink::GetSourceDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-getsourcedisplayname)

[IOleObject::GetUserType](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getusertype)

[IOleUILinkContainer](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkcontainera)

[OLEUICHANGESOURCE](https://learn.microsoft.com/windows/desktop/api/oledlg/ns-oledlg-oleuichangesourcea)

[OleUIChangeSource](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuichangesourcea)

[USERCLASSTYPE](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-userclasstype)