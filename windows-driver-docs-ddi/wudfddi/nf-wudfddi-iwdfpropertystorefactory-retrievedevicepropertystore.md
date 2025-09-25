# IWDFPropertyStoreFactory::RetrieveDevicePropertyStore

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedevicepropertystore) method retrieves a property store interface that drivers can use to access the registry.

## Parameters

### `RootSpecifier` [in]

The address of a driver-allocated [WDF_PROPERTY_STORE_ROOT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wdf_property_store_root) structure. The driver fills in this structure to identify the property store that [RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedevicepropertystore) retrieves.

### `Flags` [in]

A [WDF_PROPERTY_STORE_RETRIEVE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_property_store_retrieve_flags)-typed flag that specifies whether UMDF should create a specified registry entry if it does not exist, and whether the new entry should be deleted when Windows restarts.

### `DesiredAccess` [in]

A REGSAM-typed bit mask that specifies the types of access to the registry that you want your driver to have. The REGSAM type is defined in Winreg.h, and is described in the Windows SDK at [REGSAM](https://learn.microsoft.com/windows/win32/shell/messages). The bit mask must not specify GENERIC_WRITE, KEY_CREATE_SUB_KEY, or WRITE_DAC access. (Although the driver cannot specify KEY_CREATE_SUB_KEY, its call to [RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedevicepropertystore) can create a subkey.)

### `SubkeyPath` [in]

A pointer to a caller-supplied character string that represents the name of a subkey located under the registry key that the *RootSpecifier* parameter specifies. This parameter is optional and can be **NULL**. See more information in Remarks.

### `PropertyStore` [out]

The address of a location that receives a pointer to an [IWDFNamedPropertyStore2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfnamedpropertystore2) interface. The driver uses this interface to access values in the registry.

### `Disposition` [out]

The address of a location that receives a [WDF_PROPERTY_STORE_DISPOSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_property_store_disposition)-typed value.

## Return value

[RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedevicepropertystore) returns S_OK if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The caller provided an invalid input argument. |
| **E_OUTOFMEMORY** | An attempt to allocate memory failed. |

This method might return one of the other values that Winerror.h contains

## Remarks

Your driver can call [RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedevicepropertystore) to obtain access to the driver's software key, the current device's hardware key, keys for the device interfaces that the current device supports, or the **DEVICEMAP** key.

If you supply the *SubkeyPath* parameter, you must use a unique name, such as the driver's service name. A driver might use a subkey to store device-specific information.

For more information about using [RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedevicepropertystore) to access the registry, see [Using the Registry in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers).

#### Examples

The following code example retrieves the value that is assigned to the **PortName** entry under a device's hardware key.

```
IWDFPropertyStoreFactory *pPropertyStoreFactory = NULL;
WDF_PROPERTY_STORE_ROOT RootSpecifier;
IWDFNamedPropertyStore2 * pHardwarePropertyStore2 = NULL;
PROPVARIANT comPortPV;
WCHAR portName[] = L"PortName";
HRESULT hr;
...
//
// Get the property store factory interface.
//
hr = m_FxDevice->QueryInterface(IID_PPV_ARGS(&pPropertyStoreFactory));
if (FAILED(hr))
{
    goto Exit;
}
//
//Initialize the WDF_PROPERTY_STORE_ROOT structure. We want to open the
// \Device Parameters subkey under the device's hardware key.
//
RtlZeroMemory(&RootSpecifier,
              sizeof(WDF_PROPERTY_STORE_ROOT));
RootSpecifier.LengthCb = sizeof(WDF_PROPERTY_STORE_ROOT);
RootSpecifier.RootClass = WdfPropertyStoreRootClassHardwareKey;
RootSpecifier.Qualifier.HardwareKey.ServiceName = WDF_PROPERTY_STORE_HARDWARE_KEY_ROOT;

//
// Get the property store interface for the hardware key of the
// device that m_FxDevice represents.
//
hr = pPropertyStoreFactory->RetrieveDevicePropertyStore(
                                           &RootSpecifier,
                                           WdfPropertyStoreNormal,
                                           KEY_QUERY_VALUE,
                                           NULL,
                                           &pHardwarePropertyStore2,
                                           NULL
                                           );
if (FAILED(hr))
{
    goto Exit;
}

//
// Get the value of the "PortName" entry, which is stored under
// the device's \Device Parameters subkey.
//
PropVariantInit(&comPortPV);
hr = pHardwarePropertyStore2->GetNamedValue(portName,
                                            &comPortPV);
if (FAILED(hr))
{
   goto Exit;
}
...
Exit:
    SAFE_RELEASE(pHardwarePropertyStore2);
    SAFE_RELEASE(pPropertyStoreFactory);
...
```

## See also

[IWDFDevice::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-retrievedevicepropertystore)

[IWDFDeviceInitialize::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-retrievedevicepropertystore)

[IWDFPropertyStoreFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfpropertystorefactory)