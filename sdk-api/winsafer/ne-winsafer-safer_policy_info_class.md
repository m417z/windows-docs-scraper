# SAFER_POLICY_INFO_CLASS enumeration

## Description

The **SAFER_POLICY_INFO_CLASS** enumeration type defines the ways in which a policy may be queried.

## Constants

### `SaferPolicyLevelList:1`

Queries for the list of all levels defined in a policy.

### `SaferPolicyEnableTransparentEnforcement`

Queries for the policy value to determine whether DLL checking is enabled.

### `SaferPolicyDefaultLevel`

Queries for the default policy level.

### `SaferPolicyEvaluateUserScope`

Queries to determine whether user scope rules should be consulted during policy evaluation.

### `SaferPolicyScopeFlags`

Queries to determine whether the policy is to skip members of the local administrators group.

### `SaferPolicyDefaultLevelFlags`

### `SaferPolicyAuthenticodeEnabled`

## Remarks

The **SAFER_POLICY_INFO_CLASS** enumeration type is used by the [SaferGetPolicyInformation](https://learn.microsoft.com/windows/desktop/api/winsafer/nf-winsafer-safergetpolicyinformation) function.