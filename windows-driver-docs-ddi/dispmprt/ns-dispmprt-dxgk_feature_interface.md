## Description

The **DXGK_FEATURE_INTERFACE** structure contains the port driver's interface that can be used to query it for its enabled features and their support.

## Members

### `Size`

Size of this structure, in bytes.

### `Version`

The version number of the feature interface. Version number constants are defined in *Dispmprt.h* (for example, DXGK_FEATURE_INTERFACE_VERSION_1).

### `Context`

Pointer to a private context block.

### `InterfaceReference`

Pointer to the port driver's interface reference function.

### `InterfaceDereference`

Pointer to the port driver's interface dereference function.

### `IsFeatureEnabled`

The port driver's [**DXGKCB_ISFEATUREENABLED2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_isfeatureenabled2) function. KMD can call this function to query whether the system has enabled a feature.

### `QueryFeatureInterface`

The port driver's [**DXGKCB_QUERYFEATUREINTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_queryfeatureinterface) function. KMD can call this function to query the OS for a feature's interface.

## Remarks

To get this interface, KMD calls *Dxgkrnl*'s [**DxgkCbQueryServices**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_query_services) callback with [**ServiceType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_services) set to **DxgkServicesFeature**. KMD can call **DxgkCbQueryServices** once it obtains the callback's pointer from a call to its [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**DXGK_SERVICES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-dxgk_services)

[**DXGKCB_ISFEATUREENABLED2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_isfeatureenabled2)

[**DXGKCB_QUERYFEATUREINTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_queryfeatureinterface)

[**DxgkCbQueryServices**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_query_services)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)