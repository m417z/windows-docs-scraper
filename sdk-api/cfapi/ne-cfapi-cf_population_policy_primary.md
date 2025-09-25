# CF_POPULATION_POLICY_PRIMARY enumeration

## Description

Allows a sync provider to control how placeholder directories and files should be created by the platform. This is the primary policy.

## Constants

### `CF_POPULATION_POLICY_PARTIAL:0`

With **CF_POPULATION_POLICY_PARTIAL** population policy, when the platform detects access on a not fully populated directory, it will request only the entries required by the user application from the sync provider. This policy is not currently supported by the platform.

### `CF_POPULATION_POLICY_FULL:2`

With **CF_POPULATION_POLICY_FULL** population policy, when the platform detects access on a not fully populated directory, it will request the sync provider return all entries under the directory before completing the user request.

### `CF_POPULATION_POLICY_ALWAYS_FULL:3`

When **CF_POPULATION_POLICY_ALWAYS_FULL** is selected, the platform assumes that the full name space is always available locally. It will never forward any directory enumeration request to the sync provider.

## See also

[CfRegisterSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfregistersyncroot)