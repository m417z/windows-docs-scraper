# HANDLE_ACCESS_OPTIONS enumeration

## Description

Defines the level of access that a handle has on files.

## Constants

### `HAO_NONE:0`

None.

### `HAO_READ_ATTRIBUTES:0x80`

The handle can be used to read file attributes.

### `HAO_READ:0x120089`

The handle can be used to read the file.

### `HAO_WRITE:0x120116`

The handle can be used to write to the file.

### `HAO_DELETE:0x10000`

The handle can be used to delete the file.