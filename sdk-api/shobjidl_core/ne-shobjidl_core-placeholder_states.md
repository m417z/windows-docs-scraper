# PLACEHOLDER_STATES enumeration

## Description

Specifies the states that a placeholder file can have. Retrieve this value through the System.FilePlaceholderStatus (PKEY_FilePlaceholderStatus) property.

## Constants

### `PS_NONE:0`

None of the other states apply at this time.

### `PS_MARKED_FOR_OFFLINE_AVAILABILITY:0x1`

May already be or eventually will be available offline.

### `PS_FULL_PRIMARY_STREAM_AVAILABLE:0x2`

The primary stream has been made fully available.

### `PS_CREATE_FILE_ACCESSIBLE:0x4`

The file is accessible through a call to the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function, without requesting the opening of reparse points.

### `PS_CLOUDFILE_PLACEHOLDER:0x8`

### `PS_DEFAULT`

### `PS_ALL`

A bitmask value for all valid PLACEHOLDER_STATES flags.