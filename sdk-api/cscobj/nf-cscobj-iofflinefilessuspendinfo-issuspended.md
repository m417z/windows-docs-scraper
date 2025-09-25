# IOfflineFilesSuspendInfo::IsSuspended

## Description

Determines whether an item is suspended.

If an item is suspended and is a suspended root, it was suspended by using the [IOfflineFilesSuspend::SuspendRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessuspend-suspendroot) method. If an item is suspended but is not a suspended root, its suspension was inherited from a suspended root.

## Parameters

### `pbSuspended` [out]

Receives **TRUE** if the item is suspended, or **FALSE** otherwise.

### `pbSuspendedRoot` [out]

Receives **TRUE** if the item is a suspended root, or **FALSE** otherwise. If the item is not suspended, this value is always **FALSE**.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesSuspendInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessuspendinfo)