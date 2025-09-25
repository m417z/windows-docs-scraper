# IWDTFPNPActions2::EDTTryStopDeviceRequestNewResources

## Description

Attempts to send an IRP_MN_STOP_DEVICE event to the target device and
assign new resources to the target device.

## Parameters

### `pbSuccess` [out, retval]

True if the operation succeeds; otherwise, false.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** The [IWDTFEnhancedDeviceTestSupportAction2::Enable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfedtaction/nf-wdtfedtaction-iwdtfenhanceddevicetestsupportaction2-enable)
method must be called for the target device before calling this method.

Similar to the [EDTTryStopDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfpnpaction/nf-wdtfpnpaction-iwdtfpnpaction2-edttrystopdevice) method,
**EDTTryStopDeviceRequestNewResources** attempts to trigger a PnP resource
rebalance (e.g. IRP_MN_STOP_DEVICE) on the target device stack, with the addition that the method
attempts to force the device onto a new set of hardware resources.

The Stop IRP is not guaranteed. Other drivers on the stack can fail the IRP_MN_QUERY_STOP_DEVICE event
which precedes the Stop IRP (resulting in IRP_MN_CANCEL_STOP_DEVICE). Also, the system may
optimize if it detects that the target device does not use hardware resources (e.g. a USB mouse)
and send a CancelStop IRP instead.

If your device does not consume hardware resources but you still wish to attempt to test
how the drivers and applications handle the PnP resource rebalance, you can instead run
**EDTTryStopDeviceRequestNewResources** on a parent device, grandparent,
etc., which does consume hardware resources. For example, if your device is a USB mouse, you can
run this method on the parent USB controller instead.