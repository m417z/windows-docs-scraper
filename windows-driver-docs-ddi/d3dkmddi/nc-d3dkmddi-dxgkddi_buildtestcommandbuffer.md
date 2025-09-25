## Description

KMD's **DXGKDDI_BUILDTESTCOMMANDBUFFER** function builds a test command buffer for [kernel-mode testing](https://learn.microsoft.com/windows-hardware/drivers/display/kernel-mode-testing-of-wddm-features).

## Parameters

### `hAdapter`

[in] A handle to a context block that is associated with a display adapter. The kernel-mode display miniport driver (KMD) previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pArgs`

[in/out] Pointer to a [**DXGKARG_BUILDTESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_buildtestcommandbuffer) structure that describes the test command buffer to build.

## Return value

**DXGKDDI_BUILDTESTCOMMANDBUFFER** returns NTSTATUS_SUCCESS if the function succeeds. Otherwise, it returns an appropriate NTSTATUS code such as STATUS_BUFFER_OVERFLOW.

## Remarks

**DXGKDDI_BUILDTESTCOMMANDBUFFER** builds a command buffer with device-specific instructions for a set of simple commands. KMD returns a pointer to this function in **pfnBuildTestCommandBuffer** via [**DxgkDdiQueryFeatureInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryfeatureinterface)(DXGK_FEATURE_KERNEL_MODE_TESTING).

When **pDmaBuffer** is NULL or is too small, KMD needs to set the required size for the buffer in **DmaBufferSize** and return STATUS_BUFFER_OVERFLOW.

When **pDmaBufferPrivateData** is NULL or too small and KMD needs to generate private data, KMD needs to set the required size in **DmaBufferPrivateDataSize** and return STATUS_BUFFER_OVERFLOW.

The KMD must calculate the size of both buffers in the same call.

For more information, see [Kernel-mode testing](https://learn.microsoft.com/windows-hardware/drivers/display/kernel-mode-testing-of-wddm-features).

## See also

[**DXGKARG_BUILDTESTCOMMANDBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_buildtestcommandbuffer)

[**DxgkDdiQueryFeatureInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryfeatureinterface)