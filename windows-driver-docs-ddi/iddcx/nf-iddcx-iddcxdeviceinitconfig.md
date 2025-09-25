# IddCxDeviceInitConfig function

## Description

 Creates a WDFDEVICE initialization structure to allow indirect displays to be used.

## Parameters

### `DeviceInit`

The information about the device that is being initialized.

### `Config`

The information required about the configuration of the client.

## Return value

(NTSTATUS) The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method may return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.