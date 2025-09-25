# DEVICE_INTERNAL_STATUS_DATA structure

## Description

A device returns its internal error history data in a DEVICE_INTERNAL_STATUS_DATA structure during an [IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_internal_log) request.

## Members

### `Version`

Version of this structure. Set to **sizeof**(DEVICE_INTERNAL_STATUS_DATA).

### `Size`

Total size in bytes of this structure. Set to **sizeof**(DEVICE_INTERNAL_STATUS_DATA) plus the device's internal data size specified by **StatusDataLength**.

### `T10VendorId`

The Vendor ID defined by T10 industry association.

### `DataSet1Length`

Specifies the data length for data set 1.

### `DataSet2Length`

Specifies the data length for data set 2.

### `DataSet3Length`

Specifies the data length for data set 3.

### `DataSet4Length`

Specifies the data length for data set 4.

### `StatusDataVersion`

Specifies the data version.

### `Reserved`

Reserved; do not use.

### `ReasonIdentifier`

Specifies the device internal status when the status data is generated.

### `StatusDataLength`

Size, in bytes, of the entire buffer that *StatusData* points to.

### `StatusData`

Pointer to the status data header, which is always 512 bytes in size. The actual data follows the status data header.

## Remarks

DEVICE_INTERNAL_STATUS_DATA is the output buffer for [IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_internal_log). The device will return its error history data in this structure.

See the SCSI specification for more information.

## See also

[IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_device_internal_log)