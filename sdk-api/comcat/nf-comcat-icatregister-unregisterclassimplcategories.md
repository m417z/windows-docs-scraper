# ICatRegister::UnRegisterClassImplCategories

## Description

Removes one or more implemented category identifiers from a class.

## Parameters

### `rclsid` [in]

The class identifier.

### `cCategories` [in]

The number of category CATIDs to be removed.

### `rgcatid` [in]

An array of CATIDs that are to be removed. Only the category IDs specified in this array are removed.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One or more arguments are incorrect. |

## Remarks

In case of an error, this method does not ensure that the registry is restored to the state prior to the call. This method will be successful even if one or more of the category IDs specified are not registered for the class. This method can only be called by the owner of a class, usually as part of the de-installation of the component.

## See also

[ICatRegister](https://learn.microsoft.com/windows/desktop/api/comcat/nn-comcat-icatregister)