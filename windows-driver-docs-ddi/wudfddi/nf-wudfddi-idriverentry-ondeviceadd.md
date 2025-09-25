# IDriverEntry::OnDeviceAdd

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnDeviceAdd** method adds a new device to a system.

## Parameters

### `pWdfDriver` [in]

A pointer to the [IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver) interface for the parent driver object that the new device belongs to.

### `pWdfDeviceInit` [in]

A pointer to the [IWDFDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize) interface that the driver uses to initialize the newly created device.

## Return value

**OnDeviceAdd** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h. The driver should return S_OK only if it successfully called the [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice) method to create the [framework device object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object). If the driver returns an error code, UMDF tears down the entire device stack regardless of whether the driver is a filter driver or a function driver.

## Remarks

A new device object is created for each device that is loaded in the driver host process. When a new device arrives in the system, the framework calls **OnDeviceAdd** to notify the driver of the arrival and passes the [IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver) and [IWDFDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize) interfaces in the call. The driver can call the [IWDFDeviceInitialize::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-retrievedevicepropertystore) method to query for the device information that is provided as part of device installation. The driver must call the [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice) method to configure and create the device. If the driver does not successfully call **IWDFDriver::CreateDevice** before it returns S_OK, UMDF determines that the driver's behavior is incorrect and terminates the host process.

Any driver whose **OnDeviceAdd** method returns S_OK will subsequently receive a call to its [IPnpCallbackHardware::OnReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware-onreleasehardware) method when the UMDF tears down the device stack.

Do not use the [IWDFDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize) interface that the *pWdfDeviceInit* parameter points to after the driver has called [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice).

For more information, see [Adding a Device](https://learn.microsoft.com/windows-hardware/drivers/wdf/adding-a-device).

## See also

[IDriverEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-idriverentry)

[IPnpCallbackHardware::OnReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware-onreleasehardware)

[IWDFDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize)

[IWDFDeviceInitialize::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-retrievedevicepropertystore)

[IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver)

[IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice)