## Description

**DxgkDdiWriteVirtualizedInterrupt** services writes to the MSI-X interrupt table during the process of live migration of a virtualized GPU device.

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. The display miniport driver previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DXGKDDI_ADD_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pArgs`

[in] Pointer to a [**DXGKARG_GPUP_WRITE_VIRTUALIZED_MSIX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_gpup_write_virtualized_msix) structure that contains information needed to write to the MSI-X table.

## Return value

**DxgkDdiWriteVirtualizedInterrupt** returns STATUS_SUCCESS upon successful completion of the write operation; otherwise it returns an appropriate NTSTATUS code.

## Remarks

KMD's **DxgkDdiWriteVirtualizedInterrupt** is used in the context of virtualizing GPU devices, specifically for handling interrupts. The MSI-X (Message Signaled Interrupts eXtended) table is a data structure used in the PCI (Peripheral Component Interconnect) system of a computer, which allows for device-specific handling of interrupts.

**DxgkDdiWriteVirtualizedInterrupt** should write the values specified in [**WriteValue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_interrupt_table_entry) to the MSI-X table.

For more information, see [Live migration on GPU-P devices](https://learn.microsoft.com/windows-hardware/drivers/display/live-migration-on-gpup-devices).

## See also

[**DXGKARG_GPUP_WRITE_VIRTUALIZED_MSIX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_gpup_write_virtualized_msix)

[**DXGK_INTERRUPT_TABLE_ENTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_interrupt_table_entry)