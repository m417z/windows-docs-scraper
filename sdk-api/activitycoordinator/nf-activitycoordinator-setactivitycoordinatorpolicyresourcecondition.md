## Description

Sets a resource’s desired condition for a policy. For resources the developer does not want their policy to monitor, they can set the resource’s condition to **ACTIVITY_COORDINATOR_CONDITION_NOT_SET**.

## Parameters

### `policy`

Supplies a handle to the target policy.

### `resource`

Supplies the resource of interest.

### `condition`

Supplies the desired condition.

## Return value

Returns an **HRESULT**.

## Remarks

## See also

[ACTIVITY_COORDINATOR_CONDITION](https://learn.microsoft.com/windows/win32/api/activitycoordinatortypes/ne-activitycoordinatortypes-activity_coordinator_condition)

[ACTIVITY_COORDINATOR_RESOURCE](https://learn.microsoft.com/windows/win32/api/activitycoordinatortypes/ne-activitycoordinatortypes-activity_coordinator_resource)