# ICatRegister::UnRegisterCategories

## Description

Removes the registration of one or more component categories. Each component category consists of a CATID and a list of locale-dependent description strings.

## Parameters

### `cCategories` [in]

The number of categories to be removed.

### `rgcatid` [in]

The CATIDs of the categories to be removed.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One or more arguments are incorrect. |

## Remarks

This method will be successful even if one or more of the category IDs specified are not registered. This method can only be called by the owner of a category, usually as part of the installation or de-installation of the operating system or application.

This method does not remove the component category tags from individual classes. To do this, use the [ICatRegister::UnRegisterClassReqCategories](https://learn.microsoft.com/windows/desktop/api/comcat/nf-comcat-icatregister-unregisterclassreqcategories) method.

## See also

[ICatRegister](https://learn.microsoft.com/windows/desktop/api/comcat/nn-comcat-icatregister)