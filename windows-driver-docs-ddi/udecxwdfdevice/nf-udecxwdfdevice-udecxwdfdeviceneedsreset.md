# UdecxWdfDeviceNeedsReset function

## Description

Informs the USB device emulation class extension (UdeCx) that the device needs a reset operation.

## Parameters

### `UdeWdfDevice` [In]

A handle to a framework device object that represents a USB device. The client driver initialized this object in the previous call to [**UdecxWdfDeviceAddUsbDeviceEmulation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/nf-udecxwdfdevice-udecxwdfdeviceaddusbdeviceemulation).

### `ResetType` [In]

A [**UDECX_WDF_DEVICE_RESET_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/ne-udecxwdfdevice-_udecx_wdf_device_reset_type)-type value that indicates the type of reset. Only `UdecxWdfDeviceResetAttemptPlatformLevelDeviceReset` is supported at this time.

## Return value

The function returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

If an existing reset operation is in progress, the function fails with a STATUS_DEVICE_BUSY error. Note that only `UdecxWdfDeviceResetAttemptPlatformLevelDeviceReset` is supported at this time. `UdecxWdfDeviceResetAttemptFunctionLevelDeviceReset` is not supported.

## See also

[**UDECX_WDF_DEVICE_RESET_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxwdfdevice/ne-udecxwdfdevice-_udecx_wdf_device_reset_type)