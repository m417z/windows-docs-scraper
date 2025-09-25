## Description

Specifies a placeholder management policy for a [CF_SYNC_POLICIES](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_sync_policies) structure.

## Constants

### `CF_PLACEHOLDER_MANAGEMENT_POLICY_DEFAULT` : 0x00000000
Only a sync provider can perform placeholder management operations in a sync roo

### `CF_PLACEHOLDER_MANAGEMENT_POLICY_CREATE_UNRESTRICTED` : 0x00000001

Any process can create a placeholder within an active sync root.

### `CF_PLACEHOLDER_MANAGEMENT_POLICY_CONVERT_TO_UNRESTRICTED` : 0x00000002

Any process can convert a file within an active sync root to a placeholder.

### `CF_PLACEHOLDER_MANAGEMENT_POLICY_UPDATE_UNRESTRICTED` : 0x00000004

Any process can update a placeholder within an active sync root.

## Remarks

By default, only a sync provider can perform placeholder management operations in a sync root. Non sync provider processes can perform placeholder management operations only if the sync root is inactive, i.e., when the sync root is not connected to by any sync provider. These policies, when enabled, allow non sync provider processes to perform respective placeholder management operations in an active sync root. The default policy allowing only a connected sync provider to perform any placeholder management operations. The three other policies can be specified in any combination.

## See also

[CF_SYNC_POLICIES](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_sync_policies)