# _WDF_PROPERTY_STORE_RETRIEVE_FLAGS enumeration

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WDF_PROPERTY_STORE_RETRIEVE_FLAGS** enumeration contains values that indicate whether UMDF should create a registry key if the key does not already exist.

## Constants

### `WdfPropertyStoreNormal`

Do not create the registry key if it does not exist.

### `WdfPropertyStoreCreateIfMissing`

Create the registry key if it does not exist. The key will be *nonvolatile*, which means that it will not be deleted when Windows restarts.

### `WdfPropertyStoreCreateVolatile`

Create the registry key if it does not exist. The key will be volatile, which means that it will be deleted when Windows restarts. This flag is available in UMDF versions 1.9 and later.

### `WdfPropertyStoreRetrieveFlagsMask`

Reserved for system use.

## Remarks

**WDF_PROPERTY_STORE_RETRIEVE_FLAGS** enumeration values are used as input to the [IWDFDevice::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedevicepropertystore), [IWDFDeviceInitialize::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-retrievedevicepropertystore), and [IWDFPropertyStoreFactory::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfpropertystorefactory-retrievedevicepropertystore) methods.

## See also

[IWDFDevice::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedevicepropertystore)

[IWDFDeviceInitialize::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-retrievedevicepropertystore)

[IWDFPropertyStoreFactory::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfpropertystorefactory-retrievedevicepropertystore)