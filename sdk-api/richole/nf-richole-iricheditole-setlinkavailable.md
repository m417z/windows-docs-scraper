# IRichEditOle::SetLinkAvailable

## Description

Sets the value of the link-available bit in the object's flags. The link-available bit defaults to **TRUE**. It should be set to **FALSE** if any errors occur on the link which would indicate problems connecting to the linked object or application. When those problems are repaired, the bit should be set to **TRUE** again.

## Parameters

### `iob`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of object whose bit is to be set. If this parameter is REO_IOB_SELECTION, the bit on the selected object is to be set.

### `fAvailable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value used in the set operation. The value can be **TRUE** or **FALSE**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK on success, or a failure code otherwise. E_INVALIDARG is returned if the index is invalid.

## See also

[IRichEditOle](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditole)