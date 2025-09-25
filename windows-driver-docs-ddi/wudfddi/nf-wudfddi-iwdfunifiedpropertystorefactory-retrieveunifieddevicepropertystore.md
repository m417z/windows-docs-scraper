# IWDFUnifiedPropertyStoreFactory::RetrieveUnifiedDevicePropertyStore

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RetrieveUnifiedDevicePropertyStore** method retrieves a unified property store interface.

## Parameters

### `RootSpecifier` [in]

The address of a driver-allocated [WDF_PROPERTY_STORE_ROOT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wdf_property_store_root) structure. The driver fills in this structure to identify the unified property store that **RetrieveUnifiedDevicePropertyStore** retrieves.

### `PropertyStore` [out]

The address of a location that receives a pointer to an [IWDFUnifiedPropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfunifiedpropertystore) interface.

## Return value

**RetrieveUnifiedDevicePropertyStore** returns S_OK if the operation succeeds. Otherwise, the method might return one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The caller provided an invalid input argument. |
| **E_OUTOFMEMORY** | An attempt to allocate memory failed. |

This method might return one of the other values that *Winerror.h* contains.

## Remarks

Your driver can call **RetrieveUnifiedDevicePropertyStore** to obtain access to a current device's hardware key or a device interface key that the device supports.

The **RootClass** member of the [WDF_PROPERTY_STORE_ROOT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wdf_property_store_root) structure pointed to by *RootSpecifier* must be set to **WdfPropertyStoreRootClassHardwareKey** or **WdfPropertyStoreRootClassDeviceInterfaceKey**.

In addition, if **RootClass** is set to **WdfPropertyStoreRootClassHardwareKey**, then the **Qualifier.HardwareKey.ServiceName** member of *RootSpecifier* must be NULL.

For more information about accessing the registry, see [Using the Registry in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers).

#### Examples

The following code example retrieves a unified property store interface.

```
HRESULT
GetDevicePropertyStore(
    _In_  IWDFDevice *                  FxDevice,
    _Out_ IWDFUnifiedPropertyStore **   ppUnifiedPropertyStore
    )
{
    HRESULT hr;
    IWDFUnifiedPropertyStore *          pUnifiedPropertyStore = NULL;
    WDF_PROPERTY_STORE_ROOT             RootSpecifier;
    IWDFUnifiedPropertyStoreFactory *   pUnifiedPropertyStoreFactory = NULL;

    HRESULT hrQI = FxDevice->QueryInterface(
                        IID_PPV_ARGS(&pUnifiedPropertyStoreFactory)
                        );
    WUDF_TEST_DRIVER_ASSERT(SUCCEEDED(hrQI));

    RootSpecifier.LengthCb = sizeof(RootSpecifier);
    RootSpecifier.RootClass = WdfPropertyStoreRootClassHardwareKey;
    RootSpecifier.Qualifier.HardwareKey.ServiceName = NULL;

    hr = pUnifiedPropertyStoreFactory->RetrieveUnifiedDevicePropertyStore(
            &RootSpecifier,
            &pUnifiedPropertyStore
            );

    if (FAILED(hr))
    {
        TraceEvents(
            TRACE_LEVEL_ERROR,
            TEST_TRACE_DEVICE,
            "Failed to retrieve unified property store for device: ”
            “hr = %!HRESULT!",
            hr
            );
        goto exit;
    }

    *ppUnifiedPropertyStore = pUnifiedPropertyStore;

exit:
    SAFE_RELEASE(pUnifiedPropertyStoreFactory);

    return hr;
}

```

## See also

[IWDFUnifiedPropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfunifiedpropertystore)

[IWDFUnifiedPropertyStoreFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfunifiedpropertystorefactory)