# PRJ_UPDATE_FAILURE_CAUSES enumeration

## Description

Descriptions for the reason an update failed.

## Constants

### `PRJ_UPDATE_FAILURE_CAUSE_NONE:0x00000000`

The update did not fail.

### `PRJ_UPDATE_FAILURE_CAUSE_DIRTY_METADATA:0x00000001`

The item was a dirty placeholder (hydrated or not), and the provider did not specify PRJ_UPDATE_ALLOW_DIRTY_METADATA in [PRJ_UPDATE_TYPES](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ne-projectedfslib-prj_update_types).

### `PRJ_UPDATE_FAILURE_CAUSE_DIRTY_DATA:0x00000002`

The item was a full file and the provider did not specify PRJ_UPDATE_ALLOW_DIRTY_DATA in [PRJ_UPDATE_TYPES](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ne-projectedfslib-prj_update_types).

### `PRJ_UPDATE_FAILURE_CAUSE_TOMBSTONE:0x00000004`

The item was a tombstone and the provider did not specify PRJ_UPDATE_ALLOW_TOMBSTONE in [PRJ_UPDATE_TYPES](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ne-projectedfslib-prj_update_types).

### `PRJ_UPDATE_FAILURE_CAUSE_READ_ONLY:0x00000008`

The item had the DOS read-only bit set and the provider did not specify PRJ_UPDATE_ALLOW_READ_ONLY in [PRJ_UPDATE_TYPES](https://learn.microsoft.com/windows/desktop/api/projectedfslib/ne-projectedfslib-prj_update_types).