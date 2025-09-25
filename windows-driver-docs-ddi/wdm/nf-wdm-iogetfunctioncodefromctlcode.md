# IoGetFunctionCodeFromCtlCode macro

## Description

The **IoGetFunctionCodeFromCtlCode** macro returns the value of the function code contained in an I/O control code.

## Parameters

### `ControlCode` [in]

The IOCTL_*XXX* (or FSCTL_*XXX*) value, which can be obtained from the driver's I/O stack location of the IRP at **Parameters.DeviceIoControl.IoControlCode**.

## Remarks

**IoGetFunctionCodeFromCtlCode** returns the value of the Function part of the given IOCTL_XXX code.

For information about the layout of IOCTL codes, see [Using I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-i-o-control-codes).

## See also

[IoBuildDeviceIoControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest)