# IPnpCallback::OnQueryStop

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnQueryStop** method notifies a driver before a device is stopped.

## Parameters

### `pWdfDevice` [in]

A pointer to the [IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice) interface for the device object of the device that will be stopped.

## Return value

If the driver determines that the device can be stopped, the **OnQueryStop** callback method must return S_OK or another status code for which SUCCEEDED(status) equals **TRUE**. Otherwise it must return a status code for which SUCCEEDED(status) equals **FALSE**. HRESULT error codes are defined in Winerror.h. Do not return HRESULT_FROM_NT(STATUS_NOT_SUPPORTED).

This method must use the HRESULT_FROM_NT macro to return a specific HRESULT value to return status to a kernel-mode client. For more information, see [Supporting Kernel-mode Clients](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-kernel-mode-clients-in-umdf-1-x-drivers).

## Remarks

A driver registers the [IPnpCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallback) interface when it calls the [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice) method to create a device object.

The framework does not synchronize the **OnQueryStop** callback function with other PnP and power management callback functions.

**OnQueryStop** is not called in framework versions 1.7 and earlier.

For more information about the **OnQueryStop** callback method, see [The PnP Manager Redistributes System Resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/the-pnp-manager-redistributes-system-resources).

## See also

[IPnpCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallback)

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice)