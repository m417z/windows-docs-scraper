# DXGKCB_ISFEATUREENABLED callback function

## Description

A kernel-mode display miniport driver (KMD) calls **DxgkCbIsFeatureEnabled** to query whether the OS has enabled a feature. Starting in Windows 11, version 24H2 (WDDM 3.2), this port driver callback function has been replaced by [**DXGK_FEATURE_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkddi_feature_interface).

## Parameters

### `unnamedParam1` [in/out]

Pointer to a [**DXGKARGCB_ISFEATUREENABLED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_isfeatureenabled) structure that contains information about the feature being queried.

## Return value

**DxgkCbIsFeatureEnabled** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it returns an appropriate NTSTATUS code.

## Remarks

Starting in WDDM 2.9, drivers can call [**DXGKCB_QUERYFEATURESUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_queryfeaturesupport) to provide additional information to the OS.

The OS sets the **Enabled** member of [**DXGKARGCB_ISFEATUREENABLED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_isfeatureenabled) to TRUE when it allows the driver to enable support for the queried feature. **Enabled** is set to FALSE to instruct the driver to not enable its support for the feature.

**DXGKCB_*XXX*** functions are implemented by *Dxgkrnl*. To use this callback function, set the appropriate members of [**DXGKARGCB_ISFEATUREENABLED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_isfeatureenabled) and then call **DxgkCbIsFeatureEnabled** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_ISFEATUREENABLED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_isfeatureenabled)

[**DXGKCB_QUERYFEATURESUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_queryfeaturesupport)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)