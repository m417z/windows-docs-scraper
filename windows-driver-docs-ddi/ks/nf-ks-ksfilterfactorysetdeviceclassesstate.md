# KsFilterFactorySetDeviceClassesState function

## Description

The **KsFilterFactorySetDeviceClassesState** function enables or disables the device classes that have been registered by a given filter factory.

## Parameters

### `FilterFactory` [in]

A pointer to the [KSFILTERFACTORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilterfactory) for which to change device class status.

### `NewState` [in]

If set to **TRUE**, the device classes are enabled; if **FALSE**, they are disabled.

## Return value

**KsFilterFactorySetDeviceClassesState** returns STATUS_SUCCESS or an error code.

## Remarks

This function is available in Windows XP and DirectX 8.0 and later.