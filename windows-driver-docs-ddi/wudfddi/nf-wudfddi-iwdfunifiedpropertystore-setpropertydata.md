# IWDFUnifiedPropertyStore::SetPropertyData

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **SetPropertyData** method modifies the current setting of a device property.

## Parameters

### `PropertyKey` [in]

A pointer to a [DEVPROPKEY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315031(v=vs.85)) structure that specifies the device property key.

### `Lcid` [in]

Specifies a locale identifier. Set this parameter either to a language-specific LCID value or to LOCALE_NEUTRAL. The LOCALE_NEUTRAL LCID specifies that the property is language-neutral (that is, not specific to any language). Do not set this parameter to LOCALE_SYSTEM_DEFAULT or LOCALE_USER_DEFAULT. For more information about language-specific LCID values, see [LCID Structure](https://learn.microsoft.com/openspecs/windows_protocols/ms-lcid/63d3d639-7fd2-4afb-abbe-0d5b5551eef8).

### `Flags` [in]

Reserved. Drivers should set this value to 0.

### `PropertyType` [in]

A pointer to a [DEVPROPTYPE](https://learn.microsoft.com/previous-versions/ff543546(v=vs.85)) value that specifies the type of the data that is provided in the *PropertyData* buffer.

### `PropertyDataSize` [in]

The size, in bytes, of the buffer that *PropertyData* points to.

### `PropertyData` [in, optional]

A pointer to the device property data. Set this parameter to **NULL** to delete the specified property.

## Return value

**SetPropertyData** returns S_OK if the operation succeeds. Otherwise, the method might return the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | The framework's attempt to allocate memory failed. |
| **HRESULT_FROM_WIN32 (ERROR_INVALID_PARAMETER)** | If the driver specifies **WdfPropertyStoreRootClassDeviceInterfaceKey**, the requested interface must be one that the UMDF driver previously registered. |
| **HRESULT_FROM_WIN32 (STATUS_NOT_SUPPORTED)** | The driver can modify device interface property data only starting with Windows 8. |

This method might return an HRESULT-typed value corresponding to one of the other values that *Winerror.h* contains.

## Remarks

Framework-based drivers use the **SetPropertyData** method to modify device properties that are defined as part of the unified device property model.

In particular, you can use this method to modify a device's [hardware key](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers) or an instance of a device interface class. When you call [IWDFUnifiedPropertyStoreFactory::RetrieveUnifiedDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfunifiedpropertystorefactory-retrieveunifieddevicepropertystore), set the *RootSpecifier* parameter's **RootClass** member to **WdfPropertyStoreRootClassHardwareKey** or **WdfPropertyStoreRootClassDeviceInterfaceKey**.

If you specify **WdfPropertyStoreRootClassHardwareKey**, then when you call **SetPropertyData**, you must provide a custom [DEVPROPKEY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315031(v=vs.85)) value in the *PropertyKey* parameter, and not a PnP-defined key. The value must have been previously set by calling **SetPropertyData**, a [SetupDI device property function](https://learn.microsoft.com/windows-hardware/drivers/install/using-device-installation-functions), or by using the [INF AddProperty directive](https://learn.microsoft.com/windows-hardware/drivers/install/inf-addproperty-directive).

If the driver specifies **WdfPropertyStoreRootClassDeviceInterfaceKey**, the requested interface must be one that the UMDF driver previously registered at runtime.

If the driver registers an interface in its INF file, it must set associated properties in the INF as well.

For more information about accessing the registry, see [Using the Registry in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers).

#### Examples

```
HRESULT
SetFriendlyName(
    _In_ IWDFUnifiedPropertyStore * pUnifiedPropertyStore
    )
{
    HRESULT hr = S_OK;
    WCHAR friendlyName[] = L"UMDF OSR USB Fx2 Test Device";

    hr = pUnifiedPropertyStore->SetPropertyData(
            &DEVPKEY_Device_FriendlyName,
            0, //Lcid
            0, //Flags
            DEVPROP_TYPE_STRING, //Type
            sizeof(friendlyName),
            friendlyName
            );

    if (FAILED(hr))
    {
        TraceEvents(
            TRACE_LEVEL_ERROR,
            TEST_TRACE_DEVICE,
            "SetPropertyData failed: hr = %!HRESULT!",
            hr
            );
        goto exit;
    }

exit:
    return hr;
}

```

## See also

[GetPropertyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfunifiedpropertystore-getpropertydata)

[IWDFUnifiedPropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfunifiedpropertystore)

[IWDFUnifiedPropertyStoreFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfunifiedpropertystorefactory)

[RetrieveUnifiedDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfunifiedpropertystorefactory-retrieveunifieddevicepropertystore)

[WDF_PROPERTY_STORE_ROOT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wdf_property_store_root)

[WDF_PROPERTY_STORE_ROOT_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_property_store_root_class)