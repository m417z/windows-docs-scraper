# IWDTFPNPAction2::EDTCancelStopDevice

## Description

Sends an IRP_MN_CANCEL_STOP_DEVICE event to the target device.

## Parameters

### `pbSuccess` [out, retval]

True if the operation succeeds; otherwise, false.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** The [IWDTFEnhancedDeviceTestSupportAction2::Enable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfedtaction/nf-wdtfedtaction-iwdtfenhanceddevicetestsupportaction2-enable)
method must be called for the target device before calling this method.

**EDTCancelStopDevice** attempts to trigger an IRP_MN_CANCEL_STOP_DEVICE
event by causing the system to send an IRP_MN_QUERY_STOP_DEVICE event and by intentionally failing
the query IRP in the DeviceManagement2 helper driver.

It is possible for the filter drivers that are loaded above the helper driver
to fail the query IRP as well. In that case, the helper driver will indicate this condition
by setting EDTRS_QueryStopVetoed in ppResult.

## See also

[IWDTFPNPAction2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfpnpaction/nn-wdtfpnpaction-iwdtfpnpaction2)