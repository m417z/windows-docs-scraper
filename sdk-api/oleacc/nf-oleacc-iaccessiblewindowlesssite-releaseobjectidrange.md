# IAccessibleWindowlessSite::ReleaseObjectIdRange

## Description

Releases an object ID range that was acquired by a previous call to the [IAccessibleWindowlessSite::AcquireObjectIdRange](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessiblewindowlesssite-acquireobjectidrange) method.

## Parameters

### `rangeBase` [in]

Type: **long**

The first object ID in the range of IDs to be released.

### `pRangeOwner` [in, optional]

Type: **[IAccessibleHandler](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessiblehandler)***

The windowless ActiveX control with which the range was associated when it was acquired.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To prevent mistakes when releasing object ranges, the system uses the *pControl* parameter to ensure that the range of object IDs being released actually belongs to the specified windowless control.

## See also

[IAccessibleWindowlessSite](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessiblewindowlesssite)

[IAccessibleWindowlessSite::AcquireObjectIdRange](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessiblewindowlesssite-acquireobjectidrange)