## Description

The **KsForwardAndCatchIrp** function forwards an IRP to the specified driver after initializing the next stack location, and regains control of the IRP on completion from that driver. The function is used with devices that can be stacked and do not use file objects to communicate.

If a file object is being used, the caller must initialize the current stack location with that file object before calling the **KsForwardAndCatchIrp** function. The function verifies that there is a new stack location to copy into before attempting to do so. If there is not a new stack location, the function returns STATUS_INVALID_DEVICE_REQUEST. Regardless of whether a new stack location is present, the IRP is not completed.

## Parameters

### `DeviceObject` [in]

Specifies the device to forward the IRP to.

### `Irp` [in]

Specifies the IRP that is being forwarded to the specified driver.

### `FileObject` [in]

Specifies a file object value to copy to the next stack location. This can be **NULL** in order to set no file object, but the value is always copied to the next stack location. If the current file object is to be preserved, it must be passed in this parameter.

### `StackUse` [in]

Specifies a value enumerated by KSSTACK_USE. If the value is *KsStackCopyToNewLocation*, the parameters are copied to the next stack location. If the value is *KsStackReuseCurrentLocation*, the current stack location is reused when the IRP is forwarded and the stack location is returned to the current location. If the value is *KsStackUseNewLocation*, the new stack location is used as is.

## Return value

The **KsForwardAndCatchIrp** function returns the result of the **IoCallDriver**, or it returns an invalid status if no more stack depth is available.

## Remarks

The type KSSTACK_USE enumeration specifies how the IRP stack is used when forwarding the IRP to the next driver.

| Enumeration | Description |
|---|---|
| KsStackCopyToNewLocation | Indicates that the parameters are to be copied to the next stack location. |
| KsStackReuseCurrentLocation | Indicates that the current stack location is to be reused. |
| KsStackUseNewLocation | Indicates that the next stack location is to be used without modification. |