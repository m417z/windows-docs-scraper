# IPnpCallback::OnSurpriseRemoval

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnSurpriseRemoval** method notifies a driver after a device is removed from a computer unexpectedly so that the driver can perform necessary operations.

## Parameters

### `pWdfDevice` [in]

A pointer to the [IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice) interface for the device object of the device that is removed unexpectedly.

## Remarks

A driver registers the [IPnpCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallback) interface when the driver calls the [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice) method to create a device object.

The framework does not synchronize the **OnSurpriseRemoval** callback function with other PnP and power management callback functions.

For more information about when the framework calls this callback function, and for more information about synchronization issues, see [A User Unplugs a Device](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-user-unplugs-a-device).

## See also

[IPnpCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallback)

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice)