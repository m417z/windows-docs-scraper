# IddCxCheckOsFeatureSupport function

## Description

**IddCxCheckOsFeatureSupport** checks which specific features are supported from each 1.11 and later IddCx version.

## Parameters

### `pOutArgs` [out]

Pointer to an [**IDARG_OUT_FEATURES_SUPPORTED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_features_supported) structure that contains the output arguments of the function.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds, otherwise an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

Once a driver has confirmed it's running on an OS that supports IddCx 1.11 or later by checking the value returned by [**IddCxGetVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxgetversion), it must call **IddCxCheckOsFeatureSupport** to check which specific features are supported from each 1.11 and later IddCx version. The flags in **[IDARG_OUT_FEATURES_SUPPORTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_features_supported)::Features_1_11** tell the driver which of the IddCx 1.11 features are available.

**IddCxCheckOsFeatureSupport** isn't intended to be a replacement for [**IddCxGetVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxgetversion). Drivers should use both to determine the OS capabilities. As a general rule when new features are added, typically requiring DDI updates, the IddCx version changes and new fields are added to **IDARG_OUT_FEATURES_SUPPORTED** and a call to **IddCxCheckOsFeatureSupport** indicates which features are supported. If OS updates such as bugfixes are made that don't need a DDI update, then only the value returned by **IddCxGetVersion** is updated.

## See also

[**IDARG_OUT_FEATURES_SUPPORTED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_features_supported)

[IddCx versions](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-versions)