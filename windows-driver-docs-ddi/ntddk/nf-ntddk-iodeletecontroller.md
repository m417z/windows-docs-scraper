# IoDeleteController function

## Description

The **IoDeleteController** routine removes a given controller object from the system, for example, when the driver that created it is being unloaded.

## Parameters

### `ControllerObject` [in]

Pointer to the controller object to be released.

## Remarks

**IoDeleteController** deallocates the memory for the controller object, including the controller extension.

This routine must be called when a driver that created a controller object is being unloaded or when the driver encounters a fatal error during device start-up, such as being unable to properly initialize a physical device.

A driver must release certain resources for which the driver supplied storage in its controller extension before it calls **IoDeleteController**. For example, if the driver stores the pointer to its interrupt object(s) in the controller extension, it must call [IoDisconnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodisconnectinterrupt) before **IoDeleteController**.

## See also

[IoCreateController](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatecontroller)

[IoDisconnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iodisconnectinterrupt)