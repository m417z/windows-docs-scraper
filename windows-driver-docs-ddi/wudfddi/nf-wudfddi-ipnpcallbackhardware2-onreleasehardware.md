# IPnpCallbackHardware2::OnReleaseHardware

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnReleaseHardware** method performs operations that are needed when a device is no longer accessible.

## Parameters

### `pWdfDevice` [in]

A pointer to the [IWDFDevice3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice3) interface for the framework device object.

### `pWdfResourcesTranslated` [in]

A pointer to the [IWDFCmResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfcmresourcelist) interface for the framework resource-list object that identifies the translated hardware resources that the Plug and Play manager has assigned to the device.

## Return value

**OnReleaseHardware** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h. Do not return HRESULT_FROM_NT(STATUS_NOT_SUPPORTED).

## Remarks

A driver registers the [IPnpCallbackHardware2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackhardware2) interface when the driver calls the [IWDFDriver::CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createdevice) method to create a device object.

The **OnReleaseHardware** method must free resources that were allocated during the call to the driver's [IPnpCallbackHardware2::OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onpreparehardware) method, regardless of whether **OnPrepareHardware** succeeded or failed. As such, **OnReleaseHardware** must be able to handle the cleanup of partial resources.

For information about deleting an interrupt object, see [Deleting an Interrupt Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/deleting-an-interrupt-object).

For information about parsing hardware resources, see [Finding and Mapping Hardware Resources in a UMDF Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/finding-and-mapping-hardware-resources-in-umdf-1-x-drivers).

#### Examples

See example code in [IWDFDevice3::MapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-mapiospace).

## See also

[IPnpCallbackHardware2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackhardware2)

[OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onpreparehardware)