# DXGKDDI_ENDEXCLUSIVEACCESS callback function

## Description

*Dxgkrnl* calls **DxgkDdiEndExclusiveAccess** to notify the kernel-mode driver that an IOMMU domain switch just completed.

## Parameters

### `hAdapter`

[in] A handle to a context block that is associated with a display adapter.

### `pEndExclusiveAccess`

[in] Pointer to a [**DXGKARG_ENDEXCLUSIVEACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_endexclusiveaccess) structure that contains the input arguments for **DxgkDdiEndExclusiveAccess**.

## Return value

**DxgkDdiEndExclusiveAccess** should return STATUS_SUCCESS if the operation succeeds. Otherwise, it should return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

*Dxgkrnl* calls **DxgkDdiBeginExclusiveAccess** and **DxgkDdiEndExclusiveAccess** as a pair when an IOMMU domain switch needs to occur. See [**DxgkDdiBeginExclusiveAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_beginexclusiveaccess) for implementation details.

## See also

[**DRIVER_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_driver_initialization_data)

[**DXGKARG_ENDEXCLUSIVEACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_endexclusiveaccess)

[**DxgkDdiBeginExclusiveAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_beginexclusiveaccess)