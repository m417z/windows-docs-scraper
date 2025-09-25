## Description

The WHEA_FIRMWARE_ERROR_RECORD_REFERENCE structure describes a reference to a firmware error record that is specific to the Itanium processor architecture.

## Members

### `Type`

The type of firmware error record. This member is always set to WHEA_FIRMWARE_RECORD_TYPE_IPFSAL.

### `Reserved`

Reserved for system use.

### `FirmwareRecordId`

The identifier of the firmware error record.

## Remarks

The WHEA_FIRMWARE_ERROR_RECORD_REFERENCE structure describes the data that is contained in an Itanium processor firmware error record reference section of an [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records). An error record contains an Itanium processor firmware error record reference section only if the **SectionType** member of one of the [WHEA_ERROR_RECORD_SECTION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structures that describe the error record sections for that error record contains FIRMWARE_ERROR_RECORD_REFERENCE_GUID.

The WHEA_FIRMWARE_ERROR_RECORD_REFERENCE structure contains a reference to a SAL error record that was created by the system firmware. For more information about the format of a SAL error record, see the [Intel Itanium Processor Family System Abstraction Layer Specification](https://www.intel.com/content/dam/www/public/us/en/documents/specification-updates/itanium-system-abstraction-layer-specification.pdf).

## See also

[WHEA_ERROR_RECORD_SECTION_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor)