## Description

The **RegisterOpRegionHandler** routine registers an operation region handler with the [ACPI driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/acpi-driver).

## Parameters

### `DeviceObject` [in]

Pointer to the [physical device object (PDO)](https://learn.microsoft.com/windows-hardware/drivers/kernel/types-of-wdm-device-objects) that represents the ACPI device that defines the operation region.

### `AccessType` [in]

Specifies ACPI_OPREGION_ACCESS_AS_COOKED.

### `RegionSpace` [in]

Specifies one of the following types of region space.

| Region space identifier | Description |
|---|---|
| ACPI_OPREGION_REGION_SPACE_MEMORY | System memory |
| ACPI_OPREGION_REGION_SPACE_IO | I/O space |
| ACPI_OPREGION_REGION_SPACE_PCI_CONFIG | PCI configuration |
| ACPI_OPREGION_REGION_SPACE_EC | Embedded controller |
| ACPI_OPREGION_REGION_SPACE_SMB | System management bus |
| ACPI_OPREGION_REGION_SPACE_CMOS_CONFIG | CMOS configuration |
| ACPI_OPREGION_REGION_SPACE_PCIBARTARGET | PCI base address register |
| Vendor-defined value from 0x80 to 0xFF | Vendor-defined |

### `Handler` [in]

Pointer to the [ACPI_OP_REGION_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/oprghdlr/nc-oprghdlr-acpi_op_region_handler)-typed operation region handler (supplied by an ACPI device function driver).

### `Context` [in]

Pointer to a device-specific operation region context (supplied by an ACPI device function driver).

### `Flags` [in]

Reserved for internal use.

### `OperationRegionObject` [out]

Pointer to caller-allocated buffer that, on output, contains a pointer to the operation region object that the ACPI driver creates for the operation region.

## Return value

Returns one of the following status values:

| Return code | Description |
|---|---|
| STATUS_SUCCESS | The operating region handler was successfully registered. |
| STATUS_ACPI_INVALID_DATA | The specified information is not valid. |
| STATUS_INSUFFICIENT_RESOURCES | The routine could not allocate the necessary system resources. |
| STATUS_Xxx | An internal error occurred. |

## Remarks

The operation region context specified by *Context* is device-specific and is only used by the function driver. Typically, the context is the device extension for the [functional device object (FDO)](https://learn.microsoft.com/windows-hardware/drivers/kernel/types-of-wdm-device-objects). The ACPI driver passes this context back to the function driver when it calls the operation region handler. The operation region object is only used by a function driver to uniquely identify the operation region when it deregisters the operation region handler.

For more information about operation regions, see [Supporting an Operation Region](https://learn.microsoft.com/windows-hardware/drivers/acpi/supporting-an-operation-region).

## See also

[ACPI_OP_REGION_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/oprghdlr/nc-oprghdlr-acpi_op_region_handler)

[DeRegisterOpRegionHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/oprghdlr/nf-oprghdlr-deregisteropregionhandler)