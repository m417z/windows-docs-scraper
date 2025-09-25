# IoSetStartIoAttributes function (ntifs.h)

## Description

The **IoSetStartIoAttributes** routine sets attributes for the driver's [StartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_startio) routine.

## Parameters

### `DeviceObject` [in]

Pointer to the device object for the driver's device.

### `DeferredStartIo` [in]

If **TRUE**, the I/O manager will defer any call to the driver's [StartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_startio) routine while the driver is already inside the routine. In particular, if the *StartIo* routine calls [IoStartNextPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartnextpacket), the *StartIo* routine will not be called again until the current invocation completes. The default is **FALSE**.

### `NonCancelable` [in]

If **TRUE**, the IRP cannot be canceled once it has been dequeued by a call to **IoStartNextPacket**. The default is **FALSE**. Drivers that set this member to **FALSE** must synchronize their IRP handling with the cancel spin lock.

## See also

[IoStartNextPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartnextpacket)

[StartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_startio)