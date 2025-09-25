# WHEA_ERROR_SOURCE_CONFIGURATION_DEVICE_DRIVER structure

## Description

## Members

### `Version`

A ULONG specifying the version of this structure to use. Starting in Windows 10, version 2004, set to `WHEA_DEVICE_DRIVER_CONFIG_V2`.

### `SourceGuid`

A GUID corresponding to the driver generating the errors.

### `LogTag`

Used by device drivers that also create [SEL (System Event Log)](https://learn.microsoft.com/windows-hardware/drivers/whea/querying-the-system-event-log-for-hardware-error-events) data to help identify the source of the SEL log.

### `Reserved`

Reserved for system use.

### `Initialize`

A pointer to the driver's [*WHEA_ERROR_SOURCE_INITIALIZE_DEVICE_DRIVER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-_whea_error_source_initialize_device_driver) event callback function.

### `Uninitialize`

A pointer to the driver's [*WHEA_ERROR_SOURCE_UNINITIALIZE_DEVICE_DRIVER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-_whea_error_source_uninitialize_device_driver) event callback function.

### `MaxSectionDataLength`

Specifies the maximum size, in bytes, for a single section in a reported error.

### `MaxSectionsPerReport`

A ULONG that specifies the maximum number of sections per report.

### `CreatorId`

A GUID identifying the creator, i.e. the organization, that is generating the error.

### `PartitionId`

A GUID that is used in the [Common Platform Error Record (CPER)](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records). Can be zero.

## Remarks

The WHEA_ERROR_SOURCE_CONFIGURATION_DEVICE_DRIVER structure is used as input to the [**WheaAddErrorSourceDeviceDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-wheaadderrorsourcedevicedriver) function.

For more info, see [Using WHEA on Windows 10](https://learn.microsoft.com/windows-hardware/drivers/whea/using-whea-on-windows-10).

## See also