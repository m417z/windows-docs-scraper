# _STORAGE_HW_FIRMWARE_INFO_QUERY structure

## Description

This structure contains information about the device firmware.

## Members

### `Version`

The version of this structure. This should be set to sizeof(STORAGE_HW_FIRMWARE_INFO_QUERY)

### `Size`

The size of this structure as a buffer.

### `Flags`

The flags associated with the query. The following are flags that can be set in this member.

| Flag | Description |
| --- | --- |
| STORAGE_HW_FIRMWARE_REQUEST_FLAG_CONTROLLER | Indicates that the target of the request is different than the device handle or object itself. |

### `Reserved`

Reserved for future use.