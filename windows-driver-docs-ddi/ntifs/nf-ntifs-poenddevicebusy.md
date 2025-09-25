# PoEndDeviceBusy function (ntifs.h)

## Description

The **PoEndDeviceBusy** routine marks the end of a period of time in which the device is busy.

## Parameters

### `IdlePointer` [in, out]

A pointer to an idle counter. This is a pointer value that was previously returned by the [**PoRegisterDeviceForIdleDetection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregisterdeviceforidledetection) routine. Because **PoRegisterDeviceForIdleDetection** might return a NULL pointer, the caller must verify that the pointer is non-NULL before it calls **PoEndDeviceBusy**.

## Remarks

The [**PoStartDeviceBusy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-postartdevicebusy) and **PoEndDeviceBusy** routines mark the start and end of a time period in which a device is busy. Each call to **PoStartDeviceBusy** must be followed by a corresponding call to **PoEndDeviceBusy**. For more information about how these routines work together, see [**PoStartDeviceBusy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-postartdevicebusy).

## See also

[**PoRegisterDeviceForIdleDetection**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-poregisterdeviceforidledetection)

[**PoStartDeviceBusy**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-postartdevicebusy)