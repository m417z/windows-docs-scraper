# IOCTL_STORAGE_DEVICE_POWER_CAP IOCTL

## Description

Windows applications can use this control code to specify a maximum operational power consumption level for a storage device. The OS will do it's best to transition the device to a power state that will not exceed the given maximum. However, this depends on what the device supports. The actual maximum may be less than or greater than the desired maximum.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,                 // handle to device
  IOCTL_STORAGE_DEVICE_POWER_CAP,   // dwIoControlCode
  (LPDWORD) lpInBuffer,             // input buffer
  (DWORD) nInBufferSize,            // size of input buffer
  (LPDWORD) lpOutBuffer,            // output buffer
  (DWORD) nOutBufferSize,           // size of output buffer
  (LPDWORD) lpBytesReturned,        // number of bytes returned
  (LPOVERLAPPED) lpOverlapped       // OVERLAPPED structure
);
```

## Parameters

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

This IOCTL is sent to the device driver with a maximum power value that the driver is expected to honor. This IOCTL then returns with a value that represents what the device driver is actually capable of achieving. This value could be equal to, less than, or greater than the desired value that was sent originally.

For example, consider a storage device driver that implements three operational power states that have a maximum power consumption level of 10 watts, 8 watts, and 6 watts. If the caller of this IOCTL specifies that the device should not consume more than 9 watts, it must choose its 8 watt state because that is the highest state it has that is still less than 9 watts. If the caller of this IOCTL specifies that the device should not consume more than 5 watts, the device driver will pick the 6 watt state because 6 watts is the minimum value the device can function at.

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)