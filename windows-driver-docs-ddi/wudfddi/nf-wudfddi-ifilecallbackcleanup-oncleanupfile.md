# IFileCallbackCleanup::OnCleanupFile

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnCleanupFile** method cancels all I/O requests that a driver has pending in the framework queue.

## Parameters

### `pWdfFileObject` [in]

A pointer to the [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface for the file object that is associated with the device.

## Remarks

A driver registers the [IFileCallbackCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ifilecallbackcleanup) interface when the driver calls the [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice) method to create a device object.

The framework calls the **OnCleanupFile** method to notify the driver to cancel all I/O requests that it has pending. The framework notifies the driver in response to an application calling the Microsoft Win32 **CloseHandle** function.

For information about when the framework calls **OnCleanupFile**, see [Driver-Created Versus Application-Created File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/driver-created-versus-application-created-file-objects).

## See also

[IFileCallbackCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ifilecallbackcleanup)

[IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice)

[IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile)