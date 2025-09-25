# IFunctionDiscovery::RemoveInstance

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Removes the specified function instance, based on category and subcategory.

## Parameters

### `enumSystemVisibility` [in]

A [SystemVisibilityFlags](https://learn.microsoft.com/windows/win32/api/functiondiscoveryapi/ne-functiondiscoveryapi-systemvisibilityflags) value that specifies whether the function instance is removed system-wide or only for the current user.

### `pszCategory` [in]

The category of the function instance. See [Category Definitions](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/category-definitions).

### `pszSubCategory` [in]

The subcategory of the function instance to be removed. See [Subcategory Definitions](https://learn.microsoft.com/previous-versions/windows/desktop/fundisc/subcategory-definitions). This parameter can be **NULL**.

### `pszCategoryIdentity` [in]

The provider instance identifier string. This string is returned from [GetProviderInstanceID](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nf-functiondiscoveryapi-ifunctioninstance-getproviderinstanceid).

## Return value

Possible return values include, but are not limited to, the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | The value of *pszCategoryIdentity* is invalid. |
| **E_OUTOFMEMORY** | The method is unable to allocate the memory required to perform this operation. |
| **E_ACCESSDENIED** | The user has insufficient access permission to perform the requested action. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)**<br><br>0x80070002 | The value of *pszCategory* or *pszSubCategory* is unknown. |

## Remarks

Access permission to change HKEY_LOCAL_MACHINE\SYSTEM registry keys is required in order to add or remove function instances using the registry provider (Administrator or Power User access levels). The user must have Administrator access to remove a function instance system-wide.

**Note** This method is not supported by all providers.

## See also

[IFunctionDiscovery](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctiondiscovery)