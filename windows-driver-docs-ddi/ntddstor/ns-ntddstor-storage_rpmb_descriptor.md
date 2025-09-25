## Description

The **STORAGE_RPMB_DESCRIPTOR** structure contains information about a device's Replay Protected Memory Block (RPMB) support.

## Members

### `Version`

Version of this structure. Set to STORAGE_RPMB_DESCRIPTOR_VERSION_1.

### `Size`

Size of this structure, in bytes. Set to ```sizeof(STORAGE_RPMB_DESCRIPTOR)```.

### `SizeInBytes`

Size of the RPMB, in bytes. **SizeInBytes** cannot be zero.

### `MaxReliableWriteSizeInBytes`

Maximum amount of data supported in one transaction, in bytes. **MaxReliableWriteSizeInBytes** cannot be zero.

### `FrameFormat`

A [**STORAGE_RPMB_FRAME_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_rpmb_data_frame) structure identifying the frame format that the payload will be in.

## Remarks

An application will issue [**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property) with the [**STORAGE_PROPERTY_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id) enumeration set to **StorageAdapterRpmbProperty** to determine whether the device contains an RPMB, and the maximum payload size the RPMB supports.

Storport responds with the payload information in this structure when the [**STORAGE_QUERY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_query_type) enumeration is set to **PropertyStandardQuery**.

## See also

[**IOCTL_STORAGE_QUERY_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_query_property)

[**STORAGE_PROPERTY_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_property_id)

[**STORAGE_QUERY_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_query_type)

[**STORAGE_RPMB_FRAME_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_rpmb_data_frame)