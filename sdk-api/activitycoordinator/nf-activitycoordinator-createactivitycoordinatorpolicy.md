## Description

Allocates a new policy and pre-populates fields based on the supplied policy template enumeration. The caller can customize the policy further using [SetActivityCoordinatorPolicyResourceCondition](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-setactivitycoordinatorpolicyresourcecondition).

## Parameters

### `policyTemplate`

Supplies a policy template enumeration value.

### `policy`

Supplies a pointer to an **ACTIVITY_COORDINATOR_POLICY** handle that receives the created policy handle.

## Return value

Returns an **HRESULT**.

## Remarks

The caller should subscribe to the policy to receive coordination notifications using [SubscribeActivityCoordinatorPolicy](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-subscribeactivitycoordinatorpolicy). When no longer needed, the caller should destroy the policy using [DestroyActivityCoordinatorPolicy](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-destroyactivitycoordinatorpolicy).

## See also

[GetActivityCoordinatorPolicyResourceCondition](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-getactivitycoordinatorpolicyresourcecondition)

[SetActivityCoordinatorPolicyResourceCondition](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-setactivitycoordinatorpolicyresourcecondition)

[SubscribeActivityCoordinatorPolicy](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-subscribeactivitycoordinatorpolicy)

[DestroyActivityCoordinatorPolicy](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-destroyactivitycoordinatorpolicy)

[ACTIVITY_COORDINATOR_POLICY_TEMPLATE](https://learn.microsoft.com/windows/win32/api/activitycoordinatortypes/ne-activitycoordinatortypes-activity_coordinator_policy_template)