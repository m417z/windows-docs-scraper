# CF_HYDRATION_POLICY structure

## Description

Specifies the [CF_HYDRATION_POLICY_PRIMARY](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_hydration_policy_primary) and its [CF_HYDRATION_POLICY_MODIFIER](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_hydration_policy_modifier).

## Members

### `Primary`

The primary hydration policy.

### `Modifier`

The hydration policy modifier.

## Remarks

The hydration policy allows a sync provider to control how placeholder files should be hydrated by the platform. It consists of a primary policy and a set of policy modifiers.

## See also

[CF_HYDRATION_POLICY_PRIMARY](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_hydration_policy_primary)

[CF_HYDRATION_POLICY_MODIFIER](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_hydration_policy_modifier)