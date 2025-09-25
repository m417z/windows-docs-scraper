# IWDTFPNPActions2::EDTCancelRemoveDevice

## Description

Sends an IRP_MN_CANCEL_REMOVE_DEVICE event to the target device.

## Parameters

### `pbSuccess` [out, retval]

True if the operation succeeds; otherwise, false.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** The [IWDTFEnhancedDeviceTestSupportAction2::Enable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfedtaction/nf-wdtfedtaction-iwdtfenhanceddevicetestsupportaction2-enable)
method must be called for the target device before calling this method.

**EDTCancelRemoveDevice** triggers an IRP_MN_CANCEL_REMOVE event
by intentionally failing an IRP_MN_QUERY_REMOVE_DEVICE event.