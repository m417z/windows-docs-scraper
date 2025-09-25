## Description

Gets a resource’s desired condition for a policy. Unmonitored resources in a policy are indicated by **ACTIVITY_COORDINATOR_CONDITION_NOT_SET**.

## Parameters

### `policy`

Supplies a handle to the target policy.

### `resource`

Supplies the resource of interest.

### `condition`

Supplies a pointer to a buffer that receives the resource’s configured condition.

## Return value

Returns an **HRESULT**.

## Remarks

## See also

[ACTIVITY_COORDINATOR_CONDITION](https://learn.microsoft.com/windows/win32/api/activitycoordinatortypes/ne-activitycoordinatortypes-activity_coordinator_condition)

[ACTIVITY_COORDINATOR_RESOURCE](https://learn.microsoft.com/windows/win32/api/activitycoordinatortypes/ne-activitycoordinatortypes-activity_coordinator_resource)