## Description

KMD can call the display port driver's **DxgkIsFeatureEnabled2** function before *Dxgkrnl* is enabled to determine whether a particular feature is enabled.

## Parameters

### `DriverObject`

[in] Pointer to a [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object). The display miniport driver previously obtained this pointer in its [**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-display-miniport-driver) function.

### `pArgs`

[in] Pointer to a [**DXGKARGCB_ISFEATUREENABLED2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_isfeatureenabled2) structure that contains information about the feature to query.

## Return value

**DxgkIsFeatureEnabled2** returns STATUS_SUCCESS upon success completion. Otherwise, it returns an appropriate NTSTATUS code.

## Remarks

**DxgkIsFeatureEnabled2** is defined in the display port driver's library (*displib.lib*). As a result, KMD can call this function to check for the presence of an enabled feature before *Dxgkrnl* is initialized. Because **DxgkIsFeatureEnabled2** is intended to be used at [**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-display-miniport-driver), only a subset of global features can be queried through it. This subset currently includes:

* DXGK_FEATURE_GPUVAIOMMU

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-display-miniport-driver)

[**DXGKARGCB_ISFEATUREENABLED2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_isfeatureenabled2)