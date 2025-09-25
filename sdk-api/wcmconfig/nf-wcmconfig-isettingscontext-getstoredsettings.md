# ISettingsContext::GetStoredSettings

## Description

Gets the stored setting changes from the context for the given namespace. This method returns a pointer to an address of an enumerator for each of the parameters *ppAddedSettings*, *ppModifiedSettings*, and *ppDeletedSettings* that identifies the set of paths for the added, modified, and deleted settings respectively. These strings may then be passed to [ISettingsContext::RevertSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingscontext-revertsetting).

## Parameters

### `pIdentity` [in]

The [ISettingsIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingsidentity) object that specifies the namespace to get the settings for. This namespace identity should be fully-specified.

### `ppAddedSettings` [out]

 A pointer to a newly allocated [IItemEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-iitemenumerator) object that lists the set of paths for the added settings. Each path identifies a setting added to the context.

### `ppModifiedSettings` [out]

A pointer to a newly-allocated [IItemEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-iitemenumerator) object that lists the set of paths for the modified settings.

### `ppDeletedSettings` [out]

A pointer to a newly-allocated [IItemEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-iitemenumerator) object that lists the set of paths for the deleted settings.

## Return value

This method returns an HRESULT value. **S_OK** indicates success. It returns **WCM_E_NAMESPACENOTFOUND** if *pIdentity* references a namespace that is not in the context.

It may return **E_OUTOFMEMORY** if there are insufficient resources on the system to allocate the enumerators.

## Remarks

*ppAddedSettings*, *ppModifiedSettings*, and *ppDeletedSettings* are enumerators for which Current returns a var with variable type BSTR that identifies the paths for the added, modified, and deleted settings respectively. Enumerating through the enumerators produces a set of path strings, each of which identifies a setting that has been added, modified, or deleted in this context. These strings can then be passed to [RevertSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nf-wcmconfig-isettingscontext-revertsetting).

## See also

[ISettingsContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-isettingscontext)