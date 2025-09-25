# IFunctionDiscovery::AddInstance

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Creates or modifies a function instance.

## Parameters

### `enumSystemVisibility` [in]

A [SystemVisibilityFlags](https://learn.microsoft.com/windows/win32/api/functiondiscoveryapi/ne-functiondiscoveryapi-systemvisibilityflags) value that specifies whether the created function instance is visible system wide or only to the current user.

**Note** The function instance is stored in HKEY_LOCAL_MACHINE regardless of the *enumSystemVisibility* value. The user must have Administrator access to add a function instance.

### `pszCategory` [in]

The category of the created function instance. See [Category Definitions](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/category-definitions).

### `pszSubCategory` [in]

The subcategory of the created function instance. See [Subcategory Definitions](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/subcategory-definitions). The maximum length of this string is MAX_PATH.

### `pszCategoryIdentity` [in]

The provider instance identifier string. This string is returned from [GetProviderInstanceID](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstance-getproviderinstanceid).

### `ppIFunctionInstance` [out]

A pointer to an [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface pointer that receives the function instance.

## Return value

Possible return values include, but are not limited to, the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The value of *enumSystemVisibility*, *pszCategory*, or *pszCategoryIdentity* is invalid. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |
| **E_ACCESSDENIED** | The user has insufficient access permission to perform the requested action. |
| **E_FAIL** | The provider does not support adding function instances directly using the [AddInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscovery-addinstance) method. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)**<br><br>0x80070002 | The value of *pszCategory* or *pszSubCategory* is unknown. |
| **STRSAFE_E_INVALID_PARAMETER** | An invalid parameter was specified. This error is returned when the length of the *pszSubCategory* string exceeds MAX_PATH. |

## Remarks

This method temporarily creates a new function instance for the specified category and subcategory. The provider that implements the category is responsible for persisting the metadata associated with the newly created function instance using the [IFunctionDiscoveryProviderFactory::CreateInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nf-functiondiscoveryprovider-ifunctiondiscoveryproviderfactory-createinstance) method.

The function instance is not written to the registry if its associated property store does not have any values. Use the [IFunctionInstance::OpenPropertyStore](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstance-openpropertystore) method to check the property store values.

If a function instance already exists for the specified category and subcategory, the existing registry entry is overwritten. The **AddInstance** method returns S_OK. The Function Discovery change notification process invokes the calling application's [IFunctionDiscoveryNotification::OnUpdate](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onupdate) method with *enumQueryUpdateAction* set to **QUA_CHANGE**.

**Note** The [IFunctionDiscoveryNotification::OnUpdate](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctiondiscoverynotification-onupdate) method is not supported by any current provider.

Whether the new function instance is capable of being visible system-wide or only to the user depends on the provider. The registry provider initially sets its default function instance visibility to system wide.

Access permission to change HKEY_LOCAL_MACHINE\SYSTEM registry keys is required in order to add or remove function instances using the registry provider (Administrator or Power User access).

## See also

[IFunctionDiscovery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscovery)