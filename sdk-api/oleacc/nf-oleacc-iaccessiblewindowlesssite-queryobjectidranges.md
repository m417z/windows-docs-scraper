# IAccessibleWindowlessSite::QueryObjectIdRanges

## Description

Retrieves the object ID ranges that a particular windowless Microsoft ActiveX control has reserved.

## Parameters

### `pRangesOwner` [in, optional]

Type: **[IAccessibleHandler](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessiblehandler)***

The control whose ranges are being queried.

### `psaRanges` [out, optional]

Type: **SAFEARRAY****

Receives the array of object ID ranges. The array contains a set of paired integers. For each pair, the first integer is the first object ID in the range, and the second integer is a count of object IDs in the range.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAccessibleWindowlessSite](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessiblewindowlesssite)