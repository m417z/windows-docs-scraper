## Description

**DXGKCB_QUERYFEATUREINTERFACE** is a port driver-implemented callback function that is used to query for a feature interface.

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. KMD previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of its [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pArgs`

[in/out] Pointer to a [**DXGKARGCB_QUERYFEATUREINTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_queryfeatureinterface) structure in which input and output information about the port driver's feature's interface is stored.

## Return value

**DXGKCB_QUERYFEATUREINTERFACE** returns STATUS_SUCCESS upon successful completion. Otherwise, it returns an appropriate NTSTATUS code.

## Remarks

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**DXGK_FEATURE_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_feature_interface)

[**DXGKARGCB_QUERYFEATUREINTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_queryfeatureinterface)