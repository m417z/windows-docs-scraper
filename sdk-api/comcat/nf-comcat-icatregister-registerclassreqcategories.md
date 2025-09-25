# ICatRegister::RegisterClassReqCategories

## Description

Registers the class as requiring one or more component categories.

## Parameters

### `rclsid` [in]

The class identifier.

### `cCategories` [in]

The number of category CATIDs to be associated as category identifiers for the class.

### `rgcatid` [in]

An array of CATIDs to be associated as category identifiers for the class.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One or more arguments are incorrect. |

## Remarks

In case of an error, this method does not ensure that the registry is restored to the state prior to the call. This method can only be called by the owner of a class, usually as part of the installation of the component.

## See also

[ICatRegister](https://learn.microsoft.com/windows/desktop/api/comcat/nn-comcat-icatregister)