## Description

An enumeration of the set of supported conditions.

## Constants

### `ACTIVITY_COORDINATOR_CONDITION_GOOD`

The condition of the resource is good.

Background activities consuming a resource in this condition are highly unlikely to interfere with user experiences dependent on this resource.

### `ACTIVITY_COORDINATOR_CONDITION_MEDIUM`

The condition of the resource is acceptable.

Background activities consuming a resource in this condition may interfere with user experiences and/or system performance, but will not critically degrade them.

### `ACTIVITY_COORDINATOR_CONDITION_NOT_SET`

The condition of the resource is not monitored.

Policies should only use this condition for resources **not** consumed by their associated activities. Consuming a resource whose condition is not monitored can cause severe impact to the user experience and/or system performance, and may critically degrade them. Potential impacts may also not be transitory, such as consuming network on a metered connection (potential financial cost to the user) or running in a low battery state (reduced battery life for the user who may not have charging access).

## Remarks

## See also

[GetActivityCoordinatorPolicyResourceCondition](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-getactivitycoordinatorpolicyresourcecondition)

[SetActivityCoordinatorPolicyResourceCondition](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-setactivitycoordinatorpolicyresourcecondition)

[ACTIVITY_COORDINATOR_RESOURCE](https://learn.microsoft.com/windows/win32/api/activitycoordinatortypes/ne-activitycoordinatortypes-activity_coordinator_resource)