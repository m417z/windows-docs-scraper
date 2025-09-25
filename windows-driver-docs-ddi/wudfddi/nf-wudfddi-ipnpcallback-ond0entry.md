# IPnpCallback::OnD0Entry

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnD0Entry** method notifies a driver when a device enters the D0 power state so that the driver can perform necessary operations, such as enabling the device.

## Parameters

### `pWdfDevice` [in]

A pointer to the [IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice) interface for the device object of the device that enters the D0 power state.

### `previousState` [in]

A [WDF_POWER_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_device_state)-typed value that identifies the power state of the device before it entered the D0 power state.

## Return value

If the **OnD0Entry** callback encounters no errors, it must return
S_OK or another status code for which SUCCEEDED(status) equals **TRUE**.

 If it returns a status code for which SUCCEEDED(status) equals **FALSE**, the framework removes the device. If the device's drivers are not supporting other devices on the system, the I/O manager unloads the drivers.
The framework notifies the PnP manager, which then attempts to restart the device by requesting the bus driver to reenumerate its devices. If your driver was unloaded, it will be reloaded. In this case, the framework will not call the driver's [IPnpCallback::OnD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0exit) callback function.

HRESULT error codes are defined in Winerror.h.

## Remarks

A driver registers the [IPnpCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallback) interface when it calls the [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice) method to create a device object.

## See also

[IPnpCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallback)

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice)

[WDF_POWER_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_device_state)