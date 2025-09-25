## Description

KMD's **DxgkDdiQueryFeatureSupport** function is called to query its support for a feature.

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. KMD previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of its [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pArgs`

[in/out] Pointer to a [**DXGKARG_QUERYFEATURESUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_queryfeaturesupport) structure in which input and output feature support information is stored.

## Return value

**DxgkDdiQueryFeatureSupport** returns STATUS_SUCCESS upon successful completion. Otherwise, it returns an appropriate NTSTATUS code.

## Remarks

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**DXGKARG_QUERYFEATURESUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_queryfeaturesupport)

[**DXGKDDI_FEATURE_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkddi_feature_interface)