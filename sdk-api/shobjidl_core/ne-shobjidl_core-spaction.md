# SPACTION enumeration

## Description

Describes an action being performed that requires progress to be shown to the user using an [IActionProgress](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iactionprogress) interface.

## Constants

### `SPACTION_NONE:0`

No action is being performed.

### `SPACTION_MOVING`

Files are being moved.

### `SPACTION_COPYING`

Files are being copied.

### `SPACTION_RECYCLING`

Files are being deleted.

### `SPACTION_APPLYINGATTRIBS`

A set of attributes are being applied to files.

### `SPACTION_DOWNLOADING`

A file is being downloaded from a remote source.

### `SPACTION_SEARCHING_INTERNET`

An Internet search is being performed.

### `SPACTION_CALCULATING`

A calculation is being performed.

### `SPACTION_UPLOADING`

A file is being uploaded to a remote source.

### `SPACTION_SEARCHING_FILES`

A local search is being performed.

### `SPACTION_DELETING`

**Windows Vista and later**. A deletion is being performed.

### `SPACTION_RENAMING`

**Windows Vista and later**. A renaming action is being performed.

### `SPACTION_FORMATTING`

**Windows Vista and later**. A formatting action is being performed.

### `SPACTION_COPY_MOVING`

**Windows 7 and later**. A copy or move action is being performed.

## See also

[IActionProgress](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iactionprogress)