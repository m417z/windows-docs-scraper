# IWDTFPNPAction2::EDTSurpriseRemoveDevice

## Description

Sends an IRP_MN_SURPRISE_REMOVAL event to the target device.

## Parameters

### `pbSuccess` [out, retval]

True if the operation succeeds; otherwise, false.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** The [IWDTFEnhancedDeviceTestSupportAction2::Enable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfedtaction/nf-wdtfedtaction-iwdtfenhanceddevicetestsupportaction2-enable)
method must be called for the target device before calling this method.

**EDTSurpriseRemoveDevice** attempts to trigger a surprise removal of the target device.
This operation is useful for testing
how drivers and driver/device aware applications handle the IRP_MN_SURPRISE_REMOVAL event, e.g. scenarios in which
the device unexpectedly fails or is removed.

## See also

[IWDTFPNPAction2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfpnpaction/nn-wdtfpnpaction-iwdtfpnpaction2)