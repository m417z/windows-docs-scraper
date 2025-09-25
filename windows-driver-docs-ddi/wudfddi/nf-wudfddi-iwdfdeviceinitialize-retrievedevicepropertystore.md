# IWDFDeviceInitialize::RetrieveDevicePropertyStore

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedevicepropertystore) method retrieves a device property store that clients can read and write device properties through.

## Parameters

### `pcwszServiceName` [in, optional]

A pointer to a **NULL**-terminated string that represents the name of the device property store. This parameter is optional. The driver can pass **NULL** if the driver does not supply a name for a device property store.

### `Flags` [in]

A [WDF_PROPERTY_STORE_RETRIEVE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_property_store_retrieve_flags)-typed value that identifies how to retrieve the device property store.

### `ppPropStore` [out]

A pointer to a buffer that receives a pointer to the [IWDFNamedPropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfnamedpropertystore) interface that is used to retrieve device properties.

### `pDisposition` [out, optional]

A pointer to a variable that receives a [WDF_PROPERTY_STORE_DISPOSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_property_store_disposition)-typed value that identifies whether the framework created the device property store or the device property store already existed. This parameter is optional. The driver can pass **NULL** if the driver does not require the disposition information.

## Return value

[RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedevicepropertystore) returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

The caller should call the **Release** method of the [IWDFNamedPropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfnamedpropertystore) interface after finishing with the property store.

For more information, see [Using the Registry in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers).

## See also

[IWDFDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize)

[IWDFNamedPropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfnamedpropertystore)

[WDF_PROPERTY_STORE_DISPOSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_property_store_disposition)

[WDF_PROPERTY_STORE_RETRIEVE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_property_store_retrieve_flags)