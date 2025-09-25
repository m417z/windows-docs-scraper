## Description

KMD's **DxgkDdiQueryFeatureInterface** function is called to query its interface for a feature.

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. KMD previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of its [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pArgs`

[in/out] Pointer to a [**DXGKARG_QUERYFEATUREINTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_queryfeatureinterface) structure in which input and output information about the feature's interface is stored.

## Return value

**DxgkDdiQueryFeatureInterface** returns STATUS_SUCCESS upon successful completion. Otherwise, it returns an appropriate NTSTATUS code.

## Remarks

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**DXGKARG_QUERYFEATUREINTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_queryfeatureinterface)

[**DXGKDDI_FEATURE_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkddi_feature_interface)