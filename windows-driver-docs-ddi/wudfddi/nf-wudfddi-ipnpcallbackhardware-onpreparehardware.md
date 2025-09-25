# IPnpCallbackHardware::OnPrepareHardware

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnPrepareHardware** method notifies a driver to make the specified hardware accessible.

## Parameters

### `pWdfDevice` [in]

A pointer to the [IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice) interface for the device object of the device to make accessible.

## Return value

**OnPrepareHardware** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes defined in Winerror.h. Do not return HRESULT_FROM_NT(STATUS_NOT_SUPPORTED).

If **OnPrepareHardware** returns an error code, the framework will still call the [IPnpCallbackHardware::OnReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware-onreleasehardware) method. The **OnReleaseHardware** method can then free resources that were allocated during the call to **OnPrepareHardware**. Because **OnReleaseHardware** must free resources for both success and failure cases of **OnPrepareHardware**, it must be able to handle the cleanup of partial resources.

This method must use the HRESULT_FROM_NT macro to return a specific HRESULT value to return status to a kernel-mode client. For more information, see [Supporting Kernel-mode Clients](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-kernel-mode-clients-in-umdf-1-x-drivers).

## Remarks

A driver registers the [IPnpCallbackHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackhardware) interface when it calls the [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice) method to create a device object.

Receiving a call to the **OnPrepareHardware** method is equivalent to a Microsoft Windows Driver Model (WDM) driver receiving an [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) IRP.

For more information, see [Finding and Mapping Hardware Resources in a UMDF Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/finding-and-mapping-hardware-resources-in-umdf-1-x-drivers).

## See also

[IPnpCallbackHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackhardware)

[IPnpCallbackHardware2::OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onpreparehardware)

[IPnpCallbackHardware::OnReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware-onreleasehardware)

[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device)

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice)