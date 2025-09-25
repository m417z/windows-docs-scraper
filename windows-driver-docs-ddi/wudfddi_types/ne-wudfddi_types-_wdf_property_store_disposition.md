# _WDF_PROPERTY_STORE_DISPOSITION enumeration

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WDF_PROPERTY_STORE_DISPOSITION** enumeration contains values that indicate whether a registry value was created or already existed when a driver obtained a property store interface.

## Constants

### `CreatedNewStore`

The device property store (registry value) was created.

### `OpenedExistingStore`

The device property store already exists.

## Remarks

The **WDF_PROPERTY_STORE_DISPOSITION** enumeration is used as output from the [IWDFDevice::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedevicepropertystore), [IWDFDeviceInitialize::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-retrievedevicepropertystore), and [IWDFPropertyStoreFactory::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfpropertystorefactory-retrievedevicepropertystore) methods.

## See also

[IWDFDevice::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedevicepropertystore)

[IWDFDeviceInitialize::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-retrievedevicepropertystore)

[IWDFPropertyStoreFactory::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfpropertystorefactory-retrievedevicepropertystore)