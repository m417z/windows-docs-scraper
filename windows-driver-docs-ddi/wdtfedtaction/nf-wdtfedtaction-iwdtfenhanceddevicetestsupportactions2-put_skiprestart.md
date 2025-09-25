# IWDTFEnhancedDeviceTestSupportActions2::put_SkipRestart method

## Description

Sets a value that indicates whether the target device should be restarted by default.

This property is write-only.

## Parameters

### `bSkipRestart`

A BOOL value indicating if the device should be restarted.

## Return value

## Syntax

```cpp
HRESULT put_SkipRestart(
  [in] VARIANT_BOOL bSkipRestart
);
```

## Remarks

The [Enable](https://learn.microsoft.com/windows-hardware/drivers/ddi/) and
[Disable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfedtaction/nf-wdtfedtaction-iwdtfenhanceddevicetestsupportaction2-disable) methods
attempt to restart the target device by default. Use this method to skip that step.

## See also

[IWDTFEnhancedDeviceTestSupportAction2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfedtaction/nn-wdtfedtaction-iwdtfenhanceddevicetestsupportaction2)