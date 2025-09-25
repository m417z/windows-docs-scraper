# IWDTFPNPAction2::EDTTryStopDeviceFailRestart

## Description

Attempts to send an IRP_MN_STOP_DEVICE event to the target device and
then fail the subsequent device restart.

## Parameters

### `pbSuccess` [out, retval]

True if the operation succeeds; otherwise, false.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** The [IWDTFEnhancedDeviceTestSupportAction2::Enable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfedtaction/nf-wdtfedtaction-iwdtfenhanceddevicetestsupportaction2-enable)
method must be called for the target device before calling this method.

**EDTTryStopDeviceFailRestart** attempts to trigger a PnP resource
rebalance (a Query Stop, Stop, Start IRP sequence) in which it fails the IRP_MN_START_DEVICE event
which follows a successful Query Stop and Stop. The failed Start IRP, in turn, causes the system
to surprise remove the device (IRP_MN_SURPRISE_REMOVAL).

The Stop IRP is not guaranteed. Other drivers on the stack can fail an
IRP_MN_QUERY_STOP_DEVICE event which precedes the Stop IRP (resulting in IRP_MN_CANCEL_STOP_DEVICE).
Also, the system may optimize if it detects that the target device does not use hardware
resources (e.g. a USB mouse) and send a CancelStop IRP instead.

If your device does not consume hardware resources but you still wish to attempt to test
how the drivers and applications handle the PnP resource rebalance with a failed start, you can
instead run the **EDTTryStopDeviceFailRestart** method on a parent
device, grandparent, etc., which does consume hardware resources. For example, if your device
is a USB mouse, you can run this method on the parent USB controller instead.

## See also

[IWDTFPNPAction2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtfpnpaction/nn-wdtfpnpaction-iwdtfpnpaction2)