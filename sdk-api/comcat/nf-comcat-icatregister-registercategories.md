# ICatRegister::RegisterCategories

## Description

Registers one or more component categories. Each component category consists of a CATID and a list of locale-dependent description strings.

## Parameters

### `cCategories` [in]

The number of component categories to be registered.

### `rgCategoryInfo` [in]

An array of [CATEGORYINFO](https://learn.microsoft.com/windows/desktop/api/comcat/ns-comcat-categoryinfo) structures, one for each category to be registered. By providing the same CATID for multiple **CATEGORYINFO** structures, multiple locales can be registered for the same component category.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One or more arguments are incorrect. |

## Remarks

This method can only be called by the owner of a category, usually as part of the installation or de-installation of the operating system or application.

## See also

[ICatRegister](https://learn.microsoft.com/windows/desktop/api/comcat/nn-comcat-icatregister)