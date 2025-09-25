## Description

A kernel-mode display miniport driver (KMD) calls **DXGKCB_QUERYFEATURESUPPORT** to query whether the OS will permit it to enable support for a feature. Starting in Windows 11, version 24H2 (WDDM 3.2), this port driver callback function has been replaced by [**DXGK_FEATURE_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkddi_feature_interface).

## Parameters

### `unnamedParam1`

Pointer to a [**DXGKARGCB_QUERYFEATURESUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_queryfeaturesupport) structure that contains information about the feature being queried.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate NTSTATUS code.

## Remarks

The OS sets the **Enabled** member of [**DXGKARGCB_QUERYFEATURESUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_queryfeaturesupport) to TRUE when it permits the driver to enable support for the queried feature. **Enabled** is set to FALSE to instruct the driver to not enable its support for the feature.

The OS's determination of whether to enable a feature is based on a number of factors.

Pre-WDDM 2.9 drivers can call [**DXGKCB_ISFEATUREENABLED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_isfeatureenabled) instead.

## See also

[**DXGKARGCB_QUERYFEATURESUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_queryfeaturesupport)