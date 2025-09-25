## Description

The **DXGK_INTERRUPT_TABLE_ENTRY** structure contains data to write to an MSI-X table entry.

## Members

### `MessageAddress`

System-specified message address (per PCI Local Bus Specification, section 6.8).

### `MessageData`

System-specified message (per PCI Local Bus Specification, section 6.8).

### `VectorControl`

Vector control field (per PCI Local Bus Specification, section 6.8).

## Remarks

For more information, see [Live migration on GPU-P devices](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**DXGKARG_GPUP_WRITE_VIRTUALIZED_MSIX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_gpup_write_virtualized_msix)

[**DxgkDdiWriteVirtualizedInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_writevirtualizedinterrupt)