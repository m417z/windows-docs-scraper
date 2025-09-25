# MBB_DEVICE_WAKE_CAPABILITIES_INIT function

## Description

The **MBB_DEVICE_WAKE_CAPABILITIES_INIT** method initializes a [**MBB_DEVICE_WAKE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/ns-mbbcx-_mbb_device_wake_capabilities) structure.

## Parameters

### `Capabilities`

A pointer to a driver-allocated [**MBB_DEVICE_WAKE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/ns-mbbcx-_mbb_device_wake_capabilities) structure.

## Remarks

This methods zeroes out the memory of the **MBB_DEVICE_WAKE_CAPABILITIES** structure, then fills in the **Size** member. After calling this method, set the remaining members of the **MBB_DEVICE_WAKE_CAPABILITIES** structure according to your device's capabilities, then call [**MbbDeviceSetWakeCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbdevicesetwakecapabilities).

## See also