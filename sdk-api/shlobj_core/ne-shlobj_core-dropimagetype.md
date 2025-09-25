# DROPIMAGETYPE enumeration

## Description

Values used with the [DROPDESCRIPTION](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-dropdescription) structure to specify the drop image.

## Constants

### `DROPIMAGE_INVALID:-1`

No drop image preference; use the default image.

### `DROPIMAGE_NONE:0`

A red bisected circle such as that found on a "no smoking" sign.

### `DROPIMAGE_COPY`

A plus sign (+) that indicates a copy operation.

### `DROPIMAGE_MOVE`

An arrow that indicates a move operation.

### `DROPIMAGE_LINK`

An arrow that indicates a link.

### `DROPIMAGE_LABEL:6`

A tag icon that indicates that the metadata will be changed.

### `DROPIMAGE_WARNING:7`

A yellow exclamation mark that indicates that a problem has been encountered in the operation.

### `DROPIMAGE_NOIMAGE:8`

**Windows 7 and later**. Use no drop image.