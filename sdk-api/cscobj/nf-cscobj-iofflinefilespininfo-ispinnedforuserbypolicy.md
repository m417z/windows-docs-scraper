# IOfflineFilesPinInfo::IsPinnedForUserByPolicy

## Description

Determines whether the item was pinned for users by Group Policy.

## Parameters

### `pbPinnedForUser` [out]

Receives **TRUE** if the item was pinned for users by Group Policy, or **FALSE** otherwise.

### `pbInherit` [out]

Receives **TRUE** if the pinned state is inherited by new child items, or **FALSE** otherwise.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

When an item is pinned in the Offline Files cache, it is protected from automatic eviction and is guaranteed to be available offline.

This method corresponds to the OFFLINEFILES_PIN_CONTROL_FLAG_FORUSER_POLICY pin control flag used by the [IOfflineFilesCache::Pin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-pin) method.

## See also

[IOfflineFilesCache::Pin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-pin)

[IOfflineFilesPinInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilespininfo)