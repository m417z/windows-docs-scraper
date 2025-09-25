# IWDFUnifiedPropertyStore::GetPropertyData

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetPropertyData** method retrieves the current setting for a device property.

## Parameters

### `PropertyKey` [in]

A pointer to a [DEVPROPKEY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315031(v=vs.85)) structure that specifies the device property key.

### `Lcid` [in]

Specifies a locale identifier. Set this parameter either to a language-specific LCID value or to LOCALE_NEUTRAL. The LOCALE_NEUTRAL LCID specifies that the property is language-neutral (that is, not specific to any language). Do not set this parameter to LOCALE_SYSTEM_DEFAULT or LOCALE_USER_DEFAULT. For more information about language-specific LCID values, see [LCID Structure](https://learn.microsoft.com/openspecs/windows_protocols/ms-lcid/63d3d639-7fd2-4afb-abbe-0d5b5551eef8).

### `Flags` [in]

Reserved for system use. Drivers should set this value to 0.

### `PropertyDataSize` [in]

The size, in bytes, of the buffer that *PropertyData* points to.

### `PropertyData` [out, optional]

A pointer to the device property data.

### `PropertyDataRequiredSize` [out]

A pointer to a ULONG to receive the size of the property information that is returned in *PropertyData*.

### `PropertyType` [out]

A pointer to a [DEVPROPTYPE](https://learn.microsoft.com/previous-versions/ff543546(v=vs.85)) value. If **GetPropertyData** completes successfully, the method uses *PropertyType* to supply the type of data that is returned in the *PropertyData* buffer.

## Return value

**GetPropertyData** returns S_OK if the operation succeeds. Otherwise, the method might return the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | The framework's attempt to allocate memory failed. |
| **HRESULT_FROM_NT(STATUS_BUFFER_TOO_SMALL)** | The *PropertyDataRequiredSize* parameter contains the size of the required buffer. |
| **HRESULT_FROM_WIN32 (ERROR_INVALID_PARAMETER)** | If the driver specifies **WdfPropertyStoreRootClassDeviceInterfaceKey**, the requested interface must be one that the UMDF driver previously registered. |
| **HRESULT_FROM_WIN32 (STATUS_NOT_SUPPORTED)** | The driver can request device interface property data only starting with Windows 8. |

This method might return one of the other values that *Winerror.h* contains.

## Remarks

Framework-based drivers use the **GetPropertyData** method to retrieve device properties that are defined as part of the unified device property model.

In particular, you can use this method to retrieve a device's [hardware key](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers) or an instance of a device interface class. When you call [IWDFUnifiedPropertyStoreFactory::RetrieveUnifiedDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfunifiedpropertystorefactory-retrieveunifieddevicepropertystore), set the *RootSpecifier* parameter's **RootClass** member to **WdfPropertyStoreRootClassHardwareKey** or **WdfPropertyStoreRootClassDeviceInterfaceKey**.

If you specify **WdfPropertyStoreRootClassHardwareKey**, then when you call **GetPropertyData**, you must provide a custom [DEVPROPKEY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/dn315031(v=vs.85)) value in the *PropertyKey* parameter, and not a PnP-defined key. The value must have been previously set by calling [SetPropertyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfunifiedpropertystore-setpropertydata), a [SetupDI device property function](https://learn.microsoft.com/windows-hardware/drivers/install/using-device-installation-functions), or by using the [INF AddProperty directive](https://learn.microsoft.com/windows-hardware/drivers/install/inf-addproperty-directive).

For more information about device properties, see [Device Properties](https://learn.microsoft.com/windows-hardware/drivers/image/device-properties).

For more information about accessing the registry, see [Using the Registry in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers).

#### Examples

For variable size properties, the driver should make two passes to retrieve the property data. First, the driver should pass a NULL buffer in the *PropertyData* parameter, and set *PropertyDataSize* to 0.
Then, the driver should then allocate a buffer based on the *PropertyDataRequiredSize* returned and call **GetPropertyData** again, passing the allocated buffer.

The following example demonstrates this
pattern.

```
HRESULT
GetFriendlyName(
    _In_ IWDFUnifiedPropertyStore * pUnifiedPropertyStore
    )
{
    HRESULT hr = S_OK;
    DEVPROPTYPE type;
    ULONG requiredSize;
    BYTE * friendlyNameBuffer = NULL;
    ULONG friendlyNameBufferSize;

    hr = pUnifiedPropertyStore->GetPropertyData(
            &DEVPKEY_Device_FriendlyName,
            0, //Lcid
            0, //Flags
            0, //BufferSize
            NULL, //Buffer
            &requiredSize,
            &type
            );

    if (HRESULT_CODE(hr) != ERROR_INSUFFICIENT_BUFFER)
    {
        TraceEvents(
            TRACE_LEVEL_ERROR,
            TEST_TRACE_DEVICE,
            "GetPropertyData failed: hr = %!HRESULT!",
            hr
            );
        goto exit;
    }

    friendlyNameBufferSize = requiredSize;
    friendlyNameBuffer = new BYTE[requiredSize];
    if (NULL == friendlyNameBuffer)
    {
        hr = E_OUTOFMEMORY;
        TraceEvents(
            TRACE_LEVEL_ERROR,
            TEST_TRACE_DEVICE,
            "Out of memory while allocating property data buffer returning:”
            “ %!HRESULT!",
            hr
            );
        goto exit;
    }

    hr = pUnifiedPropertyStore->GetPropertyData(
            &DEVPKEY_Device_FriendlyName,
            0, //Lcid
            0, //Flags
            friendlyNameBufferSize,
            friendlyNameBuffer,
            &requiredSize,
            &type
            );

    if (FAILED(hr))
    {
        TraceEvents(
            TRACE_LEVEL_ERROR,
            TEST_TRACE_DEVICE,
            "GetPropertyData failed: hr = %!HRESULT!",
            hr
            );
        goto exit;
    }

    if (type != DEVPROP_TYPE_STRING)
    {
        TraceEvents(
            TRACE_LEVEL_ERROR,
            TEST_TRACE_DEVICE,
            "Expected type %d, actual type: %d",
            DEVPROP_TYPE_STRING,
            type
            );
        hr = E_UNEXPECTED;
        goto exit;
    }

exit:
    delete [] friendlyNameBuffer;
    friendlyNameBuffer = NULL;

    return hr;
}

```

## See also

[IWDFUnifiedPropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfunifiedpropertystore)

[IWDFUnifiedPropertyStoreFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfunifiedpropertystorefactory)

[RetrieveUnifiedDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfunifiedpropertystorefactory-retrieveunifieddevicepropertystore)

[SetPropertyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfunifiedpropertystore-setpropertydata)

[WDF_PROPERTY_STORE_ROOT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wdf_property_store_root)

[WDF_PROPERTY_STORE_ROOT_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_property_store_root_class)