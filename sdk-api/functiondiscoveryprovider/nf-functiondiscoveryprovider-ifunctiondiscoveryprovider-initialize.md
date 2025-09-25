# IFunctionDiscoveryProvider::Initialize

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Initializes the Function Discovery provider object. This method is intended to be called immediately after the object is created.

## Parameters

### `pIFunctionDiscoveryProviderFactory` [in]

A pointer to the [IFunctionDiscoveryProviderFactory](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryproviderfactory) interface. The provider should use this interface to create new Function Discovery objects.

### `pIFunctionDiscoveryNotification` [in]

A pointer to an [IFunctionDiscoveryNotification](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscoverynotification) interface. The provider should use this interface to send [OnUpdate](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onupdate), [OnEvent](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onevent), and [OnError](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onerror) notifications to the Function Discovery notification queue. Queued notifications are sent to client programs by Function Discovery.

### `lcidUserDefault` [in]

The locale identifier of the caller. The provider should use *lcidUserDefault* to return localized strings for the resource enumerated by the provider.

### `pdwStgAccessCapabilities` [out]

Specifies the least restrictive possible access mode of the property stores associated with the function instances created by this provider.

If the DWORD value is set to -1, [InstancePropertyStoreValidateAccess](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryprovider-instancepropertystorevalidateaccess) will be called every time [OpenPropertyStore](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstance-openpropertystore) is called on a function instance created by this provider. Otherwise, the value specified by this parameter determines the least restrictive possible access mode for all property stores associated with all function instances created by this provider. A more restrictive access mode will be applied to an individual property store if a client calls **OpenPropertyStore** with the *dwStgAccess* parameter set to a value that is more restrictive than the specified *pdwStgAccessCapabilities* value.

For efficiency, specify a *pdwStgAccessCapabilities* value whenever possible.

The following modes are supported:

#### STGM_READ

#### STGM_READWRITE

#### STGM_WRITE

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One of the parameters contains an invalid argument. |

## Remarks

If your provider is going to create Function Discovery objects, queue notifications, or enumerate resources with localized strings, you must call **AddRef** on and cache the initialized *pIFunctionDiscoveryProviderFactory*, *pIFunctionDiscoveryNotification*, and *lcidUserDefault* parameters for later use when you implement the **Initialize** method.

## See also

[IFunctionDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryprovider)