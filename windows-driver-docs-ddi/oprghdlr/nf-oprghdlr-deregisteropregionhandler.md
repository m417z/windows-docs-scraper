## Description

The **DeRegisterOpRegionHandler** routine deregisters an operation region handler with the [ACPI driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/acpi-driver).

## Parameters

### `DeviceObject` [in]

Pointer to the physical device object (PDO) that represents the ACPI device that defines the operation region.

### `OperationRegionObject` [in]

Specifies the operation region object returned by [RegisterOpRegionHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/oprghdlr/nf-oprghdlr-registeropregionhandler) for the operation region handler.

## Return value

Returns one of the following status values.

| Return code | Description |
|---|---|
| **STATUS_SUCCESS** | The operating region handler was successfully registered. |
| **STATUS_INSUFFICIENT_RESOURCES** | The routine could not allocate the necessary system resources. |
| **STATUS_Xxx** | An internal error occurred. |

## Remarks

This routine is used in combination with [RegisterOpRegionHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/oprghdlr/nf-oprghdlr-registeropregionhandler). To deregister an operation region handler, the caller must specify the operation region object returned by **RegisterOpRegionHandler** when it registered the operation region handler.

For more information about operation regions, see [Supporting an Operation Region](https://learn.microsoft.com/windows-hardware/drivers/acpi/supporting-an-operation-region).

## See also

[ACPI_OP_REGION_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/oprghdlr/nc-oprghdlr-acpi_op_region_handler)

[RegisterOpRegionHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/oprghdlr/nf-oprghdlr-registeropregionhandler)