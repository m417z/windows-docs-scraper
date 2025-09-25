## Description

> [!WARNING]
> Starting with Windows 10, the APIs which support third-party print providers are deprecated. Microsoft does not recommend any investment into third-party print providers. Additionally, on Windows 8 and newer products where the v4 print driver model is available, third-party print providers may not create or manage queues which use v4 print drivers.

The **UpdatePrintDeviceObject** function updates the properties of a device object that is in the print provider queue.

## Parameters

### `hPrinter` [in]

The HANDLE to an open printer. This should be a handle that was returned by the **AddPrinter** or **OpenPrinter** spooler functions.

### `hDeviceObject` [in]

The HANDLE to the device object to be updated. This should be a device object that was created with [AddPrintDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-addprintdeviceobject).

## Return value

The **UpdatePrintDeviceObject** function returns S_OK, if the properties of the device object were updated successfully. Otherwise it returns an error.

For example, this function can return HRESULT_FROM_WIN32(ERROR_INVALID_HANDLE), if the function call was made with an invalid HANDLE, or the device object was removed before the function call was made.

## Remarks

The [**PRINTER_INFO_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) structure is a good example of the kind of properties that **UpdatePrintDeviceObject** can update.

## See also

[AddPrintDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-addprintdeviceobject)

[**PRINTER_INFO_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2)