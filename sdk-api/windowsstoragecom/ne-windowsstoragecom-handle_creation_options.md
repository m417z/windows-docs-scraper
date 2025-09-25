# HANDLE_CREATION_OPTIONS enumeration

## Description

Represents the action to take depending on whether the file already exists.

## Constants

### `HCO_CREATE_NEW:0x1`

Create a new file. The operation fails if the file already exists.

### `HCO_CREATE_ALWAYS:0x2`

Create a new file. If the file already exists, then it is truncated so that its size is zero bytes.

### `HCO_OPEN_EXISTING:0x3`

Open a file only if it exists. The operation fails if the file does not exist.

### `HCO_OPEN_ALWAYS:0x4`

Open a file, creating it if it does not already exist.

### `HCO_TRUNCATE_EXISTING:0x5`

Open a file and truncates it so that its size is zero bytes. The operation fails if the file does not exist.