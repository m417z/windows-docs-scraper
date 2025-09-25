# CF_REGISTER_FLAGS enumeration

## Description

Flags for registering and updating a sync root.

## Constants

### `CF_REGISTER_FLAG_NONE:0x00000000`

No registration flags.

### `CF_REGISTER_FLAG_UPDATE:0x00000001`

Use this flag for modifying previously registered sync root identities and policies.

### `CF_REGISTER_FLAG_DISABLE_ON_DEMAND_POPULATION_ON_ROOT:0x00000002`

The on-demand directory/folder population behavior is globally controlled by the population policy. This flag allows a sync provider to opt out of the on-demand population behavior just for the sync root itself while keeping on-demand population on for all other directories under the sync root. This is useful when the sync provider would like to pre-populate the immediate child files/directories of the sync root.

### `CF_REGISTER_FLAG_MARK_IN_SYNC_ON_ROOT:0x00000004`

This flag allows a sync provider to mark the sync root to be registered in-sync simultaneously at the registration time. An alternative is to call [CfSetInSyncState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetinsyncstate) on the sync root later.

## See also

[CfSetInSyncState](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfsetinsyncstate)

[CfRegisterSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfregistersyncroot)