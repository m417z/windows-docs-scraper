# _STORAGE_DEVICE_ATTRIBUTES_DESCRIPTOR structure

## Description

The STORAGE_DEVICE_ATTRIBUTES_DESCRIPTOR structure is used to retrieve the attributes information for a device.

## Members

### `Version`

Contains the version of the data reported.

### `Size`

Indicates the quantity of data reported, in bytes. This is the `sizeof(STORAGE_DEVICE_ATTRIBUTES_DESCRIPTOR)`.

### `Attributes`

| Value | Meaning |
| --- | --- |
| **STORAGE_ATTRIBUTE_BYTE_ADDRESSABLE_IO**<br><br>0x01 | Attribute that indicates a storage device supports byte addressable IO. |
| **STORAGE_ATTRIBUTE_BLOCK_IO**<br><br>0x02 | Attribute that indicates a storage device supports block IO. |
| **STORAGE_ATTRIBUTE_DYNAMIC_PERSISTENCE**<br><br>0x04 | Attribute that indicates that persistence of data on storage device may change. |
| **STORAGE_ATTRIBUTE_VOLATILE**<br><br>0x08 | Attribute that indicates a storage device is volatile and does not support persistence of data. |
| **STORAGE_ATTRIBUTE_ASYNC_EVENT_NOTIFICATION**<br><br>0x10 | Reserved |
| **STORAGE_ATTRIBUTE_PERF_SIZE_INDEPENDENT**<br><br>0x20 | Attribute that indicates a storage device has IO performance independent of IO sizes. |