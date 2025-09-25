# PRJ_FILE_STATE enumeration

## Description

The state of an item.

## Constants

### `PRJ_FILE_STATE_PLACEHOLDER:0x00000001`

The item is a placeholder.

### `PRJ_FILE_STATE_HYDRATED_PLACEHOLDER:0x00000002`

The item is a hydrated placeholder, i.e., the item's content has been written to disk.

### `PRJ_FILE_STATE_DIRTY_PLACEHOLDER:0x00000004`

The placeholder item's metadata has been modified.

### `PRJ_FILE_STATE_FULL:0x00000008`

The item is full.

### `PRJ_FILE_STATE_TOMBSTONE:0x00000010`

The item is a tombstone.

## Remarks

The PRJ_FILE_STATE_FULL and PRJ_FILE_STATE_TOMBSTONE bits will not appear in combination with each other or any other bit.