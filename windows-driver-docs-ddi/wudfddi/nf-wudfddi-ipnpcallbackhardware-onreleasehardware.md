# IPnpCallbackHardware::OnReleaseHardware

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnReleaseHardware** method notifies a driver to perform operations that are necessary when the specified hardware is no longer accessible.

## Parameters

### `pWdfDevice` [in]

A pointer to the [IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice) interface for the device object of the device that is no longer accessible.

## Return value

**OnReleaseHardware** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h. Do not return HRESULT_FROM_NT(STATUS_NOT_SUPPORTED).

This method must use the HRESULT_FROM_NT macro to return a specific HRESULT value to return status to a kernel-mode client. For more information, see [Supporting Kernel-mode Clients](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-kernel-mode-clients-in-umdf-1-x-drivers).

## Remarks

A driver registers the [IPnpCallbackHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackhardware) interface when the driver calls the [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice) method to create a device object.

The **OnReleaseHardware** method must free resources that were allocated during the call to the driver's [IPnpCallbackHardware::OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware-onpreparehardware) method whether **OnPrepareHardware** succeeded or failed. Therefore, **OnReleaseHardware** must be able to handle the cleanup of partial resources.

For more information, see [Finding and Mapping Hardware Resources in a UMDF Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/finding-and-mapping-hardware-resources-in-umdf-1-x-drivers).

## See also

[IPnpCallbackHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackhardware)

[IPnpCallbackHardware2::OnReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onreleasehardware)

[IPnpCallbackHardware::OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware-onpreparehardware)

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice)