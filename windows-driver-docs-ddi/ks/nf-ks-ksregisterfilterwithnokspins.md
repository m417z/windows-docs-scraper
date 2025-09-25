# KsRegisterFilterWithNoKSPins function

## Description

The **KsRegisterFilterWithNoKSPins** function registers with DirectShow filters that have no kernel streaming pins and, therefore, do not stream in kernel mode.

## Parameters

### `DeviceObject` [in]

A pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure corresponding to the device to which to register the filter.

### `InterfaceClassGUID` [in]

A pointer to the GUID representing the class to register. For instance, this would point to KSCATEGORY_TVTUNER for a TvTuner filter.

### `PinCount` [in]

The count of the number of pins on the filter.

### `PinDirection` [in]

A pointer to the first element of an array of Boolean values indicating pin direction for each pin on the filter. Output pins are **TRUE**; input pins are **FALSE**. This array must be *PinCount* in length.

### `MediumList` [in]

A pointer to the first element of an array of [KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure) structures defining the mediums for each pin on the filter. This array must be *PinCount* in length.

### `CategoryList` [in, optional]

A pointer to the first element of an array of GUIDs defining the categories for each pin on the filter. If this parameter is present, it must be *PinCount* in length.

## Return value

Returns success or failure of creating the FilterData key in the registry.

## Remarks

Use **KsRegisterFilterWithNoKSPins** to register TvTuners, Crossbars, and similar components. **KsRegisterFilterWithNoKSPins** creates a new registry key, **FilterData**, that contains the mediums, and optionally the categories, for each pin on the filter.

This function is only used to register filters that have no corresponding kernel pins. If successful, **KsRegisterFilterWithNoKSPins** creates a key in the registry that can be then used by DirectShow.

If writing a BDA minidriver, consider using [KsFilterFactoryUpdateCacheData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactoryupdatecachedata) instead of this routine. See details on the reference page for **KsFilterFactoryUpdateCacheData**.

For more information, see [AVStream Descriptors](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-descriptors) and [Initializing an AVStream Minidriver](https://learn.microsoft.com/windows-hardware/drivers/stream/initializing-an-avstream-minidriver).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[KsFilterFactoryUpdateCacheData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactoryupdatecachedata)

[KsFilterRegisterPowerCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterregisterpowercallbacks)