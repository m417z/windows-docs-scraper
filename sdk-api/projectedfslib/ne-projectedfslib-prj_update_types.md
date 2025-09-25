# PRJ_UPDATE_TYPES enumeration

## Description

Flags to specify whether updates will be allowed given the state of a file or directory on disk.

## Constants

### `PRJ_UPDATE_NONE:0x00000000`

Allow update only if the item is a placeholder (whether hydrated or not).

### `PRJ_UPDATE_ALLOW_DIRTY_METADATA:0x00000001`

Allow update if the item is a placeholder or a dirty placeholder.

### `PRJ_UPDATE_ALLOW_DIRTY_DATA:0x00000002`

Allow update if the item is a placeholder or if it is a full file.

### `PRJ_UPDATE_ALLOW_TOMBSTONE:0x00000004`

Allow update if the item is a placeholder or if it is a tombstone.

### `PRJ_UPDATE_RESERVED1:0x00000008`

Reserved for future use.

### `PRJ_UPDATE_RESERVED2:0x00000010`

Reserved for future use.

### `PRJ_UPDATE_ALLOW_READ_ONLY:0x00000020`

Allow update regardless of whether the DOS read-only bit is set on the item.

### `PRJ_UPDATE_MAX_VAL`

Maximum value.