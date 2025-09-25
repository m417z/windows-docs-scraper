# IPnpCallbackSelfManagedIo::OnSelfManagedIoRestart

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnSelfManagedIoRestart** method restarts a device's self-managed I/O operations.

## Parameters

### `pWdfDevice` [in]

A pointer to the [IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice) interface for the device object of the device for which the self-managed I/O operations are restarted.

## Return value

If the **OnSelfManagedIoRestart** callback encounters no errors, it must return
S_OK or another status code for which SUCCEEDED(status) equals **TRUE**.

 If it returns a status code for which SUCCEEDED(status) equals **FALSE**, the framework will stop the device and unload the device's drivers. In this case, the framework calls the driver's [IPnpCallbackSelfManagedIo::OnSelfManagedIoFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackselfmanagedio-onselfmanagedioflush) and [IPnpCallbackSelfManagedIo::OnSelfManagedIoCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackselfmanagedio-onselfmanagediocleanup) callback methods.

HRESULT error codes are defined in Winerror.h.

## Remarks

A driver registers the [IPnpCallbackSelfManagedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackselfmanagedio) interface when it calls the [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice) method to create a device object.

## See also

[IPnpCallbackSelfManagedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackselfmanagedio)

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice)