# IOleUILinkInfoA::GetLastUpdate

## Description

Determines the last time the object was updated.

## Parameters

### `dwLink` [in]

Container-defined unique identifier for a single link. Containers can use the pointer to the link's container site for this value.

### `lpLastUpdate` [out]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that indicates the time that the object was last updated.

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

If the time that the object was last updated is known, copy it to *lpLastUpdate*. If it is not known, then leave *lpLastUpdate* unchanged and Unknown will be displayed in the link page.

## See also

[IOleUILinkInfo](https://learn.microsoft.com/windows/desktop/api/oledlg/nn-oledlg-ioleuilinkinfoa)