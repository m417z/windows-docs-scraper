# HANDLE_SHARING_OPTIONS enumeration

## Description

Defines the requested sharing mode of the file handle.

## Constants

### `HSO_SHARE_NONE:0`

Prevents other processes from opening a file if they request delete, read, or write access.

### `HSO_SHARE_READ:0x1`

Enables subsequent open operations on a file to request read access.
Otherwise, other processes cannot open the file if they request read access.

### `HSO_SHARE_WRITE:0x2`

Enables subsequent open operations on a file to request write access.
Otherwise, other processes cannot open the file if they request write access.

### `HSO_SHARE_DELETE:0x4`

Enables subsequent open operations on a file to request delete access.
Otherwise, other processes cannot open the file if they request delete access.