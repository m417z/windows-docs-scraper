# IPnpCallbackSelfManagedIo::OnSelfManagedIoFlush

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnSelfManagedIoFlush** method flushes the device for a device's self-managed I/O operations.

## Parameters

### `pWdfDevice` [in]

A pointer to the [IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice) interface for the device object of the device that is flushed.

## Remarks

A driver registers the [IPnpCallbackSelfManagedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackselfmanagedio) interface when the driver calls the [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice) method to create a device object.

## See also

[IPnpCallbackSelfManagedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackselfmanagedio)

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice)