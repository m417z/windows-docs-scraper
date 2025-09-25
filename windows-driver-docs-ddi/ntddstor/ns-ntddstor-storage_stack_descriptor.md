## Description

The **STORAGE_STACK_DESCRIPTOR** structure describes the storage stack for the device.

## Members

### `Version`

The size of this structure serves as the version. This is set to `sizeof(STORAGE_STACK_DESCRIPTOR)`.

### `Size`

Size of buffer. The returned value indicates how big the buffer should be to store complete data.

### `StorageStackType`

Type of storage stack for the device, such as SCSI, NVMe, and so on.

## Remarks

## See also