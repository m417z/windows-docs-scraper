## Description

A policy allowing a sync provider to control when the platform should clear the in-sync state on a placeholder file or directory.

## Constants

### `CF_INSYNC_POLICY_NONE:0x00000000`

The default in-sync policy.

### `CF_INSYNC_POLICY_TRACK_FILE_CREATION_TIME:0x00000001`

Clears in-sync state when a file is created.

### `CF_INSYNC_POLICY_TRACK_FILE_READONLY_ATTRIBUTE:0x00000002`

Clears in-sync state when a file is read-only.

### `CF_INSYNC_POLICY_TRACK_FILE_HIDDEN_ATTRIBUTE:0x00000004`

Clears in-sync state when a file is hidden.

### `CF_INSYNC_POLICY_TRACK_FILE_SYSTEM_ATTRIBUTE:0x00000008`

Clears in-sync state when a file is a system file.

### `CF_INSYNC_POLICY_TRACK_DIRECTORY_CREATION_TIME:0x00000010`

Clears in-sync state when a directory is created.

### `CF_INSYNC_POLICY_TRACK_DIRECTORY_READONLY_ATTRIBUTE:0x00000020`

Clears in-sync state when a directory is read-only.

### `CF_INSYNC_POLICY_TRACK_DIRECTORY_HIDDEN_ATTRIBUTE:0x00000040`

Clears in-sync state when a directory is hidden.

### `CF_INSYNC_POLICY_TRACK_DIRECTORY_SYSTEM_ATTRIBUTE:0x00000080`

Clears in-sync state when a directory is a system directory.

### `CF_INSYNC_POLICY_TRACK_FILE_LAST_WRITE_TIME:0x00000100`

Clears in-sync state based on the last write time to a file.

### `CF_INSYNC_POLICY_TRACK_DIRECTORY_LAST_WRITE_TIME:0x00000200`

Clears in-sync state based on the last write time to a directory.

### `CF_INSYNC_POLICY_TRACK_FILE_ALL:0x0055550f`

Clears in-sync state for any changes to a file.

### `CF_INSYNC_POLICY_TRACK_DIRECTORY_ALL:0x00aaaaf0`

Clears in-sync state for any changes to a directory.

### `CF_INSYNC_POLICY_TRACK_ALL:0x00ffffff`

Clears in-sync state for any changes to a file or directory.

### `CF_INSYNC_POLICY_PRESERVE_INSYNC_FOR_SYNC_ENGINE:0x80000000`

In-sync policies are exempt from clearing.

## See also

[CfRegisterSyncRoot](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfregistersyncroot)