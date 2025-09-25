## Description

The **DXGKARG_GPUP_WRITE_VIRTUALIZED_MSIX** structure is a parameter for the [**DxgkDdiWriteVirtualizedInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_writevirtualizedinterrupt) function that writes to the MSI-X interrupt table during the process of live migration of a virtualized GPU device.

## Members

### `vfIndex`

[in] Identifies the virtual function / vDEV being referenced. This index value localizes to the specific virtual device.

### `InterruptTableIndex`

[in] Index of the MSI-X table entry to write to.

### `WriteValue`

[in] A [**DXGK_INTERRUPT_TABLE_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_interrupt_table_entry) structure that contains the data to write to the MSI-X table entry.

## Remarks

For more information, see [Live migration on GPU-P devices](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**DXGK_INTERRUPT_TABLE_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_interrupt_table_entry)

[**DxgkDdiWriteVirtualizedInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_writevirtualizedinterrupt)