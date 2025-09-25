# IProviderPublishing::RemoveInstance

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Deletes an existing function instance.

## Parameters

### `enumVisibilityFlags` [in]

A [SystemVisibilityFlags](https://learn.microsoft.com/windows/win32/api/functiondiscoveryapi/ne-functiondiscoveryapi-systemvisibilityflags) enumeration value which specifies the visibility of the function instance which the provider is about to delete. It is up to the provider whether or not to honor this setting, however the current user visibility can be used to allow processes running in a non-Administrator security context to still be able to remove function instances.

### `pszSubCategory` [in]

The subcategory string of the function instance.

### `pszProviderInstanceIdentity` [in]

The provider instance identifier.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One of the parameters contains an invalid argument. |
| **E_POINTER** | The *pSiteInfo*, *pszSubCategory*, or *pszProviderInstanceIdentity* parameter is **NULL**. |

## See also

[IProviderPublishing](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-iproviderpublishing)