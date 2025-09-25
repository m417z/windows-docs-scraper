## Description

To interface with the Replay Protected Memory Block (RPMB), applications first need to query whether the device contains an RPMB and the max payload size the RPMB supports. To do this, the application sends [IOCTL_STORAGE_QUERY_PROPERTY IOCTL](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_query_property) with [STORAGE_PROPERTY_ID enumeration](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-storage_property_id) set to StorageAdapterRpmbProperty (defined in STORAGE_PROPERTY_QUERY in ntddstor.h). Storport then responds with the following payload (defined in ntddstor.h) when [STORAGE_QUERY_TYPE enumeration](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-storage_query_type) is set to PropertyStandardQuery.

## Members

### `Version`

Shall be set to STORAGE_RPMB_DESCRIPTOR_VERSION_1

### `Size`

Shall be set to sizeof(STORAGE_RPMB_DESCRIPTOR)

### `SizeInBytes`

The size of the RPMB, in bytes. 0 if not supported, RPMB size in bytes otherwise.

### `MaxReliableWriteSizeInBytes`

The maximum amount of data supported in one transaction in bytes. 0 if not supported, minimum 512 bytes.

### `FrameFormat`

To support different RPMB frame formats, specifies which frame format the payload will be in so the port driver can take the appropriate action.

## Remarks

## See also