# IFileCallbackClose::OnCloseFile

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnCloseFile** method is called when the last reference count on a file object goes down to zero and before the file object is released.

## Parameters

### `pWdfFileObject` [in]

A pointer to the [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface for the file object that is associated with the device.

## Remarks

A driver registers the [IFileCallbackClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ifilecallbackclose) interface when the driver calls the [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice) method to create a device object.

For information about when the framework calls **OnCloseFile**, see [Driver-Created Versus Application-Created File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/driver-created-versus-application-created-file-objects).

## See also

[IFileCallbackClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ifilecallbackclose)

[IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice)

[IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile)