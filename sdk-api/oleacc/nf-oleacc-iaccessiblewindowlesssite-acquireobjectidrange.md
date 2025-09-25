# IAccessibleWindowlessSite::AcquireObjectIdRange

## Description

Acquires a range of object IDs from the control host and marks them as reserved by a specific windowless control.

## Parameters

### `rangeSize` [in]

The size of the object ID range that is being requested.

### `pRangeOwner` [in, optional]

The windowless control that is requesting the range.

### `pRangeBase` [out]

The first object ID in the acquired range.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To avoid using an object ID that belongs to another windowless control, a control should acquire an object ID range before calling the [NotifyWinEvent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-notifywinevent) function. A control should acquire enough object IDs for all of its contained accessible objects. For example, a tree control with 100 children would reserve at least 101 object IDs, one for the root, and one for each child. A tree control that is expected to grow would reserve as many object IDs as expected. If the tree control is expected to grow by several hundred children, it would reserve a range of 1000 IDs just to be safe.

When the window that contains the Microsoft ActiveX control receives a [WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject) message with an **LPARAM** value (object ID) that is in a reserved range, it should call the [IAccessibleHandler::AccessibleObjectFromID](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessiblehandler-accessibleobjectfromid) method to get an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) object for that object ID.

## See also

[IAccessibleWindowlessSite](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessiblewindowlesssite)

[IAccessibleWindowlessSite::ReleaseObjectIdRange](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessiblewindowlesssite-releaseobjectidrange)