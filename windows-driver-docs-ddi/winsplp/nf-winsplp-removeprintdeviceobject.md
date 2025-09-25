## Description

> [!WARNING]
> Starting with Windows 10, the APIs which support third-party print providers are deprecated. Microsoft does not recommend any investment into third-party print providers. Additionally, on Windows 8 and newer products where the v4 print driver model is available, third-party print providers may not create or manage queues which use v4 print drivers.

The **RemovePrintDeviceObject** function removes a device object from a print provider queue.

## Parameters

### `hDeviceObject` [in]

The HANDLE to the device object to be removed. This should be a device object that was created with [AddPrintDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-addprintdeviceobject).

## Return value

The **RemovePrintDeviceObject** function returns S_OK, if the device object was removed successfully. Otherwise it returns an error.

For example, this function can return HRESULT_FROM_WIN32(ERROR_INVALID_HANDLE), if an invalid device object handle was used to call the function. And note that, regardless of the return value, the device object HANDLE becomes invalid after a call to **RemovePrintDeviceObject** has completed.

## Remarks

Call **RemovePrintDeviceObject** to remove the device object for a printer that has been deleted. When the spooler services stops, all the device objects are automatically deleted, so it is not required to call **RemovePrintDeviceObject** for each printer device object.

## See also

[AddPrintDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-addprintdeviceobject)