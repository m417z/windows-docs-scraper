# RxMakeLateDeviceAvailable function

## Description

**RxMakeLateDeviceAvailable** modifies the device object to make a "late device" available. A late device is one that is not created in the driver's load routine.

## Parameters

### `RxDeviceObject` [in]

A pointer to the where the created device object is to be stored.

## Remarks

**RxMakeLateDeviceAvailable** clears the DO_DEVICE_INITIALIZING bit in the **Flags** member of the device object.